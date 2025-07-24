#include "iostream"

using namespace std;

/*
 * 指针进行加减运算是可以的
 * 
 * 每次加减n， 就是对内存地址进行 n* 类型大小 的加减操作
 * 如int类型指针，+1 是内存地址+4(字节)，因为int类型占用4字节大小
 */

int main() {
    int num1 = 10;
    int *p = &num1;

    cout << "指针变量p中记录的地址: " << p << endl;
    p++;
    cout << "指针变量p进行了+1后记录的地址: " << p << endl;

    double num2 = 10;
    double *p2 = &num2;
    cout << "指针变量p2中记录的地址: " << p2 << endl;
    p2++;
    cout << "指针变量p2进行了+1后记录的地址: " << p2 << endl;

    int arr[] = {1, 2, 3, 4, 5}; // 内存连续排列的，每个元素的地址差值是4个字节（int数组）
    int *arr_p = arr; // 指针记录了数组0下标元素的地址

    cout << "数组第一个元素是: " << *arr_p << endl;
    cout << "数组第一个元素是: " << arr[0] << endl;
    cout << "数组第二个元素是: " << *(arr_p + 1) << endl; // arr_p + 1 正好是内存地址+4字节，正好就是下一个元素的地方
    cout << "数组第二个元素是: " << arr[1] << endl;
    cout << "数组第三个元素是: " << *(arr_p + 2) << endl; // arr_p + 2 正好是内存地址+8字节，正好就是下一个元素的地方
    cout << "数组第三个元素是: " << arr[2] << endl;

    // 作业
    int v1[] = {1,2,3,4,5,6,7,8,9,10};
    char v2[] = {'a', 'b', 'c', 'd', 'e'};

    int* p1 = v1;

    for(int i = 0; i < sizeof(v1)/sizeof(v1[0]); ++i) {
        cout << "v1[" << i << "] = " << *(p1 + i) << endl;
    }

    cout << endl;

    char* p2_char = v2;

    for (int i = 0; i < sizeof(v2)/sizeof(v2[0]); ++i) {
        cout << "v2[" << i << "] = " << *(p2_char + i) << endl;
    }

    return 0;
}  