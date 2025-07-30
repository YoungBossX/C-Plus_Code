#include "iostream" // 包含

using namespace std;

#define NUM 10 // 宏（包含符号常量）展开

/*
 * 编译流程：
 *
 * 1. 预处理
 *   处理源代码中的预处理指令，如宏展开、条件编译指令、包含头文件等
 *   g++ -E xxx.cpp -o xxx.i
 *
 * 2. 编译
 *   将预处理后的代码转换为汇编语言
 *   g++ -S xxx.i -o xxx.s
 *
 * 3. 汇编 
 *   将汇编代码，转换为机器码（01二进制）
 *   g++ -c xxx.s -o xxx.o
 *
 * 4. 链接
 *    将机器码文件和所需的其它库链接得到程序
 *    g++ xxx.o -o xxx.exe
*/

int main() {
    cout << "手动编译的演示！" << endl;
    cout << "宏定义的值为：" << NUM << endl;
    return 0;
}