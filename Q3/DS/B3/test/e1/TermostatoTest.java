package e1;

import org.junit.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class TermostatoTest {

    Off off = new Off();
    Manual manual = new Manual();
    Timer timer = new Timer();
    Program program = new Program();

    @Test
    public void Termostato(){
        Termostato t = new Termostato(20);

        t.newTemperature(25.6f);
        t.setModo(manual);
        t.newTemperature(23);
        t.screenInfo();
        t.setModo(timer, 7);
        t.newTemperature(24);
        t.screenInfo();
        t.newTemperature(23);
        t.screenInfo();
        t.setModo(program, 20);
        t.newTemperature(22);
        t.screenInfo();
        t.newTemperature(19);
        t.screenInfo();
        t.newTemperature(20);
        t.setModo(off);
        t.newTemperature(10);
        t.screenInfo();

        assertEquals("\n" +
                "20.0 Modo Off - Calefacción apagada.\n" +
                "25.6 Modo Off - Calefacción apagada.\n" +
                "Se activa el modo Manual.\n" +
                "23.0 Modo Manual - Calefacción encendida.\n" +
                "Se activa el modo Timer 7 minutos.\n" +
                "24.0 Modo Timer (faltan 2 minutos) - Calefacción encendida.\n" +
                "Se desactiva el modo Timer.\n" +
                "Se activa el modo Off.\n" +
                "23.0 Modo Off - Calefacción apagada.\n" +
                "Se activa el modo Program a 20.0 grados.\n" +
                "22.0 Modo Program (a 20.0 grados) - Calefacción apagada.\n" +
                "19.0 Modo Program (a 20.0 grados) - Calefacción encendida.\n" +
                "20.0 Modo Program (a 20.0 grados) - Calefacción apagada.\n" +
                "Se activa el modo Off.\n" +
                "10.0 Modo Off - Calefacción apagada.\n", t.registro());

        t.setModo(program);

        assertThrows(UnsupportedOperationException.class,() -> t.setModo(timer));
        assertThrows(UnsupportedOperationException.class,() -> t.setModo(timer, 10));
    }
}
