//
// Created by admin on 2023/3/30.
//

#include "./single_list.h"

SingleList::SingleList() {
    this->m_Head = nullptr;
    this->m_Size = 0;
}

SingleList::SingleList(int val) {
    this->m_Head = new Node(val);
}

SingleList::~SingleList() {
    this->Clear();
}

void SingleList::PushHead(int val) {
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

void SingleList::PushBack(int val) {
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

void SingleList::Insert(int val, int index) {
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

void SingleList::Init(int count) {
    if (count <= 0) {
        return;
    }

    srand(time(0));
    for (int i = 0; i < count; i++) {
        int num = (rand() % 10) + 1;
        this->PushBack(num);
    }
}

void SingleList::Clear() {
    while (this->m_Head != nullptr) {
        Node* delNode = this->m_Head;
        this->m_Head = this->m_Head->next;

        delete delNode;
        delNode = nullptr;
    }
}

void SingleList::Print() {
    LPNODE temp = this->m_Head;
    while (temp != nullptr) {
        std::cout << temp->data << "  ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

const int SingleList::Size() const {
    return this->m_Size;
}