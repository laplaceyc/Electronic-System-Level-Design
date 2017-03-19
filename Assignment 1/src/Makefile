SYSTEMC_DIR = /users/course/2017S/cs613500/vlsipda14/ESL/systemc-2.3.1a
PROJECT     = SimpleExample
BUILDFLAGS  = -g3
CXX         = g++ -std=c++11

INCFLAGS    = -I${SYSTEMC_DIR}/include
LDFLAGS     = -L${SYSTEMC_DIR}/lib-linux64/ -lsystemc -lm 
SRC_CPPHEAD = display noisybus packet slave1 timer master memory
SRC_CPP     = $(SRC_CPPHEAD:=.cpp}
MAIN        = main.cpp
OBJECTS     = $(SRC_CPPHEAD:=.o)
HEADERS		= $(SRC_CPPHEAD:=.h)

EXE = $(PROJECT)

all: $(EXE)

$(EXE): $(MAIN) $(OBJECTS)  $(HEADERS)
	@echo "$@ building..."
	$(CXX) $(INCFLAGS) $(MAIN) $(OBJECTS) $(LDFLAGS) -o $@
	@echo ""
	@echo "$@ build done successfully..."
	@echo ""

%.o:%.cpp %.h
	@echo "Compiling $< ..."
	$(CXX) -c $< $(INCFLAGS)

clean:
	rm -f $(EXE) \
	rm -f *.o


