#!/bin/bash

basedir=`dirname $0`
version=$(cat "$basedir/../version")

version_signature=$(echo $version | ruby -ne 'print "v%02d%02d%02d" % $_.strip.split(/\./)')

find $basedir/.. -name '*.tmpl' -print0 | while IFS= read -r -d '' f; do
    if [ -f "$f" ]; then
        outputfile=`dirname "$f"`/`basename "$f" .tmpl`
        tmpfile=`mktemp /tmp/setversion.XXXXXX`

        sed "s|PKGVERSION|$version|g" "$f" | \
            sed "s|VERSIONSIGNATURE|$version_signature|g" > $tmpfile
        if cmp -s "$tmpfile" "$outputfile"; then
            # tmpfile and outputfile are same. remove tmpfile.
            rm -f "$tmpfile"
        else
            mv "$tmpfile" "$outputfile"
        fi
    fi
done

# append version_signature to MODULE_NAME and PRODUCT_BUNDLE_IDENTIFIER in project.pbxproj
sed -i '' "s|MODULE_NAME = org\.pqrs\.driver\.VirtualHIDDevice.*;|MODULE_NAME = org.pqrs.driver.VirtualHIDDevice_${version_signature};|g" ../src/VirtualHIDDevice.xcodeproj/project.pbxproj
sed -i '' "s|PRODUCT_BUNDLE_IDENTIFIER = org\.pqrs\.driver\.VirtualHIDDevice.*;|PRODUCT_BUNDLE_IDENTIFIER = org.pqrs.driver.VirtualHIDDevice_${version_signature};|g" ../src/VirtualHIDDevice.xcodeproj/project.pbxproj
