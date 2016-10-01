#pragma once

#include "VirtualHIDManager.hpp"
#include "karabiner_virtualhiddevice.h"

class org_pqrs_driver_VirtualHIDManager_UserClient final : public IOUserClient {
  OSDeclareDefaultStructors(org_pqrs_driver_VirtualHIDManager_UserClient);

public:
  virtual bool initWithTask(task_t owningTask, void* securityToken, UInt32 type) override;
  virtual IOReturn clientClose(void) override;

  virtual bool start(IOService* provider) override;
  virtual IOReturn externalMethod(uint32_t selector, IOExternalMethodArguments* arguments,
                                  IOExternalMethodDispatch* dispatch = 0, OSObject* target = 0, void* reference = 0) override;

private:
  static IOReturn staticPointingInputReportCallback(org_pqrs_driver_VirtualHIDManager_UserClient* target, void* reference, IOExternalMethodArguments* arguments);
  IOReturn pointingInputReportCallback(const karabiner_virtualhiddevice_hid_pointing_input_report& input);

  static IOExternalMethodDispatch methods_[static_cast<size_t>(karabiner_virtualhiddevice_user_client_method_end_)];
  task_t owner_;
  org_pqrs_driver_VirtualHIDManager* provider_;
};
