#include "creditCard.hpp"
#include "transaction.hpp"
#include <vector>

void CreditCardAccount::purchase(double amount) {
    appendTransaction(Transaction::Type::Purchase, amount);
}

void CreditCardAccount::credit(double amount) {
    appendTransaction(Transaction::Type::Credit, amount);
}

void CreditCardAccount::appendTransaction(Transaction::Type type, double amount) {
    auto node = new Transaction(type, amount);
    if (head == nullptr) {
        head = node;
        return;
    }

    auto first = head;
    while (first->getNext()) {
        first = first->getNext();
    }

    first->setNext(node);
}

double CreditCardAccount::getBalance() const {
    if (head == nullptr) return 0.0;
    double amount = 0.0;

    auto first = head;
    while (first != nullptr) {
        switch (first->getType()) {
            case Transaction::Type::Purchase:
                amount -= first->getAmount();
                break;
            case Transaction::Type::Credit:
                amount += first->getAmount();
                break;
        }
        first = first->getNext();
    }

    return amount;
}

std::vector<Transaction> CreditCardAccount::getTransactions() const {
    std::vector<Transaction> transactions;

    auto first = head;
    while (first) {
        transactions.push_back(*first);
        first = first->getNext();
    }

    return transactions;
}
