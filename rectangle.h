#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"

class TRectangle : public Figure {
public:
	TRectangle();
	TRectangle(size_t i,size_t j);
	friend std::ostream &operator<<(std::ostream &os, const TRectangle &rectangle);
	friend std::istream &operator>>(std::istream &is, TRectangle &rectangle);
	TRectangle operator=(const TRectangle &right);
	bool operator==(const TRectangle &right);
	void Print() override;
	~TRectangle() {};
private:
	size_t SideA;
	size_t SideB;
};

#endif