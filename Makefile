all: gitclean
	make -C src
	mkdir -p dist
	rm -rf dist/org.pqrs.driver.VirtualHIDManager.kext
	cp -R src/build/Release/VirtualHIDManager.kext dist/org.pqrs.driver.VirtualHIDManager.kext
	rm -rf dist/org.pqrs.driver.VirtualHIDPointing.kext
	cp -R src/build/Release/VirtualHIDPointing.kext dist/org.pqrs.driver.VirtualHIDPointing.kext
	bash ./scripts/codesign.sh dist

clean:
	make -C src clean

gitclean:
	git clean -f -x -d
