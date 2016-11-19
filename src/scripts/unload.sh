#!/bin/bash

PATH=/bin:/sbin:/usr/bin:/usr/sbin; export PATH

# --------------------------------------------------
for kext in $(kextstat | ruby -ne 'print $1,"\n" if /(org\.pqrs\.driver\.VirtualHIDManager.*?) /'); do
    sudo kextunload -b $kext -q
done

exit 0
