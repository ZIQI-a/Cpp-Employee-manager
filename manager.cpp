#include <iostream>
using namespace std;
#include "manager.h"

//���캯������ֵ����
manager::manager(int id,string name,int did){
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}
//��ʾԱ����Ϣ
void manager::showinfo(){
	cout << "Ա�����: " << this->m_id 
		<< "\tԱ��������" << this->m_name
		<< "\tԱ�����ţ�" << this->getDeptName()
		<<"\t��λְ�������쵼������ָʹ����"
		<<endl;
} 
//��ȡԱ������
string manager::getDeptName(){
	return string("����");
}