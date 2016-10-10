CXXHEADERS = $(wildcard *.h)
CXXSOURCES = sorts.cpp helpers.cpp
CXXOBJECTS = $(CXXSOURCES:%.cpp=%.o)

TESTSOURCE = tester.cpp
TESTOBJECT = $(TESTSOURCE:%.cpp=%.o)

MAINSOURCE = main.cpp
MAINOBJECT = $(MAINSOURCE:%.cpp=%.o)

CPP = g++
C_FLAGS = -Wall --pedantic-errors -O2

sort-visualizer: ${CXXHEADERS} ${CXXOBJECTS} ${MAINOBJECT}
	${CPP} ${C_FLAGS} ${CXXOBJECTS} ${MAINOBJECT} -o sort-visualizer

test: ${CXXHEADERS} ${CXXOBJECTS} ${TESTOBJECT}
	${CPP} ${C_FLAGS} ${CXXOBJECTS} ${TESTOBJECT} -o test

%.o: %.cpp ${CXXHEADERS}
	${CPP} -c $<

clean:
	-@rm -f *.o
	-@rm -f test
	-@rm -f sort-visualizer
