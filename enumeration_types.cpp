#include "iostream"

using namespace std;

/*
 * enum 枚举类型名称{
 * 枚举元素,
 * 枚举元素,
 * ...,
 * ...,  
 * }
 */

int main(){
    // 询问喜欢的颜色
    enum Color {
        RED,
        YELLOW,
        BLUE,
    };

    int num;
    cout << "你喜欢什么颜色？0:红色 1:黄色 2:蓝色";
    cin >> num;

    switch (num) {
        case RED:
            cout << "你喜欢红色！" << endl;
            break;
        case YELLOW:
            cout << "你喜欢黄色！" << endl;
            break;
        case BLUE:
            cout << "你喜欢蓝色！" << endl;
            break;
        default:
            cout << "你输入的颜色不在范围内！" << endl;
            break;
    }

    return 0;
}