IDIR = ./include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=./obj

LIBS= -lm -lGL -lGLU -lglut
	
_DEPS = Point.h Model_3d.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Model_3d.o Point.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Model_3d:
	g++ -o $@ $../src/Model_3d.cpp $(CFLAGS) $(LIBS)

main: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LIBS)
