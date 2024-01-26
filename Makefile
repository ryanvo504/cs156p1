# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall

# Source file
SOURCE = builddepend.cpp

# Executable name
TARGET = builddepend

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	
clean:
    rm -f $(TARGET)
