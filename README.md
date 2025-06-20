# Brushless L&R Master
Rebuilding a vintage L&R Master precision watch cleaning machine with modern brushless motor controls

https://github.com/user-attachments/assets/d17b6613-2972-4438-96e9-239b7f4856e6

## Components
* L&R Master precision watch cleaning machine
* Adafruit [Pro Trinket 5V](https://learn.adafruit.com/introducing-pro-trinket)
  * Mode selection: SPDT toggle switch
  * Speed control: 1-turn 10k Ohm potentiometer
* Rev [SPARK MAX](https://docs.revrobotics.com/brushless/spark-max/overview) motor controller
* Rev [NEO Brushless Motor V1.1](https://docs.revrobotics.com/brushless/neo/v1.1)
* 12VDC power supply

## SPARK MAX configuration
* Motor Type: REV NEO Brushless
* Idle Mode: Coast
* Smart Current Limit: 10A
* PWM Input Deadband: 0.05
* Hard & soft limit switches disabled
* Ramp rate: 1 second to full speed
