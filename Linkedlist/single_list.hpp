#ifndef __SINGLE_LIST_HPP__
#define __SINGLE_LIST_HPP__

#include <iostream>
#include <time.h>

/// @brief 链表节点
typedef struct Node {
    /// @brief 保存的数据
    int data;

    /// @brief 指向下一个节点的指针
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
    SingleList() = default;

    SingleList(int val) {
        this->m_Head = new Node(val);
    }

    ~SingleList() {
        this->Clear();
    }

    /// @brief 插头
    /// @param val 
    void PushHead(int val) {
        if (this->m_Head == nullptr) {
            this->m_Head = new Node(val);
        }
        else {
            // 构造新节点
            LPNODE newNode = new Node();
            newNode->data = val;
            newNode->next = this->m_Head;

            this->m_Head = newNode;
        }

        this->m_Size++;
    }

    /// @brief 插尾
    /// @param val 
    void PushBack(int val) {
        if (this->m_Head == nullptr) {
            this->PushHead(val);
        }
        else {
            // 用临时指针，指向链表尾节点
            LPNODE temp = this->m_Head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            // 构造新节点
            LPNODE newNode = new Node();
            newNode->data = val;
            newNode->next = nullptr;

            // 指向新节点
            temp->next = newNode;

            // 更新链表长度
            this->m_Size++;
        }
    }

    /// @brief 按下标插入(插入下标后一个节点)
    /// @param val 
    /// @param index 
    void Insert(int val, int index) {
        if (index == 0) {
            this->PushHead(val);
        }
        else if (index >= this->m_Size - 1) {
            this->PushBack(val);
        }
        else {
            // 找到对应下标的节点
            LPNODE temp = this->m_Head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }

            LPNODE newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            this->m_Size++;
        }
    }

public:
    /// @brief 初始化一个链表
    /// @param count 
    void Init(int count = 5) {
        if (count <= 0) {
            return;
        }

        srand(time(0));
        for (int i = 0; i < count; i++) {
            int num = (rand() % 10) + 1;
            this->PushBack(num);
        }
    }

    /// @brief 清空链表
    void Clear() {
        while (this->m_Head != nullptr) {
            Node* delNode = this->m_Head;
            this->m_Head = this->m_Head->next;

            delete delNode;
            delNode = nullptr;
        }
    }

    /// @brief 打印链表
    void Print() {
        LPNODE temp = this->m_Head;
        while (temp != nullptr) {
            std::cout << temp->data << "  ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    const int Size() const {
        return this->m_Size;
    }

private:
    /// @brief 头结点
    LPNODE m_Head;

    /// @brief 长度
    size_t m_Size;
};


/*
    TODO:
        1. 快慢指针获取中间值
        2. 反转
        3. 合并
*/


#endif // __SINGLE_LIST_HPP__