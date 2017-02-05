#Image Processor Makefile

CC = g++
CCFLAGS = -std=c++11

BIN = bin
BUILD = build
SRC = src
INC = inc

CPP_FILES := $(wildcard $(SRC)/*.cpp)
OBJ_FILES := $(addprefix $(BUILD)/,$(notdir $(CPP_FILES:.cpp=.o)))

$(BIN)/ImageProcessor: $(OBJ_FILES)
	$(CC) $(CCFLAGS) -o $@ $^

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

run:
	cd bin; ./ImageProcessor

clean:
	rm -f *.o $(BUILD)/*.o