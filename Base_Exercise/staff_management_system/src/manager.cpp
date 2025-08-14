#include "manager.h"

Manager::Manager(int id, string name, int d_id) {
    this -> m_id = id;
    this -> m_name = name;
    this -> m_department_id = d_id;
}

void Manager::showInfo() {
    cout << "职工编号: " << this->m_id;
    cout << "\t职工姓名: " << this->m_name;
    cout << "\t职工部门: " << this->getDeptName();
    cout << "\t岗位职责：完成老板交给的任务，并下发任务给员工"  << endl;
}

string Manager::getDeptName() {
    return "经理";
}