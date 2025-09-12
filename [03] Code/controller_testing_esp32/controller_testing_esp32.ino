// controller_testing_esp32.ino
// Code for testing the controller, made for the ESP32 board

// Assigned variables for each of the pots
// LX dicates the joint heirarchy, i.e. Base to Wrist
int potL1Pin = 33;
int potL2Pin = 32;
int potL3Pin = 34;
int potL4Pin = 35;

int buttonPin = 25; // button pin for the end effector
int buttonVal = 0; // stores button value
String button_state; // stores button state

void setup()
{
  Serial.begin(115200); // starts serial monitor
  pinMode(buttonPin, INPUT); // initializes button
}

void loop()
{
  current_pot_angle(potL1Pin);
  current_pot_angle(potL2Pin);
  current_pot_angle(potL3Pin);
  current_pot_angle(potL4Pin);
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
        case 33: potName = "Joint L1"; break;
        case 32: potName = "Joint L2"; break;
        case 34: potName = "Joint L3"; break;
        case 35: potName = "Joint L4"; break;
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