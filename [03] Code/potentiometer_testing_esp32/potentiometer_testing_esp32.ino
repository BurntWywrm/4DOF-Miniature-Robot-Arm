// ESP32 Potentiometer Input
// https://github.com/BurntWywrm/4DOF-Miniature-Robot-Arm
// This code is to recieve and store potentiometer signals to the ADC pins of the ESP32
// Then mapping the recieved inputs 0 to 270 degrees.

int potPin = 35;

void setup() {
  Serial.begin(115200); // Starts serial monitor with a baud rate of 115200
}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead(potPin);
  int degrees = map(potVal, 0, 4095, 0, 270);
  Serial.println(degrees);
}

