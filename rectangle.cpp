#include <iostream>
#include "rectangle.h"

TRectangle::TRectangle(){
	SideA = SideB = 0;
}

TRectangle::TRectangle(size_t i, size_t j) : SideA(i), SideB(j) {
std::cout << "Rectangle created: " << SideA << ", " << SideB << std::endl;
}

std::ostream &operator<<(std::ostream &os, const TRectangle &rectangle) {
	os << '(' << rectangle.SideA << ' ' << rectangle.SideB << ')';
	return os;
}

std::istream &operator>>(std::istream &is, TRectangle &rectangle) {
	is >> rectangle.SideA;
	is >> rectangle.SideB;
	return is;
}

void TRectangle::Print() {
std::cout << "a=" << SideA << ", b=" << SideB << ", c=" << SideA << ", d=" << SideB <<
std::endl;
}

TRectangle TRectangle::operator=(const TRectangle &right) {
	if (this == &right) {
		return *this; 
	}
	SideA = right.SideA;
	SideB = right.SideB;
	return *this;
}

bool TRectangle::operator==(const TRectangle &right) {
	return (SideA == right.SideA && SideB == right.SideB);
}