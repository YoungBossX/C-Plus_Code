#include "iostream"

using namespace std;

/*
 * new 类型、 new 类型[n]
 * delete 指针、delete[] 指针
 */

int main() {
    int* p = new int;

    *p = 10;
    cout << "new申请的4字节空间内，存放的是：" << *p << endl;

    delete p;

    // int num = 10;
    // cout << num << endl;
    // delete &num; // 错误：不能对非动态（静态）分配的内存使用 delete
 
    int* p_arr = new int[5]; // 申请5元素可以存放int类型的数组空间
    // p_arr的地址就是数组空间的内存区域的开头（第一个元素的位置）
    p_arr[0] = 10; // 等同于 *(p_arr + 0) = 10
    p_arr[1] = 20; // 等同于 *(p_arr + 1) = 20
    p_arr[2] = 30; // 等同于 *(p_arr + 2) = 30
    p_arr[3] = 40; // 等同于 *(p_arr + 3) = 40
    p_arr[4] = 50; // 等同于 *(p_arr + 4) = 50

    cout << "数组的第一个元素是：" << p_arr[0] << endl;
    cout << "数组的第二个元素是：" << p_arr[1] << endl;
    cout << "数组的第三个元素是：" << p_arr[2] << endl;
    cout << "数组的第四个元素是：" << p_arr[3] << endl;
    cout << "数组的第五个元素是：" << p_arr[4] << endl;
    cout << p_arr << endl;
    cout << p_arr + 1 << endl;

    delete[] p_arr;

    // 作业
    int* arr = new int[10];

    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1; 
    }

    cout << "数组元素为：" << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}  