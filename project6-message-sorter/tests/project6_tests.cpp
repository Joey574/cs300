/**
 * @file project6_tests.cpp
 * @brief Provided unit tests for Project 6. Run them often; they are the
 *        quickest way to find pointer mistakes in merge() and mergeSort().
 */
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "LinkedList.h"
#include "Message.h"
#include "MessageIO.h"
#include "gtest/gtest.h"

namespace {

// Builds a list holding the given values, in order.
template <typename T>
void fill(LinkedList<T>& list, const std::vector<T>& values) {
  for (std::size_t i = 0; i < values.size(); i++) {
    list.insert(static_cast<int>(i) + 1, values[i]);
  }
}

// Empties a list (removing from the front) and returns its entries in order.
template <typename T>
std::vector<T> drain(LinkedList<T>& list) {
  std::vector<T> values;
  while (!list.isEmpty()) {
    values.push_back(list.getEntry(1));
    list.remove(1);
  }
  return values;
}

// Sorts a vector of ints with LinkedList::mergeSort() and returns the result.
std::vector<int> sortedByList(const std::vector<int>& values) {
  LinkedList<int> list;
  fill(list, values);
  list.mergeSort();
  return drain(list);
}

std::vector<Message> readMessageFile(const std::string& fileName) {
  std::ifstream in(std::string(PROJECT6_DATA_DIR) + "/" + fileName);
  EXPECT_TRUE(in.is_open()) << "cannot open " << fileName;
  std::vector<Message> messages;
  std::string line;
  while (std::getline(in, line)) {
    if (!line.empty()) {
      messages.push_back(parseMessage(line));
    }
  }
  return messages;
}

// Fails unless the two vectors hold the same messages in the same order.
void expectSameMessages(const std::vector<Message>& actual,
                        const std::vector<Message>& expected) {
  ASSERT_EQ(actual.size(), expected.size());
  for (std::size_t i = 0; i < actual.size(); i++) {
    EXPECT_EQ(actual[i].getArrivalTime(), expected[i].getArrivalTime())
        << "at index " << i;
    EXPECT_EQ(actual[i].getSender(), expected[i].getSender())
        << "at index " << i;
    EXPECT_EQ(actual[i].getSubject(), expected[i].getSubject())
        << "at index " << i;
  }
}

void checkFileSortsLikeStableSort(const std::string& fileName) {
  std::vector<Message> original = readMessageFile(fileName);
  ASSERT_FALSE(original.empty());

  // Build the list by inserting at the front, last message first.
  LinkedList<Message> list;
  for (std::size_t i = original.size(); i > 0; i--) {
    list.insert(1, original[i - 1]);
  }
  list.mergeSort();
  std::vector<Message> actual = drain(list);

  std::vector<Message> expected = original;
  std::stable_sort(expected.begin(), expected.end());
  expectSameMessages(actual, expected);
}

}  // namespace

// ----------------------------------------------------------- copying

TEST(LinkedListCopyTest, CopyConstructorMakesAnIndependentCopy) {
  LinkedList<int> original;
  fill(original, std::vector<int>({3, 1, 2}));
  LinkedList<int> copy(original);
  EXPECT_EQ(copy.getLength(), 3);

  copy.remove(1);
  copy.setEntry(1, 99);
  original.insert(4, 7);

  EXPECT_EQ(drain(original), std::vector<int>({3, 1, 2, 7}));
  EXPECT_EQ(drain(copy), std::vector<int>({99, 2}));
}

TEST(LinkedListCopyTest, CopyOfEmptyListIsEmpty) {
  LinkedList<int> original;
  LinkedList<int> copy(original);
  EXPECT_TRUE(copy.isEmpty());
  EXPECT_TRUE(copy.insert(1, 5));
  EXPECT_TRUE(original.isEmpty());
}

TEST(LinkedListCopyTest, AssignmentReplacesTheOldEntries) {
  LinkedList<int> source;
  fill(source, std::vector<int>({1, 2, 3}));
  LinkedList<int> target;
  fill(target, std::vector<int>({9, 8, 7, 6, 5}));
  target = source;
  EXPECT_EQ(target.getLength(), 3);
  source.setEntry(1, 100);
  EXPECT_EQ(drain(target), std::vector<int>({1, 2, 3}));
  EXPECT_EQ(drain(source), std::vector<int>({100, 2, 3}));
}

TEST(LinkedListCopyTest, SelfAssignmentChangesNothing) {
  LinkedList<int> list;
  fill(list, std::vector<int>({1, 2, 3}));
  LinkedList<int>& alias = list;
  list = alias;
  EXPECT_EQ(drain(list), std::vector<int>({1, 2, 3}));
}

TEST(LinkedListCopyTest, SortingACopyDoesNotChangeTheOriginal) {
  LinkedList<int> original;
  fill(original, std::vector<int>({3, 1, 2}));
  LinkedList<int> copy(original);
  copy.mergeSort();
  EXPECT_EQ(drain(copy), std::vector<int>({1, 2, 3}));
  EXPECT_EQ(drain(original), std::vector<int>({3, 1, 2}));
}

// ---------------------------------------------------------------- Message

TEST(MessageTest, ConstructorAndGetters) {
  Message message(1005, "bob@example.com", "Budget review");
  EXPECT_EQ(message.getArrivalTime(), 1005);
  EXPECT_EQ(message.getSender(), "bob@example.com");
  EXPECT_EQ(message.getSubject(), "Budget review");
}

TEST(MessageTest, LessThanComparesSubjects) {
  Message a(1, "x@example.com", "Apple");
  Message b(2, "x@example.com", "Banana");
  EXPECT_TRUE(a < b);
  EXPECT_FALSE(b < a);
}

TEST(MessageTest, EqualSubjectsAreNeitherLess) {
  Message a(1, "x@example.com", "Same");
  Message b(2, "y@example.com", "Same");
  EXPECT_FALSE(a < b);
  EXPECT_FALSE(b < a);
}

TEST(MessageTest, LessThanIgnoresArrivalTimeAndSender) {
  Message earlier(1, "a@example.com", "Zebra");
  Message later(99, "z@example.com", "Aardvark");
  EXPECT_FALSE(earlier < later);
  EXPECT_TRUE(later < earlier);
}

TEST(MessageTest, LessThanWorksOnConstMessages) {
  const Message a(1, "x@example.com", "Apple");
  const Message b(2, "x@example.com", "Banana");
  EXPECT_TRUE(a < b);
}

TEST(MessageTest, SubjectComparisonIsCaseSensitive) {
  Message upper(1, "x@example.com", "Zoom");
  Message lower(2, "x@example.com", "apple");
  EXPECT_TRUE(upper < lower);  // 'Z' comes before 'a' in ASCII
}

// ------------------------------------------------------ mergeSort, ints

TEST(MergeSortTest, EmptyList) {
  LinkedList<int> list;
  list.mergeSort();
  EXPECT_TRUE(list.isEmpty());
  EXPECT_EQ(list.getLength(), 0);
}

TEST(MergeSortTest, SingleItem) {
  EXPECT_EQ(sortedByList({7}), std::vector<int>({7}));
}

TEST(MergeSortTest, TwoItemsAlreadyInOrder) {
  EXPECT_EQ(sortedByList({1, 2}), std::vector<int>({1, 2}));
}

TEST(MergeSortTest, TwoItemsOutOfOrder) {
  EXPECT_EQ(sortedByList({2, 1}), std::vector<int>({1, 2}));
}

TEST(MergeSortTest, ThreeItems) {
  EXPECT_EQ(sortedByList({3, 1, 2}), std::vector<int>({1, 2, 3}));
}

TEST(MergeSortTest, OddLength) {
  EXPECT_EQ(sortedByList({5, 3, 7, 1, 6, 2, 4}),
            std::vector<int>({1, 2, 3, 4, 5, 6, 7}));
}

TEST(MergeSortTest, EvenLength) {
  EXPECT_EQ(sortedByList({8, 3, 5, 1, 6, 2, 7, 4}),
            std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8}));
}

TEST(MergeSortTest, AlreadySorted) {
  std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(sortedByList(values), values);
}

TEST(MergeSortTest, ReverseSorted) {
  EXPECT_EQ(sortedByList({10, 9, 8, 7, 6, 5, 4, 3, 2, 1}),
            std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
}

TEST(MergeSortTest, AllEqual) {
  std::vector<int> values(6, 4);
  EXPECT_EQ(sortedByList(values), values);
}

TEST(MergeSortTest, DuplicatesAndNegatives) {
  EXPECT_EQ(sortedByList({3, -1, 3, 0, -1, 2, 3}),
            std::vector<int>({-1, -1, 0, 2, 3, 3, 3}));
}

TEST(MergeSortTest, EveryLengthFromZeroToFifty) {
  for (int n = 0; n <= 50; n++) {
    std::vector<int> values;
    for (int i = 0; i < n; i++) {
      values.push_back((i * 37 + 11) % 23);  // scrambled, with duplicates
    }
    std::vector<int> expected = values;
    std::sort(expected.begin(), expected.end());
    EXPECT_EQ(sortedByList(values), expected) << "length " << n;
  }
}

TEST(MergeSortTest, LengthIsUnchanged) {
  LinkedList<int> list;
  fill(list, std::vector<int>({4, 2, 9, 1, 7}));
  list.mergeSort();
  EXPECT_EQ(list.getLength(), 5);
}

TEST(MergeSortTest, ListIsUsableAfterSorting) {
  LinkedList<int> list;
  fill(list, std::vector<int>({4, 2, 9, 1, 7}));
  list.mergeSort();

  EXPECT_TRUE(list.insert(6, 10));   // the last node must end the chain
  EXPECT_TRUE(list.insert(1, 0));
  EXPECT_EQ(list.getLength(), 7);
  EXPECT_EQ(list.getEntry(7), 10);
  EXPECT_THROW(list.getEntry(8), std::out_of_range);
  EXPECT_TRUE(list.remove(7));
  EXPECT_EQ(drain(list), std::vector<int>({0, 1, 2, 4, 7, 9}));
}

TEST(MergeSortTest, SortingTwiceChangesNothing) {
  LinkedList<int> list;
  fill(list, std::vector<int>({4, 2, 9, 1, 7}));
  list.mergeSort();
  list.mergeSort();
  EXPECT_EQ(drain(list), std::vector<int>({1, 2, 4, 7, 9}));
}

// ----------------------------------------------- mergeSort, Messages

TEST(MergeSortMessageTest, SortsBySubject) {
  LinkedList<Message> list;
  list.insert(1, Message(1, "a@example.com", "Charlie"));
  list.insert(2, Message(2, "b@example.com", "Alpha"));
  list.insert(3, Message(3, "c@example.com", "Bravo"));
  list.mergeSort();
  std::vector<Message> result = drain(list);
  ASSERT_EQ(result.size(), 3u);
  EXPECT_EQ(result[0].getSubject(), "Alpha");
  EXPECT_EQ(result[1].getSubject(), "Bravo");
  EXPECT_EQ(result[2].getSubject(), "Charlie");
}

TEST(MergeSortMessageTest, EqualSubjectsKeepTheirOriginalOrder) {
  // Added in arrival order; the sort must keep arrival order within a subject.
  LinkedList<Message> list;
  list.insert(1, Message(10, "a@example.com", "B"));
  list.insert(2, Message(20, "b@example.com", "A"));
  list.insert(3, Message(30, "c@example.com", "B"));
  list.insert(4, Message(40, "d@example.com", "A"));
  list.insert(5, Message(50, "e@example.com", "B"));
  list.mergeSort();
  std::vector<Message> result = drain(list);
  ASSERT_EQ(result.size(), 5u);
  EXPECT_EQ(result[0].getArrivalTime(), 20);
  EXPECT_EQ(result[1].getArrivalTime(), 40);
  EXPECT_EQ(result[2].getArrivalTime(), 10);
  EXPECT_EQ(result[3].getArrivalTime(), 30);
  EXPECT_EQ(result[4].getArrivalTime(), 50);
}

TEST(MergeSortMessageTest, SmallFileMatchesStableSort) {
  checkFileSortsLikeStableSort("messages_small.txt");
}

TEST(MergeSortMessageTest, LargeFileMatchesStableSort) {
  checkFileSortsLikeStableSort("messages_large.txt");
}
