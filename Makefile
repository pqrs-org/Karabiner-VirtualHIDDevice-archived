all: gitclean
	make -C src
	rm -rf dist
	mkdir -p dist
	mkdir -p dist/include
	cp -R src/build/Release/VirtualHIDDevice.kext dist/org.pqrs.driver.VirtualHIDDevice.kext
	cp src/include/karabiner_virtualhiddevice.hpp dist/include
	bash ./scripts/codesign.sh dist
	bash ./scripts/setpermissions.sh dist

install:
	bash ./src/scripts/unload.sh
	sudo rm -rf /tmp/org.pqrs.driver.VirtualHIDDevice
	sudo mkdir -p /tmp/org.pqrs.driver.VirtualHIDDevice
	sudo cp -R dist/org.pqrs.driver.VirtualHIDDevice.kext /tmp/org.pqrs.driver.VirtualHIDDevice
	sudo kextload /tmp/org.pqrs.driver.VirtualHIDDevice/org.pqrs.driver.VirtualHIDDevice.kext

clean:
	make -C src clean

gitclean:
	git clean -f -x -d
