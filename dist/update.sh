#!/bin/sh

PATH='/bin:/sbin:/usr/bin:/usr/sbin'; export PATH

basedir=`dirname "$0"`
cd "$basedir"

bundle_identifier='org.pqrs.driver.VirtualHIDDevice.v020300'
install_directory='/Library/Application Support/org.pqrs/Karabiner-VirtualHIDDevice'

# Skip if already installed
if kextstat | grep -q "$bundle_identifier"; then
    echo "$bundle_identifier is already installed"
    exit 0
fi

# Unload kexts
for kext in `kextstat | ruby -ne 'print $1,"\n" if /(org\.pqrs\.driver\.VirtualHIDDevice.*?) /'`; do
    kextunload -b "$kext" -q
done

# Copy kext
rm -rf "$install_directory"
mkdir -p "$install_directory"
cp -R include "$install_directory"
cp -R org.pqrs.driver.VirtualHIDDevice.kext "$install_directory"

# Load kext
kextload "$install_directory/org.pqrs.driver.VirtualHIDDevice.kext"
