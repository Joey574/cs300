#include "creditCard.hpp"
#include "transaction.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
    CreditCardAccount card;

    while(1) {
        std::cout << "Enter action:\n1) Append Purchase\n2) Append Credit\n3) Exit\n: ";
        std::string choice;
        std::cin >> choice;

        Transaction::Type type;
        int c = std::atoi(choice.c_str());
        if (c == 1) {
            type = Transaction::Type::Purchase;
        } else if (c == 2) {
            type = Transaction::Type::Credit;
        } else if (c == 3) {
            break;
        } else {
            std::cout << "Invalid choice\n";
        }

        std::cout << "Enter Amount: ";
        std::cin >> choice;
        double amount = atof(choice.c_str());
        card.appendTransaction(type, amount);
    }

    const std::vector<Transaction> transactions = card.getTransactions();

    double total = 0.0;
    size_t count = 0;
    for (const auto& t : transactions) {
        if (t.getType() == Transaction::Type::Purchase) {
            total += t.getAmount();
            count++;
        }
    }

    std::cout << "Average Purchase: " << total / (double)count << "\n";
}
