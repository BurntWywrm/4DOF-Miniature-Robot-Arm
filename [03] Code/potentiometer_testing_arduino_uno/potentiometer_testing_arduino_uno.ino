// potentiometer_testing_arduino_uno.ino
// https://github.com/BurntWywrm/4DOF-Miniature-Robot-Arm
// Code for testing a single potentiometer made for an Arduino Uno

int potPin = A5; // initializes pot
int potVal = 0; // stores the pot value

void setup()
{
    Serial.begin(9600); // Starts Serial Monitor
}

void loop()
{
    potVal = analogRead(potPin); // reads & stores pot value

    // displays the pot value
    Serial.print("Pot Value: ");
    Serial.println(potVal); 

    int potDegrees = map(potVal, 0, 1023, 0, 180); // maps the read values into angles with a max range of 180 degrees
    
    // displays the converted pot value
    Serial.print("Pot Degrees: ");
    Serial.print(potDegrees);
    Serial.println(" Degrees");

    delay(100); // Configure if the displayed code isnt readable
}