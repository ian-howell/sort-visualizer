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

tester: ${CXXHEADERS} ${CXXOBJECTS} ${TESTOBJECT}
	${CPP} ${C_FLAGS} ${CXXOBJECTS} ${TESTOBJECT} -o test

%.o: %.cpp ${CXXHEADERS}
	${CPP} -c $<

clean:
	-@rm -f *.o
	-@rm -f tester
	-@rm -f sort-visualizer
