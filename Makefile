CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/BasicCNN.c src/Utils.c
OBJ = $(SRC:.c=.o)
TARGET = BasicCNN

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "Linking $@"
	$(CC) -o $@ $^

%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)