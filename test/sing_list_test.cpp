//
// Created by admin on 2023/3/30.
//

#include <iostream>
#include "../src/List/single_list.h"

int main() {

    SingleList singleList;

//    std::cout << "Init" << std::endl;
//    singleList.Init();
//    singleList.Print();
//
//    std::cout << "PushHead" << std::endl;
//    singleList.PushHead(100);
//    singleList.Print();
//
//    std::cout << "PushBack" << std::endl;
//    singleList.PushBack(200);
//    singleList.Print();
//
//    std::cout << "Insert 1 pos" << std::endl;
//    singleList.Insert(300, 1);
//    singleList.Print();

//    std::cout << "Init" << std::endl;
//    singleList.Init();
//    singleList.Print();
//
//    std::cout << "Reverse" << std::endl;
//    //singleList.Reverse();
//    singleList.ReverseByRecursion(singleList.GetHead());
//    singleList.Print();

//    std::cout << "Merge Begin" << std::endl;
//    std::cout << "List 1 Print" << std::endl;
//    singleList.PushBack(1);
//    singleList.PushBack(3);
//    singleList.PushBack(5);
//    singleList.Print();
//
//    SingleList singleList2;
//    std::cout << "List 2 Print" << std::endl;
//    singleList2.PushBack(2);
//    singleList2.PushBack(4);
//    singleList2.PushBack(6);
//    singleList2.Print();
//
//    std::cout << "Merge over Print" << std::endl;
//    LPNODE newNode = singleList.Merge(singleList2.GetHead());
//    singleList.Print(newNode);

    singleList.Init(9);
    singleList.Print();
    auto midVal = singleList.GetMiddleValue();
    std::cout << midVal << std::endl;

    return 0;
}