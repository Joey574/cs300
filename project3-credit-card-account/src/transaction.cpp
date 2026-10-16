#include "transaction.hpp"

Transaction::Type Transaction::getType() const {
    return this->type;
}

double Transaction::getAmount() const {
    return this->amount;
}

Transaction* Transaction::getNext() const {
    return this->next;
}

void Transaction::setNext(Transaction* node) {
    this->next = node;
}
