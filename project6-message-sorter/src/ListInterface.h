/**
 * @file ListInterface.h
 * @brief Interface for the List ADT, as specified in Lecture 10.
 */
#ifndef LIST_INTERFACE_H_
#define LIST_INTERFACE_H_

template <typename ItemType>
class ListInterface {
 public:
  virtual ~ListInterface() = default;

  /** @return true if this list has no entries, or false if not. */
  virtual bool isEmpty() const = 0;

  /** @return the number of entries currently in this list. */
  virtual int getLength() const = 0;

  /**
   * Inserts an entry into this list at a given position.
   * @param[in] newPosition  position for the new entry (1 to getLength() + 1)
   * @param[in] newEntry     the entry to insert
   * @return true if the insertion succeeded, or false if the position is
   *         invalid (the list is unchanged)
   */
  virtual bool insert(int newPosition, const ItemType& newEntry) = 0;

  /**
   * Removes the entry at a given position from this list.
   * @param[in] position  position of the entry to remove (1 to getLength())
   * @return true if the removal succeeded, or false if the position is
   *         invalid (the list is unchanged)
   */
  virtual bool remove(int position) = 0;

  /** Removes all entries from this list. */
  virtual void clear() = 0;

  /**
   * Gets the entry at a given position in this list.
   * @param[in] position  position of the entry (1 to getLength())
   * @return the entry at that position
   * @throw std::out_of_range if position is invalid
   */
  virtual ItemType getEntry(int position) const = 0;

  /**
   * Replaces the entry at a given position in this list.
   * @param[in] position  position of the entry to replace (1 to getLength())
   * @param[in] newEntry  the replacement entry
   * @return true if the replacement succeeded, or false if the position is
   *         invalid (the list is unchanged)
   */
  virtual bool setEntry(int position, const ItemType& newEntry) = 0;
};

#endif  // LIST_INTERFACE_H_
