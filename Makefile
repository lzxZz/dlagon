.PHONY : build clean test

build:
	
	@./tools/build.sh

clean:
	@-rm -r build

test:
	@make
	@./build/target/test