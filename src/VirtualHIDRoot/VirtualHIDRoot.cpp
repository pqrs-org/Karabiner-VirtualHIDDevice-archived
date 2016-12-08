#include "VirtualHIDRoot.hpp"

#define super IOService
OSDefineMetaClassAndStructors(VIRTUAL_HID_ROOT_CLASS, super);

bool VIRTUAL_HID_ROOT_CLASS::init(OSDictionary* dictionary) {
  if (!super::init(dictionary)) {
    return false;
  }

  virtualHIDEventService_ = nullptr;

  return true;
}

bool VIRTUAL_HID_ROOT_CLASS::start(IOService* provider) {
  IOLog(VIRTUAL_HID_ROOT_CLASS_STRING "::start\n");

  if (!super::start(provider)) {
    return false;
  }

  do {
    virtualHIDEventService_ = new VIRTUAL_HID_EVENT_SERVICE_CLASS();
    if (virtualHIDEventService_) {
      if (virtualHIDEventService_->init(nullptr)) {
        if (virtualHIDEventService_->attach(this)) {
          if (virtualHIDEventService_->start(this)) {
            IOLog(VIRTUAL_HID_ROOT_CLASS_STRING "::virtualHIDEventService_ is started\n");
            break;
          }

          // Error handling
          virtualHIDEventService_->detach(this);
        }
      }
      // Error handling
      virtualHIDEventService_->release();
      virtualHIDEventService_ = nullptr;
    }

  } while (true);

  // Publish ourselves so clients can find us
  //
  // Note:
  // IOHIDDevice (VirtualHIDPointing, etc) cannot create custom UserClient directly.
  // Therefore, we provide UserClient here.
  registerService();

  return true;
}

void VIRTUAL_HID_ROOT_CLASS::stop(IOService* provider) {
  IOLog(VIRTUAL_HID_ROOT_CLASS_STRING "::stop\n");

  if (virtualHIDEventService_) {
    virtualHIDEventService_->terminate(kIOServiceSynchronous);
    virtualHIDEventService_->release();
    virtualHIDEventService_ = nullptr;
  }

  super::stop(provider);
}
