6lab: main.o list.o rectangle.o Trapeze.o Rhombus.o item.o TAllocationBlock.o
	g++ -std=c++11 -o 6lab main.o list.o Trapeze.o Rhombus.o rectangle.o item.o TAllocationBlock.o
main.o: main.cpp rectangle.h list.h
	g++ -std=c++11 -c main.cpp
list.o: list.cpp rectangle.h list.h item.h
	g++ -std=c++11 -c list.cpp
rectangle.o: rectangle.cpp rectangle.h Figure.h
	g++ -std=c++11 -c rectangle.cpp
Rhombus.o: Rhombus.h Rhombus.cpp Figure.h
	g++ -std=c++11 -c Rhombus.cpp
Trapeze.o: Trapeze.h Trapeze.cpp Figure.h
	g++ -std=c++11 -c Trapeze.cpp
item.o: item.cpp item.h
	g++ -std=c++11 -c item.cpp
TAllocationBlock.o: TAllocationBlock.h TAllocationBlock.cpp
	g++ -std=c++11 -c TAllocationBlock.cpp
clear:
	rm -rf *.o 6lab