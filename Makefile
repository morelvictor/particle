SRC_DIR = src
BIN_DIR = .bin
CC = gcc
FLAGS = -g -Wall -Wno-unused-command-line-argument -std=c99 `sdl2-config --libs --cflags` -lSDL2_image -lSDL2_ttf
EXE = particle

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(addprefix $(BIN_DIR)/, $(SRC:.c=.o))

all: clean particle

$(EXE): $(OBJ) $(BIN_DIR) $(SRC_DIR)
	$(CC) $(OBJ) -o $(EXE) $(FLAGS)

$(BIN_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(BIN_DIR)
	$(CC) -c $< -o $@ $(FLAGS)

$(SRC_DIR):
	@mkdir -p $(SRC_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)/$(SRC_DIR)

.PHONY: clean run

run: all
	./particle

clean:
	rm -rf $(BIN_DIR)

