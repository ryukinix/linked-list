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

template<typename T>
struct Node {
    T data;
    Node<T> *next;
};

template<typename T>
class List {
private:
    Node<T> *nodes = nullptr;
public:
    void insert(T);
    void remove(T);
    int index(T);
    void show(void);
    void push(T);
    T pop(void);
    void clear(void);
    ~List();
    List(int n_elements, ...);
};

#endif
