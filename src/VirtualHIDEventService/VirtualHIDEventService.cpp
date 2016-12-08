#include "VirtualHIDEventService.hpp"

#define super IOHIDEventService
OSDefineMetaClassAndStructors(VIRTUAL_HID_EVENT_SERVICE_CLASS, super);

void VIRTUAL_HID_EVENT_SERVICE_CLASS::dispatchKeyboardEvent(UInt32 usagePage, UInt32 usage, UInt32 value) {
  AbsoluteTime ts;
  clock_get_uptime(&ts);

  // options values:
  // * kHIDDispatchOptionKeyboardNoRepeat
  IOOptionBits options = 0;

  super::dispatchKeyboardEvent(ts, usagePage, usage, value, options);
}
