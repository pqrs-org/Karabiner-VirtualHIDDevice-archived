#pragma once

#include "DiagnosticMacros.hpp"
#include "VersionSignature.hpp"

BEGIN_IOKIT_INCLUDE;
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
END_IOKIT_INCLUDE;

#include "VirtualHIDEventService.hpp"

class VIRTUAL_HID_ROOT_CLASS final : public IOService {
  OSDeclareDefaultStructors(VIRTUAL_HID_ROOT_CLASS);

public:
  virtual bool init(OSDictionary* dictionary = nullptr) override;
  virtual bool start(IOService* provider) override;
  virtual void stop(IOService* provider) override;

  VIRTUAL_HID_EVENT_SERVICE_CLASS* getVirtualHIDEventService(void) const {
    return virtualHIDEventService_;
  }

private:
  VIRTUAL_HID_EVENT_SERVICE_CLASS* virtualHIDEventService_;
};
