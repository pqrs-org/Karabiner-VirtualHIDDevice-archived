#pragma once

#include "VirtualHIDKeyboard.hpp"
#include "VirtualHIDManager.hpp"
#include "VirtualHIDPointing.hpp"
#include "karabiner_virtualhiddevice.hpp"

class org_pqrs_driver_VirtualHIDManager_UserClient final : public IOUserClient {
  OSDeclareDefaultStructors(org_pqrs_driver_VirtualHIDManager_UserClient);

public:
  virtual bool initWithTask(task_t owningTask,
                            void* securityToken,
                            UInt32 type) override;

  virtual IOReturn clientClose(void) override;

  virtual IOReturn externalMethod(uint32_t selector,
                                  IOExternalMethodArguments* arguments,
                                  IOExternalMethodDispatch* dispatch = 0,
                                  OSObject* target = 0,
                                  void* reference = 0) override;

private:
  static IOReturn staticInitializeVirtualHIDKeyboardCallback(org_pqrs_driver_VirtualHIDManager_UserClient* target,
                                                             void* reference,
                                                             IOExternalMethodArguments* arguments);
  IOReturn initializeVirtualHIDKeyboardCallback(void);

  static IOReturn staticInitializeVirtualHIDPointingCallback(org_pqrs_driver_VirtualHIDManager_UserClient* target,
                                                             void* reference,
                                                             IOExternalMethodArguments* arguments);
  IOReturn initializeVirtualHIDPointingCallback(void);

  static IOReturn staticTerminateVirtualHIDKeyboardCallback(org_pqrs_driver_VirtualHIDManager_UserClient* target,
                                                            void* reference,
                                                            IOExternalMethodArguments* arguments);
  IOReturn terminateVirtualHIDKeyboardCallback(void);

  static IOReturn staticTerminateVirtualHIDPointingCallback(org_pqrs_driver_VirtualHIDManager_UserClient* target,
                                                            void* reference,
                                                            IOExternalMethodArguments* arguments);
  IOReturn terminateVirtualHIDPointingCallback(void);

  static IOReturn staticPostKeyboardInputReportCallback(org_pqrs_driver_VirtualHIDManager_UserClient* target,
                                                        void* reference,
                                                        IOExternalMethodArguments* arguments);
  IOReturn postKeyboardInputReportCallback(const pqrs::karabiner_virtualhiddevice::hid_report::keyboard_input& input);

  static IOReturn staticPostPointingInputReportCallback(org_pqrs_driver_VirtualHIDManager_UserClient* target,
                                                        void* reference,
                                                        IOExternalMethodArguments* arguments);
  IOReturn postPointingInputReportCallback(const pqrs::karabiner_virtualhiddevice::hid_report::pointing_input& input);

  static IOExternalMethodDispatch methods_[static_cast<size_t>(pqrs::karabiner_virtualhiddevice::user_client_method::end_)];
  org_pqrs_driver_VirtualHIDKeyboard* virtualHIDKeyboard_;
  org_pqrs_driver_VirtualHIDPointing* virtualHIDPointing_;
};
