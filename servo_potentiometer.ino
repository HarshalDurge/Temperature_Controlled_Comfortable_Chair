
#include <BH1750.h>
#include <Wire.h>
#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;  // create another servo object to control a second servo
BH1750 lightMeter;

int potPin1 = A0;  // analog pin used to connect the potentiometer for servo1
int potPin2 = A1;  // analog pin used to connect the potentiometer for servo2
int val1;          // variable to read the value from the analog pin for servo1
int val2;          // variable to read the value from the analog pin for servo2
const int relayPin = 7; // Define the relay pin
const float threshold = 300.0; // Light intensity threshold in lux

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  pinMode(relayPin, OUTPUT); // Set relay pin as an output
  digitalWrite(relayPin, LOW); // Ensure relay is off at start
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
  servo2.attach(8); // attaches the servo on pin 8 to the servo object

}
  
void loop() {
  val1 = analogRead(potPin1);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servo1.write(val1);                    // sets the servo position according to the scaled value

  val2 = analogRead(potPin2);            // reads the value of the potentiometer (value between 0 and 1023)
  val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servo2.write(val2);                    // sets the servo position according to the scaled value

  delay(15);                             // waits for the servo to reach the position

  float lux = lightMeter.readLightLevel(); // Read the light level in lux

  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");

  if (lux < threshold) {
    digitalWrite(relayPin, HIGH); // Turn on the relay
  } else {
    digitalWrite(relayPin, LOW); // Turn off the relay
  }

  delay(1000); // Wait for a second before the next reading
}
  
