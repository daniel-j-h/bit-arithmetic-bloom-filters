TARGET=bloom
OBJECTS=bloom.o main.o djb2.o
CFLAGS=-Wall -Wextra -pedantic -std=c99
LDLIBS=

$(TARGET): $(OBJECTS)

clean:
	rm *.o $(TARGET)
