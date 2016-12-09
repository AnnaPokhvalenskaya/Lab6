#include "Trapeze.h" 
#include <iostream>

TTrapeze::TTrapeze() : TTrapeze(0, 0, 0, 0) { }

TTrapeze::TTrapeze(size_t i, size_t j, size_t k, size_t l) : SideA(i), SideB(j), SideC(k), SideD(l) {
std::cout << "Trapeze created: " << SideA << ", " << SideB << ", " << SideC << ", " << SideD << std::endl;
}

std::ostream &operator<<(std::ostream &os, const TTrapeze &rectangle) {
    os << '(' << rectangle.SideA << ' ' << rectangle.SideB << ')';
    return os;
}

std::istream &operator>>(std::istream &is, TTrapeze &rectangle) {
    is >> rectangle.SideA;
    is >> rectangle.SideB;
    return is;
}

TTrapeze TTrapeze::operator=(const TTrapeze &right) {
    if (this == &right) {
        return *this; 
    }
    SideA = right.SideA;
    SideB = right.SideB;
    return *this;
}

bool TTrapeze::operator==(const TTrapeze &right) {
    return (SideA == right.SideA && SideB == right.SideB);
}

void TTrapeze::Print() {
std::cout << "a=" << SideA << ", b=" << SideB << ", c=" << SideC << ", d=" << SideD << 
std::endl;
}

TTrapeze::~TTrapeze() {
std::cout << "Trapeze deleted" << std::endl; 
}