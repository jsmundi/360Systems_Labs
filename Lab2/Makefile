# Makefile 
#
# Author: JT  Mundi
#
# Compile: make
# Run    : make run
# Clean  : make clean
# 

CPP = gcc
FLAGS = -Wall -std=c99 -pedantic 

EXEC = person
OBJS = person.o 

default:${EXEC}

clean:
	rm -f ${EXEC}
	rm -f *.o

run: ${EXEC}
	./${EXEC}

${EXEC}:${OBJS}
	${CPP} ${FLAGS} -o ${EXEC} ${OBJS}

val: 
	valgrind --leak-check=yes {EXEC}

.c.o:
	${CPP} ${FLAGS} -c $<

main.o: person.c person.h linkedList.h
