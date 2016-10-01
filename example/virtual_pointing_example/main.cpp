#include "karabiner_virtualhiddevice.hpp"
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/hid/IOHIDDevice.h>
#include <IOKit/hid/IOHIDElement.h>
#include <IOKit/hid/IOHIDManager.h>
#include <IOKit/hid/IOHIDQueue.h>
#include <IOKit/hid/IOHIDValue.h>
#include <IOKit/hidsystem/IOHIDShared.h>
#include <IOKit/hidsystem/ev_keymap.h>
#include <iostream>
#include <thread>
#include <cmath>

int main(int argc, const char* argv[]) {
  if (getuid() != 0) {
    std::cerr << "virtual_pointing_example requires root privilege." << std::endl;
  }

  auto service = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceNameMatching("org_pqrs_driver_VirtualHIDManager"));
  if (!service) {
    std::cerr << "IOServiceGetMatchingService error" << std::endl;
    return 1;
  }

  io_connect_t connect = IO_OBJECT_NULL;
  auto kr = IOServiceOpen(service, mach_task_self(), kIOHIDServerConnectType, &connect);
  if (kr != KERN_SUCCESS) {
    std::cerr << "IOServiceOpen error" << std::endl;
    return 1;
  }

  for (int i = 0; i < 400; ++i) {
    pqrs::karabiner_virtualhiddevice::hid_report::pointing_input report;
    report.x = static_cast<uint8_t>(cos(0.1 * i) * 20);
    report.y = static_cast<uint8_t>(sin(0.1 * i) * 20);

    kr = IOConnectCallStructMethod(connect,
                                   static_cast<uint32_t>(pqrs::karabiner_virtualhiddevice::user_client_method::pointing_input_report),
                                   &report, sizeof(report),
                                   nullptr, 0);
    if (kr != KERN_SUCCESS) {
      std::cerr << "IOConnectCallStructMethod error" << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  return 0;
}
