IDIR =../include
CXX=g++
CXXFLAGS= -I../include

ODIR=obj
LDIR=-L../lib

LIBS=-lm -lSDL2 -lGLU -lGL -lSOIL -lglut -lSDL2_ttf -lSDL2_image


_OBJ = cad.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

cad: $(OBJ)
	g++ -o $@ $^ $(CXXFLAGS) $(LIBS) 


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
