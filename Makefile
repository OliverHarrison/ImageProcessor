#Image Processor Makefile

CC = g++
CCFLAGS = -std=c++11

BIN = bin
BUILD = build
SRC = src
INC = include

CPP_FILES := $(wildcard $(SRC)/*.cpp) lodepng.o
OBJ_FILES := $(addprefix $(BUILD)/,$(notdir $(CPP_FILES:.cpp=.o)))

$(BIN)/ImageProcessor: $(OBJ_FILES)
	$(CC) $(CCFLAGS) -o $@ $^

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CC) $(CCFLAGS) -I $(INC) -c $< -o $@

$(BUILD)/lodepng.o:
	$(CC) $(CCFLAGS) -c $(INC)/lodepng.cpp -o $(BUILD)/lodepng.o

run:
	cd bin; ./ImageProcessor sample-images/lenna.png

test:
	cd tests; make; make run

clean:
	rm -f $(BUILD)/*.o $(BIN)/*.exe