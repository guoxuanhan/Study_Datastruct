#include "single_list.hpp"

int main() {

#if 1
#pragma region 单链表测试

    SingleList singleList;

    std::cout << "初始化" << std::endl;
    singleList.Init();
    singleList.Print();

    std::cout << "插头" << std::endl;
    singleList.PushHead(100);
    singleList.Print();

    std::cout << "插尾" << std::endl;
    singleList.PushBack(200);
    singleList.Print();

    std::cout << "插中间" << std::endl;
    singleList.Insert(300, 1);
    singleList.Print();

#pragma endregion
#endif // 0


    return 0;
}
