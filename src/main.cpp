// Copyright 2022 NNTU-CS
#include <iostream>
#include "tpqueue.h"

int main() {
    TPQueue<SYM> pqueue;
    pqueue.push(SYM{'a', 4});
    pqueue.push(SYM{'b', 7});
    SYM c1 = pqueue.pop();
    SYM c2 = pqueue.pop();
    std::cout << c1.ch << " " << c1.prior << std::endl;
    std::cout << c2.ch << " " << c2.prior << std::endl;
    return 0;
}
