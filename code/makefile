IDIR =../include
CC=gcc
C_FLAGS=-I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS=-lm -lSDL -lGLUT -lGLU -lGL

_DEPS= clicks.h buttons.h construct.h cube.h draw.h keys.h Ltexture.h messNet.h node.h point.h printtxt.h project.h standardHandler.h window.h

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))


$(PROGNAME): $(O_FILES)
        rm -f $(PROGNAME)
        $(CC) $(L_FLAGS) -o $(PROGNAME) $(O_FILES) $(L_POSTFLAGS)
_OBJ = cad.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cadmake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
