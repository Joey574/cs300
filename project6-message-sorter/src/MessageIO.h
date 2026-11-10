/**
 * @file MessageIO.h
 * @brief Provided helpers for reading and printing Messages (Project 6).
 *
 * Do not change this file. Your Message class must provide the constructor
 * and getters used here.
 */
#ifndef MESSAGE_IO_H_
#define MESSAGE_IO_H_

#include <iosfwd>
#include <string>

#include "ListInterface.h"
#include "Message.h"

/**
 * Converts one line of a message file into a Message.
 *
 * A line has three fields separated by '|':
 *   arrivalTime|sender|subject
 * for example: 1005|bob@example.com|Budget review
 * The arrival time is a non-negative whole number. Neither the sender nor the
 * subject is empty or contains '|'. A trailing '\r' (from a Windows line
 * ending) is ignored.
 *
 * @param[in] line  one line of text, without its '\n'
 * @return the Message described by the line
 * @throw std::invalid_argument if the line is not in this format
 */
Message parseMessage(const std::string& line);

/**
 * Formats a Message as "arrivalTime | sender | subject", with no newline.
 * @param[in] message  the message to format
 * @return the formatted text
 */
std::string formatMessage(const Message& message);

/**
 * Prints the messages in a list, one per line, in list order. A list of 20 or
 * fewer messages is printed in full. A longer list prints its first 5
 * messages, a line containing "...", and its last 5 messages. An empty list
 * prints "(no messages)".
 *
 * @param[in] messages  the list to print
 * @param[out] out      where to print
 */
void printMessages(const ListInterface<Message>& messages, std::ostream& out);

#endif  // MESSAGE_IO_H_
