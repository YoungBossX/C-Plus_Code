#include "iostream"

using namespace std;

int main(){
    // ! 非运算符
    bool b1 = !(1 == 1);
    bool b2 = !(1 == 2);
    cout << "b1非运算符的结果：" << b1 << endl;
    cout << "b2非运算符的结果：" << b2 << endl;
    // && 与运算符，两个条件都要同时为true（真）,结果为真，否则只要有一个为false（假），结果就是假
    bool b3 = 1 == 1 && 2 == 2;
    bool b4 = 1 == 1 && 2 == 3;
    cout << "b3与运算符的结果：" << b3 << endl;
    cout << "b4与运算符的结果：" << b4 << endl;
    // || 或运算符，只要有一个为真，结果就是真
    bool b5 = 1 == 1 || 2 == 2;
    bool b6 = 1 == 1 || 2 == 3; 
    bool b7 = 1 == 2 || 2 == 3;
    cout << "b5或运算符的结果：" << b5 << endl;
    cout << "b6或运算符的结果：" << b6 << endl;
    cout << "b7或运算符的结果：" << b7 << endl;

    return 0;
}   