#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class boss:public worker{
public:
	//���캯�������ڳ�ʼ��
	boss(int id,string name,int did);
	//��ӡboss��Ϣ
	virtual void showinfo();
	//��ȡbossְλ
	virtual string getDeptName();
	
};