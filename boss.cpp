#include <iostream>
#include "boss.h"
using namespace std;

boss::boss(int id,string name,int did){
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}

void boss::showinfo(){
	cout << "Ա����ţ�" << this->m_id
		<< "\t������  " << this->m_name
		<< "\t���ţ�" << this->getDeptName()
		<< "\t��λְ�� ����˾��С����"
		<< endl;;
}

string boss::getDeptName(){
	return string("�ϰ岿");
}