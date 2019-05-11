.PHONY : build clean test line

build:
	@./script/build.sh

clean:
	@-rm -r build
test:
	@make
	@./build/test/test_main

line:
	wc -l `find dlagon -name "*"`