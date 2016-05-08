OBJECTS=main.o
EXE=game

DEPS := $(OBJECTS:.o=.d)
-include $(DEPS)

CXXFLAGS=-Wall -Wextra -std=c++14 -g -MD

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

clean:
	$(RM) $(OBJECTS) $(EXE)

.PHONY:all clean
