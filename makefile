CC := gcc
CFLAGS := -lm -I./include

SRC_DIR := src
CORE_DIR := core
WRAPPER_DIR := wrappers
BUILD_DIR := build
TARGET_FILE := bin/main

SRC_FILES := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(CORE_DIR)/*.c) $(wildcard $(WRAPPER_DIR)/*.c)

OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))


$(TARGET_FILE): $(OBJ_FILES)
	$(CC) -o $@ $^ $(CFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@

clean:
	rm $(OBJ_FILES) $(TARGET_FILE)

.PHONY:
	clean

