//
// Created by admin on 2023/4/4.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>

// 顺序表
class Vector {
public:
    Vector();

    ~Vector();

    Vector(const Vector& that);

    Vector& operator = (Vector& that);
public:
    // 头部插入
    void PushHead(int val);

    // 尾部插入
    void PushBack(int val);

    // 中间插入
    void Insert(int index, int val);
public:
    void PopHead();

    void PopBack();

    void Erase(int index);
public:
    void Init(int count = 5);

    void Print();
private:
    // 扩容
    void CheckCapacity();
private:
    // 数据
    int *m_Head;

    // 元素个数
    size_t m_Size;

    // 可用容量
    size_t m_Capacity;
};


#endif //VECTOR_H
