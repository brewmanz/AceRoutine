/*
MIT License

Copyright (c) 2018 Brian T. Park

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Coroutine.h"
#include "compat.h" // FPSTR()

namespace ace_routine {

// Create the sStatusStrings lookup table to translate Status integer to a
// human-readable string. When it is used, it increases flash memory by 86
// bytes, and static RAM by 14 bytes. It is currently only used by
// CoroutineScheduler::list() but I think it's worth it to make debugging
// easier.

#ifdef ACE_USE_FLASH_STRING_STATUS
 #ifdef ACE_USE_FLASH_SHORT_STRING_STATUS
  static const char kStatusSuspendedString[] PROGMEM = "Sspd";
  static const char kStatusYieldingString[] PROGMEM = "Yldg";
  static const char kStatusDelayingString[] PROGMEM = "Dlyg";
  static const char kStatusRunningString[] PROGMEM = "Rnng";
  static const char kStatusEndingString[] PROGMEM = "Endg";
  static const char kStatusTerminatedString[] PROGMEM = "Trmntd";
 #else
  static const char kStatusSuspendedString[] PROGMEM = "Suspended";
  static const char kStatusYieldingString[] PROGMEM = "Yielding";
  static const char kStatusDelayingString[] PROGMEM = "Delaying";
  static const char kStatusRunningString[] PROGMEM = "Running";
  static const char kStatusEndingString[] PROGMEM = "Ending";
  static const char kStatusTerminatedString[] PROGMEM = "Terminated";
 #endif
 #ifdef ACE_USE_FLASH_STRING_ARRAY_STATUS
  const __FlashStringHelper* const sStatusStrings[] PROGMEM = {
 #else
  const __FlashStringHelper* const sStatusStrings[] = {
 #endif
   FPSTR(kStatusSuspendedString),
   FPSTR(kStatusYieldingString),
   FPSTR(kStatusDelayingString),
   FPSTR(kStatusRunningString),
   FPSTR(kStatusEndingString),
   FPSTR(kStatusTerminatedString),
  };
#endif
template<> CoroutineTemplate<ClockInterface>::fpChangeStatusCB CoroutineTemplate<ClockInterface>::msChangeStatusCB = nullptr;
}
