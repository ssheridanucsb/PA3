CXX = clang++

CXXFLAGS = -std=c++11 

prog3.out: main.o avl.o twofive.o 
	${CXX} ${CXXFLAGS} $^ -o $@

main.o: main.cpp
	${CXX} ${CXXFLAGS} main.cpp -c

avl.o: avl.cpp
	${CXX} ${CXXFLAGS} avl.cpp -c

twofive.o: twofive.cpp
	${CXX} ${CXXFLAGS} twofive.cpp -c

clean: 
	/bin/rm -f prog3.out *.o