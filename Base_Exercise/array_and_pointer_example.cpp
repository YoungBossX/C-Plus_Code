#include "iostream"

using namespace std;

int main() {
    int size = 10;
    int* pArr = new int[10]{3, 5, 1, 11, 99, 66, 22, 2, 8, 6};

    // for (int i = 0; i < size - 1; i++) {
    //     for (int j = 0; j < size - 1 - i; j++) {
    //         if (*(pArr + j) > *(pArr + j + 1)) {
    //             int temp = *(pArr + j);
    //             *(pArr + j) = *(pArr + j + 1);
    //             *(pArr + j + 1) = temp;
    //         }
    //     }
    // }

    // for (int i = 0; i < size - 1; i++) {
    //     for (int j = i; j < size; j++) {
    //         if (*(pArr + i) > *(pArr + j)) {
    //             int temp = *(pArr + i);
    //             *(pArr + i) = *(pArr + j);
    //             *(pArr + j) = temp;
    //         }
    //     } 
    // }

    // int min;
    // int min_index;
    // for (int i = 0; i < size - 1; i++) {
    //     for (int j = i; j < size; j++) {
    //         if (j == i) {
    //             min = pArr[i];
    //             min_index = i;
    //         } else if (pArr[j] < min) {
    //             min = pArr[j];
    //             min_index = j;
    //         }
    //     } 
    //     // 进行交换，将当前最小值的值和第一个元素（相对，第一次是0下标，第二次是1下标...）进行位置交换
    //     int temp = pArr[i];
    //     pArr[i] = pArr[min_index];
    //     pArr[min_index] = temp;
    // }

    int max;
    int max_index;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i; j < size; j++) {
            if (j == i) {
                max = pArr[i];
                max_index = i;
            } else if (pArr[j] > max) {
                max = pArr[j];
                max_index = j;
            }
        } 
        // 进行交换，将当前最大值的值和第一个元素（相对，第一次是0下标，第二次是1下标...）进行位置交换
        int temp = pArr[i];
        pArr[i] = pArr[max_index];
        pArr[max_index] = temp;
    }
    
    cout << "排序后的数组元素为：";
    for (int i = 0; i < 10; i++) {
        cout << *(pArr + i) << " ";
    }

    delete[] pArr;

    return 0;
}