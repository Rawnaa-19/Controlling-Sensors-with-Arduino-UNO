# Controlling Sensors with Arduino UNO
## Table of Contents : 
1. [Introduction](#Introduction)
1. [Ultrasonic sensor](#Ultrasonic-sensor)
    - [Circuit Components](#Circuit-Components)
    - [Circuit Wiring](#Ultrasonic-Circuit-Wiring)
    - [Arduino Code](#Ultrasonic-Arduino-Code)
    - [Code simulation](#Ultrasonic-Code-simulation)
1. [Digital Sensor](#DC-Motor)
     - [Circuit Components](#DC-Motor-Circuit-Components)
     - [Circuit Wiring](#DC-Motor-Circuit-Wiring)
     - [Arduino Code](#DC-Motor-Arduino-Code)
     - [Code simulation](#knob-Motor-code-simulation)
1. [Analog Sensor]()
   - [Circuit Components](#knob-Circuit-Components)
   - [Circuit Wiring](#knob-Circuit-Wiring)
   - [Arduino Code](#knob-Arduino-Code)
   - [Code simulation](#knob-code-simulation)
1. [References](#References)

## Ultrasonic Sensor
Ultrasonic sensor is an electrical device that measures the distance to an object by sending an ultrasonic sound waves. It calculates the distance by using this formula D = ½ T x C, the T here refers to time that the ultrasonic sound takes untill it reaches an object,and the C is the speed of sound.(Robocraze, 2022)
The ultrasonic sensor has 4 pins (Vcc , ground, trigger,and echo pin).The trigger pin is the input pin that triggers "initiates" the sensor by sending the sound waves.

<kbd> **Figure 1** <br><br>Ultrasonic sensor<br><br> <kbd>![image](https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/b378af0f-30e8-406d-99c8-483acdc0b914) [osoyoo.com][ref]</kbd></kbd>
