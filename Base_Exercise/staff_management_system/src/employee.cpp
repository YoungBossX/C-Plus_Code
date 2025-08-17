/* 
 * 普通员工类继承职工抽象类，并重写父类中纯虚函数
 * 
 */


#include "employee.h"

Employee::Employee(int id, string name, int d_id) {
    this->m_id = id;
    this->m_name = name;
    this->m_department_id = d_id;
}

void Employee::showInfo() {
    cout << "职工编号: " << this->m_id;
    cout << "\t职工姓名: " << this->m_name;
    cout << "\t岗位: " << this->getDeptName();
    cout << "\t岗位职责：完成经理交给的任务"  << endl;
}

string Employee::getDeptName() {
    return "普通员工";
}