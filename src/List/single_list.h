//
// Created by admin on 2023/3/30.
//

#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

#include <iostream>
#include <ctime>

// 链表节点
typedef struct Node {
    // 保存的数据
    int data;

    // 指向下一个节点的指针
    Node* next;

    Node() = default;

    Node(int val) {
        data = val;
        next = nullptr;
    }
} *LPNODE;


/// @brief 单向链表
class SingleList {
public:
    SingleList();

    SingleList(int val);

    ~SingleList();

public:
    // 插头
    void PushHead(int val);

    // 插尾
    void PushBack(int val);

    // 按下标插入(插入下标后一个节点)
    void Insert(int val, int index);

public:
    // 初始化一个链表
    void Init(int count = 5);

    // 清空链表
    void Clear();

    // 打印链表
    void Print();

    // 传入头节点打印链表
    void Print(LPNODE head);

    // 获取元素个数
    const int Size() const;

    const LPNODE GetHead();

public:
    // 以下是习题：

    // 反转
    void Reverse();

    // 用递归的方式反转
    LPNODE ReverseByRecursion(LPNODE head);

    // 合并
    LPNODE Merge(Node *that);

    // 获取中间值
    int GetMiddleValue();

private:
    // 头结点
    LPNODE m_Head;

    // 长度
    size_t m_Size;
};

#endif //SINGLE_LIST_H
