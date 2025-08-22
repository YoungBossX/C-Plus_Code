/*
 * 主要针对C++泛型编程和ST技术做详细讲解，探讨C++更深层的使用
 *
 * 模板的概念
 *  - 模板就是建立通用的模具，大大提高复用性
 * 
 * 模板的特点
 *  - 模板不可以直接使用，它只是一个框架
 *  - 模板的通用并不是万能的
 * 
 * 案例描述:  实现一个通用的数组类
 * 要求如下：
 *  - 可以对内置数据类型以及自定义数据类型的数据进行存储
 *  - 将数组中的数据存储到堆区
 *  - 构造函数中可以传入数组的容量
 *  - 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
 *  - 提供尾插法和尾删法对数组中的数据进行增加和删除
 *  - 可以通过下标的方式访问数组中的元素
 *  - 可以获取数组中当前元素个数和数组的容量 
 * 
 * 总结：
 *  - 能够利用所学知识点实现通用的数组
 */

#include "template_class_template_case_array_wrapper.hpp"

void func1() {
    MyArray<int> arr1(5);
    MyArray<int> arr2(arr1);
    MyArray<int> arr3(100);
    arr3 = arr1;
}

void printArray(MyArray<int>& arr) {
    for(int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void func2() {
    MyArray<int> arr1(5);

    for(int i = 0; i < 5; i++) {
        arr1.pushBack(i);
    }
    printArray(arr1);
    cout << "Current size: " << arr1.getSize() << endl;
    cout << "Current capacity: " << arr1.getCapacity() << endl;

    MyArray<int> arr2(arr1);
    printArray(arr2);
    arr2.popBack();
    cout << "After pushBack, arr2: ";
    printArray(arr2);
    cout << "Current size: " << arr2.getSize() << endl;
    cout << "Current capacity: " << arr2.getCapacity() << endl;
}

class Person{
public:
	string m_Name;
	int m_Age;

	Person() {};
	Person(string name, int age) {
	    this->m_Name = name;
		this->m_Age = age;
	}
};

void printPersonArray(MyArray<Person>& arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        cout << "Name: " << arr[i].m_Name << ", Age: " << arr[i].m_Age << endl;
    }
}

void func3() {
    MyArray<Person> arr(10);

   	Person p1("XCC", 26);
	Person p2("xcc", 20);
	Person p3("Xcc", 18);
	Person p4("XCc", 19);
	Person p5("xCC", 22);

    arr.pushBack(p1);
    arr.pushBack(p2);
    arr.pushBack(p3);
    arr.pushBack(p4);
    arr.pushBack(p5);

    printPersonArray(arr);

    cout << "Current size: " << arr.getSize() << endl;
    cout << "Current capacity: " << arr.getCapacity() << endl;
}

int main() {
    // func1();
    func2();
    func3();

    return 0;
}