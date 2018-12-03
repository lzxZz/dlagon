TARGET = ./target/debug/server

OPTION = -g -Wall -I./include

OBJS = ./obj/main.o \

DLAGON_OBJS = 	./obj/server.o \
	./obj/httpreq.o \
	./obj/httpres.o \
	./obj/socket.o

vpath %.cpp ./src/
vpath %.cc ./src/
vpath %.h ./include/



$(TARGET) : $(OBJS) $(DLAGON_OBJS)
	@-mkdir ./target/
	@-mkdir ./target/debug/
	g++ -o $(TARGET) $(OBJS) $(DLAGON_OBJS) $(OPTION) -lunp	-lpthread
	@echo ">>>>>>>>>>>>>>>> -------------- <<<<<<<<<<<<<<<<<<"
	@echo ">>>>>>>>>>>>>>>> build success! <<<<<<<<<<<<<<<<<<"
	@echo ">>>>>>>>>>>>>>>> -------------- <<<<<<<<<<<<<<<<<<"


./obj/main.o : main.cpp server.h 
	@-mkdir ./obj/
	gcc -c ./src/main.cpp -o ./obj/main.o  $(OPTION)

./obj/server.o : server.cpp server.h 
	gcc -c ./src/server.cpp -o ./obj/server.o $(OPTION) 

./obj/httpreq.o : http/request.cc
	gcc -c ./src/http/request.cc -o ./obj/httpreq.o $(OPTION)

./obj/httpres.o : http/response.cc
	gcc -c ./src/http/response.cc -o ./obj/httpres.o $(OPTION)

./obj/socket.o : socket.cc
	gcc -c ./src/socket.cc -o ./obj/socket.o $(OPTION)

.PHONY : run clean line basic

clean : 
	@rm ./obj/*
	@rm $(TARGET)
	@echo "clean!"

run :
	@$(TARGET)

line:
	@-wc -l ./src/** ./include/**
	@-wc -l ./src/http/** ./include/http/**
	@-wc -l ./src/socket/** ./include/socket/**

mem:
	make
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all $(TARGET)

.PHONY : basic cb rb

BASIC_OBJS = $(DLAGON_OBJS) \
			./example/basic/main.o

basic : $(BASIC_OBJS)
	g++ $(BASIC_OBJS) -o example/basic/basic -lpthread

example/basic/main.o : example/basic/main.cc	
	gcc -o example/basic/main.o -c  example/basic/main.cc	  -I./include 

cb : 
	@-rm $(BASIC_OBJS)
	@-rm example/basic/basic
rb :
	@example/basic/basic


.PHONY : release
release: $(DLAGON_OBJS)
	@-mkdir release
	@cp -r ./include release/include
	@ar rcs -o ./release/libdlagon.a $(DLAGON_OBJS)
	@echo ">>>>>>>>>>>>>>>> -------------- <<<<<<<<<<<<<<<<<<"
	@echo ">>>>>>>>>>>>>>> release success! <<<<<<<<<<<<<<<<<"
	@echo ">>>>>>>>>>>>>>>> -------------- <<<<<<<<<<<<<<<<<<"
	