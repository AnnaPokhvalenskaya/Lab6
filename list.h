#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Figure.h"
#include "item.h"
#include "rectangle.h"
#include "Rhombus.h"
#include "Trapeze.h"
#include "iterator.h"

#include "TAllocationBlock.h"

template<class T> class TList {
public:
	TList(); 
	void Push(std::shared_ptr<T> &temp); 
	std::shared_ptr<T> Pop();  
	template <class A> friend std::ostream &operator<<(std::ostream &os, const TList<A> &list); 
	~TList() {}; 
  	
 //  	void * operator new (size_t size);
	// void operator delete(void *p);
	
	TIterator<std::shared_ptr<TItem<T> >, T> begin() {
		return TIterator<std::shared_ptr<TItem<T> >, T>(Tail);
	};
  	TIterator<std::shared_ptr<TItem<T> >, T> end() {
  			return TIterator<std::shared_ptr<TItem<T> >, T>(nullptr);
  	};


private:
	void PushFront(std::shared_ptr<T> &temp); 
	void PushBack(std::shared_ptr<T> &temp); 
	void PushAtIndex(std::shared_ptr<T> &temp, const int &id); 
	std::shared_ptr<T> PopFront();
	std::shared_ptr<T> PopBack();
	std::shared_ptr<T> PopAtIndex(const int &id);

	int ListSize;
	std::shared_ptr<TItem<T> > Tail;

	static TAllocationBlock list_allocator;
};

#endif