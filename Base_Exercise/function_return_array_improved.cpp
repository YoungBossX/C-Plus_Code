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

// 参数1：被处理数组的指针
// 参数2：被处理数组的长度（必须）
void plus_one_in_arr(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        arr[i] += 1;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    plus_one_in_arr(arr, sizeof(arr) / sizeof(arr[0]));

    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}  