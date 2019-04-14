.PHONY : build clean test line install

build:
	
	@./tools/build.sh

clean:
	@-rm -r build

test:
	@make
	@./build/test/test_main

line:
	@-wc -l  `find ./dlagon/ -name "*"`

install:
	make build
	@-mkdir ~/.include
	@-mkdir ~/.lib
	@-rm -r ~/.include/dlagon
	@-rm ~/.lib/libdlagon.a
	cp dlagon/include ~/.include/dlagon -r -f
	cp build/libdlagon.a ~/.lib/ -f
	@echo ">>>>>>>>>>>>>>>>>>      安装完成        <<<<<<<<<<<<<<<<<<<<<"