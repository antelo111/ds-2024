# Makefile for compiling hello.cpp to hello.o  
  
# Compiler  
CC = g++  
  
# Compiler flags  
CFLAGS = -c  
  
# Target file  
TARGET = hello.o  
  
all: $(TARGET)  
  
$(TARGET): hello.cpp  
	$(CC) $(CFLAGS) hello.cpp -o $(TARGET)  
  
clean:  
	rm -f $(TARGET)  