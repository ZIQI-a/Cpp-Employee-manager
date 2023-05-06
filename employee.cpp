#include <iostream>
#include "employee.h"
using namespace std;

employee::employee(int id,string name,int did){
	//初始化员工函数，信息传到函数中
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;

}

void employee::showinfo(){
	cout << "员工编号：" <<this->m_id
		<<"\t员工姓名：" <<this->m_name
		<<"\t员工部门：" << this->getDeptName() 
		<< " \t岗位职责：完成老板交给的任务,并下发任务给员工"
		<<endl;
}

string employee::getDeptName(){
	return string("破事部");
}