series08: exercise1main.o exercise2main.o exercise3main.o exercise4main.o exercise5main.o exercise6.o matrix.o
 g++ exercise1main.o exercise2main.o exercise3main.o exercise4main.o exercise5main.o matrix.o ~o series08
exercise1main.o: exercise1main.cpp
 g++ ~c exercise1main.cpp
exercise2main.o: exercise2main.cpp
 g++ ~c exercise2main.cpp
exercise3main.o: exercise3main.cpp
 g++ ~c exercise3main.cpp
exercise4main.o: exercise4main.cpp
 g++ ~c exercise4main.cpp
exercise5main.o: exercise5main.cpp
 g++ ~c exercise5main.cpp
exercise6.o: exercise6.cpp
 g++ ~c exercise6.cpp
matrix.o: matrix.cpp
 g++ ~c matrix.cpp
clean: 
 rm *.o matrix