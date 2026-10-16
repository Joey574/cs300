#ifndef CREDIT_CARD_HPP
#define CREDIT_CARD_HPP
#include "transaction.hpp"

#include <vector>

class CreditCardAccount {
    public:
        CreditCardAccount() : head(nullptr) {}

        CreditCardAccount(const CreditCardAccount& other) : head(nullptr) {
            auto first = other.head;
            while (first) {
                appendTransaction(first->getType(), first->getAmount());
                first = first->getNext();
            }
        }

        ~CreditCardAccount() {
            while (head) {
                auto tmp = head->getNext();
                delete head;
                head = tmp;
            }
        }

        CreditCardAccount* operator = (CreditCardAccount& other) {
            while (head) {
                auto tmp = head->getNext();
                delete head;
                head = tmp;
            }

            auto first = other.head;
            while (first) {
                appendTransaction(first->getType(), first->getAmount());
                first = first->getNext();
            }

            return this;
        }

        /// @brief Appends a purchase to the transaction history of the defined amount
        void purchase(double amount);

        /// @brief Appends credit to the transaction history of the defined amount
        void credit(double amount);

        /// @brief Returns the users current balance based on transaction history
        double getBalance() const;

        /// @brief Returns a copy of the transactions as a vector
        std::vector<Transaction> getTransactions() const;

        /// @brief Appends a transaction of specified type and amount
        void appendTransaction(Transaction::Type type, double amount);

        size_t size() const;

    private:
        Transaction* head;

};

#endif
