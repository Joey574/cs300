/**
 * @file Node.h
 * @brief A node in a linked chain, as designed in Lecture 4.
 */
#ifndef NODE_H_
#define NODE_H_

template <class ItemType>
class Node {
 public:
  Node();
  explicit Node(const ItemType& anItem);
  Node(const ItemType& anItem, Node<ItemType>* nextNode);

  void setItem(const ItemType& anItem);
  void setNext(Node<ItemType>* nextNode);
  ItemType getItem() const;
  Node<ItemType>* getNext() const;

 private:
  ItemType item;
  Node<ItemType>* next;
};

// Template implementations are in Node.cpp, which this header includes.
#include "Node.cpp"

#endif  // NODE_H_
