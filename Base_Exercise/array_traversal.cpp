#include "iostream"

using namespace std;

/*
 * 获取数组长度：sizeof(数组对象) / sizeof(数组某个元素)
 * 高级for循环获取数组每个元素:
 * for(元素类型 临时变量:数组变量)
 * {
 *  临时变量即数组元素;
 * }
 */

int main(){
    int arr[] = {1, 2, 3, 4, 5};

    // while
    int i = 0;
    while (i < sizeof(arr) / sizeof(arr[0])) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
        i++;
    }

    // for
    for (int j = 0; j < sizeof(arr) / sizeof(arr[0]); j++) {
        cout << "arr[" << j << "] = " << arr[j] << endl;
    }

    for (int elem : arr) {
        cout << "arr[" << elem - 1 << "] = " << elem << endl;
    }

    return 0;
} 