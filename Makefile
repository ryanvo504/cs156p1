FLAGS = -Wall -Werror
CPP = g++
 

builddepend.o: builddepend.cpp
    # to make shapes.o using shapes.cpp, we only need one call
    # to the compiler
    $(CPP) $(FLAGS) -c builddepend.cpp
    # this expands to: g++ -Wall -Werror -c shapes.cpp
 
# to make our final testShapes program, we need shapes.o, tdd.o, and 
# testShapes.o as dependencies
testDepend: builddepend.o
    $(CPP) $(FLAGS) $^ -o $@
    # the above line expands to:
