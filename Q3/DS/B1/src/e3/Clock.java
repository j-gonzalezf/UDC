package e3;

/*
 * @author j.gonzalezf
 * @author adriano.miranda
 */

import java.time.Period;

public class Clock {        //defino la clase Clock
        private int seconds;
        private int minutes;
        private int hours;

        public enum Period {
                AM("AM"), PM("PM");
                String name;

                Period(String name) {
                        this.name = name;
                }
        }

        Period periodo;

        public Clock(String s) {
        }

        public Clock(int horas, int minutos, int segundos) {        //comprueba que los la hora se introduca correctamente

                if ((horas >= 0) && (minutos >= 0) && (segundos >= 0)) {        //tiempo positivos
                        if ((horas < 24) && (minutos < 60) && (segundos < 60)) {    //hora en formato 24
                                hours = horas;
                                minutes = minutos;
                                seconds = segundos;
                        }
                } else {
                        throw new IllegalArgumentException("values do not represent a valid hour");
                }
        }

        public Clock(int horas, int minutos, int segundos, Period period) { //comprueba que los la hora se introduca correctamente
                if ((horas >= 0) && (minutos >= 0) && (segundos >= 0)) {        //tiempos positivos
                        if ((horas < 13) && (minutos < 60) && (segundos < 60)) {    //Hora en en formato 12
                                hours = horas;
                                minutes = minutos;
                                seconds = segundos;
                                periodo = period;
                        } else {
                                throw new IllegalArgumentException("values do not represent a valid hour");
                        }
                }
        }

        public int getHours24() {       //si es PM y menor de doce se le suman 12 horas
                if ((hours < 12) && (periodo == Period.PM)) {
                        hours = hours + 12;
                } else if (hours == 12) {     //si es justo las 12 serian las 0
                        hours = 0;
                }
                return hours;
        }

        public int getHours12() {
                if (hours > 12) {          //si la hora es mayor que 12 se le restan 12 para que sea formato 12h
                        hours = hours - 12;  // y el periodo sería PM
                        periodo = Period.PM;
                }
                return hours;
        }

        public int getMinutes() {
                return minutes;
        }

        public int getSeconds() {
                return seconds;
        }

        public Period getPeriod() {
                return periodo;
        }

        public String printHour24() {
                getHours24();   //las horas las cojo de esta función en formato 24 h
                String h, m, s;
                String hora, minutos, segundos, reloj;
                hora = Integer.toString(hours);
                if (hours < 10)
                        h = "0";         //entre 0 y 9 se le pone un 0 para que la salida esté en el formato correcto
                else h = "";
                minutos = Integer.toString(minutes);
                if (minutes < 10) m = "0";
                else m = "";
                segundos = Integer.toString(seconds);
                if (seconds < 10) s = "0";
                else s = "";
                reloj = h + hora + ":" + m + minutos + ":" + s + segundos;  //esta sería la salida
                System.out.println(reloj);                                  //La imprimo
                return reloj;
        }

        public String printHour12() {
                getHours12();
                String h, m, s;
                String hora, minutos, segundos, reloj;
                hora = Integer.toString(hours);
                if (hours < 10) h = "0";    //entre 0 y 9 se le pone un 0 para que la salida esté en el formato correcto
                else h = "";
                minutos = Integer.toString(minutes);
                if (minutes < 10) m = "0";
                else m = "";
                segundos = Integer.toString(seconds);
                if (seconds < 10) s = "0";
                else s = "";
                reloj = h + hora + ":" + m + minutos + ":" + s + segundos + " " + periodo;  //Esta es la salida
                System.out.println(reloj);                                                  //La imprimo
                return reloj;

        }

        public boolean equals(Object o) {
                Clock aux = (Clock) o;
                if (o == null) {
                        return false;
                } else if ((this.getClass() == o.getClass()) || (this == o)) {
                        return true;
                } else if (this.getMinutes() == aux.getMinutes() && this.getSeconds() == aux.getSeconds() && this.getHours24() == aux.getHours24()) {
                        return true;
                } else return false;
        }

        @Override
        public int hashCode() {
                getHours12();
                getPeriod();    //para el hashCode sumo a las horas los minutos,segundos y hashCode del perdiodo multiplicado cada uno por 31
                int hash = hours;
                hash = 31 * hash + minutes;
                hash = 31 * hash + seconds;
                hash = 31 * hash + periodo.hashCode();
                return hash;
        }
}
