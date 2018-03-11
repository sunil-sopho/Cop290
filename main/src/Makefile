IDIR=../include
ODIR=../obj

CC=g++
CFLAGS=-I ${IDIR}
LDFLAGS=-lglut -lGLU -lGL
SRC=$(wildcard *.cpp)

DEPS=${IDIR}/*

_OBJ=$(SRC:.cpp=.o)
OBJ=$(patsubst %, ${ODIR}/%,${_OBJ})

${ODIR}/%.o: %.cpp ${DEPS}
	@(${CC} -c -o $@ $< ${CFLAGS})

main: ${OBJ}
	@(${CC} -o $@ $^ ${CFLAGS} ${LDFLAGS})

clean:
	@(rm -f core ${ODIR}/*.o main)