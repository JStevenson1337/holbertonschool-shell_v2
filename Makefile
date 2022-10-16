.PHONY: all, debug, clean
VPATH = src
#
# Compiler flags
#
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

#
# Linker flags
#
<<<<<<< HEAD
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS=$(OBJS:%.o=%.d)
CFLAGS=-I. -I./src -g3 -O0 -Wall -Werror -Wextra -pedantic
RM=rm -f
=======
OBJS = $(patsubst %.c, %.o, $(wildcard src/*.c))
HEADERS = $(wildcard src/*.h)

DEPS=$(OBJS:%.o=%.d)


>>>>>>> b8270ff (save before fork)

SRC_DIR=src/
OBJS_DIR=lib/

<<<<<<< HEAD
=======
#patsubst $(patsubst pattern, replacement, text) find whitespace-seperated words in
#text that match pattern and replacec them with replacement
>>>>>>> b8270ff (save before fork)
OBJS = $(patsubst %.c, $(OBJS_DIR)/%$(ARCH)$(DEBUG).o, $(notdir $(wildcard $(SRC_DIR)/*.c)))

all: $(TARGET)
		@echo "Build complete!"

$(TARGET): $(OBJS)
	$(CC)  $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

-include $(DEPS)

$(OBJS_DIR)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

.PHONY : clean
clean:
	$(RM) $(OBJS) $(DEPS) $(TARGET)

# Language: makefile
