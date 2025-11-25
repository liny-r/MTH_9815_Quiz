#include <iostream>
#include "Hashtable.hpp"


int main() {
    IntHasher h;
    IntEquality eq;

    Hashtable<int, std::string> table(10, h, eq);

    table.insert(1, "hello");
    table.insert(2, "you");

    std::cout << table.at(1) << std::endl;
    std::cout << table.at(2) << std::endl;

    return 0;
}
