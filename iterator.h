#ifndef ITERATOR_H
#define ITERATOR_H

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

template <typename N, typename M> TIterator<N, M>::TIterator(const N& node) {
  nodePtr = node;
}
    
template <typename N, typename M> std::shared_ptr<M> TIterator<N, M>::operator* () {
  return nodePtr->GetValue();
}

template <typename N, typename M> std::shared_ptr<M> TIterator<N, M>::operator-> () {
  return nodePtr->GetValue();
}
template <typename N, typename M> void TIterator<N, M>::operator ++ () {
  nodePtr = nodePtr->GetNext();
}

template <typename N, typename M> bool TIterator<N, M>::operator == (TIterator const& other) {
  return nodePtr == other.nodePtr;
}

template <typename N, typename M> bool TIterator<N, M>::operator != (TIterator const& other) {
  return !(*this == other);
}

#endif