# Controlling Sensors with Arduino UNO
## Table of Contents : 
1. [Introduction](#Introduction)
1. [Ultrasonic sensor](#Ultrasonic-sensor)
    - [Circuit Components](#Ultrasonic-Circuit-Components)
    - [Circuit Wiring](#Ultrasonic-Circuit-Wiring)
    - [Arduino Code](#Ultrasonic-Arduino-Code)
    - [Code simulation](#Ultrasonic-Code-simulation)
1. [Ultrasonic sensor with a LED](#Ultrasonic-sensor-with-a-LED)
    - [Circuit Components](#Ultrasonic-with-a-LED-Circuit-Components)
    - [Circuit Wiring](#Ultrasonic-with-a-LED-Circuit-Wiring)
    - [Arduino Code](#Ultrasonic-with-a-LED-Arduino-Code)
    - [Code simulation](#Ultrasonic-with-a-LED-Code-simulation)
1. [Digital Sensor](#Digital-Sensor)
     - [Circuit Components](#PIR-Circuit-Components)
     - [Circuit Wiring](#PIR-Circuit-Wiring)
     - [Arduino Code](#PIR-Arduino-Code)
     - [Code simulation](#PIR-code-simulation)
1. [Analog Sensor](#Analog-Sensor)
   - [Circuit Components](#LDR-Circuit-Components)
   - [Circuit Wiring](#LDR-Circuit-Wiring)
   - [Arduino Code](#LDR-Arduino-Code)
   - [Code simulation](#LDR-code-simulation)
1. [References](#References)
## Introduction
The third task for the Electronics and Power Department is controlling some sensors with an Arduino UNO. A sensor is an input device that produces an output in response to its surrounding environment.Detecting an object in the back of a vehicle, monitoring a patient's heart rate, and using smoke detectors are just some of the many applications for sensors,which can be classified into two types: analog and digital.[^7] Analog sensors measure a continuous range and the output is a continuous signal represented by a sine wave, while digital sensors measure discrete values and the output is a discrete signal represented by a square wave. [^7]

## Ultrasonic Sensor
Ultrasonic sensor "a digital sensor" is an electrical device that measures the distance to an object by sending an ultrasonic sound waves. It calculates the distance by using this formula D = ½ T x C, the T here refers to time that the ultrasonic sound takes untill it reaches an object,and the C is the speed of sound.[^5]
The ultrasonic sensor has 4 pins (Vcc , ground, trigger,and echo pin).The trigger pin is the input pin that triggers "initiates" the sensor by sending the sound waves to detect an object.And the echo pin is the output pin that recieves the sound wave and send a signal back if an object is detected.[^5]

<kbd> **Figure 1** <br><br>*Ultrasonic sensor*<br><br> <kbd>![image](https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/b378af0f-30e8-406d-99c8-483acdc0b914) [^4]</kbd></kbd>

### Ultrasonic Circuit Components
1. HC-SR04 Ultrasonic sensor
2. Arduino UNO
3. Breadboard
4. Wires
   
### Ultrasonic Circuit Wiring
The 4 pins of the Ultrasonic are all connected to the Arduino through the breadboard. The Vcc pin is connected to the 5v pin of the Arduino, the ground pin is connected to the GND pin of the Arduino, the trigger pin is connected to pin 12 of the Arduino, and the echo pin is connected to pin 11 of the arduino.<br><br>

<kbd> **Figure 2** <br><br>*Ultrasonic Sensor Circuit*<br><br> <kbd>![image](https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/f67f0a58-ffe2-426d-a7f8-1f1cd8913207)</kbd></kbd>

### Ultrasonic Arduino Code
In the following code the readUltrasonicDistance() method is used to send a signal from the trigger pin and send back the time it took to detect an object (send the signal back) over the echo pin.[^2]<br><br>
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

## Ultrasonic sensor with a LED
### Ultrasonic with a LED Circuit Components
1. HC-SR04 Ultrasonic sensor
2. Red LED
3. 220 ohm resistor
4. Arduino UNO
5. Breadboard
6. Wires
   
### Ultrasonic with a LED Circuit Wiring
The 4 pins of the Ultrasonic are all connected to the Arduino throught the breadboard. The Vcc pin is connected to the 5v pin of the Arduino, the ground pin is connected to the GND pin of the Arduino, the trigger pin is connected to pin 12 of the Arduino, and the echo pin is connected to pin 11 of the arduino.The positive "Anode" leg of the LED is connected to the resistor that is connected to pin 5 of the Arduino, and the cathode leg of the LED is connected to the GND pin of the arduino through the breadboard <br><br>

<kbd> **Figure 3** <br><br>*Ultrasonic Sensor with a LED Circuit*<br><br> <kbd>![image](https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/860ea708-17a3-4408-a5af-aaea4ac63336)</kbd></kbd>

### Ultrasonic with a LED Arduino Code
In the following code the readUltrasonicDistance() method is used to send a signal from the trigger pin and send back the time it took to detect an object (send the signal back) over the echo pin.[^2]. In addition, the LED will only light up if the distance measured by the ultrasonic is less than 50 cm.<br><br>
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
  pinMode(5, OUTPUT);
}
void loop()
{
Serial.println(0.01723 * readUltrasonicDistance(echoPin, echoPin));
  dist = 0.01723 * readUltrasonicDistance(triggerPin, echoPin);
  if (dist < 50) {
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
```
### Ultrasonic with a LED Code simulation


https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/8a48c35c-33e6-4575-add9-cc291c67755f


## Digital Sensor
Passive infrared sensor "PIR" is an another example of a digital sensor,since it reads discrete values "HIGH or LOW". A PIR sensor detects motion by measuring infrared light from the surrounding object.[^6]

### PIR Circuit Components
1. PIR sensor
2. Arduino UNO
3. Wires
4. Breadboard

### PIR Circuit Wiring
The PIR sensor has 3 pins (Vcc, ground , and signal). The Vcc pin is connected to the 5V pin of the Arduino through the breadboard,The ground pin is connected to the GND pin of the Arduino through the breadboard,and the signal pin is connected to pin 2 of the Arduino.<br><br>

<kbd> **Figure 4** <br><br>*PIR Sensor Circuit*<br><br> <kbd>![image](https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/1dfc5e5f-c98f-45bb-82f9-e95b3440fc05)</kbd></kbd>
### PIR Arduino Code
The following code reads the sensor value, and if HIGH, it prints "motion detected" on the serial monitor, and if LOW, "motion stopped" is printed on the serial monitor.[^6]<br><br>
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
## Analog Sensor
I have added the LDR light dependent resistor sensor to this task as an example of an analog sensor.LDR sensors are light sensitive devices that measure light intensity.[^3]
### LDR Circuit Components
1. LDR Sensor
2. 10k ohm resistor
3. Arduino UNO
4. Breadboar
5. Wires

### LDR Circuit Wiring
The LDR sensor has two pins.And to apply voltage divider, the 10k ohm resistor need to be connected in series with the sensor.[^1]<br><br>

<kbd> **Figure 5** <br><br>*LDR Sensor Circuit*<br><br> <kbd>![image](https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/59c43984-42b9-4864-bfcf-15094c4f4b40)</kbd></kbd>

### LDR-Arduino-Code
From the Arduino IDE **File>examples>Analog>AnalogInOutSerial** section, a ready to use code is provided.[^1]
```
const int analogInPin = A0;  // Analog input pin that the LDR is attached to

int sensorValue = 0;  // value read from the pot

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.println(sensorValue);

  delay(2);
}
```
### LDR code simulation


https://github.com/Rawnaa-19/Controlling-Sensors-with-Arduino-UNO/assets/106926557/4113e20c-82e3-498f-b3a1-f9779baa9297

### References
[^1]: Instructables. (2017). How to use a Light Dependent Resistor (LDR). Instructables. https://www.instructables.com/How-to-Use-a-Light-Dependent-Resistor-LDR/ 
[^2]: Instructables. (2023). Ultrasonic distance sensor in Arduino with Tinkercad. Instructables. https://www.instructables.com/Ultrasonic-Distance-Sensor-Arduino-Tinkercad/
[^3]: Keim, R. (n.d.). Photoresistor. Resistor Types | Resistor Guide. https://eepower.com/resistor-guide/resistor-types/photo-resistor/# 
[^4]: Micro bit Lesson — Using the Ultrasonic Module « osoyoo.com. (2018, September 18). https://osoyoo.com/2018/09/18/micro-bit-lesson-using-the-ultrasonic-module/ 
[^5]: Robocraze. (2022). What is Ultrasonic Sensor: Working Principle & Applications. Robocraze. https://robocraze.com/blogs/post/what-is-ultrasonic-sensor
[^6]: Santos, S., & Santos, S. (2019). Arduino with PIR Motion Sensor | Random Nerd Tutorials. Random Nerd Tutorials. https://randomnerdtutorials.com/arduino-with-pir-motion-sensor/
[^7]: Teja, R. (2023). What is a Sensor? Different Types of Sensors and their Applications. ElectronicsHub. https://www.electronicshub.org/different-types-sensors/ 

  
