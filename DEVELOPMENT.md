# Classes

* VirtualHIDRoot
  * VirtualHIDRoot_UserClient
    * VirtualHIDKeyboard
      * IOHIDInterface
        * IOHIDEventDriver
        * VirtualHIDEventService
    * VirtualHIDPointing

# Restrictions

## We should not add virtual pointing device until user really want to add it

macOS UI changes the scroll bar design if a mouse device (not trackpad) is connected.
The virtual pointing device affect this behavior.

## We should not use VirtualHIDKeyboard::handleReport

macOS has an issue that macOS ignores EnableSecureEventInput for input events from `VirtualHIDKeyboard::handleReport`.
Thus, we should use `dispatchKeyboardEvent` to post keyboard events.

* We have to provide the sub class of `IOHIDEventService` to use `dispatchKeyboardEvent`.
* `IOHIDEventService` requires to implement `getReportElements()` in the sub class.
* We cannot create `IOHIDElement` directly, thus we have to get the elements from `IOHIDInterface::createMatchingElements()`.
* We cannot make multiple `IOHIDEventDriver` instances under one `IOHIDInterface` instance, thus we have to use `IOHIDEventService`.
