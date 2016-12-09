#ifndef RHOMBUS_H
#define RHOMBUS_H
#include <cstdlib>
#include <iostream> 
#include "Figure.h"

class TRhombus : public Figure{ 
public:
	TRhombus(); 
	TRhombus(size_t i,size_t j);
    friend std::ostream &operator<<(std::ostream &os, const TRhombus &rectangle);
    friend std::istream &operator>>(std::istream &is, TRhombus &rectangle);
    TRhombus operator=(const TRhombus &right);
    bool operator==(const TRhombus &right);
	void Print() override;
	virtual ~TRhombus(); 
private:
	size_t SideA; 
	size_t SideB;
};	
#endif 	