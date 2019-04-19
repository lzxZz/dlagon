.PHONY : build clean test

build:
	@./script/build.sh

clean:
	@-rm -r build
test:
	@make
	@./build/test/test_main
