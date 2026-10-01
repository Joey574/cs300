#ifndef ARRAYBAG_HPP
#define ARRAYBAG_HPP
#include <cstddef>
#include <cstdlib>
#include <cstring>

template<typename T>
class ResizeableArrayBag {
    public:
        ResizeableArrayBag<T>() : data(nullptr), size(0), capacity(0) {}
        ResizeableArrayBag<T>(int capacity) : data(malloc(capacity*sizeof(T))), size(0), capacity(size) {}

        void Push(T item) {
            if (size == capacity) {
                capacity *= 2;
                data = realloc(data, capacity*sizeof(T));
            }

            data[size++] = item;
        }

        T getNext();
        T removeNext();

        size_t Size() const {
            return size;
        }

        size_t Capacity() const {
            return capacity;
        }

        const T& operator [](int i) const {
            return data[i];
        }

        T& operator [](int i) {
            return data[i];
        }

        ~ResizeableArrayBag() {
            if (data) {
                free(data);
            }
        }

    private:
        T* data;
        size_t size;
        size_t capacity;
};

#endif // ARRAYBAG_HPP
