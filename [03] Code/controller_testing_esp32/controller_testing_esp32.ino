// controller_testing_esp32.ino
// https://github.com/BurntWywrm/4DOF-Miniature-Robot-Arm
// This code is to recieve and store potentiometer signals to the ADC pins of the ESP32
// Then mapping the recieved inputs 0 to 270 degrees.

/* Assigned pot pins */
/* LX dictates the pin heirarchy, base, shoulder, elbow, wrist. */
int potL1Pin = 33;
int potL2Pin = 32;
int potL3Pin = 35;
int potL4Pin = 34;

/* Assigned button pins */
int buttonPin = 25; 
int buttonVal = 0;
String buttonState = "";

/* Assigned Angle Variables */
int MAX_ANGLE = 270;

// Angle pins to feed through bluetooth
int potL1Angle = 0;
int potL2Angle = 0;
int potL3Angle = 0;
int potL4Angle = 0;

void setup()
{
  Serial.begin(115200); // Starts serial monitor with a baud rate of 115200
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  /* Main code functionality */
  get_angle(potL1Pin);
  get_angle(potL2Pin);
  get_angle(potL3Pin);
  get_angle(potL4Pin);
  get_button_state();

  /* Displays info */
  display_pot_angle(potL1Pin);
  display_pot_angle(potL2Pin);
  display_pot_angle(potL3Pin);
  display_pot_angle(potL4Pin);

  // Displays button state
  Serial.print("button state: ");
  Serial.println(buttonState);
  Serial.println("---------------------");
  delay(250);
}

void get_button_state(){
  buttonVal = digitalRead(buttonPin);

  if (buttonVal == LOW){
    buttonState = "Close";
  }
  else{
    buttonState = "Open";
  }
}

void get_angle(int potPin){
  int potVal = analogRead(potPin); // Stores pot value
  int potAngle = map(potVal, 0, 4095, 0, MAX_ANGLE); // Maps potentiometer from 0 to 270 degrees

  /* Simple switch statement to store the correct variable */
  switch(potPin){
    case 33: potL1Angle = potAngle; break;
    case 32: potL2Angle = potAngle; break;
    case 35: potL3Angle = potAngle; break;
    case 34: potL4Angle = potAngle; break;
  }
}

void display_pot_angle(int potPin){
  int potVal = analogRead(potPin); // Stores pot value
  int potAngle = map(potVal, 0, 4095, 0, MAX_ANGLE); // Maps potentiometer from 0 to 270 degrees
  /* Simple switch statement to assign the correct potentiometer name */
  String potName = ""; // Stores pot name
  switch(potPin){
    case 33: potName = "Joint L1"; break;
    case 32: potName = "Joint L2"; break;
    case 35: potName = "Joint L3"; break;
    case 34: potName = "Joint L4"; break;
  }

  /* Displays current pot angle */
  Serial.print(potName);
  Serial.print(": ");
  Serial.print(potAngle);
  Serial.println(" Degrees");
}