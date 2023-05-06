#include <iostream>
using namespace std;
#include "manager.h"

//构造函数，将值传入
manager::manager(int id,string name,int did){
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}
//显示员工信息
void manager::showinfo(){
	cout << "员工编号: " << this->m_id 
		<< "\t员工姓名：" << this->m_name
		<< "\t员工部门：" << this->getDeptName()
		<<"\t岗位职责：上听领导话，下指使下属"
		<<endl;
} 
//获取员工部门
string manager::getDeptName(){
	return string("经理部");
}