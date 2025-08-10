#include "iostream"

using namespace std;

/*
 * 继承是面向对象三大特性之一
 *
 * 继承的语法：class 子类 : 继承方式  父类
 * 
 * 继承方式一共有三种：
 *      公共继承
 *      保护继承
 *      私有继承
 * 
 * 菱形继承概念：
 *  - 两个派生类继承同一个基类
 *  - 又有某个类同时继承者两个派生类
 *  - 这种继承被称为菱形继承，或者钻石继承
 * 
 * 菱形继承问题：
 *  - 产生二义性
 *  - 数据继承了两份，这份数据只需要一份就即可
 * 总结：
 *  - 菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
 *  - 利用虚继承可以解决菱形继承问题
 */

class Animal
{
public:
	int m_Age;
};

// 继承前加virtual关键字后，变为虚继承
// 此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal {};
class Tuo   : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void func1()
{
	SheepTuo st;
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 200;

    // 当菱形继承，两个父类拥有相同数据，需要加以作用域区分
    // 这份数据只要一份就即可，菱形继承导致数据有两份，资源浪费
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;
}

int main() {
    func1();

    return 0;
}