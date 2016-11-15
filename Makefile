OBJECTS=main.o
EXE=game

DEPS := $(OBJECTS:.o=.d)


CXXFLAGS=-Wall -Wextra -std=c++17 -g -MD

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

clean:
	$(RM) $(OBJECTS) $(EXE)

-include $(DEPS)
.PHONY:all clean
