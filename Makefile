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
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS=$(OBJS:%.o=%.d)
CFLAGS=-I. -I./src -g3 -O0 -Wall -Werror -Wextra -pedantic
RM=rm -f

SRC_DIR=src/
OBJS_DIR=lib/

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
