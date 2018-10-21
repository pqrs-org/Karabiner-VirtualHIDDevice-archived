# Development

## Classes

- VirtualHIDRoot
  - VirtualHIDRoot_UserClient
    - VirtualHIDKeyboard
    - VirtualHIDPointing

## About LED state

The VirtualHIDKeyboard post a hid report with {kHIDPage_LEDs, kHIDUsage_LED_CapsLock} when the VirtualHIDKeyboard's LED state is manipuated.

You can detect the LED state changes by the hid report.

## Restrictions

### We should not add virtual pointing device until user really want to add it

macOS UI changes the scroll bar design if a mouse device (not trackpad) is connected.
The virtual pointing device affect this behavior.
