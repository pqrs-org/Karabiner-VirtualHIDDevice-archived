#include "VirtualHIDRoot.hpp"

#define super IOService
OSDefineMetaClassAndStructors(VIRTUAL_HID_ROOT_CLASS, super);

bool VIRTUAL_HID_ROOT_CLASS::start(IOService* provider) {
  IOLog("org_pqrs_driver_VirtualHIDRoot::start\n");

  if (!super::start(provider)) {
    return false;
  }

  // Publish ourselves so clients can find us
  //
  // Note:
  // IOHIDDevice (VirtualHIDPointing, etc) cannot create custom UserClient directly.
  // Therefore, we provide UserClient here.
  registerService();

  return true;
}

void VIRTUAL_HID_ROOT_CLASS::stop(IOService* provider) {
  IOLog("org_pqrs_driver_VirtualHIDRoot::stop\n");

  super::stop(provider);
}
