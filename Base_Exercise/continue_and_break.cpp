#include "iostream"

using namespace std;

// continue 跳过本次循环，进入下一次循环流程
// break 直接停止所在循环的执行

int main() {
    // 通过for循环输出1到20之间的奇数
    for (int i = 1; i <= 20; i++) {
        if (i % 2 == 0) {
            continue; // 如果是偶数，跳过本次循环
        }
        cout << i << " ";
    }

    cout << endl;

    // 通过for循环输出1到20之间的数字
    for (int i = 1; true; i++) {
        cout << i << " ";
        if (i == 20) {
            break; // 当i等于20时，直接跳出循环
        }
    }

    cout << endl;

    // 通过while循环输出1到20之间的奇数
    int i = 1;
    while (i <= 20) {
        if (i % 2 == 0) {
            i++; // 如果是偶数，跳过本次循环
            continue;
        }
        cout << i << " ";
        i++;
    }

    cout << endl;

    // 两者在嵌套循环中只对它所在的循环起作用
    for (int num = 1; num <= 5; num++) {
        int i = 1;
        while (i <= 20) {
            if (i % 2 == 0) {
                i++; // 如果是偶数，跳过本次循环
                continue;
            }
            cout << i << " ";
            i++;
        }
    }
    
    return 0;
}