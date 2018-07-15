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



void List::insert(int data) {
    Node **tail;
    for (tail = &this->nodes; *tail != nullptr; tail = &(*tail)->next);
    *tail = new Node;
    (*tail)->data = data;
    (*tail)->next = nullptr;
}


void List::remove(int data) {
    Node **node = &this->nodes, **prev = &this->nodes;

    while (*node != nullptr) {
        if ((*node)->data == data) {
            Node *to_delete = *node;
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


int List::index(int data) {
    Node *node;
    int idx = 0;
    for (node = this->nodes; node != nullptr; node = node->next) {
        if (node->data == data) {
            return idx;
        }
        idx++;
    }
    return -1;
}


void List::show() {
    using namespace std;
    cout << "[";
    Node **node;
    for (node = &this->nodes; *node != nullptr; node = &(*node)->next) {
        cout << (*node)->data;
        if ((*node)->next != nullptr) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void List::push(int data) {
    Node *head = new Node;
    head->data = data;
    head->next = this->nodes;
    this->nodes = head;
}

int List::pop(void) {
    int data = -1;
    if (this->nodes != nullptr) {
        Node *new_head;
        new_head = this->nodes->next;
        delete this->nodes;
        this->nodes = new_head;
    }

    return data;
}

void free_nodes(Node *head) {
    if (head != nullptr) {
        free_nodes(head->next);
        delete head;
    }
}

void List::clear(void) {
    free_nodes(this->nodes);
    this->nodes = nullptr;
}

List::~List() {
    this->clear();
}

List::List(int n_elements, ...) {
    va_list args;
    va_start(args, n_elements);

    while (n_elements--) {
        int i = va_arg(args, int);
        this->insert(i);
    }

    va_end(args);
}
