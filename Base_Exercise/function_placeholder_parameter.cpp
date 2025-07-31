#include "iostream"

using namespace std;

// 占位参数
// 返回值类型 函数名(数据类型) {}
void func(int a, int) {
    cout << "this is a func!" << endl;
}

int main() {
    func(1, 2);

    return 0;
}