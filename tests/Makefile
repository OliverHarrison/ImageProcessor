#Image Processor Unit Tests Makefile

CC = g++
CCFLAGS = -std=c++11

BIN = bin
BUILD = build
SRC = src
INC = include

CPP_FILES := $(wildcard $(SRC)/*.cpp)
OBJ_FILES := $(addprefix $(BUILD)/,$(notdir $(CPP_FILES:.cpp=.o)))

$(BIN)/ImageProcessorTest: $(OBJ_FILES) build/pixel.o build/image.o build/lodepng.o
	$(CC) $(CCFLAGS) -o $@ $^

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CC) $(CCFLAGS) -I ../$(INC) -I ../src -c $< -o $@

$(BUILD)/%.o: ../src/%.cpp
	$(CC) $(CCFLAGS) -I ../$(INC) -c $< -o $@

$(BUILD)/lodepng.o:
	$(CC) $(CCFLAGS) -c ../$(INC)/lodepng.cpp -o $(BUILD)/lodepng.o

run:
	cd bin; ./ImageProcessorTest

clean:
	rm -f *.o $(BUILD)/*.o