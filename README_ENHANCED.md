# Arduino Core for Nordic Semiconductor nRF5 based boards, enhanced version

*THIS IS A FORK OF* [sandeepmistry/arduino-nRF5](https://github.com/sandeepmistry/arduino-nRF5). If
you are looking for a more stable and compatible version use the version of sandeepmistry.

This fork provides more functionality like Nordic specific output modes, AVR compatibility and some
librararies supporting internal hardware of Nordic Semiconducter MCUs. This breaks compatibility
with Arduino SAMD core.

## Core enhancements

### avr/wdt.h

This header file provides an interface to internal hardware watch dog.

wdt_enable() accepts a timeout in ms. The WDTO_... constants are updated.

wdt_disable() does'n work like expected. It set the timeout to 36h and configure the WDT to
pause in sleep mode. Running code from flash with DCDC enabled consumes 133mAh. A CR2032
(250mAh) powered device is reset a maximum of one time in battery life when wdt_disable is
used at the beginning.

## Additional libraries

