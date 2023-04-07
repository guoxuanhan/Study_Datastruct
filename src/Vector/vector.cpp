//
// Created by admin on 2023/4/4.
//

#include <iostream>
#include <ctime>
#include "vector.h"

Vector::Vector() {
    this->m_Size = 0;
    this->m_Capacity = 5;
    this->m_Head = new int[this->m_Capacity];
}

Vector::~Vector() {
    if(this->m_Head != nullptr) {
        delete this->m_Head;
        this->m_Head = nullptr;
    }

    this->m_Size = 0;
    this->m_Capacity = 0;
}

Vector::Vector(const Vector& that) {
    this->m_Size = that.m_Size;
    this->m_Capacity = that.m_Capacity;

    if(this->m_Head != nullptr) {
        delete this->m_Head;
        this->m_Head = nullptr;
    }

    this->m_Head = new int[that.m_Capacity];
    for(int i = 0; i < this->m_Size; i++) {
        this->m_Head[i] = that.m_Head[i];
    }
}

Vector& Vector::operator = (Vector& that) {
    if(this == &that) {
        return *this;
    }

    this->m_Size = that.m_Size;
    this->m_Capacity = that.m_Capacity;

    if(this->m_Head != nullptr) {
        delete this->m_Head;
        this->m_Head = nullptr;
    }

    this->m_Head = new int[that.m_Capacity];
    for(int i = 0; i < this->m_Size; i++) {
        this->m_Head[i] = that.m_Head[i];
    }

    return  *this;
}

void Vector::PushHead(int val) {
    this->CheckCapacity();

    // 将后面所有的元素往后移动
    for(int i = this->m_Size - 1; i >= 0; i--) {
        this->m_Head[i + 1] = this->m_Head[i];
    }

    this->m_Head[0] = val;
    this->m_Size++;
}

void Vector::PushBack(int val) {
    this->CheckCapacity();

    this->m_Head[this->m_Size++] = val;
}

void Vector::Insert(int index, int val) {
    this->CheckCapacity();

    // 将从下标开始的后面元素往后移动
    for (int i = this->m_Size - 1; i >= index ; i--) {
        this->m_Head[i + 1] = this->m_Head[i];
    }

    this->m_Head[index] = val;
    this->m_Size++;
}

void Vector::PopHead() {
    for(int i = 1; i < this->m_Size; i++) {
        this->m_Head[i - 1] = this->m_Head[i];
    }

    this->m_Size--;
}

void Vector::PopBack() {
    this->m_Size--;
}

void Vector::Erase(int index) {
    for(int i = index; i < this->m_Size - 1; i++) {
        this->m_Head[i] = this->m_Head[i + 1];
    }

    this->m_Size--;
}

void Vector::Init(int count) {
    if (count <= 0) {
        return;
    }

    srand(time(0));
    for (int i = 0; i < count; i++) {
        int num = (rand() % 10) + 1;
        this->PushBack(num);
    }
}

void Vector::Print() {
    for(int i = 0; i < this->m_Size; i++) {
        std::cout << this->m_Head[i] << " ";
    }
    std::cout << std::endl;
}

void Vector::CheckCapacity() {
    if(this->m_Size == this->m_Capacity) {
        // 扩容2倍
        this->m_Capacity = this->m_Capacity == 0 ? 1 : this->m_Capacity << 1;
        int *newData = new int[this->m_Capacity];
        memcpy(newData, this->m_Head, sizeof(int) * this->m_Size);
        delete this->m_Head;
        this->m_Head = newData;
    }
}