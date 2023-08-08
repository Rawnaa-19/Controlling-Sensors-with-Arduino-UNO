# Controlling Sensors with Arduino UNO
## Table of Contents : 
1. [Introduction](#Introduction)
1. [Ultrasonic sensor](#Ultrasonic-sensor)
    - [Circuit Components](#Ultrasonic-Circuit-Components)
    - [Circuit Wiring](#Ultrasonic-Circuit-Wiring)
    - [Arduino Code](#Ultrasonic-Arduino-Code)
    - [Code simulation](#Ultrasonic-Code-simulation)
1. [Digital Sensor](#Digital-Sensor)
     - [Circuit Components](#PIR-Circuit-Components)
     - [Circuit Wiring](#PIR-Circuit-Wiring)
     - [Arduino Code](#PIR-Arduino-Code)
     - [Code simulation](#PIR-code-simulation)
1. [Analog Sensor](#Analog-Sensor)
   - [Circuit Components](#knob-Circuit-Components)
   - [Circuit Wiring](#knob-Circuit-Wiring)
   - [Arduino Code](#knob-Arduino-Code)
   - [Code simulation](#knob-code-simulation)
1. [References](#References)
## Introduction
The third task for the Electronics and Power Department is controlling some sensors with an Arduino UNO. A sensor is an input device that produces an output in response to its surrounding environment.Detecting an object in the back of a vehicle, monitoring a patient's heart rate, and using smoke detectors are just some of the many applications for sensors,which can be classified into two types: analog and digital.**(Teja, 2023)** Analog sensors measure a continuous range and the output is a continuous signal represented by a sine wave, while digital sensors measure discrete values and the output is a discrete signal represented by a square wave. (Teja, 2023)

## Ultrasonic Sensor
Ultrasonic sensor "a digital sensor" is an electrical device that measures the distance to an object by sending an ultrasonic sound waves. It calculates the distance by using this formula D = ½ T x C, the T here refers to time that the ultrasonic sound takes untill it reaches an object,and the C is the speed of sound.(Robocraze, 2022)
The ultrasonic sensor has 4 pins (Vcc , ground, trigger,and echo pin).The trigger pin is the input pin that triggers "initiates" the sensor by sending the sound waves to detect an object.And the echo pin is the output pin that recieves the sound wave and send a signal back if an object is detected  (Robocraze, 2022)

<kbd> **Figure 1** <br><br>*Ultrasonic sensor*<br><br> <kbd>![image](https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/b378af0f-30e8-406d-99c8-483acdc0b914) [osoyoo.com][ref]</kbd></kbd>

### Ultrasonic Circuit Components
1. HC-SR04 Ultrasonic sensor
2. Arduino UNO
3. Breadboard
4. Wires
   
### Ultrasonic Circuit Wiring
The 4 pins of the Ultrasonic are all connected to the Arduino throught the breadboard. The Vcc pin is connected to the 5v pin of the Arduino, the ground pin is connected to the GND pin of the Arduino, the trigger pin is connected to pin 12 of the Arduino, and the echo pin is connected to pin 11 of the arduino.<br><br>

<kbd> **Figure 2** <br><br>*Ultrasonic Sensor Circuit*<br><br> <kbd>![image](https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/f67f0a58-ffe2-426d-a7f8-1f1cd8913207)</kbd></kbd>

### Ultrasonic Arduino Code
In the following code the readUltrasonicDistance() method is used to send a signal from the trigger pin and send back the time it took to detect an object (send the signal back) over the echo pin.(Instructables, 2023)<br><br>
```
// C++ code
//
int dist = 0;
int triggerPin=12;//Orange Wire
int echoPin = 11;// Yellow Wire
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.println(0.01723 * readUltrasonicDistance(echoPin, echoPin));
  dist = 0.01723 * readUltrasonicDistance(triggerPin, echoPin);

  delay(10); // Delay a little bit to improve simulation performance
}
```
### Ultrasonic Code simulation

https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/5a9a103f-f5fb-4fc3-a5ed-0da530c85fcf

## Digital Sensor
Passive infrared sensor "PIR" is an another example of a digital sensor,since it reads discrete values "HIGH or LOW". A PIR sensor detects motion by measuring infrared light from the surrounding object.(Santos & Santos, 2019)

### PIR Circuit Components
1. PIR sensor
2. Arduino UNO
3. Wires
4. Breadboard

### PIR Circuit Wiring
The PIR sensor has 3 pins (Vcc, ground , and signal). The Vcc pin is connected to the 5V pin of the Arduino through the breadboard,The ground pin is connected to the GND pin of the Arduino through the breadboard,and the signal pin is connected to pin 2 of the Arduino.<br><br>

<kbd> **Figure 3** <br><br>*PIR Sensor Circuit*<br><br> <kbd>![image](https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/1dfc5e5f-c98f-45bb-82f9-e95b3440fc05)</kbd></kbd>
### PIR Arduino Code
The following code reads the sensor value, and if HIGH, it prints "motion detected" on the serial monitor, and if LOW, "motion stopped" is printed on the serial monitor.(Santos & Santos, 2019)<br><br>
```
int sensor = 2;              // the pin that the sensor is atteched to
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
      Serial.println("Motion detected!");   
  } 
  else {
        Serial.println("Motion stopped!"); 
  }
}
```
### PIR code simulation

https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/0b5643e2-e346-42b2-a2d1-f08bbf275a62

