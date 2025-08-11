#include "iostream"

using namespace std;

/*
 * 多态是C++面向对象三大特性之一
 *
 * 多态分为两类：
 * - 静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
 * - 动态多态: 派生类和虚函数实现运行时多态
 *
 * 静态多态和动态多态区别：
 * - 静态多态的函数地址早绑定  -  编译阶段确定函数地址
 * - 动态多态的函数地址晚绑定  -  运行阶段确定函数地址
 * 
 * 重写：函数返回值类型、函数名、参数列表、完全一致称为重写
 * 
 * 案例描述：
 *  - 分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类
 * 多态的优点：
 *  - 代码组织结构清晰
 *  - 可读性强
 *  - 利于前期和后期的扩展以及维护
 * 
 * 总结：C++开发提倡利用多态设计程序架构，因为多态优点很多
 */

class Calculator{
public:
    int m_num1;
    int m_num2;

    int getResult(string op) {
        if (op == "+") {
            return m_num1 + m_num2;
        } else if (op == "-") {
            return m_num1 - m_num2;
        } else if (op == "*") {
            return m_num1 * m_num2;
        } else if (op == "/") {
            return m_num1 / m_num2;
        } else {
            cout << "不支持的运算符" << endl;
            return 0;
        }
    }
};

void func1() {
    // 如果想扩展新的功能，需求修改源码
    // 在真是开发中提倡开闭原则
    // 开闭原则：对扩展进行开放，对修改进行关闭
    Calculator cal;
    cal.m_num1 = 10;
    cal.m_num2 = 5;
    cout << cal.m_num1 << " + " << cal.m_num2 << " = " << cal.getResult("+") << endl;
    cout << cal.m_num1 << " - " << cal.m_num2 << " = " << cal.getResult("-") << endl;
    cout << cal.m_num1 << " * " << cal.m_num2 << " = " << cal.getResult("*") << endl;
    cout << cal.m_num1 << " / " << cal.m_num2 << " = " << cal.getResult("/") << endl;
}

// 利用多态实现计算器
// 实现计算器的抽象类
class AbstractCalculator {
public:
    virtual int getResult() = 0;

    int m_num1;
    int m_num2;
};

class AddCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_num1 + m_num2;
    }
};

class SubCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_num1 - m_num2;
    }
};

class MulCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_num1 * m_num2;
    }
};

class DivCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_num1 / m_num2;
    }
};

void func2() {
    AbstractCalculator* calculator = new AddCalculator;
    calculator->m_num1 = 100;
    calculator->m_num2 = 100;

    cout << calculator->m_num1 << " + " << calculator->m_num2 << " = " << calculator->getResult() << endl;

    delete calculator;

    calculator = new SubCalculator;
    calculator->m_num1 = 100;
    calculator->m_num2 = 100;

    cout << calculator->m_num1 << " - " << calculator->m_num2 << " = " << calculator->getResult() << endl;

    delete calculator;

    calculator = new MulCalculator;
    calculator->m_num1 = 100;
    calculator->m_num2 = 100;

    cout << calculator->m_num1 << " * " << calculator->m_num2 << " = " << calculator->getResult() << endl;

    delete calculator;

    calculator = new DivCalculator;
    calculator->m_num1 = 100;
    calculator->m_num2 = 100;

    cout << calculator->m_num1 << " / " << calculator->m_num2 << " = " << calculator->getResult() << endl;

    delete calculator;
}

int main() {
    func1();
    cout << "------------------------" << endl;
    func2();

    return 0;
}