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

  delay(10); // Delay a little bit to improve simulation performance
}