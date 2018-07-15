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

#ifndef LIST_H
#define LIST_H

typedef struct node {
    int data;
    struct node *next;
} Node;

class List {
private:
    Node *nodes = nullptr;
public:
    void insert(int);
    void remove(int);
    int index(int);
    void show(void);
    ~List();
};

#endif
