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
    List l(0);
    l.show();
    for (int i = 0; i <= 10; i++) {
        l.insert(i);
    }
    for (int i = 0; i <= 10; i += 2) {
        l.remove(i);
    }
    l.show();
    l.clear();
    l.push(1); l.push(2); l.push(3);
    l.show();
    l.pop(); l.show();
    l.pop(); l.show();
    l.pop(); l.show();
    return 0;
}
