#include "iostream"

using namespace std;

/* 移除下标0和5，2个元素 */

int main() {
    int* p_arr = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 创建一个新数组
    int* p_new_arr = new int[8];
    
    
    // for循环遍历老数组，将需要的元素一个个放入新数组
    // for (int i = 0; i < 10; i++) {
    //     if (i != 0 && i != 5) {
    //         p_new_arr[i - (i > 5 ? 2 : 1)] = p_arr[i];
    //     }
    // }

    int offset = 0;
    for (int i = 0; i < 10; i++) {
        if (i == 0 || i == 5) {
            offset++; 
            continue; 
        }
        p_new_arr[i - offset] = p_arr[i];
    }

    delete[] p_arr; // 释放老数组内存
    p_arr = p_new_arr; // 将新数组的地址赋给老数组指

    cout << "新数组的元素为：";
    for (int i = 0; i < 8; i++) {
        cout << p_arr[i] << " ";
    }
    cout << endl;
    cout << "老数组的元素为：";
    for (int i = 0; i < 8; i++) {
        cout << p_arr[i] << " ";
    }

    return 0;
}  