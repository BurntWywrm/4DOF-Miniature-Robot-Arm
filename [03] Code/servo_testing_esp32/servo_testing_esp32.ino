// servo_testing.ino
// https://github.com/BurntWywrm/4DOF-Miniature-Robot-Arm
// Code for testing servos using a Adafruit PCA9685 servo breakout board 

#include <Wire.h> // Initialize Wire library for I2C
#include <Adafruit_PWMServoDriver.h> // Initialize adafruit PCA9685 servo library

// Define maximum and minimum number of "ticks" for the servo motors.
// Configure as necessary
#define MIN 750 // Minimum Value for pulse width count
#define MAX 2700 // Maximum Value for pulse width count

// Servo Motor Connectors
// Configure as necessary
#define SERVOL1 0

#define FREQUENCY 50

// Create object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

void setup()
{
  Serial.begin(115200); // Serial Monitor initilization
  
  // Initializes PWM
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

void loop()
{
  // Sweeps the servo back and forth
  for (int pulselen = MIN; pulselen <= MAX; pulselen += 5){
    pwm.setPWM(SERVOL1, 0, pulselen);
    delay(10);
  }
  delay(250); // quick pause
  for (int pulselen = MAX; pulselen >= MIN; pulselen -= 5){
    pwm.setPWM(SERVOL1, 0, pulselen);
    delay(10);
  }
  delay(250); // quick pause
}