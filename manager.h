#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class manager : public worker{
public:
	//���캯������ֵ����
	manager(int id,string name,int did);
	//��ʾԱ����Ϣ
	virtual void showinfo();
	//��ȡԱ������
	virtual string getDeptName();

};