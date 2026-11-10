/**
 * @file LinkedList.cpp
 * @brief Implementation of the LinkedList class template.
 *
 * Do not add this file to a CMake target: LinkedList.h includes it, because
 * the compiler must see template implementations wherever they are used.
 */
#include <stdexcept>
#include <utility>

#include "LinkedList.h"

template <typename ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0) {}

template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& other)
    : headPtr(nullptr), itemCount(0) {
  try {
    Node<ItemType>* origPtr = other.headPtr;
    Node<ItemType>* tailPtr = nullptr;
    while (origPtr != nullptr) {
      Node<ItemType>* newPtr = new Node<ItemType>(origPtr->getItem());
      if (tailPtr == nullptr) {
        headPtr = newPtr;
      } else {
        tailPtr->setNext(newPtr);
      }
      tailPtr = newPtr;
      itemCount++;
      origPtr = origPtr->getNext();
    }
  } catch (...) {
    clear();  // do not leak the nodes copied so far
    throw;
  }
}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList() {
  clear();
}

template <typename ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(
    const LinkedList<ItemType>& other) {
  if (this != &other) {
    LinkedList<ItemType> copy(other);  // may throw; this list is still intact
    std::swap(headPtr, copy.headPtr);
    std::swap(itemCount, copy.itemCount);
  }
  return *this;  // copy's destructor frees our old nodes
}

template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const {
  return itemCount == 0;
}

template <typename ItemType>
int LinkedList<ItemType>::getLength() const {
  return itemCount;
}

template <typename ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
  bool canInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
  if (!canInsert) {
    return false;
  }
  Node<ItemType>* newPtr = new Node<ItemType>(newEntry);
  if (newPosition == 1) {
    newPtr->setNext(headPtr);
    headPtr = newPtr;
  } else {
    Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
    newPtr->setNext(prevPtr->getNext());
    prevPtr->setNext(newPtr);
  }
  itemCount++;
  return true;
}

template <typename ItemType>
bool LinkedList<ItemType>::remove(int position) {
  bool canRemove = (position >= 1) && (position <= itemCount);
  if (!canRemove) {
    return false;
  }
  Node<ItemType>* nodePtr = nullptr;
  if (position == 1) {
    nodePtr = headPtr;
    headPtr = headPtr->getNext();
  } else {
    Node<ItemType>* prevPtr = getNodeAt(position - 1);
    nodePtr = prevPtr->getNext();
    prevPtr->setNext(nodePtr->getNext());
  }
  nodePtr->setNext(nullptr);
  delete nodePtr;
  nodePtr = nullptr;
  itemCount--;
  return true;
}

template <typename ItemType>
void LinkedList<ItemType>::clear() {
  while (!isEmpty()) {
    remove(1);
  }
}

template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
  if (position < 1 || position > itemCount) {
    throw std::out_of_range("LinkedList::getEntry(): invalid position");
  }
  return getNodeAt(position)->getItem();
}

template <typename ItemType>
bool LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) {
  bool canSet = (position >= 1) && (position <= itemCount);
  if (canSet) {
    getNodeAt(position)->setItem(newEntry);
  }
  return canSet;
}

template <typename ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const {
  Node<ItemType>* curPtr = headPtr;
  for (int skip = 1; skip < position; skip++) {
    curPtr = curPtr->getNext();
  }
  return curPtr;
}

// ---------------------------------------------------------------------------
// Merge sort (Project 6): your work goes below.
//
// The stubs compile but do not sort. Replace each body, deleting the TODO
// comments and the "(void)" lines as you go. Document your reasoning in
// comments, and keep each function focused on its own job.
// ---------------------------------------------------------------------------

// Private helper
template <typename ItemType>
Node<ItemType>* LinkedList<ItemType>::merge(Node<ItemType>* leftPtr,
                                            Node<ItemType>* rightPtr) {
  // TODO: merge the two sorted chains by relinking their nodes (see the
  // contract in LinkedList.h). Remember that ItemType supports only operator<.
  (void)rightPtr;
  return leftPtr;
}

// Private helper
template <typename ItemType>
Node<ItemType>* LinkedList<ItemType>::mergeSort(Node<ItemType>* listPtr,
                                                int size) {
  // TODO: base case; split the chain in two (and detach the halves); sort
  // each half; merge the sorted halves. Return the head of the result.
  (void)size;
  return listPtr;
}

template <typename ItemType>
void LinkedList<ItemType>::mergeSort() {
  // TODO: sort the chain that starts at headPtr, and update headPtr.
}
