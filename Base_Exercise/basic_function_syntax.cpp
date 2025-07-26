#include "iostream"

using namespace std;

/*
 * 返回值类型 函数名字(参数1类型 参数1名称, 参数2类型 参数2名称, ......., 参数N类型 参数N名称) 
 * {
 *      函数体;
 * 
 *      return 返回值; // 如果函数返回值类型不是void，则必须有return语句
 * }
 */

int get_max(int i, int j) {
    return (i > j) ? i : j;
}

int get_min(int i, int j, int k) {
    int min_value;
    if (i < j) {
        if (i < k) {
            min_value = i;
        } else {
            min_value = k;
        }
    } else {
        if (j < k) {
            min_value = j;
        } else {
            min_value = k;
        }
    }

    // return (i < j) ? ((i < k) ? i : k) : ((j < k) ? j : k);
    return min_value;
}

int main() {
    int a = 10;
    int b = 20;
    int max_value1 = get_max(a, b);

    cout << "最大值为：" << max_value1 << endl;

    int max_value2 = get_max(30, 40);
    cout << "最大值为：" << max_value2 << endl;

    int min_value = get_min(60, 20, 30);
    cout << "最小值为：" << min_value << endl;

    return 0;
}