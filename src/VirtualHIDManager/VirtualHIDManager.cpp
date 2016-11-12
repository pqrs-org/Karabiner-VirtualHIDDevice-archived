#include "VirtualHIDManager.hpp"

#define super IOService
OSDefineMetaClassAndStructors(org_pqrs_driver_VirtualHIDManager, IOService);

bool org_pqrs_driver_VirtualHIDManager::start(IOService* provider) {
  IOLog("org_pqrs_driver_VirtualHIDManager::start\n");

  if (!super::start(provider)) {
    return false;
  }

  // Publish ourselves so clients can find us
  //
  // Note:
  // IOHIDDevice (VirtualHIDPointing, etc) cannot create custom UserClient directly.
  // Therefore, we provide IOHIDManager for UserClient.
  registerService();

  return true;
}

void org_pqrs_driver_VirtualHIDManager::stop(IOService* provider) {
  IOLog("org_pqrs_driver_VirtualHIDManager::stop\n");

  super::stop(provider);
}
