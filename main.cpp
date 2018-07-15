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
using namespace std;

int main() {
    List<const char*> l(2, "templates", "infernais");
    l.show();
    l.push("banana");
    l.show();
    l.push("abacate");
    l.show();
    l.push("maçã");
    l.show();
    l.pop();
    l.show();
    l.pop();
    l.show();
    l.pop();
    l.show();
    return 0;
}
