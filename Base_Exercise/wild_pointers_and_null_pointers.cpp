#include "iostream"

using namespace std;

int main() {
    // 空指针
    // int* p1 = nullptr; // 声明了一个指针变量（p就被分配了8个字节的空间）
    // int* p2 = NULL;

    // int* p;
    // *p = 10; // 试图将10存储到p指向的地址，但p未初始化，导致野指针

    int* p;
    cout << p << endl; // 不为0的话就是有脏数据

    return 0;
}  