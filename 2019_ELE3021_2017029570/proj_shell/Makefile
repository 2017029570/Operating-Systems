CC = g++
CXXFLAGS = -g -Wall -std=c++11

SRCS := $(wildcard src/*.cc)
OBJS := $(SRCS:.cc=.o)
BIN = ./bin/
INC = ./include/
LIB = ./lib/ -lpthread

CPPFLAGS += -I$(INC)

TARGET = shell
$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) $(CPPFLAGS) -o $(BIN)$(TARGET) $(OBJS) -L$(LIB)

clean:
	rm $(BIN)$(TARGET) $(OBJS)    
