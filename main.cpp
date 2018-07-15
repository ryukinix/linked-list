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
    l.insert(1);
    l.insert(2);
    l.insert(2);
    l.insert(3);
    l.insert(2);
    l.remove(3);
    l.show();
    cout << l.index(3) << endl;
    return 0;
}
