#include <Servo.h>

Servo servo1;                  // Servo 1 object
Servo servo2;                  // Servo 2 object
const int buttonPin = 2;       // Pin connected to the button
int servo1Position = 0;        // Initial position of servo 1
int servo2Position = 90;       // Initial position of servo 2
int targetPosition1 = 0;       // Target position for servo 1
int targetPosition2 = 90;      // Target position for servo 2
bool buttonState = false;      // Button state
bool lastButtonState = false;  // Last button state
int stepDelay = 5;             // Delay between each servo step (lower = faster)

void setup() {
  servo1.attach(9);              // Attach servo 1 to pin 9
  servo2.attach(10);             // Attach servo 2 to pin 10
  pinMode(buttonPin, INPUT_PULLUP); // Enable pull-up resistor on pin 2
  servo1.write(servo1Position);  // Set initial position for servo 1
  servo2.write(servo2Position);  // Set initial position for servo 2
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin) == LOW; // Read button state

  // Check for button state change (debounce)
  if (currentButtonState != lastButtonState) {
    delay(50); // Debounce delay
    if (currentButtonState == true) { // When button is pressed
      // Toggle target positions
      if (targetPosition1 == 0) {
        targetPosition1 = 90;   // Set target for servo 1 to 90 degrees
        targetPosition2 = 0;    // Set target for servo 2 to 0 degrees
      } else {
        targetPosition1 = 0;    // Reset target for servo 1 to 0 degrees
        targetPosition2 = 90;   // Reset target for servo 2 to 90 degrees
      }

      // Move servos gradually to target positions
      moveServosGradually(servo1Position, targetPosition1, servo1);
      moveServosGradually(servo2Position, targetPosition2, servo2);

      // Update current positions
      servo1Position = targetPosition1;
      servo2Position = targetPosition2;
    }
  }

  lastButtonState = currentButtonState; // Store previous button state
}

// Function to gradually move servos to target position
void moveServosGradually(int startPos, int endPos, Servo &servo) {
  if (startPos < endPos) {
    for (int pos = startPos; pos <= endPos; pos++) {
      servo.write(pos);           // Move servo to current position
      delay(stepDelay);           // Step delay for speed control
    }
  } else {
    for (int pos = startPos; pos >= endPos; pos--) {
      servo.write(pos);           // Move servo to current position
      delay(stepDelay);           // Step delay for speed control
    }
  }
}
