#include "iostream"

using namespace std;

void switch_num1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;

}

void switch_num2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 使用引用传递
// 这种方式可以直接交换变量的值，而不需要使用指针
void switch_num3(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    int num;
    cout << "请输入数字（1-3）：";
    cin >> num;

    switch(num) {
        case 1:
            switch_num1(x, y);
            cout << "x = " << x << ", y = " << y << endl;
            break;
        case 2:
            switch_num2(&x, &y);
            cout << "x = " << x << ", y = " << y << endl;
            break;
        case 3:
            switch_num3(x, y);
            cout << "x = " << x << ", y = " << y << endl;
            break;
        default:
            cout << "无效输入" << endl;
            break;
    }

    return 0;
}   