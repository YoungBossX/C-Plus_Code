#include "iostream"
#include "windows.h"

using namespace std;

/*
 * 求：一个新的结构（class）能够在内部封装：属性（变量）和行为（函数），作为整体体使用
 */

class AlarmClock // 设计图纸
{
public:
    // 封装属性
    double length_cm;  // 长度
    double width_cm;   // 宽度
    double height_cm;  // 高度

    // 封装行为：响铃和 say_hi
    void clock_ring(int freq, int duration)
    {
        // 给定的频率和给定的延时时间，发出声音
        Beep(freq, duration);
    }

    void say_hi() const
    {
        cout << "长度：" << length_cm << " cm, ";
        cout << "宽度：" << width_cm << " cm, ";
        cout << "高度：" << height_cm << " cm" << endl;
    }
};


int main() {
    AlarmClock my_clock1 = {10, 20, 30}; // 生成实体（基于类得到的实体，闹钟）
    cout << "闹钟的属性：" << endl;
    cout << "长度：" << my_clock1.length_cm << " cm, ";
    cout << "宽度：" << my_clock1.width_cm << " cm, ";
    cout << "高度：" << my_clock1.height_cm << " cm" << endl;

    my_clock1.clock_ring(1000, 1000);
    my_clock1.say_hi();

    AlarmClock my_clock2 = {20, 30, 40}; // 生成另一个实体
    cout << "闹钟的属性：" << endl;
    cout << "长度：" << my_clock2.length_cm << " cm, ";
    cout << "宽度：" << my_clock2.width_cm << " cm, ";
    cout << "高度：" << my_clock2.height_cm << " cm" << endl;

    my_clock2.clock_ring(2000, 1000);
    my_clock2.say_hi();

    AlarmClock my_clock3;
    my_clock3.clock_ring(3000, 1000);

    return 0;
}