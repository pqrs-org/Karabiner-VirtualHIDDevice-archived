all: gitclean
	make -C src
	mkdir -p dist
	rm -rf dist/org.pqrs.driver.VirtualHIDManager.kext
	cp -R src/build/Release/VirtualHIDManager.kext dist/org.pqrs.driver.VirtualHIDManager.kext
	rm -rf dist/org.pqrs.driver.VirtualHIDPointing.kext
	cp -R src/build/Release/VirtualHIDPointing.kext dist/org.pqrs.driver.VirtualHIDPointing.kext
	bash ./scripts/codesign.sh dist

# Note:
# load VirtualHIDManager after VirtualHIDPointing is loaded

install:
	bash ./src/scripts/unload.sh
	sudo rm -rf /Library/Extensions/org.pqrs.driver.VirtualHIDManager.kext
	sudo rm -rf /Library/Extensions/org.pqrs.driver.VirtualHIDPointing.kext
	bash ./scripts/setpermissions.sh dist
	sudo cp -R dist/org.pqrs.driver.VirtualHIDManager.kext /Library/Extensions
	sudo cp -R dist/org.pqrs.driver.VirtualHIDPointing.kext /Library/Extensions
	sudo kextload /Library/Extensions/org.pqrs.driver.VirtualHIDPointing.kext
	sudo kextload /Library/Extensions/org.pqrs.driver.VirtualHIDManager.kext

clean:
	make -C src clean

gitclean:
	git clean -f -x -d
