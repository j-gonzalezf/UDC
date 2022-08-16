-module(break_md5).
-define(PASS_LEN, 6).
-define(UPDATE_BAR_GAP, 1000).
-define(BAR_SIZE, 40).
-define(NUM_PROCS, 1).

-export([
         break_md5s/1,
         break_md5/1,
         pass_to_num/1,
         num_to_pass/1,
         num_to_hex_string/1,
         hex_string_to_num/1
        ]).

-export([progress_loop/4]).
-export([break_md5/5]).
-export([create_proccess/7]).

% Base ^ Exp

pow_aux(_Base, Pow, 0) ->
    Pow;
pow_aux(Base, Pow, Exp) when Exp rem 2 == 0 ->
    pow_aux(Base*Base, Pow, Exp div 2);
pow_aux(Base, Pow, Exp) ->
    pow_aux(Base, Base * Pow, Exp - 1).

pow(Base, Exp) -> pow_aux(Base, 1, Exp).

%% Number to password and back conversion

num_to_pass_aux(_N, 0, Pass) -> Pass;
num_to_pass_aux(N, Digit, Pass) ->
    num_to_pass_aux(N div 26, Digit - 1, [$a + N rem 26 | Pass]).

num_to_pass(N) -> num_to_pass_aux(N, ?PASS_LEN, []).

pass_to_num(Pass) ->
    lists:foldl(fun (C, Num) -> Num * 26 + C - $a end, 0, Pass).

%% Hex string to Number

hex_char_to_int(N) ->
    if (N >= $0) and (N =< $9) -> N - $0;
       (N >= $a) and (N =< $f) -> N - $a + 10;
       (N >= $A) and (N =< $F) -> N - $A + 10;
       true                    -> throw({not_hex, [N]})
    end.

int_to_hex_char(N) ->
    if (N >= 0)  and (N < 10) -> $0 + N;
       (N >= 10) and (N < 16) -> $A + (N - 10);
       true                   -> throw({out_of_range, N})
    end.

hex_string_to_num(Hex_Str) ->
    lists:foldl(fun(Hex, Num) -> Num*16 + hex_char_to_int(Hex) end, 0, Hex_Str).

num_to_hex_string_aux(0, Str) -> Str;
num_to_hex_string_aux(N, Str) ->
    num_to_hex_string_aux(N div 16,
                          [int_to_hex_char(N rem 16) | Str]).

num_to_hex_string(0) -> "0";
num_to_hex_string(N) -> num_to_hex_string_aux(N, []).

%% Progress bar runs in its own process
%%TODO N2 es el numero de claves probadas, estimación: crear variable por parametro que va sumando los tiempos (T2-T1) y se imprime al llegar a 1 segundo imprime (N2*1000000)/(T2-T1)
progress_loop(N, Bound, Count, Estimacion) ->
    T1 = erlang:monotonic_time(microsecond),
    receive
        {stop, Pid} ->
            Pid ! stop;
        {stop_hashes, Hashes, Pid} ->
            Pid ! {stop_hashes, Hashes},
            ok;
        {progress_report, Checked} ->
            N2 = N + Checked,
            Full_N = N2 * ?BAR_SIZE div Bound,
            Full = lists:duplicate(Full_N, $=),
            Empty = lists:duplicate(?BAR_SIZE - Full_N, $-),
            T2 = erlang:monotonic_time(microsecond),
            Count2 = Count + (T2-T1),
            
            case  Count2 >= 1000000 of
                true ->
                    Estimacion2 = floor(Checked/((T2-T1)/1000000)),          %%Estima cuantas contraseñas se calculan por segundo (sabemos que se calculan 1000 cada T2-T1 microsegundos)
                    io:format("\r[~s~s] ~.2f%  ~.2p ", [Full, Empty, N2/Bound*100, Estimacion2]),
                    progress_loop(N2, Bound, 0, Estimacion2);
                false ->                                                     %%Si aún no llegamos a 1 segundo 
                    io:format("\r[~s~s] ~.2f%  ~.2p ", [Full, Empty, N2/Bound*100, Estimacion]),
                    progress_loop(N2, Bound, Count2, Estimacion) 
            end
    end. 

%% break_md5/2 iterates checking the possible passwords
break_md5([],_,_,_, Pid)-> 
    Pid ! finished,
    ok;   %No hay más hashes por encontrar (cuando esta completada devuelve ok)
break_md5(Hashes, N, N, _, Pid) -> 
    Pid ! {not_found, Hashes},  % not_found para cuando no se encuentra la contraseña
    ok;
break_md5(Hashes, N, Bound, Progress_Pid, Pid) ->
    receive 
        {del, New_Hashes}->
            break_md5(New_Hashes, N, Bound, Progress_Pid, Pid);
        stop -> ok
    after 0 ->    
        if N rem ?UPDATE_BAR_GAP == 0 ->
            Progress_Pid ! {progress_report, ?UPDATE_BAR_GAP};
        true ->
            ok
        end,
        Pass = num_to_pass(N),
        Hash = crypto:hash(md5, Pass),
        Num_Hash = binary:decode_unsigned(Hash),
        case lists:member(Num_Hash,Hashes) of       %%para cada Hash de la lista de hashes 
            true ->                                 %%Si lo encuentro imprimo la contraseña y elimino el hash de la lista de hashes
                io:format("\e[2K\r~.16B: ~s~n", [Num_Hash, Pass]),
                Pid ! {find, lists:delete(Num_Hash, Hashes)},      
                break_md5(lists:delete(Num_Hash,Hashes), N+1, Bound, Progress_Pid, Pid);
            false ->
                break_md5(Hashes, N+1, Bound, Progress_Pid, Pid)     %%Si no es esa contraseña pruebo con el siguiente
        end
    end.

create_proccess(0, Num_Hashes, X, Bound, Progress_Pid, N, List_Pid) ->
    receive
        {stop_hashes, Hashes} -> {not_found, Hashes};
        stop -> ok;
        {find, Hashes} ->
            Fun = fun (Pid_Aux) -> Pid_Aux ! {del, Hashes} end,
            lists:foreach(Fun, List_Pid),
            create_proccess(0, Num_Hashes, X, Bound, Progress_Pid, N, List_Pid);
        finished -> 
            if N == ?NUM_PROCS ->   %%Si es el ultimo proceso paras
                Progress_Pid ! {stop, self()}, 
                create_proccess(0, Num_Hashes, X, Bound, Progress_Pid, N, List_Pid);
            true ->
                create_proccess(0, Num_Hashes, 1, Bound, Progress_Pid, N+1, List_Pid)
            end;
        {not_found, Hashes} -> 
            if N == ?NUM_PROCS ->
                Progress_Pid ! {stop_hashes, Hashes, self()},
                create_proccess(0, Num_Hashes, X, Bound, Progress_Pid, N, List_Pid);
            true ->
                create_proccess(0, Num_Hashes, 1, Bound, Progress_Pid, N+1, List_Pid)
            end
    end;

create_proccess(N, Num_Hashes, X, Bound, Progress_Pid, Y, List_Pid) -> 
    Start = Bound div ?NUM_PROCS * (N-1),   %% Donde empieza y donde acaba el numero de passwords a encontrar
    End = Bound div ?NUM_PROCS * N,
    Pid = spawn(?MODULE, break_md5,[Num_Hashes, Start, End, Progress_Pid, self()]),
	create_proccess(N-1, Num_Hashes, X, Bound, Progress_Pid, Y, [Pid | List_Pid]).

%% Break a list of hashes

break_md5s(Hashes) ->
    Bound = pow(26, ?PASS_LEN),
    List_Pid = [],
    Progress_Pid = spawn(?MODULE, progress_loop, [0, Bound, 0,0]),
    Num_Hashes = lists:map(fun hex_string_to_num/1, Hashes),
    Res = create_proccess(?NUM_PROCS, Num_Hashes, 0, Bound, Progress_Pid, 1, List_Pid),
    Progress_Pid ! stop,
    Res.

%% Break a single hash

break_md5(Hash) -> break_md5s([Hash]).
