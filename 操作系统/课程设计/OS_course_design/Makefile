CC = gcc
CXX = g++

CFLAGS = -Wall -g

SOURCE = $(wildcard *.c)

TARGET = $(patsubst %.c,%,$(SOURCE))

.PHONY: all clean

%: %.c
	$(CC) $(CFLAGS) $< -o $@

all: $(TARGET)


clean: 
	rm -f $(TARGET)
