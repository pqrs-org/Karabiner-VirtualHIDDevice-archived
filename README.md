[![Build Status](https://travis-ci.org/tekezo/Karabiner-VirtualHIDDevice.svg?branch=master)](https://travis-ci.org/tekezo/Karabiner-VirtualHIDDevice)
[![License](https://img.shields.io/badge/license-Public%20Domain-blue.svg)](https://github.com/tekezo/Karabiner-VirtualHIDDevice/blob/master/LICENSE.md)

# Karabiner-VirtualHIDDevice

Karabiner-VirtualHIDDevice is a virtual HID device driver for macOS.

## System requirements

* OS X 10.11.*
* OS X 10.12.*

## How to build

System requirements:

* OS X 10.11+
* Xcode 8+
* Command Line Tools for Xcode

### Step 1: Getting source code

Clone the source from github.

```
git clone --depth 1 https://github.com/tekezo/Karabiner-VirtualHIDDevice.git
```

### Step 2: Building a package

```
cd Karabiner-VirtualHIDDevice
make
```

The `make` script will create a redistributable kext into `dist` directory.

## Example

* `example/virtual_keyboard_example`
* `example/virtual_pointing_example`

### Usage

Execute the following instructions in Terminal.

1. Install VirtualHIDDevice.kext by `make install` in the top directory.
2. `cd example/virtual_pointing_example`
3. `make`
4. `make run`

## Caution

macOS has an issue that macOS ignores EnableSecureEventInput for input events from `post_keyboard_input_report`.
Thus, use `dispatch_keyboard_event` to post keyboard events via VirtualHIDKeyboard.

You can confirm the issue of macOS by `appendix/dump_hid_report`.

1. `cd appendix/dump_hid_report`
2. `make`
3. `make run`
4. Enable `Secure Keyboard Entry` in Terminal.
5. Open new tab in Terminal.
6. `cd example/virtual_keyboard_example`
7. `make`
8. `make run`

If you can see output in `dump_hid_report`, the virtual keyboard input is leaked.
