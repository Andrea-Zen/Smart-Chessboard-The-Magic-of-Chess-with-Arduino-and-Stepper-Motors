Arduino Dual Servo Control with Button
This Arduino project controls two servos with a single button. Pressing the button moves the first servo from 0 to 90 degrees and the second servo from 90 to 0 degrees. Releasing the button returns both servos to their initial positions. The movement speed of the servos is adjustable for smoother, faster transitions.

Components
1 x Arduino Uno R3
1 x Push Button
1 x Servo Motor (for pin 9)
1 x Servo Motor (for pin 10)
Jumper Wires
Breadboard (optional)
Power Supply (if required for high-power servos)
Wiring Diagram
Button:

Connect one terminal of the button to pin 2 on the Arduino.
Connect the other terminal to GND.
The internal pull-up resistor on pin 2 is enabled in the code.
Servos:

Connect the control wire of the first servo to pin 9 on the Arduino.
Connect the control wire of the second servo to pin 10.
Connect both servos' power (VCC) and ground (GND) to the Arduino or an external power supply if necessary.
