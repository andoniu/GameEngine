OBJECTS=main.o
EXE=game

CXXFLAGS=-Wall -Wextra -std=c++14 -g

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

clean:
	$(RM) $(OBJECTS) $(EXE)

.PHONY:all clean
