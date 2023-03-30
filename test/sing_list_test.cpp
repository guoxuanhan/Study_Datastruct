//
// Created by admin on 2023/3/30.
//

#include <iostream>
#include "../src/List/single_list.h"

int main() {

    SingleList singleList;

    std::cout << "Init" << std::endl;
    singleList.Init();
    singleList.Print();

    std::cout << "PushHead" << std::endl;
    singleList.PushHead(100);
    singleList.Print();

    std::cout << "PushBack" << std::endl;
    singleList.PushBack(200);
    singleList.Print();

    std::cout << "Insert 1 pos" << std::endl;
    singleList.Insert(300, 1);
    singleList.Print();

    return 0;
}