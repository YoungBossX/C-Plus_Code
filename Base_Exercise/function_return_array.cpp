#include "iostream"

using namespace std;

/*
 * 函数返回数组，就是返回指针，要注意：
 * - 不可返回局部数组（在函数内创建的数组），如果要返回需要
 *      - static修饰
 *      - 动态内存创建（new[]，delete[]）
 *      - 返回全局（在函数外创建的对象）
 *
 * 不推荐函数返回数组，因为要手动delete，要么static一直占内存、要么全局变量
 * 推荐，在函数外创建好数组，传入函数（地址传递或引用传递）进行操作即可
 */

int* func1() {
    int arr[] = {1, 2, 3};
    return arr; 
}

int* func2() {
    static int arr[] = {1, 2, 3};
    return arr; 
}

int* func3() {
    int* arr = new int[3]{1, 2, 3};
    return arr; 
}

int arr[] = {1, 2, 3}; // 全局变量
int* func4() {
    return arr; // 错误：返回局部数组
}

int main() {
    // int* p1= func1();
    // for (int i = 0; i < 3; i++) {
    //     cout << p1[i] << " ";
    // }

    int* p2 = func2();
    for (int i = 0; i < 3; i++) {
        cout << p2[i] << " ";
    }
    
    int* p3 = func3();
    for (int i = 0; i < 3; i++) {
        cout << p3[i] << " ";
    }
    delete[] p3;

    int* p4 = func4();
    for (int i = 0; i < 3; i++) {
        cout << p4[i] << " ";
    }

    return 0;
}  