IDIR =include 
CXX=g++ 
CC=gcc
CXXFLAGS= -I$(IDIR) -I./lib -I./kiss_sdl -std=c++11 -w

SRCDIR=src
ODIR=build
TARGET=bin/cadmake
LDIR=-L../lib

LIBS=-lm -lSDL2 -lGLU -lGL -lSOIL -lglut -lSDL2_ttf -lSDL2_image


_DEPS= clicks.h buttons.h construct.h cube.h draw.h keys.h \
Ltexture.h messNet.h node.h point.h printtxt.h project.h standardHandler.h window.h cad.h kiss_sdl.h
	
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = kiss_widgets.o kiss_draw.o kiss_general.o kiss_posix.o construct.o \
	 messNet.o window.o clicks.o standardHandler.o project.o draw.o cube.o keys.o cad.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.cpp 
	@mkdir -p $(ODIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
$(ODIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ)
	@echo "\n\n\n Linking ...." 
	g++ -o $@ $^ $(CXXFLAGS) $(LIBS) 


.PHONY: clean

clean:
	@echo " Cleaning ....";
	rm -rf $(ODIR) bin/cadmake
