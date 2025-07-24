#include "iostream"

using namespace std;

/* 在下标1和3插入数字：11和66 */

int main() {
    int* p_arr = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 创建一个新数组
    int* p_new_arr = new int[12];
    
    
    // for循环遍历老数组，将需要的元素一个个放入新数组，（非插入的位置，填充老数组元素，插入位置填充新元素）
    int offset = 0;
    for (int i = 0; i < 12; i++) {
        if (i == 1) {
            p_new_arr[i] = 11;
            offset++;
            continue;
        } else if (i == 3) {
            p_new_arr[i] = 66;
            offset++;
            continue;
        } 
        p_new_arr[i] = p_arr[i - offset];
    }

    delete[] p_arr; // 释放老数组内存
    p_arr = p_new_arr; // 将新数组的地址赋给老数组指

    cout << "新数组的元素为：";
    for (int i = 0; i < 12; i++) {
        cout << p_arr[i] << " ";
    }
    cout << endl;
    cout << "老数组的元素为：";
    for (int i = 0; i < 12; i++) {
        cout << p_arr[i] << " ";
    }

    return 0;
}  