/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

int mydelay;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  Serial.begin(115200);

  // Print welcome message
  Serial.println("Arduino Blink example v 1.0.1");

  // Print blank line
  Serial.print('\n');

  // Prompt user for input
  Serial.println("Input blink delay (milliseconds):");

  // wait for user input
  while (Serial.available() == 0){
    delay(10);
  }

  // Process user input
  mydelay = Serial.parseInt();
  Serial.print("You entered ");
  Serial.println(mydelay);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(mydelay);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(mydelay);              // wait for a second
}
