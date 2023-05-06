#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class manager : public worker{
public:
	//构造函数，将值传入
	manager(int id,string name,int did);
	//显示员工信息
	virtual void showinfo();
	//获取员工部门
	virtual string getDeptName();

};