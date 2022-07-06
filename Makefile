# -*- MakeFile -*-


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
DEPS = shell.h
CSRCS = $(wildcard *.c)
OBJSDIR = ./build/
OBJS = $(CSRCS:.c=.o)
TARGET = hsh
RM = rm -f

${TARGET}: ${OBJS}
	${CC} ${CFLAGS} -o ${TARGET} ${OBJS}


all: ${TARGET}



#
# Debug build settings
#
DBGCFLAGS = -g -O0 -DDEBUG -Wall -Werror -Wextra -pedantic
debug:
	gcc ${DBGCFLAGS} ${FLAGS} -o ${TARGET} ${CSRCS} ${DEPS}

#
#Clean up Object files
#
oclean:
	$(RM) $(OBJ)

#
#Clean up All files
#
clean:
	RM ${TARGET} ${OBJS}

oclean:
	$(RM) $(OBJ)

clean:
	RM ${TARGET} ${OBJS}

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

fclean: oclean clean

oclean:
	$(RM) $(OBJ)

clean:
	$(RM) *~ $(NAME)

re: oclean all   
