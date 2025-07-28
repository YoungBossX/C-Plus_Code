#include "iostream"

using namespace std;

/*
 * void func(int arr[]);
 * void func(int arr[10]);
 * void func(int * arr);
 * 三者完全一致，无论哪种方式，arr均被看做指针（地址传递）
 *
 * - 函数体内，sizeof无法统计数组大小，得到的总是8字节（指针本身大小）
 * - 函数接受数组传入，一般建议附带数组长度（否则非常难以统计）
 */

void func1(int arr[]) {
    cout << "函数内统计的数组大小：" << sizeof(arr) << endl;
}

void func2(int arr[10]) {
    cout << "函数内统计的数组大小：" << sizeof(arr) << endl;
}

void func3(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 自动推导数组大小
    cout << "在main函数内统计的数组大小：" << sizeof(arr) << endl; // arr本质上不是指针，它就是数组对象

    func1(arr);
    func2(arr);
    func3(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}   