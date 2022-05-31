.PHONY: all, debug, clean

#
# Compiler flags
#
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

#
# Linker flags
#
LDFLAGS = -lm
DEPS = hsh.h
CSRCS = $(wildcard *.c)
OBJSDIR = ./build/
OBJS = $(CSRCS:.c=.o)
TARGET = hsh


${TARGET}: ${OBJS}
	${CC} ${CFLAGS} -o ${TARGET} ${OBJS}


all: ${TARGET}



#
# Debug build settings
#
DBGCFLAGS = -g -O0 -DDEBUG
debug:
	gcc ${DBGCFLAGS} ${FLAGS} -o ${TARGET} ${CSRCS} ${DEPS}

clean:
	rm -f ${TARGET} ${OBJS}
