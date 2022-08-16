package e1;

public interface ModoTermostato {
    void action(Termostato t);

    void screenInfo(Termostato t);

    void newTemperature(Termostato t, float currentTemperature);
}
