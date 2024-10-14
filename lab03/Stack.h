//
// Created by Csala on 2024. 10. 14..
//

#ifndef LAB3_STACK_H
#define LAB3_STACK_H


#include <iostream>

template <typename T>
class Stack {
private:
    T* elements;
    int capacity;
    int topIndex;

    void resize() {
        capacity *= 2;
        T* newElements = new T[capacity];
        for (int i = 0; i <= topIndex; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

public:

    Stack() {
        capacity = 2;
        elements = new T[capacity];
        topIndex = -1;
    }


    void push(T value) {
        if (topIndex + 1 == capacity) {
            resize();
        }
        elements[++topIndex] = value;
    }


    void pop() {
        if (topIndex >= 0) {
            topIndex--;
        } else {
            std::cout << "Hiba: A verem már üres!" << std::endl;
        }
    }


    T top() {
        if (topIndex >= 0) {
            return elements[topIndex];
        } else {
            std::cout << "Hiba: A verem üres!" << std::endl;
            return T();
        }
    }


    bool empty() {
        return topIndex == -1;
    }


    int size() {
        return topIndex + 1;
    }


    ~Stack() {
        delete[] elements;
    }
};



#endif //LAB3_STACK_H
