#pragma once

#include "DiagnosticMacros.hpp"
#include "VersionSignature.hpp"

BEGIN_IOKIT_INCLUDE;
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
END_IOKIT_INCLUDE;

class VIRTUAL_HID_MANAGER_CLASS final : public IOService {
  OSDeclareDefaultStructors(VIRTUAL_HID_MANAGER_CLASS);

public:
  virtual bool start(IOService* provider) override;
  virtual void stop(IOService* provider) override;
};
