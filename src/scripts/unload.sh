#!/bin/bash

PATH=/bin:/sbin:/usr/bin:/usr/sbin; export PATH

# --------------------------------------------------
if kextstat | grep -q org.pqrs.driver.VirtualHIDManager; then
    sudo kextunload -b org.pqrs.driver.VirtualHIDManager || exit 1
fi

if kextstat | grep -q org.pqrs.driver.VirtualHIDPointing; then
    sudo kextunload -b org.pqrs.driver.VirtualHIDPointing || exit 1
fi

exit 0
