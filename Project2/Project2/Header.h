#pragma once
#include <iostream>
using namespace std;

template<typename T>
class AutoGrowingArray {
private:
    int size;
    int capacity;
    T* data;
public:
    AutoGrowingArray() {
        size = 0;
        capacity = 1;
        data = new T[capacity];
    }

    T operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    int getSize() const {
        return size;
    }

    void PushBack(T value) {
        if (size >= capacity) {
            capacity = 1 + capacity;
            T* new_data = new T[capacity];
            for (int idx = 0; idx < size; idx++) {
                new_data[idx] = data[idx];
            }
            delete[] data;
            data = new_data;
        }
        data[size++] = value;
    }

    friend ostream& operator<<(ostream& out, const AutoGrowingArray& Other) {
        for (int idx = 0; idx < Other.size; idx++) {
            out << Other.data[idx] << " ";
        }
        return out;
    }

    ~AutoGrowingArray() {
        delete[] data;
    }
};
