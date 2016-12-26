/* This sketch demonstrates the AVR compatible
 * atomic.h implementation. After 10 seconds the
 * counter isn't incremented for 5 seconds while
 * RTC is running.
 */

#include "nrf.h"
#include <util/atomic.h>

uint16_t counter = 0;

void setup() {
  Serial.begin(9600);

  NVIC_SetPriority(RTC0_IRQn, 15);
  NVIC_ClearPendingIRQ(RTC0_IRQn);
  NVIC_EnableIRQ(RTC0_IRQn);
  NRF_RTC0->PRESCALER = 32;
  NRF_RTC0->EVTENSET = RTC_EVTENSET_COMPARE0_Msk;
  NRF_RTC0->INTENSET = RTC_INTENSET_COMPARE0_Msk;
  NRF_RTC0->CC[0] = 500;
  NRF_RTC0->TASKS_START = 1;
}

void loop() {
  ATOMIC_BLOCK(ATOMIC_FORCEON)
  {
     if (millis()>10000) {
      delay(5000);
     }
  }
  Serial.print("Counter: ");
  Serial.println(counter);
  Serial.print("RTC: ");
  Serial.println(NRF_RTC1->COUNTER);
  Serial.print("Millis: ");
  Serial.println(millis());
  delay(300);
}

extern "C" void RTC0_IRQHandler(void) { counter++; NRF_RTC0->EVENTS_COMPARE[0] = 0; NRF_RTC0->CC[0] = NRF_RTC0->COUNTER + 500; } 
