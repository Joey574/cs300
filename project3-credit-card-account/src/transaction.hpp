#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

class Transaction {
    public:
        enum class Type { Purchase, Credit };

        Transaction(Type type, double amount) : type(type), amount(amount), next(nullptr) {}

        Type getType() const;
        double getAmount() const;

        Transaction* getNext() const;
        void setNext(Transaction* node);

    private:
        Type type;
        double amount;
        Transaction* next;
};

#endif
