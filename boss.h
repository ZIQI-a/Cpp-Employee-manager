#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class boss:public worker{
public:
	//构造函数，用于初始化
	boss(int id,string name,int did);
	//打印boss信息
	virtual void showinfo();
	//提取boss职位
	virtual string getDeptName();
	
};