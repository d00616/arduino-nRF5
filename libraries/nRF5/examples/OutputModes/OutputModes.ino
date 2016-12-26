/*
  This is a High Drive Blink example
  Turns on an LED on for one second, then off for one second, repeatedly.
  
  You can use different Output Modes. Please read the nRF datasheet about
  restrictions like standard output current or the limit of three High
  Drive Pins for nRF51 MCU.
  
  Available output modes are:
    OUTPUT_S0S1   Standard '0', Standard '1'.
    OUTPUT_H0S1   High '0', Standard '1'.
    OUTPUT_S0H1   Standard '0', High '1'.
    OUTPUT_H0H1   High '0', High '1'.
    OUTPUT_D0S1   Disconnected '0', Standard '1'.
    OUTPUT_D0H1   Disconnected '0', High '1'.
    OUTPUT_S0D1   Standard '0', Disconnected '1'.
    OUTPUT_H0D1   High '0', Disconnected '1'.

  This example code is in the public domain.
 */
int led = LED_BUILTIN;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT_H0H1);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
