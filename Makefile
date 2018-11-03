
TARGET = ./target/debug/server

OPTION = -g -Wall

OBJS = ./obj/main.o \
	./obj/server.o

vpath %.cpp ./src/
vpath %.h ./include/



$(TARGET) : $(OBJS) 
	@-mkdir ./target/
	@-mkdir ./target/debug/
	g++ -o $(TARGET) $(OBJS) $(OPTION) -lunp


./obj/main.o : main.cpp server.h
	@-mkdir ./obj/
	gcc -c ./src/main.cpp -o ./obj/main.o  $(OPTION) -lunp

./obj/server.o : server.cpp server.h
	gcc -c ./src/server.cpp -o ./obj/server.o $(OPTION) -lunp

.PHONY : run clean

clean : 
	@rm ./obj/*
	@rm $(TARGET)
	@echo "clean!"

run :
	@$(TARGET)