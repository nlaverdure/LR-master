# Spark L&R Master
Rebuilding a vintage L&R Master precision watch cleaning machine with modern brushless motor controls

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
