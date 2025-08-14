/*
 * 创建管理类
 *
 * 管理类负责的内容如下：
 *  - 与用户的沟通菜单界面
 *  - 对职工增删改查的操作
 *  - 与文件的读写交互
 */

#include "worker_manager.h"

WorkerManager::WorkerManager() {
    this -> m_emp_num = 0;
	this -> m_emp_array = nullptr;
}

// 展示菜单
void WorkerManager::showMenu() {
    cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem() {
	cout << "欢迎下次使用！" << endl;
	exit(0);
}

void WorkerManager::safeClearScreen() {
    cout << "\033[2J\033[1;1H";
    cout.flush();
}

void WorkerManager::Add_Emp() {
	cout << "请输入添加职工的数量：";
	int add_num = 0;

    while (!(cin >> add_num) || add_num <= 0) {
        if (cin.fail()) {
            cout << "输入有误，请重新输入添加职工的数量：";
            cin.clear();
            cin.ignore(1024, '\n');
        } else if (add_num <= 0) {
            cout << "数量必须大于0，请重新输入：";
        }
    }

	int new_size = this->m_emp_num + add_num;
	Worker** new_space = new Worker* [new_size];

    if (this -> m_emp_array != nullptr) {
        for (int i = 0; i < this -> m_emp_num; i++) {
            new_space[i] = this -> m_emp_array[i];
        }
    }

	for (int i = 0; i < add_num; i++) {
		int id;
		string name;
		int department_id;
		
		cout << "请输入第" << i + 1 << "个新职工编号：";
        while (!(cin >> id)) {
            cout << "输入有误，请重新输入第" << i + 1 << "个新职工编号：";
            cin.clear();
            cin.ignore(1024, '\n');
        }

        cout << "请输入第" << i + 1 << "个新职工姓名：";
        cin >> name;

        cout << "请选择该职工的岗位：" << endl;
        cout << "1、普通职工" << endl;
        cout << "2、经理" << endl;
        cout << "3、老板" << endl;
        cout << "请输入选择（1-3）：";			
        while (!(cin >> department_id) || department_id < 1 || department_id > 3) {
            if (cin.fail()) {
                cout << "输入有误，请重新选择岗位（1-3）：";
                cin.clear();
                cin.ignore(1024, '\n');
            } else {
                cout << "选择无效，请输入1-3之间的数字：";
            }
        }

		Worker* worker = nullptr;

		switch(department_id) {
            case 1:
                worker = new Employee(id, name, department_id);
                break;
            case 2:
                worker = new Manager(id, name, department_id);
                break;
            case 3:
                worker = new Boss(id, name, department_id);
                break;
        }
        new_space[this -> m_emp_num + i] = worker;
    }

	delete[] this -> m_emp_array;

    this -> m_emp_array = new_space;

    this -> m_emp_num = new_size;

	cout << "成功添加" << add_num << "名新职工！" << endl;
}

WorkerManager::~WorkerManager() {
	if (this -> m_emp_array != nullptr) {
		delete[] this -> m_emp_array;
	}
}