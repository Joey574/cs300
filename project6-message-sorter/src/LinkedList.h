/**
 * @file LinkedList.h
 * @brief Link-based implementation of the List ADT, as designed in Lecture 10,
 *        extended with a merge sort for Project 6.
 */
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "ListInterface.h"
#include "Node.h"

template <typename ItemType>
class LinkedList : public ListInterface<ItemType> {
 public:
  LinkedList();
  /** Makes a deep copy: the new list has its own nodes. */
  LinkedList(const LinkedList<ItemType>& other);
  ~LinkedList() override;
  /** Replaces this list's entries with a deep copy of other's entries. */
  LinkedList<ItemType>& operator=(const LinkedList<ItemType>& other);

  bool isEmpty() const override;
  int getLength() const override;
  bool insert(int newPosition, const ItemType& newEntry) override;
  bool remove(int position) override;
  void clear() override;
  ItemType getEntry(int position) const override;
  bool setEntry(int position, const ItemType& newEntry) override;

  /**
   * Sorts this list into ascending order using a merge sort.
   *
   * ItemType must support operator< (and nothing else is assumed about
   * comparisons). The sort is stable: entries that are equivalent keep their
   * original relative order. It relinks the existing nodes; it does not
   * create, copy, or delete any nodes.
   *
   * @post The entries are in ascending order and getLength() is unchanged.
   *       Time O(n log n) for n entries.
   */
  void mergeSort();

 private:
  Node<ItemType>* headPtr;
  int itemCount;

  /** @pre 1 <= position <= itemCount. @return the node at position. */
  Node<ItemType>* getNodeAt(int position) const;

  /**
   * Merges two sorted chains into one sorted chain by relinking their nodes.
   *
   * @param[in] leftPtr   head of a sorted chain ending in nullptr, or nullptr
   * @param[in] rightPtr  head of a sorted chain ending in nullptr, or nullptr
   * @return head of the merged chain, which ends in nullptr (nullptr if both
   *         chains are empty). When an entry in the left chain is equivalent
   *         to an entry in the right chain, the left one comes first.
   */
  static Node<ItemType>* merge(Node<ItemType>* leftPtr,
                               Node<ItemType>* rightPtr);

  /**
   * Sorts a chain by merge sort: splits it in two, sorts each half
   * recursively, and merges the sorted halves.
   *
   * @param[in] listPtr  head of a chain of exactly size nodes ending in
   *                     nullptr, or nullptr if size is 0
   * @param[in] size     the number of nodes in the chain
   * @return head of the sorted chain, which ends in nullptr
   */
  static Node<ItemType>* mergeSort(Node<ItemType>* listPtr, int size);
};

// Template implementations are in LinkedList.cpp, which this header includes.
#include "LinkedList.cpp"

#endif  // LINKED_LIST_H_
