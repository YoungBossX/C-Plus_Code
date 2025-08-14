#include "boss.h"

Boss::Boss(int id, string name, int d_id) {
    this -> m_id = id;
    this -> m_name = name;
    this -> m_department_id = d_id;
}

void Boss::showInfo() {
    cout << "职工编号: " << this->m_id;
    cout << "\t职工姓名: " << this->m_name;
    cout << "\t职工部门: " << this->getDeptName();
    cout << "\t岗位职责：管理公司所有事务"  << endl;
}

string Boss::getDeptName() {
    return "老板";
}