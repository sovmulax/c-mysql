CC = gcc
SRC_DIR = ./functions
BIN_DIR = ./bin
LIB_DIR = ./lib

# List all the source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Generate the corresponding object file names
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(SRC_FILES))

# The default target, which will build the executable
all: $(BIN_DIR)/bibliotheque run

# Link the object files and libraries to create the executable
$(BIN_DIR)/bibliotheque: $(OBJ_FILES) $(LIB_DIR)/libotheque.a
	$(CC) -o $@ $^ -lsqlite3

# Compile each source file into an object file
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $<

# Create the static library
$(LIB_DIR)/libotheque.a:  $(BIN_DIR)/ajout_livre.o $(BIN_DIR)/ajout_user.o $(BIN_DIR)/emprunts.o $(BIN_DIR)/list_adh.o $(BIN_DIR)/list_livres.o $(BIN_DIR)/list_emprunt.o 
	ar rcs $@ $^

# Clean the generated files
clean:
	rm -f $(BIN_DIR)/* $(LIB_DIR)/*

# Run the program
run:
	$(BIN_DIR)/bibliotheque