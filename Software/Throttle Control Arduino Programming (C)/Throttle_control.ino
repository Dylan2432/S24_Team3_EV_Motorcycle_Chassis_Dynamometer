#include <AccelStepper.h>
 
// Define the stepper motor and the pins that are connected to
AccelStepper stepper1(1, 2, 5); // 1 means a driver with 2 pins: STEP, DIR. Pins 2 and 5 are for STEP and DIR respectively.
 
// Constants
const int analogPin = A0;                // Analog pin for the 0-5V signal input
const int stepsPerRevolution = 90 / 1.8; // Steps for a full 90-degree throttle rotation
const float maxVoltage = 5.0;            // Maximum input voltage
const int maxDegrees = 90;               // Maximum throttle position in degrees
 
void setup() {
  Serial.begin(9600);
  stepper1.setMaxSpeed(500);       // Set max speed
  stepper1.setAcceleration(1000);  // Set acceleration
  stepper1.setCurrentPosition(0);  // Set the current position to 0
}
 
void loop() {
  // Read the analog value (0-1023) from the analog pin
  int analogValue = analogRead(analogPin);
 
  // Convert analog reading to voltage
  float voltage = analogValue * (maxVoltage / 1023.0);
 
  // Map the voltage to throttle position in degrees (0-90 degrees)
  int targetDegrees = (voltage / maxVoltage) * maxDegrees;
 
  // Convert degrees to steps for the stepper motor
  int targetSteps = (targetDegrees / (float)maxDegrees) * stepsPerRevolution;
 
  // Move the stepper motor to the target position
  stepper1.moveTo(targetSteps);
  while (stepper1.distanceToGo() != 0) {
    stepper1.run();
  }
 
  // Debugging information
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V, Target Degrees: ");
  Serial.print(targetDegrees);
  Serial.print("°, Target Steps: ");
  Serial.println(targetSteps);
 
  delay(100); // Small delay to avoid excessive updates
}

