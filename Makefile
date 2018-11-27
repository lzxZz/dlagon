
TARGET = ./target/debug/server

OPTION = -g -Wall -I./include

OBJS = ./obj/main.o \
	./obj/server.o \
	./obj/httpreq.o \
	./obj/httpres.o \
	./obj/socket.o

vpath %.cpp ./src/
vpath %.cc ./src/
vpath %.h ./include/



$(TARGET) : $(OBJS) 
	@-mkdir ./target/
	@-mkdir ./target/debug/
	g++ -o $(TARGET) $(OBJS) $(OPTION) -lunp	-lpthread
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

.PHONY : run clean line

clean : 
	@rm ./obj/*
	@rm $(TARGET)
	@echo "clean!"

run :
	@$(TARGET)

line:
	@wc -l ./src/** ./include/**

mem:
	make
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all $(TARGET)