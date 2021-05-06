CPP             = g++
RM              = rm -f
MKDIR_P			= mkdir -p
CPP_FLAGS       = -Wall -c -I. -g -std=c++11

LD              = g++
LD_FLAGS        = -Wall -shared -O2
RESULT          = output/pulsar.so

SOURCES	        = $(wildcard src/*.cpp)
OBJECTS         = $(SOURCES:%.cpp=%.o)

DEPENDENCIES	= -lphpcpp -lpulsar

all:	${OBJECTS} ${RESULT}

${RESULT}: ${OBJECTS}
	${MKDIR_P} output
	${LD} ${LD_FLAGS} -o $@ ${OBJECTS} ${DEPENDENCIES}

clean:
	${RM} -r output
	${RM} *.obj *~* ${OBJECTS} ${RESULT}

src/%.o: src/%.cpp
	${CPP} ${CPP_FLAGS} -fpic -c $< -o $@
