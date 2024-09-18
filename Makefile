CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/BasicCNN.c src/Utils.c
OBJ = $(SRC:.c=.o)
TARGET = BasicCNN

# Test-related variables
TEST_SRC = tests/TestBasicCNN.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_TARGET = run_tests

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "Linking $@"
	$(CC) -o $@ $^

%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Test target
test: $(TEST_TARGET)
	@echo "Running tests"
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ) $(filter-out src/main.o, $(OBJ))
	@echo "Linking $@"
	$(CC) -o $@ $^

# Add this rule if it's missing
tests/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_OBJ) $(TEST_TARGET)

.PHONY: all clean test