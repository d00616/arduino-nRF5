/* This sketch demonstrates the printf command.
 *
 * THIS FEATURE IS INCOMPATIBLE TO AVR and SAMD
 * BASED BOARDS.
 *
 * At this time it's only compatible with serial
 * output.
 */

void setup() {
  Serial.begin(9600);
}

void loop() {
  printf("Millis %d\n", millis());
  delay(300);
}
