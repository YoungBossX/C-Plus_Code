#pragma once

#include <iostream>
#include "fstream"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

// #define FILENAME "./data/emp_file.txt"
#define FILENAME "./Base_Exercise/staff_management_system/data/emp_file.txt"

class WorkerManager {
public:
	// 记录文件中的人数个数
	int m_staff_num;
	// 员工数组的指针
	Worker** m_staff_array;
	// 标志文件是否为空
	bool m_file_is_empty;

	// 构造函数
	WorkerManager();
	// 菜单显示
	void showMenu();
	void exitSystem();
	void safeClearScreen();
	// 增加职工
	void addStaff();
	// 统计人数
	int getStaffNum();
	// 初始化员工
	void initStaff();
	// 显示职工
	void showStaff();
	// 删除职工
	void delStaff();
	// 修改职工
	void modStaff();
	// 查找职工
	void findStaff();
	// 排序职工
	void sortStaff();
	// 按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
	int isExist(int id);
	// 保存文件
	void saveFile();
	// 清空文件
	void cleanFile();

	// 析构函数
	~WorkerManager();
};