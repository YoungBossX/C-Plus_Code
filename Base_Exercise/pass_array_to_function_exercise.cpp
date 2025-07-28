#include "iostream"

using namespace std;

/*
 * 编写一个函数，接收数组传入，对数组进行升序排序
 * - 传入参数需带有数组长度
 * - 没有返回值
 */

void sort_arr(int arr[], int length) {
    int min;
    int min_index;

    for (int i = 0; i < length - 1; i++) {
        for (int j = i; j < length; j++) {
            if(j==i) {
                min = arr[j];
                min_index = j;
            } else if(arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6, 3, 8, 7, 4};

    sort_arr(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}   