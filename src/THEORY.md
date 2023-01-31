## Theory of operation

## General methodology
Main fast loop runs on timer1 update top. There is a "hyperloop" as well, which runs on update bottom, to enable signal injection and faster PWM update
3 phase Sin wave calculated every PWM period, and FOC loop run.
Sensorless observer runs in the fastloop timer top update, and is based on the integration and clamping of fluxes in alpha beta frame. 
HFI runs in the hyperloop, timer bottom update, and is dynamically switched on and off in the slowloop.
Slowloop runs in the RCPWM input timer update interrupt. The timer should be set up to overflow and generate an interupt at 20Hz (50us) or generate an interrupt in reset mode when PWMin rising edge detected
Comparators can be set up for overcurrent events on the F303 based hardware, or an external BRK or Trip input can be put on PB12 to tri-state the bridge.
ADC analog watchdog can be used as a high priority interrupt to shutdown in case of overcurrent or ADC out of range.
