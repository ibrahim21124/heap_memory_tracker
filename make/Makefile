INC_DIR := ../include
SRC_DIR := ../src
OBJ_DIR := ../obj
BIN_DIR := ../bin
LIB_DIR := ../lib
CC := g++
AR := ar

LIB := $(LIB_DIR)/libheaptracker.a
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CIFLAGS := -I $(INC_DIR)
CFLAGS := -Wall -c -g
# LIBFLAGS := -shared
LIBFLAGS := rcs

all : $(LIB) $(OBJ_DIR)/main.o | $(BIN_DIR)
	$(CC) -o app.out $(OBJ_DIR)/main.o -L. $(LIB)
	mv app.out $(BIN_DIR)

$(OBJ_DIR)/main.o : ../main.cpp $(INC_DIR)/heaptracker.h | $(OBJ_DIR)
	$(CC) $(CIFLAGS) $(CFLAGS)  $< -o $@
	
# ar rcs library.a a.o b.o c.o d.o
$(LIB) : $(OBJ) | $(LIB_DIR)
	$(AR) $(LIBFLAGS) $@ $^ 

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CIFLAGS) $(CFLAGS) $< -o $@

$(BIN_DIR) $(LIB_DIR) $(OBJ_DIR):
	mkdir -p $@

clean: 
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR) $(LIB_DIR)

