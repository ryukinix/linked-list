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
    List l;
    for (int i = 0; i <= 10; i++) {
        l.insert(i);
    }
    for (int i = 0; i <= 10; i += 2) {
        l.remove(i);
    }
    l.show();
    return 0;
}
