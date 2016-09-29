all: gitclean
	make -C src

clean:
	make -C src clean

gitclean:
	git clean -f -x -d
