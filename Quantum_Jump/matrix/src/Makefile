CXX = g++
CXXFLAGS = -Wall -c -std=c++11
LDFLAGS =
SOURCES=Qmatrix.cpp operators.cpp solvers.cpp main_test.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXE=qJUMP

all:$(SOURCES) $(EXE)

#This i think is a function (kind of) which links all of the OBJECTS which are the object files into the
#executable which is the $@ symbol which is the left hand side of the :

$(EXE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@
#Below is called a suffix rule it is equivalent to %.cpp : %.o which takes all files with the .cpp extension 
#and applies the rule below in this case will produce the line 
#	g++ -Wall -c somthing.cpp -o somthing.o which compiles the .cpp file into a .o file 
.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o Qmatrix
