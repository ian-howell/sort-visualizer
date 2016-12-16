CXXHEADERS = $(wildcard *.h)
CXXSOURCES = column.cpp
CXXOBJECTS = $(CXXSOURCES:%.cpp=%.o)

MAINSOURCE = main.cpp
MAINOBJECT = $(MAINSOURCE:%.cpp=%.o)

LINKER = -lncurses

CPP = g++
C_FLAGS = -Wall --pedantic-errors -O2

sort-visualizer: ${CXXHEADERS} ${CXXOBJECTS} ${MAINOBJECT}
	${CPP} ${C_FLAGS} ${CXXOBJECTS} ${MAINOBJECT} ${LINKER} -o sort-visualizer

%.o: %.cpp ${CXXHEADERS}
	${CPP} -c $<

clean:
	-@rm -f *.o
	-@rm -f sort-visualizer
