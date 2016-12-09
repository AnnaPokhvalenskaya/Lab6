#include <iostream>
#include "list.h"
#include "item.h"

template <class T> TList<T>::TList() {
	ListSize = 0;
	Tail = nullptr;
}


template <class T> void TList<T>::Push(std::shared_ptr<T> &tmp) {
	int index;
	std::cout << "Enter index = ";
	std::cin >> index;
	if (index > ListSize || index < 0) {
		std::cout << "This index doesn't exist\n";
		return;
	}
	if (index == 0) {
		PushBack(tmp);
	} else if (index == ListSize) {
		PushFront(tmp);
	} else {
		PushAtIndex(tmp, index);
	}
	ListSize++;
}

template <class T> void TList<T>::PushFront(std::shared_ptr<T> &tmp) {
	std::shared_ptr<TItem<T> > iter = Tail;
	std::shared_ptr<TItem<T> > temp = std::make_shared<TItem<T> >(tmp);
	while (iter->GetNext()) {
		iter = iter->GetNext();
	}
	temp->SetPrev(iter);
	iter->SetNext(temp);
}

template <class T> void TList<T>::PushBack(std::shared_ptr<T> &tmp) {
	std::shared_ptr<TItem<T> > temp = std::make_shared<TItem<T> >(tmp);
	temp->SetNext(Tail);
	Tail = temp;
}

template <class T> void TList<T>::PushAtIndex(std::shared_ptr<T> &tmp, const int &id) {
	size_t i = 1;
	std::shared_ptr<TItem<T> > iter = Tail;
	std::shared_ptr<TItem<T> > temp = std::make_shared<TItem<T> >(tmp);
	while (i < id) {
		iter = iter->GetNext();
		i++;
	}
	temp->SetNext(iter->GetNext());
	temp->SetPrev(iter);
	iter->SetNext(temp);
	iter->GetNext()->SetPrev(temp);
}


template <class T> std::shared_ptr<T> TList<T>::Pop() {
	int index;
	std::cout << "Enter index = ";
	std::cin >> index;
	std::shared_ptr<T> result;
	if (index > ListSize || index < 0 || !ListSize) {
		std::cout << "This index doesn't exist, nothing to pop\n";
		return result;
	} 
	if (index == 0) {
		result = PopBack();
	}else if (index == ListSize - 1) {
		result = PopFront();
	} else {
		result = PopAtIndex(index);
	}
	ListSize--;
	return result;
}

template <class T> std::shared_ptr<T> TList<T>::PopFront() {
	std::shared_ptr<TItem<T> > iter = Tail;
	while (iter->GetNext()) {
		iter = iter->GetNext();
	}
	std::shared_ptr<T> result = iter->GetValue();
	iter->GetPrev()->SetNext(nullptr);
	return result;
}

template <class T> std::shared_ptr<T> TList<T>::PopBack() {
	std::shared_ptr<TItem<T>> iter = Tail;
	std::shared_ptr<T> result = iter->GetValue();
	Tail = Tail->GetNext();
	return result;
}

template <class T> std::shared_ptr<T> TList<T>::PopAtIndex(const int &id) {
	size_t i = 0;
	std::shared_ptr<TItem<T> > iter = Tail;
	while (i < id) {
		iter = iter->GetNext();
		i++;
	}
	std::shared_ptr<Figure> result = iter->GetValue();
	iter->GetNext()->SetPrev(iter->GetPrev());
	iter->GetPrev()->SetNext(iter->GetNext());
	return result;
}

template <class T> std::ostream &operator<<(std::ostream &os, const TList<T> &list) {
	if (list.ListSize) {
		std::shared_ptr<TItem<T> > iter = list.Tail;
		while (iter) {
			iter->GetValue()->Print();
			iter = iter->GetNext(); 
		}
	} else {
		os << "List is empty";
	}
	return os;
}

// template <class T> void * TList<T>::operator new (size_t size) {
// 	return list_allocator.allocate();
// }

// template <class T> void TList<T>::operator delete(void *p) {
// 	list_allocator.deallocate(p);
// }

#include "Figure.h"
template class TList<Figure>;
template std::ostream& operator<<(std::ostream& os, const TList<Figure>&
list);
