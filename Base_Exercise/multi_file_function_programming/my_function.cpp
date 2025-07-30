#include "iostream"
#include "my_function.h"

using namespace std;

/*
 * C++ 在很多地方都是有  声明  实现  2个步骤
 * 变量：
 *   1. 声明（分配空间）    int x;
 *   2. 使用（设置值）      x = 10;
 *   快捷写法（声明和赋值一起写的）    int x = 10;
 *
 * 函数：
 *   1. 声明    int add(int x, int y);
 *   2. 使用    int add(int x, int y) { return x + y; }
 */

// 实现函数
void add(int x, int y) {
    cout << (x + y) << endl;
}