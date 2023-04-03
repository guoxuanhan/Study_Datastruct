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

void SingleList::Print(LPNODE head) {
    LPNODE temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

const int SingleList::Size() const {
    return this->m_Size;
}

const LPNODE SingleList::GetHead() {
    return this->m_Head;
}

void SingleList::Reverse() {
    if (this->m_Head == nullptr || this->m_Head->next == nullptr) {
        return;
    }

    // null ---> 1 ---> 2 ---> 3 ---> 4
    //  |        |      |      |      |
    // pre      cur    nxt
    LPNODE pre = nullptr;
    LPNODE cur = m_Head;
    LPNODE nxt = cur->next;

    while (true) {
        // 修改指向，让cur指向前一个节点
        // null <--- 1      2 ---> 3 ---> 4
        //  |        |      |      |      |
        // pre      cur    nxt
        cur->next = pre;
        if(nxt == nullptr) {
            break;
        }

        // 移动三个指针，重新进入循环修改指向
        // null <--- 1      2 ---> 3 ---> 4
        //  |        |      |      |      |
        //          pre    cur    nxt
        pre =cur;
        cur = nxt;
        nxt = nxt->next;
    }

    // 出了循环cur就是最后一个节点，让它做为新的头节点
    m_Head = cur;
}

LPNODE SingleList::ReverseByRecursion(LPNODE head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // 找到最后一个节点
    LPNODE cur = ReverseByRecursion(head->next);

    // 修改最后节点的指向
    head->next->next = head;
    head->next = nullptr;

    // cur就是新的头节点
    this->m_Head = cur;
    return cur;
}

LPNODE SingleList::Merge(Node *that) {
    // 两个合并后的新节点
    LPNODE newHead = new Node(-1);

    // 用来指向两个链表比较后的最小值的节点
    LPNODE p = newHead;

    while (this->m_Head != nullptr && that != nullptr) {
        // 找到最小的节点值
        if (this->m_Head->data <= that->data) {
            p->next = this->m_Head; // 新链表链接最小节点
            this->m_Head = this->m_Head->next; // 节点后移，继续判断大小
        }
        else {
            p->next = that;
            that = that->next;
        }

        // 一定要移动新链表指针，将筛选的最小值排列起来
        p = p->next;
    }

    // 把最后不为空的链表直接拼接在新链表尾部
    p->next = this->m_Head == nullptr ? that : this->m_Head;

    return newHead->next;
}

int SingleList::GetMiddleValue() {

}