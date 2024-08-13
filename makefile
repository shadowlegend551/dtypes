CC := gcc
CFLAGS := -lm

INCLUDE_DIR := -I./include
SRC_DIR := src
CORE_DIR := core
WRAPPER_DIR := wrappers
BUILD_DIR := build
TARGET_FILE := bin/main

SRC_FILES := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(CORE_DIR)/*.c) $(wildcard $(WRAPPER_DIR)/*.c)

OBJ_FILES := $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRC_FILES)))

$(TARGET_FILE): $(OBJ_FILES)
	$(CC) $(INCLUDE_DIR) -o $@ $^ $(CFLAGS)

# Compile files from src/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(INCLUDE_DIR) -c $< -o $@

# Compile files from core/
$(BUILD_DIR)/%.o: $(CORE_DIR)/%.c
	$(CC) $(INCLUDE_DIR) -c $< -o $@

# Compile files from wrappers/
$(BUILD_DIR)/%.o: $(WRAPPER_DIR)/%.c
	$(CC) $(INCLUDE_DIR) -c $< -o $@
f:
	$(info $(OBJ_FILES))

.PHONY: clean
clean:
	rm $(wildcard $(BUILD_DIR)/*.o)
