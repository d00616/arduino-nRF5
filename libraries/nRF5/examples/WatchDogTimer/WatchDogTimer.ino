/* This sketch demonstrates the AVR compatible
 *  Hardware Watch Dog functionality.
 */

#include <avr/wdt.h>

int wdt_delay;

void setup() {
  Serial.begin(9600);
  Serial.println("Reset");
  Serial.println("Set WDT to 1s.");
  wdt_enable(WDTO_1S);
  wdt_delay = 1;
}

void loop() {
  Serial.print("Delay: ");
  Serial.println(wdt_delay);
  delay(wdt_delay);
  wdt_reset();
  wdt_delay*=2;
}
