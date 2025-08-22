#pragma once

#include <iostream>

using namespace std;

template <class T>
class MyArray{
public:
    // 有参构造
    MyArray(int capacity){
        // cout << "MyArray构造函数调用。" << endl;
        this -> m_capacity = capacity;
        this -> m_size = 0;
        this -> pAddress = new T[this -> m_capacity];
    }
    // 拷贝构造函数
    MyArray(const MyArray& arr) {
        // cout << "MyArray拷贝构造函数调用。" << endl;
        this -> m_capacity = arr.m_capacity;
        this -> m_size = arr.m_size;
        // this -> pAddress = arr.pAddress; // 浅拷贝问题，重复释放堆空间

        // 深拷贝
        this -> pAddress = new T[arr.m_capacity]; 
        // 将arr中的数据都拷贝过来
        for(int i = 0; i < arr.m_size; i++) {
            this -> pAddress[i] = arr.pAddress[i];
        }
    }

    // operator= 防止浅拷贝问题
    MyArray& operator=(const MyArray& arr) {
        // cout << "MyArray operator= 调用。" << endl;
        // 先判断原来的堆区是否有数据，如果有先释放
        if(this -> pAddress != nullptr) {
            delete[] this -> pAddress;
            this -> pAddress = nullptr;
            this -> m_capacity = 0;
            this -> m_size = 0;
        }

        // 进行深拷贝
        this -> m_capacity = arr.m_capacity;
        this -> m_size = arr.m_size;
        this -> pAddress = new T[arr.m_capacity];
        for(int i = 0; i < arr.m_size; i++) {
            this -> pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    void pushBack(const T& val) {
        // 判断容量大小是否等于m_capacity
        if(this -> m_capacity == this -> m_size) {
            return;
        }
        this -> pAddress[this -> m_size] = val;
        this -> m_size++;
    }

    void popBack() {
        // 让用户访问不到最后一个元素，即为尾删，逻辑删除
        if (this -> m_size == 0) {
            return;
        }
        this -> m_size--;
    }

    T& operator[](int index) {
        return this -> pAddress[index];
    }

    int getCapacity() {
        return this -> m_capacity;
    }

    int getSize() {
        return this -> m_size;
    }

    // 析构函数
    ~MyArray() {
        // cout << "MyArray析构函数调用。" << endl;
        if(this -> pAddress != nullptr) {
            delete[] this -> pAddress;
            this -> pAddress = nullptr;
        }
    }

private:
    T* pAddress;
    int m_capacity;
    int m_size;
};