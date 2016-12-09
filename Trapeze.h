#ifndef TRAPEZE_H
#define TRAPEZE_H

#include <cstdlib>
#include <iostream> 
#include "Figure.h"

class TTrapeze : public Figure{ 
public:
	TTrapeze(); 
	TTrapeze(size_t i,size_t j,size_t k,size_t l); 
	void Print() override;
	friend std::ostream &operator<<(std::ostream &os, const TTrapeze &rectangle);
	friend std::istream &operator>>(std::istream &is, TTrapeze &rectangle);
	TTrapeze operator=(const TTrapeze &right);
	bool operator==(const TTrapeze &right);
	virtual ~TTrapeze(); 
private:
	size_t SideA; 
	size_t SideB;
	size_t SideC;
	size_t SideD;
};	
#endif 	