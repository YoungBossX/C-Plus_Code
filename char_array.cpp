#include "iostream"

using namespace std;

int main(){
    "hello"; // 底层就是字符数组
    char s[] = "hello"; // 底层也是字符数组，会额外添加一个\0作为最后一个元素，当作结束标记

    cout << s[0] << endl;
    cout << s[1] << endl;
    cout << s[2] << endl;
    cout << s[3] << endl;
    cout << s[4] << endl;
    cout << s[5] << endl;
    cout << sizeof(s) << endl;
    cout << endl;

    for (char i : s) {
        cout << i << endl;
    }
    cout << sizeof(s) << endl;

    return 0;
}