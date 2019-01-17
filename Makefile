.PHONY : build clean test line install

build:
	
	@./tools/build.sh

clean:
	@-rm -r build

test:
	@make
	@./build/target/test

line:
	@-wc -l  `find ./dlagon/ -name "*"`

install:
	make build
	@-mkdir ~/.include
	@-mkdir ~/.lib
	cp dlagon/include ~/.include/dlagon -r
	cp build/libdlagon.a ~/.lib/
	@echo ">>>>>>>>>>>>>>>>>>      安装完成        <<<<<<<<<<<<<<<<<<<<<"