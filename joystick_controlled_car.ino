// Define joystick pins
const int joyX = A0;
const int joyY = A1;
const int joySW = 2;  // Joystick button (optional)

// Motor control pins
const int motorA1 = 3;
const int motorA2 = 4;
const int motorB1 = 5;
const int motorB2 = 6;

void setup() {
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  pinMode(joySW, INPUT_PULLUP);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);
  int joyButton = digitalRead(joySW);

  // Control Logic
  if (yValue < 400) { // Forward
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
  } else if (yValue > 600) { // Backward
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
  } else if (xValue < 400) { // Left
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
  } else if (xValue > 600) { // Right
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
  } else { // Stop
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
  }

  // Optional: Print joystick values for debugging
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  Serial.print(" | Button: ");
  Serial.println(joyButton);

  delay(50); // Small delay for stability
}
