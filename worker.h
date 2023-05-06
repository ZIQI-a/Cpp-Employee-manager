#pragma once
#include <iostream>
#include <string>
using namespace std;

class worker{
public:
	//显示个人信息函数
	virtual void showinfo() = 0;

	//获取岗位名称函数
	virtual string getDeptName() = 0;

	//创建职工编号姓名部门`
	int m_id;
	string m_name;
	int m_did;

};