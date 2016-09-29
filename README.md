[![Build Status](https://travis-ci.org/tekezo/Karabiner-VirtualHIDDevice.svg?branch=master)](https://travis-ci.org/tekezo/Karabiner-VirtualHIDDevice)
[![License](https://img.shields.io/badge/license-Public%20Domain-blue.svg)](https://github.com/tekezo/Karabiner-VirtualHIDDevice/blob/master/LICENSE.md)

# Karabiner-VirtualHIDDevice

Karabiner-VirtualHIDDevice is a virtual HID device driver for macOS.

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

The `make` script will create a redistributable **Karabiner-Elements-VERSION.dmg** in the current directory.
