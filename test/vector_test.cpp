//
// Created by admin on 2023/4/7.
//

#include <iostream>
#include "../src/Vector/vector.h"

int main() {
    Vector vector;

    std::cout << "push head" << std::endl;
    vector.PushHead(6);
    vector.PushHead(7);
    vector.PushHead(8);
    vector.Print();

    std::cout << "push back" << std::endl;
    vector.PushBack(1);
    vector.PushBack(2);
    vector.PushBack(3);
    vector.Print();

    std::cout << "insert" << std::endl;
    vector.Insert(1, 9);
    vector.Print();

    std::cout << "pop" << std::endl;
    vector.Erase(1);
    vector.Print();

    std::cout << "pop head" << std::endl;
    vector.PopHead();
    vector.Print();

    std::cout << "pop back" << std::endl;
    vector.PopBack();
    vector.Print();


}