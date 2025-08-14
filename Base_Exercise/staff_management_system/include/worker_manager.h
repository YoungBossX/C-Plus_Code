#pragma once

#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

class WorkerManager {
public:
	// 记录文件中的人数个数
	int m_emp_num;
	// 员工数组的指针
	Worker** m_emp_array;

	// 构造函数
	WorkerManager();
	// 菜单显示
	void showMenu();
	void exitSystem();
	void safeClearScreen();
	// 增加职工
	void Add_Emp();

	// 析构函数
	~WorkerManager();

};