#include "iostream"

using namespace std;

/*
 * 运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
 *
 * 总结：重载左移运算符配合友元可以实现输出自定义数据类型
 * 
 */

class Person {
	friend ostream& operator<<(ostream& out, Person& p);

public:
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

    // 不会利用成员函数重载<<运算符，因为无法实现cout在左侧
	// 成员函数实现不了p << cout 不是我们想要的效果
	// void operator<<(Person& p){
	// }

private:
    int m_A;
    int m_B;
};

// 全局函数实现左移重载
// ostream对象只能有一个
// 本质 operator<<(cout，p) 简化 cout<<p
// 不设置返回值类型会报错，不能链式输出
ostream& operator<<(ostream& out, Person& p) {
	out << "a:" << p.m_A << endl;
    out << "b:" << p.m_B << endl;
	return out;
}

void func() {

	Person p1(10, 20);

	cout << p1 << "hello world" << endl;
}

int main() {
    func();

    return 0;
}