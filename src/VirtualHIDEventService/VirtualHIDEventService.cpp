#include "VirtualHIDEventService.hpp"

#define super IOHIDEventService
OSDefineMetaClassAndStructors(VIRTUAL_HID_EVENT_SERVICE_CLASS, super);

bool VIRTUAL_HID_EVENT_SERVICE_CLASS::handleStart(IOService* provider) {
  reportElements_ = nullptr;

  auto hidInterface = OSDynamicCast(IOHIDInterface, provider);
  if (!hidInterface) {
    IOLog(VIRTUAL_HID_EVENT_SERVICE_CLASS_STRING "::handleStart provider error (provider must be IOHIDInterface).\n");
    return false;
  }
  reportElements_ = hidInterface->createMatchingElements();

  return super::handleStart(provider);
}

void VIRTUAL_HID_EVENT_SERVICE_CLASS::handleStop(IOService* provider) {
  super::handleStop(provider);

  if (reportElements_) {
    reportElements_->release();
    reportElements_ = nullptr;
  }
}

void VIRTUAL_HID_EVENT_SERVICE_CLASS::dispatchKeyboardEvent(UInt32 usagePage, UInt32 usage, UInt32 value) {
  AbsoluteTime ts;
  clock_get_uptime(&ts);

  // options values:
  // * kHIDDispatchOptionKeyboardNoRepeat
  IOOptionBits options = 0;

  super::dispatchKeyboardEvent(ts, usagePage, usage, value, options);
}
