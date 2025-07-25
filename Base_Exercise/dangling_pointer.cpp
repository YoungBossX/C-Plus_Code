#include "iostream"

using namespace std;

/*
 * 悬挂指针
 * 1.不要轻易进行指针之间的赋值
 * 2.一旦用delete，要确保真的这个内存区域没人用了
 */

int main() {
    int* p = new int;
    *p = 10;

    int* p1 = p; // p1指向p所指向的内存区域

    cout << "p指针指向的内存区域的值是: " << *p << endl;
    // delete p; // 释放p所指向的内存区域
    cout << "p1指针指向的内存区域的值是: " << *p1 << endl;

    return 0; 
}   