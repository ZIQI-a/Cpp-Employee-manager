#include <iostream>
#include "boss.h"
using namespace std;

boss::boss(int id,string name,int did){
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}

void boss::showinfo(){
	cout << "员工编号：" << this->m_id
		<< "\t姓名：  " << this->m_name
		<< "\t部门：" << this->getDeptName()
		<< "\t岗位职责： 管理公司大小事务"
		<< endl;;
}

string boss::getDeptName(){
	return string("老板部");
}