.PHONY : build clean test line

build:
	
	@./tools/build.sh

clean:
	@-rm -r build

test:
	@make
	@./build/target/test

line:
	wc -l  `find ./dlagon/ -name "*"`