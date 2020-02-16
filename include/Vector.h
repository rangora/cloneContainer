#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdio.h>
using namespace std;

template <typename T>
struct Node {
    Node(T aData = 0) : data(aData), next(nullptr) {};
    T data;
    Node<T>* next;
};

template <typename T>
class Vector {
    private:
        T* _v;
        size_t _capacity;
        size_t _size;

        Node<T>* head;
        Node<T>* tail;
        Node<T>* front;
        Node<T>* pre_back;
        Node<T>* back;

    public:
        Vector();
        virtual ~Vector();

        void listInsert(T ele);
        void listDelete();
        void listShow();

        void reserve(size_t capacity);
        void pop_back();

    private:
};


template <class T>
void Vector<T>::listInsert(T ele) {
    Node<T>* newNode = new Node<T>{ele};

    // first..
    if(head->next == nullptr) {
        head->next = newNode;
        back = front = newNode;
    }
    // other..
    else {
        pre_back = back;
        back->next = newNode;
        back = newNode;
        back->next = tail;
    }
    _size++;
}

template <class T>
void Vector<T>::listDelete() {
    auto iter = head->next;

    while(iter != tail) {
        cout << iter->data << " ";
        iter = iter->next;
    }
    cout << endl;
}

template <class T>
Vector<T>::Vector() : _size(0) {
    head = new Node<T>;
    tail = new Node<T>;
}

template <class T>
Vector<T>::~Vector() {
    delete front;
    delete back;
}

#endif // VECTOR_H
