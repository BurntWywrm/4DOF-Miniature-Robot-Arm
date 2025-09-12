// multi_potentiometer_testing.ino
// Code for testing multiple potentiometers for an Arduino Uno (and also a button)

// Assigned variables for each of the potentiometers
// LX dictates the heirarchy of the potentiometers
int potL1Pin = A0;
int potL2Pin = A1;
int potL3Pin = A2;
int potL4Pin = A3;

// button variables
int buttonPin = 13; // button for the end effector
int buttonVal = 0; // Stores button value
String button_state; // stores button state

void setup()
{
    Serial.begin(9600); // starts serial monitor
    pinMode(buttonPin, INPUT); // Initializes button
}

void loop()
{
    // Function for displaying and declaring pot angle
    current_pot_angle(potL1Pin);
    current_pot_angle(potL2Pin);
    current_pot_angle(potL3Pin);
    current_pot_angle(potL4Pin);
    // Function for displaying and declaring button state
    current_button_state();
}

void current_button_state(){
// Declares and displays current button state
    buttonVal = digitalRead(buttonPin); // stores button value
    
    // Simple if else statement to declare the state of the button
    if (buttonVal == HIGH){
        button_state = "On";
    } else if (buttonVal == LOW){
        button_state = "Off";
    }

    // Displays button state in the serial monitor
    Serial.print("Button State: ");
    Serial.println(button_state);
    Serial.println("------------------");
}

void current_pot_angle(int potIn){
// Declares and displays current pot angle
    // Declares current pot angle
    int potVal = analogRead(potIn); // Stores the pot value being fed into the function
    int degrees = map(potVal, 0, 1023, 0, 180); // Maps the potVal into degrees

    // Names pot respective to the its analog pin number
    // Simple switch statement to declare which joint is which
    String potName; // stores pot name 
    switch(potIn){
        case A0: potName = "Joint L1"; break;
        case A1: potName = "Joint L2"; break;
        case A2: potName = "Joint L3"; break;
        case A3: potName = "Joint L4"; break;
        default: potName = "Unknown Joint";
    }

    // Displays current pot angle
    Serial.print(potName);
    Serial.print(": ");
    Serial.print(degrees);
    Serial.println(" Degrees");
    Serial.println("------------------");
    delay(100); // Modify if it prints too fast
}