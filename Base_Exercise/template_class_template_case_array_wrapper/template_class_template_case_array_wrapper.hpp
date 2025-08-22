#pragma once

#include <iostream>

using namespace std;

template <class T>
class MyArray{
public:
    // 有参构造
    MyArray(int capacity){
        this -> m_capacity = capacity;
        this -> m_size = 0;
        this -> pAddress = new T[this -> m_capacity];
    }
    // 拷贝构造函数
    MyArray(const MyArray& arr) {
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
        // 先判断原来的堆区是否有数据，如果有先释放
        if(this -> pAddress != nullptr) {
            delete[] this -> pAddress;
            this -> pAddress = nullptr;
        }

        
    }

    // 析构函数
    ~MyArray() {
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