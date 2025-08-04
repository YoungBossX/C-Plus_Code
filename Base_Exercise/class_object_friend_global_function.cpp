#include "iostream"

using namespace std;

/*
 * 在程序里，有些私有属性也想让类外特殊的某些函数或者类进行访问，就需要用到友元的技术
 *
 * 友元的目的是让一个函数或者类访问另一个类中私有成员
 *
 * 友元的关键字为 friend
 *
 * 友元的三种实现：
 * - 全局函数做友元
 * - 类做友元
 * - 成员函数做友元
 */

// 建筑物类
class Building{
    // 声明全局函数 func1 为友元函数，可以访问私有成员
    friend void func1(Building* building);

public:
    string m_sitting_room;

    Building() {
        m_sitting_room = "客厅";
        m_bed_room = "卧室";
    }

private:
    string m_bed_room; 
};

// 全局函数
void func1(Building* building) {
    cout << "全局函数正在访问：" << building->m_sitting_room << endl;
    cout << "全局函数正在访问：" << building->m_bed_room << endl;
}

void func2() {
    Building building;

    func1(&building);
}

int main() {
    func2();

    return 0;
}