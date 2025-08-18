/*
 * 主要针对C++泛型编程和ST技术做详细讲解，探讨C++更深层的使用
 *
 * 函数模板
 *  - C++另一种编程思想称为泛型编程 ，主要利用的技术就是模板
 *  - C++提供两种模板机制：函数模板和类模板
 * 
 * 案例描述：
 *  - 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
 *  - 排序规则从大到小，排序算法为选择排序
 *  - 分别利用char数组和int数组进行测试
 */

#include <iostream>

using namespace std;

template<typename T>
void mySwap(T &a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySort(T arr[], int len){
    for (int i = 0; i < len; i++) {
        int max = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        mySwap(arr[i], arr[max]);
    }
}

template<typename T>
void printArray(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void func1()
{
	char charArr[] = "bdcfeagh";
	int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArray(charArr, num);
}

void func2() {
    int intArr[] = {5, 2, 9, 1, 5, 6};
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArray(intArr, num);
}

int main() {
    func1();
    func2();

    return 0;
}