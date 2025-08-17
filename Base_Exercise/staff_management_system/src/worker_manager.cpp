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
    /* 测试 */
    // int num = this -> getStaffNum();
    // cout << "当前职工人数：" << num << endl;
    // this -> m_staff_num = num;

    // this -> m_staff_array = new Worker *[this->m_staff_num];
    // initStaff();
	// for (int i = 0; i < m_staff_num; i++)
	// {
	// 	cout << "职工号：" << this -> m_staff_array[i] -> m_id
	// 		 << " 职工姓名：" << this -> m_staff_array[i] -> m_name
	// 		 << " 部门编号：" << this -> m_staff_array[i] -> m_department_id << endl;
	// }
    // 文件名不存在
    // ifstream ifs;

    // ifs.open(FILENAME, ios::in);

    // if (!ifs.is_open()) {
    //     cout << "文件不存在！" << endl;
    //     this -> m_staff_num = 0;
    //     this -> m_staff_array = nullptr;
    //     this -> m_file_is_empty = true;
    //     ifs.close();
    //     return;
    // }

    // // 文件存在，但没有记录
    // char ch;
    // ifs >> ch;
    // if (ifs.eof()) {
    //     cout << "文件为空!" << endl;
    //     this -> m_staff_num = 0;
    //     this -> m_staff_array = nullptr;
    //     this -> m_file_is_empty = true;
    //     ifs.close();
    //     return;
    // }

    /* 构造函数内容 */
    int num = this -> getStaffNum();
    this -> m_staff_num = num;
    this -> m_staff_array = new Worker *[this->m_staff_num];
    initStaff();
    // 文件名不存在
    ifstream ifs;

    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open()) {
        this -> m_staff_num = 0;
        this -> m_staff_array = nullptr;
        this -> m_file_is_empty = true;
        ifs.close();
        return;
    }

    // 文件存在，但没有记录
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        this -> m_staff_num = 0;
        this -> m_staff_array = nullptr;
        this -> m_file_is_empty = true;
        ifs.close();
        return;
    }
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

void WorkerManager::addStaff() {
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

	int new_size = this -> m_staff_num + add_num;
	Worker** new_space = new Worker* [new_size];

    if (this -> m_staff_array != nullptr) {
        for (int i = 0; i < this -> m_staff_num; i++) {
            new_space[i] = this -> m_staff_array[i];
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
        cout << "3、总裁" << endl;
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
        new_space[this -> m_staff_num + i] = worker;
    }

    if (this -> m_staff_array != nullptr) {
        delete[] this -> m_staff_array;
    }

    this -> m_staff_array = new_space;

    this -> m_staff_num = new_size;

    this->m_file_is_empty = false;

    this -> saveFile();
    cout << "成功添加" << add_num << "名新职工！" << endl;
    cout << "按任意键继续...";
    cin.ignore();
    cin.get();
    this -> safeClearScreen();
}

int WorkerManager::getStaffNum() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int d_id;
    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> d_id) {
        num++;
    }

    ifs.close();

    return num;
}

void WorkerManager::initStaff() {
    ifstream ifs;
	ifs.open(FILENAME, ios::in);

    int id;
	string name;
	int d_id;

    int index = 0;

    while (ifs >> id && ifs >> name && ifs >> d_id) {
        Worker* worker = nullptr;

        if (d_id == 1) {
            worker = new Employee(id, name, d_id);
        } else if (d_id == 2) {
            worker = new Manager(id, name, d_id);
        } else if (d_id == 3) {
            worker = new Boss(id, name, d_id);
        }

        this -> m_staff_array[index] = worker;
        index++;
    }

    ifs.close();
}

void WorkerManager::showStaff() {
    if (this -> m_file_is_empty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_staff_num; i++)
		{
			this -> m_staff_array[i] -> showInfo();
		}
	}

    cout << "按任意键继续...";
    cin.ignore();
    cin.get();
    this -> safeClearScreen();	
}

void WorkerManager::delStaff() {
	if (this -> m_file_is_empty)
	{
		cout << "文件不存在或记录为空！" << endl;
    } else {
        cout << "请输入想要删除的职工号：" << endl;
        int id = 0;
        cin >> id;

        int index = this -> isExist(id);

        if (index != -1) {
            for (int i = index; i < this -> m_staff_num - 1; i++) {
                this -> m_staff_array[i] = this -> m_staff_array[i + 1];
            }
            this -> m_staff_num--;

            cout << "删除成功！" << endl;
            this -> saveFile();

            if (this -> m_staff_num == 0) {
                delete[] this -> m_staff_array;
                this -> m_staff_array = nullptr;
                this -> m_file_is_empty = true;
                cout << "职工信息已经被清理完！" << endl;
            }
        } else {
            cout << "删除失败，未找到该职工" << endl;
        }
    }
    cout << "按任意键继续...";
    cin.ignore();
    cin.get();
    this -> safeClearScreen();
}

void WorkerManager::modStaff() {
    if (this -> m_file_is_empty)
	{
		cout << "文件不存在或记录为空！" << endl;
	} else {
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;

        int res = this -> isExist(id);
        if (res != -1) {
            delete this -> m_staff_array[res];
            int new_id = 0;
            string new_name = "";
            int new_did = 0;

            cout << "查到：" << res + 1 << "号职工，请输入新职工号：" << endl;
            while (!(cin >> new_id)) {
                cout << "输入有误！请重新输入" << res << "号职工的新职工号：";
                cin.clear();
                cin.ignore(1024, '\n');
            }

            cout << "请输入新职工姓名： " << endl;
            cin >> new_name;

            cout << "请输入岗位" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、总裁" << endl;
            cout << "请输入选择（1-3）：";			
            while (!(cin >> new_did) || new_did < 1 || new_did > 3) {
                if (cin.fail()) {
                    cout << "输入有误，请重新选择岗位（1-3）：";
                    cin.clear();
                    cin.ignore(1024, '\n');
                } else {
                    cout << "选择无效，请输入1-3之间的数字：";
                }
            }

            Worker* worker = nullptr;
            switch (new_did) {
                case 1:
                    worker = new Employee(new_id, new_name, new_did);
                    break;
                case 2:
                    worker = new Manager(new_id, new_name, new_did);
                    break;
                case 3:
                    worker = new Boss(new_id, new_name, new_did);
                    break;
                default:
                    cout << "岗位选择错误！默认为普通职工。" << endl;
                    worker = new Employee(new_id, new_name, new_did);
                    break;
            }
            this -> m_staff_array[res] = worker;
            cout << "修改成功！" << endl;
            this -> saveFile();
        } else {
            cout << "修改失败，查无此人！" << endl;
        }
    }
    cout << "按任意键继续...";
    cin.ignore();
    cin.get();
    this -> safeClearScreen();	
}

void WorkerManager::findStaff() {
    if (this -> m_file_is_empty)
	{
		cout << "文件不存在或记录为空！" << endl;
	} else {
        int select = 0;
        cout << "请输入查找的方式" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;
        cout << "请输入您的选择：";
        while (!(cin >> select) || select < 1 || select > 2) {
            if (cin.fail()) {
                cout << "输入有误，请重新选择查找的方式（1-2）：";
                cin.clear();
                cin.ignore(1024, '\n');
            } else {
                cout << "选择无效，请输入1-2之间的数字：";
            }
        }

        if (select == 1) {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            while (!(cin >> id)) {
                cout << "输入有误！请重新输入职工编号：" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
            }
            int res = isExist(id);
            if (res!= -1) {
                cout << "查找成功！该职工信息如下：" << endl;
                this -> m_staff_array[res] -> showInfo();
            } else {
                cout << "查找失败，查无此人" << endl;
            }
        } else if (select == 2) {
            string name;
            cout << "请输入查找的姓名：" << endl;
            cin >> name;

            bool flag = false;
            for (int i = 0; i < m_staff_num; i++) {
                if (m_staff_array[i] -> m_name == name) {
                    cout << "查找成功,职工编号为：" << m_staff_array[i] -> m_id  << " 号的信息如下：" << endl;
                    flag = true;
                    this -> m_staff_array[i] -> showInfo();
                }
            }
            if (!flag) {
                cout << "查找失败，查无此人" << endl;
            }
        }
    }
    cout << "按任意键继续...";
    cin.ignore();
    cin.get();
    this -> safeClearScreen();	
}

void WorkerManager::sortStaff() {
    if (this -> m_file_is_empty) {
        cout << "文件不存在或记录为空！" << endl;
    } else {
        int select = 0;
        cout << "请选择排序方式 " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;
        cout << "请输入您的选择：";
        while (!(cin >> select) || select < 1 || select > 2) {
            if (cin.fail()) {
                cout << "输入有误，请重新选择排序方式（1-2）：";
                cin.clear();
                cin.ignore(1024, '\n');
            } else {
                cout << "选择无效，请输入1-2之间的数字：";
            }
        }

        for (int i = 0; i < m_staff_num; i++) {
            int min_or_max = i;
            for (int j = i + 1; j < m_staff_num; j++) {
                if (select == 1) {
                    if (m_staff_array[min_or_max] -> m_id > m_staff_array[j] -> m_id) {
                        min_or_max = j;
                    }
                } else if (select == 2) {
                    if (m_staff_array[min_or_max] -> m_id < m_staff_array[j] -> m_id) {
                        min_or_max = j;
                    }
                }
            }
            if (i != min_or_max) {
                Worker * temp = m_staff_array[i];
                m_staff_array[i] = m_staff_array[min_or_max];
                m_staff_array[min_or_max] = temp;
            }
        }
        cout << "排序成功，排序后结果为：" << endl;
        this -> saveFile();
        this -> showStaff();
    }
}

int WorkerManager::isExist(int id) {
    int index = -1;

    for (int i = 0; i < this -> m_staff_num; i++) {
        if (this -> m_staff_array[i] -> m_id == id) {
            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager::saveFile() {
    /*  功能描述：对文件进行读写
     *  - 文件管理类中需要一个与文件进行交互的功能，对于文件进行读写操作
     */
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    if(!ofs.is_open()) {
        this -> safeClearScreen();
        cout << "文件打开失败！" << endl;
        cout << "按任意键继续...";
        cin.get();
        this -> safeClearScreen();
        return;
    }

    for (int i = 0; i < this -> m_staff_num; i++) {
        Worker* worker = this -> m_staff_array[i];
        ofs << worker -> m_id << " "
            << worker -> m_name << " "
            << worker -> m_department_id << endl;
    }
    ofs.close();
}

void WorkerManager::cleanFile() {
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
	cout << "2、返回" << endl;
    cout << "请输入您的选择：";
    int select = 0;
    while (!(cin >> select) || select < 1 || select > 2) {
        if (cin.fail()) {
            cout << "输入有误，请重新选择排序方式（1-2）：";
            cin.clear();
            cin.ignore(1024, '\n');
        } else {
            cout << "选择无效，请输入1-2之间的数字：";
        }
    }

    if (this -> m_file_is_empty) {
        cout << "文件不存在或记录为空！" << endl;
        cout << "按任意键继续...";
        cin.ignore();
        cin.get();
        this -> safeClearScreen();
        return;
    }

    if (select == 1) {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this -> m_staff_array != nullptr) {
            for (int i = 0; i < this -> m_staff_num; i++) {
                delete this -> m_staff_array[i];
            }
            this -> m_staff_num= 0;
            delete[] this -> m_staff_array;
            this -> m_staff_array = nullptr;
            this -> m_file_is_empty = true;
        }
        cout << "清空成功！" << endl;
        cout << "按任意键继续...";
        cin.ignore();
        cin.get();
        this -> safeClearScreen();
        } else if (select == 2) {
        this -> safeClearScreen();
        return;
    }
}

WorkerManager::~WorkerManager() {
	if (this -> m_staff_array != nullptr) {
        for (int i = 0; i < m_staff_num; i++) {
            delete this -> m_staff_array[i];
           this -> m_staff_array[i] = nullptr;
        }
	}
    delete[] this -> m_staff_array;
    this -> m_staff_array = nullptr;
}