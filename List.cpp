/**
 * ================================================
 *
 *         Copyright 2018 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ===============================================
 */


#include "List.hpp"
#include <iostream>
#include <cstdarg>
#include <string>

template<typename T>
void List<T>::insert(T data) {
    Node<T> **tail;
    for (tail = &this->nodes; *tail != nullptr; tail = &(*tail)->next);
    *tail = new Node<T>;
    (*tail)->data = data;
    (*tail)->next = nullptr;
}


template<typename T>
void List<T>::remove(T data) {
    Node<T> **node = &this->nodes, **prev = &this->nodes;

    while (*node != nullptr) {
        if ((*node)->data == data) {
            Node<T> *to_delete = *node;
            if (*prev == *node) {
                (*node) = (*node)->next;
            } else if ((*node)->next == nullptr) {
                (*prev)->next = nullptr;
            } else {
                (*prev)->next = (*node)->next;
            }

            delete to_delete;
            continue;
        }
        prev = node;
        node = &(*node)->next;
    }
}

template<typename T>
int List<T>::index(T data) {
    Node<T> *node;
    int idx = 0;
    for (node = this->nodes; node != nullptr; node = node->next) {
        if (node->data == data) {
            return idx;
        }
        idx++;
    }
    return -1;
}

template<typename T>
void List<T>::show() {
    using namespace std;
    cout << "[";
    Node<T> **node;
    for (node = &this->nodes; *node != nullptr; node = &(*node)->next) {
        cout << (*node)->data;
        if ((*node)->next != nullptr) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

template<typename T>
void List<T>::push(T data) {
    Node<T> *head = new Node<T>;
    head->data = data;
    head->next = this->nodes;
    this->nodes = head;
}

template<typename T>
T List<T>::pop(void) {
    T data;
    if (this->nodes != nullptr) {
        Node<T> *new_head;
        new_head = this->nodes->next;
        delete this->nodes;
        this->nodes = new_head;
    }

    return data;
}

template<typename T>
void free_nodes(Node<T> *head) {
    if (head != nullptr) {
        free_nodes(head->next);
        delete head;
    }
}

template<typename T>
void List<T>::clear(void) {
    free_nodes(this->nodes);
    this->nodes = nullptr;
}

template<typename T>
List<T>::~List() {
    this->clear();
}

template<typename T>
List<T>::List(int n_elements, ...) {
    va_list args;
    va_start(args, n_elements);

    while (n_elements--) {
        T i = va_arg(args, T);
        this->insert(i);
    }

    va_end(args);
}

template class List<int>;
template class List<double>;
template class List<const char*>;
template class List<std::string>;
