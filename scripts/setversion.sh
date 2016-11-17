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
