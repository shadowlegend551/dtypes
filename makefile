CC := gcc
CFLAGS := -lm

INCLUDE_DIR := -I./include
SRC_DIR := src
CORE_DIR := core
WRAPPER_DIR := wrappers
BUILD_DIR := build
LIB := lib/dtypes.a

SRC_FILES := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(CORE_DIR)/*.c) $(wildcard $(WRAPPER_DIR)/*.c)
OBJ_FILES := $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRC_FILES)))


# Compile files from src/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(INCLUDE_DIR) -c $< -o $@

# Compile files from core/
$(BUILD_DIR)/%.o: $(CORE_DIR)/%.c
	$(CC) $(INCLUDE_DIR) -c $< -o $@

# Compile files from wrappers/
$(BUILD_DIR)/%.o: $(WRAPPER_DIR)/%.c
	$(CC) $(INCLUDE_DIR) -c $< -o $@

# Make the library.
$(LIB): $(OBJ_FILES)
	ar -rcs $@ $(OBJ_FILES)

.PHONY: build lib clean
lib: $(LIB)
clean:
	rm $(wildcard $(BUILD_DIR)/*.o)
	rm $(LIB_NAME)
