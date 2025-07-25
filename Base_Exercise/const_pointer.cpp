#include "iostream"

using namespace std;

/*
 * const表示常量(不可变)
 * 
 * 1.指向const(常量)的指针
 * const int* p
 * 
 * 2.const(常量)指针
 * int* const p = 地址;   指针指向不可改，必须初始化
 * 
 * 3.指向const的const指针
 * const int * const p = 地址;  指针指向不可改，必须初始化，所指向的内容也不可改
 */

int main() {
    int num1 = 10, num2 = 20;

    // 1. 指向const的指针，指向可变，数据不可变
    const int* p1 = &num1;
    cout << "p1指向的值: " << *p1 << endl;
    // *p1 = 30;
    p1 = &num2;
    cout << "p1指向的新值: " << *p1 << endl;

    // 2. const指针，指向不可变，数据可变
    int* const p2 = &num1;
    cout << "p2指向的值: " << *p2 << endl;
    *p2 = 30; // 修改指针指向的值
    cout << "p2指向的新值: " << *p2 << endl;
    // p2 = &num2;

    // 3. 指向const的const指针，指向不可变，数据不可变
    const int* const p3 = &num1;
    cout << "p3指向的值: " << *p3 << endl;
    // *p3 = 40;
    // p3 = &num2;

    return 0;
}