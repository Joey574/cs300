#include <vector>

template <typename T>
class Bag {
    public:
        virtual int getCurentSize() = 0;
        virtual bool isEmpty() = 0;
        virtual bool add(T) = 0;
        virtual bool remove(T) = 0;
        virtual void clear() = 0;
        virtual int getFrequencyOf(T) = 0;
        virtual int contains(T) = 0;
        virtual std::vector<T> toVector() = 0;

};

template <typename T>
Bag<T> join(const Bag<T>& bag1, const Bag<T>& bag2) {
    Bag<T> combined;
    for (const auto& v: bag1.toVector()) {
        combined.add(v);
    }

    for (const auto& v: bag2.toVector()) {
        combined.add(v);
    }

    return combined;
}

int main() {

}
