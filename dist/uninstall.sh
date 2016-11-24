#!/bin/sh

PATH='/bin:/sbin:/usr/bin:/usr/sbin'; export PATH

install_directory='/Library/Application Support/org.pqrs/Karabiner-VirtualHIDDevice'

# Unload kexts
for kext in `kextstat | ruby -ne 'print $1,"\n" if /(org\.pqrs\.driver\.VirtualHIDDevice.*?) /'`; do
    kextunload -b "$kext" -q
done

# Delete files
rm -rf "$install_directory"
