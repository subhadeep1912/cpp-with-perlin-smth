CC = g++
CFLAGS = -std=c++17 -O3 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing
CFLAGS += -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression
CFLAGS += -Wno-gnu-compound-literal-initializer -Wno-gnu-zero-variadic-macro-arguments
CFLAGS += -Iinclude
HEADER = $(wildcard include/*.h) $(wildcard include/**/*.h)

# LDFLAGS = -Llib/ -lglfw3 -lGL -lX11 -lXxf86vm -lXrandr -pthread -lXi -ldl

SRC  = $(wildcard src/**/*.cpp) $(wildcard src/*.cpp)
OBJ  = $(SRC:.cpp=.o)
LDFLAGS = -Llib/ -lglfw3 -lGL -lX11 -lXxf86vm -lXrandr -pthread -lXi -ldl
BIN = bin

.PHONY: all clean

all: dirs game

dirs:
	mkdir -p ./$(BIN)

run: all
	$(BIN)/emu

game: $(OBJ)
	$(CC) -o $(BIN)/emu $^ $(LDFLAGS)

%.o: %.cpp $(HEADER)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)