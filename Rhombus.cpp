#include "Rhombus.h" 
#include <iostream>

TRhombus::TRhombus() : TRhombus(0, 0) { }

TRhombus::TRhombus(size_t i, size_t j) : SideA(i), SideB(j) {
std::cout << "Rhombus created: " << SideA << ", " << SideB << std::endl;
}

std::ostream &operator<<(std::ostream &os, const TRhombus &rectangle) {
    os << '(' << rectangle.SideA << ' ' << rectangle.SideB << ')';
    return os;
}

std::istream &operator>>(std::istream &is, TRhombus &rectangle) {
    is >> rectangle.SideA;
    is >> rectangle.SideB;
    return is;
}

void TRhombus::Print() {
std::cout << "d1=" << SideA << ", d2=" << SideB << /*", c=" << SideA << ", d=" << SideB << */
std::endl;
}

TRhombus TRhombus::operator=(const TRhombus &right) {
    if (this == &right) {
        return *this; 
    }
    SideA = right.SideA;
    SideB = right.SideB;
    return *this;
}

bool TRhombus::operator==(const TRhombus &right) {
    return (SideA == right.SideA && SideB == right.SideB);
}

TRhombus::~TRhombus() {
std::cout << "Rhombus deleted" << std::endl; 
}