IDIR =../include 
CXX=g++
CC=gcc
CXXFLAGS= -I$(IDIR) -I../kiss_sdl

ODIR=obj
LDIR=-L../lib

LIBS=-lm -lSDL2 -lGLU -lGL -lSOIL -lglut -lSDL2_ttf -lSDL2_image


_DEPS= clicks.h buttons.h construct.h cube.h draw.h keys.h \
Ltexture.h messNet.h node.h point.h printtxt.h project.h standardHandler.h window.h cad.h kiss_sdl.h
	
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = cad.o kiss_widgets.o kiss_draw.o kiss_general.o kiss_posix.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp 
	$(CXX) -c -o $@ $< $(CXXFLAGS)
$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CXXFLAGS)

cadmake: $(OBJ)
	g++ -o $@ $^ $(CXXFLAGS) $(LIBS) 


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
