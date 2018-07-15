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

void free_nodes(Node *head) {
    if (head != nullptr) {
        free_nodes(head->next);
        delete head;
    }
}

List::~List() {
    free_nodes(this->nodes);
}
