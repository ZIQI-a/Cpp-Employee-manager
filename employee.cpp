#include <iostream>
#include "employee.h"
using namespace std;

employee::employee(int id,string name,int did){
	//��ʼ��Ա����������Ϣ����������
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;

}

void employee::showinfo(){
	cout << "Ա����ţ�" <<this->m_id
		<<"\tԱ��������" <<this->m_name
		<<"\tԱ�����ţ�" << this->getDeptName() 
		<< " \t��λְ������ϰ彻��������,���·������Ա��"
		<<endl;
}

string employee::getDeptName(){
	return string("���²�");
}