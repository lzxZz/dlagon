.PHONY : build clean test line run

build:
	@./script/build.sh

clean:
	@-rm -r build
	@-rm -r .vscode/ipch/*
test:
	@make
	@./build/test/test_main

run:
	@make
	@./build/dlagon/run

line:
	wc -l `find dlagon -name "*"`