#include "iostream"

using namespace std;

int main() {
    int* p_arr = new int[5] {1, 2, 3, 4, 5};
    cout << "老数组的地址：" << p_arr << endl;
    int* p_new_arr = new int[4];

    for (int i = 0; i < 5; ++i) {
        if (i == 2) {
            continue;
        }
        else if (i > 2) {
            p_new_arr[i - 1] = p_arr[i];
        } else {
            p_new_arr[i] = p_arr[i];
        }
    }

    // 可选
    delete[] p_arr; // 回收老数组的空间

    cout << "新数组的地址：" << p_new_arr << endl;
    cout << "老数组的地址：" << p_arr << endl;

    // 可选
    p_arr = p_new_arr; // 将老数组的指针指向新数组的内存空间

    for (int i = 0; i < 4; ++i) {
        cout << "新数组的元素：" << p_new_arr[i] << endl;
    }

    for (int i = 0; i < 4; ++i) {
        cout << "老数组的元素：" << p_arr[i] << endl;
    }

    return 0;
}  