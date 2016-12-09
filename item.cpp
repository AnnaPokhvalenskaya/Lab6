#include "item.h"

template <class T> TItem<T>::TItem(const std::shared_ptr<T> &obj) {
	Next = Prev = nullptr;
	ptr = obj;
}

template <class T> TAllocationBlock TItem<T>::list_allocator(sizeof(TItem<T>), 100);

template <class T> std::shared_ptr<TItem<T> > TItem<T>::GetNext() {
	return Next;
}

template <class T> std::shared_ptr<TItem<T> > TItem<T>::GetPrev() {
	return Prev;
}

template <class T> std::shared_ptr<T> TItem<T>::GetValue() {
	return ptr;
}

template <class T> void TItem<T>::SetNext(std::shared_ptr<TItem<T> > next) {
	Next = next;
}

template <class T> void TItem<T>::SetPrev(std::shared_ptr<TItem<T> > prev) {
	Prev = prev;
}

template <class T> 
void* TItem<T>::operator new (size_t size) {
	return list_allocator.allocate();
}
template <class T> 
void TItem<T>::operator delete(void *ptr) {
	list_allocator.deallocate(ptr);
}

#include "Figure.h"
template class TItem<Figure>;
// template std::ostream& operator<<(std::ostream& os, const TItem<Figure>&
// list);