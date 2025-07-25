#include "iostream"

using namespace std;

/*
 * 数据类型 数组名[数组长度]
 * 
 * 数组名[下标索引]，访问数组元素
 */

int main() {
    // 定义一个整型数组，长度为5
    int arr1[5];
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    arr1[3] = 4;
    arr1[4] = 5;
    // 输出数组元素
    cout << "数组第一个元素为：" << arr1[0] << endl;
    cout << "数组第二个元素为：" << arr1[1] << endl;
    cout << "数组第三个元素为：" << arr1[2] << endl;
    cout << "数组第四个元素为：" << arr1[3] << endl;
    cout << "数组第五个元素为：" << arr1[4] << endl;

    // 数组类型 数组名[] = {元素1, 元素2, ...}
    int arr2[] = {1, 2, 3, 4, 5}; // 定义并初始化一个整型数组
    // 输出数组元素
    cout << "数组第一个元素为：" << arr2[0] << endl;
    cout << "数组第二个元素为：" << arr2[1] << endl;
    cout << "数组第三个元素为：" << arr2[2] << endl;
    cout << "数组第四个元素为：" << arr2[3] << endl;
    cout << "数组第五个元素为：" << arr2[4] << endl;

    return 0;
}   