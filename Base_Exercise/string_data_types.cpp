#include "iostream"

using namespace std;

int main(){
    // C语言风格的字符串
    char s1[] = "hello world";
    char *s2 = "hello world";

    // C++语言风格的字符串
    string s3 = "hello world";

    // 修改字符串内容,赋值语句修改不了s1
    // s1 = "666"; // 错误，s1是数组名，不能被赋值
    s2 = "666";
    s3 = "666";

    cout << "C语言风格的字符串: " << s1 << endl;
    cout << "C语言风格的字符串指针: " << s2 << endl;
    cout << "C++语言风格的字符串: " << s3 << endl;
    
    return 0;
}   