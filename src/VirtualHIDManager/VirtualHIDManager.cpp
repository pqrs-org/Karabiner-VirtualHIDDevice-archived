#include "VirtualHIDManager.hpp"

#define super IOService
OSDefineMetaClassAndStructors(org_pqrs_driver_VirtualHIDManager, IOService);

bool org_pqrs_driver_VirtualHIDManager::init(OSDictionary* dict) {
  IOLog("org_pqrs_driver_VirtualHIDManager::init\n");

  if (!super::init(dict)) {
    return false;
  }

  attachedClientCount_ = 0;
  virtualHIDKeyboard_ = nullptr;
  virtualHIDPointing_ = nullptr;

  if (auto serialNumber = OSString::withCString("org.pqrs.driver.VirtualHIDManager")) {
    setProperty(kIOHIDSerialNumberKey, serialNumber);
    serialNumber->release();
  }

  return true;
}

void org_pqrs_driver_VirtualHIDManager::free(void) {
  IOLog("org_pqrs_driver_VirtualHIDManager::free\n");

  super::free();
}

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

  terminateVirtualHIDKeyboard();
  terminateVirtualHIDPointing();

  super::stop(provider);
}

void org_pqrs_driver_VirtualHIDManager::attachClient(void) {
  ++attachedClientCount_;

  IOLog("org_pqrs_driver_VirtualHIDManager::attachClient attachedClientCount_ = %d\n", static_cast<int>(attachedClientCount_));

  createVirtualHIDKeyboard();
  createVirtualHIDPointing();
}

void org_pqrs_driver_VirtualHIDManager::detachClient(void) {
  if (attachedClientCount_ > 0) {
    --attachedClientCount_;
  }

  IOLog("org_pqrs_driver_VirtualHIDManager::detachClient attachedClientCount_ = %d\n", static_cast<int>(attachedClientCount_));

  if (attachedClientCount_ == 0) {
    if (virtualHIDKeyboard_) {
      terminateVirtualHIDKeyboard();
    }
    if (virtualHIDPointing_) {
      terminateVirtualHIDPointing();
    }
  }
}

#define CREATE_VIRTUAL_DEVICE(CLASS, POINTER)                     \
  {                                                               \
    if (POINTER) {                                                \
      return;                                                     \
    }                                                             \
                                                                  \
    /* See IOHIDResourceDeviceUserClient::createAndStartDevice */ \
    POINTER = OSTypeAlloc(CLASS);                                 \
    if (!POINTER) {                                               \
      return;                                                     \
    }                                                             \
                                                                  \
    if (!POINTER->init(nullptr)) {                                \
      goto error;                                                 \
    }                                                             \
                                                                  \
    if (!POINTER->attach(this)) {                                 \
      goto error;                                                 \
    }                                                             \
                                                                  \
    if (!POINTER->start(this)) {                                  \
      POINTER->detach(this);                                      \
      goto error;                                                 \
    }                                                             \
                                                                  \
    return;                                                       \
                                                                  \
  error:                                                          \
    if (POINTER) {                                                \
      POINTER->release();                                         \
      POINTER = nullptr;                                          \
    }                                                             \
  }

#define TERMINATE_VIRTUAL_DEVICE(POINTER) \
  {                                       \
    if (!POINTER) {                       \
      return;                             \
    }                                     \
                                          \
    POINTER->terminate();                 \
    POINTER->release();                   \
    POINTER = nullptr;                    \
  }

void org_pqrs_driver_VirtualHIDManager::createVirtualHIDKeyboard(void) {
  CREATE_VIRTUAL_DEVICE(org_pqrs_driver_VirtualHIDKeyboard, virtualHIDKeyboard_);
}

void org_pqrs_driver_VirtualHIDManager::createVirtualHIDPointing(void) {
  CREATE_VIRTUAL_DEVICE(org_pqrs_driver_VirtualHIDPointing, virtualHIDPointing_);
}

void org_pqrs_driver_VirtualHIDManager::terminateVirtualHIDKeyboard(void) {
  TERMINATE_VIRTUAL_DEVICE(virtualHIDKeyboard_);
}

void org_pqrs_driver_VirtualHIDManager::terminateVirtualHIDPointing(void) {
  TERMINATE_VIRTUAL_DEVICE(virtualHIDPointing_);
}

IOReturn org_pqrs_driver_VirtualHIDManager::handleHIDKeyboardReport(IOMemoryDescriptor* report) {
  if (!virtualHIDKeyboard_) {
    return kIOReturnError;
  }

  return virtualHIDKeyboard_->handleReport(report, kIOHIDReportTypeInput, kIOHIDOptionsTypeNone);
}

IOReturn org_pqrs_driver_VirtualHIDManager::handleHIDPointingReport(IOMemoryDescriptor* report) {
  if (!virtualHIDPointing_) {
    return kIOReturnError;
  }

  return virtualHIDPointing_->handleReport(report, kIOHIDReportTypeInput, kIOHIDOptionsTypeNone);
}
