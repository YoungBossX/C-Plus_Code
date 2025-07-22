#include <iostream>
#include <random>

using namespace std;

/*
 * 获得一个随机数(1-10)，创建一个10元素的数组对象
 * 由用户进行键盘输入，提供数组10个元素的值
 * 使用for循环挨个取出数组的元素
 * 判断每个元素是否和随机数相等
 * 最终输出用户输入的10个数字中，猜对了几个
 */

int get_random_number(int min, int max) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(min, max);  

    int random_number = dis(gen);
    return random_number;
}

int main () {
    // 1.获得随机数
    int random_number = get_random_number(1, 10);
    cout << "随机数是: " << random_number << endl;
    
    // 2.需要用户输入10次数字，将内容存进数组中
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        cout << "请输入第 " << (i + 1) << " 个数字: ";
        cin >> arr[i];
    }
    
    // 3.判断数组每个元素是否和随机数相等
    int result = 0;
    for (int i = 0; i < 10; ++i) {
        if (arr[i] == random_number) {
            result++;
        }
    }

    cout << "用户猜对了 " << result << " 个数字。" << endl;
    
    return 0;
}