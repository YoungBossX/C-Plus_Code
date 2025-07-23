#include "iostream"

using namespace std;

int main(){
    // 特点1：任意类型均可构建数组
    cout << "--------------------------特点1：任意类型均可构建数组--------------------------" << endl;
    float arr1[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char arr3[] = {'a', 'b', 1, 2, 3};
    string arr4[] = {"hello", "world", "XCC"};
    bool arr5[] = {true, 0, 1, true, false};
    enum Color {RED, GREEN, BLUE};
    Color arr6[] = {RED, GREEN, BLUE, RED, BLUE};

    cout << "float数组里第一个元素：" << arr1[0] << endl;
    cout << "double数组里第一个元素：" << arr2[0] << endl;
    cout << "char数组里第一个元素：" << arr3[0] << endl;
    cout << "string数组里第一个元素：" << arr4[0] << endl;
    cout << "bool数组里第一个元素：" << arr5[0] << endl;
    cout << "enum数组里第一个元素：" << arr6[0] << endl;
    cout << endl;

    // 特点2：固定大小（无边界检测）
    cout << "--------------------------特点2：固定大小（无边界检测）--------------------------" << endl;
    int arr7[] = {1, 2, 3, 4, 5};
    // cout << "访问arr7数组的10号下标" <<arr7[10] << endl;
    // arr7[100] = 100; // 访问越界的下标，未定义行为
    cout << endl;

    // 特点3：内存连续且有序，可通过 sizeof(数组) / sizeof(数组元素) 得到数组长度
    cout << "--------------------------特点3：内存连续且有序--------------------------" << endl;
    cout << "arr7数组的第一个元素是：" << arr7[0] << endl;
    cout << "arr7数组的第一个元素是：" << arr7[0] << endl;
    cout << "arr7数组的第一个元素是：" << arr7[0] << endl;
    cout << "arr7数组的总空间占用大小：" << sizeof(arr7) << "个字节" << endl;
    cout << "arr7数组的第一个元素空间占用的大小：" << sizeof(arr7[0]) << "个字节" << endl;
    cout << "arr7数组有几个元素：" << sizeof(arr7) / sizeof(arr7[0]) << endl;

    // 特点4：元素值可以修改
    cout << "--------------------------特点4：元素值可以修改--------------------------" << endl;
    int arr8[] = {1, 2, 3, 4, 5};
    arr8[0] = 10;
    arr8[1] = 20;
    cout << "修改后的arr8数组的第一个元素是：" << arr8[0] << endl;
    cout << "修改后的arr8数组的第二个元素是：" << arr8[1] << endl;
    cout << endl;

    // 特点5：数组变量本身不记录数据
    cout << "--------------------------特点5：数组变量本身不记录数据--------------------------" << endl;
    int arr9[] = {1, 2, 3, 4, 5};
    cout << "arr9的首地址：" << arr9 << endl;
    cout << "arr9的0号元素元素地址：" << &arr9[0] << endl;
    cout << "arr9的1号元素元素地址：" << arr9 + 1 << endl; // 1号元素的地址，加1表示偏移一个元素的大小
    cout << "arr9的1号元素元素地址：" << &arr9[1] << endl;
    cout << endl;

    return 0;
}   