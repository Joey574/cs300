/**
 * @file MessageIO.cpp
 * @brief Implementation of the provided Message helpers (Project 6).
 */
#include "MessageIO.h"

#include <cstddef>
#include <ostream>
#include <stdexcept>
#include <string>

namespace {

const int MAX_SHOWN_IN_FULL = 20;
const int NUM_SHOWN_AT_EACH_END = 5;

void printOne(const ListInterface<Message>& messages, int position,
              std::ostream& out) {
  out << formatMessage(messages.getEntry(position)) << "\n";
}

}  // namespace

Message parseMessage(const std::string& line) {
  std::string text = line;
  if (!text.empty() && text[text.size() - 1] == '\r') {
    text.erase(text.size() - 1);
  }
  const std::string problem = "malformed message line: \"" + text + "\"";

  std::size_t firstBar = text.find('|');
  if (firstBar == std::string::npos) {
    throw std::invalid_argument(problem);
  }
  std::size_t secondBar = text.find('|', firstBar + 1);
  if (secondBar == std::string::npos) {
    throw std::invalid_argument(problem);
  }
  if (text.find('|', secondBar + 1) != std::string::npos) {
    throw std::invalid_argument(problem);
  }

  std::string timeText = text.substr(0, firstBar);
  std::string sender = text.substr(firstBar + 1, secondBar - firstBar - 1);
  std::string subject = text.substr(secondBar + 1);

  bool timeIsValid = !timeText.empty() && timeText.size() <= 18;
  for (std::size_t i = 0; i < timeText.size(); i++) {
    if (timeText[i] < '0' || timeText[i] > '9') {
      timeIsValid = false;
    }
  }
  if (!timeIsValid || sender.empty() || subject.empty()) {
    throw std::invalid_argument(problem);
  }
  return Message(std::stol(timeText), sender, subject);
}

std::string formatMessage(const Message& message) {
  return std::to_string(message.getArrivalTime()) + " | " +
         message.getSender() + " | " + message.getSubject();
}

void printMessages(const ListInterface<Message>& messages, std::ostream& out) {
  int length = messages.getLength();
  if (length == 0) {
    out << "(no messages)\n";
  } else if (length <= MAX_SHOWN_IN_FULL) {
    for (int position = 1; position <= length; position++) {
      printOne(messages, position, out);
    }
  } else {
    for (int position = 1; position <= NUM_SHOWN_AT_EACH_END; position++) {
      printOne(messages, position, out);
    }
    out << "...\n";
    for (int position = length - NUM_SHOWN_AT_EACH_END + 1; position <= length;
         position++) {
      printOne(messages, position, out);
    }
  }
}
