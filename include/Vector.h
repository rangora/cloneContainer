#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdio.h>
using namespace std;

template <typename T>
struct Node {
    Node(T aData) : data(aData) {};
    T data;
};

template <typename T>
class Vector {
    private:
        size_t _capacity;
        size_t _size;
        Node<T>* _v;
        Node<T>* _begin;
        Node<T>* _end;

    public:
        Vector();
        virtual ~Vector();

        void showAll();
        void reserve(size_t capacity);
        void push_back(T ele);
        void pop_back();
        bool empty();
        void resize(size_t size);
        T at(size_t border);

        Node<T>& operator=(Node<T>& rhs);
};

template <class T>
T Vector<T>::at(size_t border) {
    if(border > _capacity || border < 0) {
        throw out_of_range("out of index");
    }
    return _v[border].data;
}

template <class T>
void Vector<T>::resize(size_t size) {
    if(size > _capacity)
        reserve(size);
    else
        _size = size;
}

template <class T>
bool Vector<T>::empty() {
    return _size > 0 ? true : false;
}

template <class T>
void Vector<T>::showAll() {
    auto iter = _v;
    while(iter != _end)
        cout << (iter++)->data << " ";
    putchar('\n');
    cout << _size << endl;
    cout << _capacity << endl;
}

template <class T>
Node<T>& Vector<T>::operator=(Node<T>& rhs) {
    this.data = rhs.data;
    this.next = rhs.next;
}

template <class T>
void Vector<T>::reserve(size_t capacity) {
    _v = (Node<T>*)malloc(sizeof(Node<T>) * capacity + 1);
    _capacity = capacity;
    _end = _v + _capacity;
}

template <class T>
void Vector<T>::push_back(T ele) {
    if(!_capacity) reserve(1);
    else if(_size >= _capacity) {
        _capacity = _capacity * 2 + 1;
        _v = (Node<T>*)realloc(_v, sizeof(Node<T>) * _capacity);
    }

    _v[_size++].data = ele;
    _end = _v + _size;
}

template <class T>
Vector<T>::Vector() : _size(0), _capacity(0) {
}

template <class T>
Vector<T>::~Vector() {
    delete _v;
}

#endif // VECTOR_H
