SYSTEMC_DIR = /users/course/2017S/cs613500/vlsipda14/ESL/systemc-2.3.1a
PROJECT     = Project1
BUILDFLAGS  = -g3
CXX         = g++ -std=c++11

INCFLAGS    = -I${SYSTEMC_DIR}/include
LDFLAGS     = -L${SYSTEMC_DIR}/lib-linux64/ -lsystemc -lm 
SRC_CPPHEAD = half_adder half_monitor full_adder full_monitor
MAIN        = main.cpp
HEADERS		= $(SRC_CPPHEAD:=.h)
EXE = $(PROJECT)
all: $(EXE)
$(EXE): $(MAIN) $(HEADERS)
	@echo "$@ building..."
	$(CXX) $(INCFLAGS) $(MAIN) $(LDFLAGS) -o $@
	@echo ""
	@echo "$@ build done successfully..."
	@echo ""

clean:
	rm -f $(EXE) \
	rm -f *.o