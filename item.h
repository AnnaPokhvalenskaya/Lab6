#ifndef ITEM_H
#define ITEM_H

#include "Figure.h"
#include <memory>
#include "rectangle.h"
#include "Rhombus.h"
#include "Trapeze.h"
#include "TAllocationBlock.h"
// #include "iterator.h"

template <class T> class TItem {
public:
	TItem(const std::shared_ptr<T> &obj);
	std::shared_ptr<TItem<T> > GetNext();
	std::shared_ptr<TItem<T> > GetPrev();
	std::shared_ptr<T> GetValue();
	void SetNext(std::shared_ptr<TItem<T> > next);
	void SetPrev(std::shared_ptr<TItem<T> > prev);

	void* operator new (size_t size) ;
	void operator delete(void *ptr);
	~TItem() {};
private:
	std::shared_ptr<TItem<T> > Next;
	std::shared_ptr<TItem<T> > Prev;
	std::shared_ptr<T> ptr;

	static TAllocationBlock list_allocator;
};

#endif