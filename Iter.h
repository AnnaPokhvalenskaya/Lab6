#ifndef LIST_H
#define LIST_H
#include <memory>
#include <iostream>

template <typename N, typename M>
    class TIterator {
  private:
    N nodePtr;
  public:
    TIterator(const N&);
    std::shared_ptr<M> operator* ();
    std::shared_ptr<M> operator-> ();
    void operator ++ ();
    bool operator == (const TIterator&);
    bool operator != (const TIterator&);
  };

#include "Iterator.h"
#endif