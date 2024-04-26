#pragma once
#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class StaticStack
{
    int size;
    int capacity;
    T* SS;

public:
    StaticStack(int cap)
    {
        capacity = cap;
        size = 0;
        SS = new T[capacity];
    }

    void Push(T val)
    {
        if (size >= capacity)
        {
            capacity = capacity + 1;
            T* new_data = new T[capacity];
            for (int idx = 0; idx < size; idx++)
            {
                new_data[idx] = SS[idx];
            }
            delete[] SS;
            SS = new_data;
        }

        SS[size++] = val;
    }

    bool Empty()
    {
        return size == 0;
    }

    void pop()
    {
        if (Empty())
        {
            throw runtime_error("Stack is already empty");
        }

        size--;
    }

    bool Full()
    {
        return size == capacity;
    }

    T top()
    {
        if (Empty())
        {
            throw runtime_error("Stack is empty");
        }
        return SS[size - 1];
    }
};
