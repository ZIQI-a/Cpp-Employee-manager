#pragma once //��ֹͷ�ļ��ظ�
#include <iostream>
#include "worker.h"
using namespace std;
//�����ļ�
#include <fstream>
//�����ļ�����
#define FILENAME "empfile.txt"

class workManager{
public:
	workManager();

	//չʾ�˵�����
	void showmenu();

	//�˳�ϵͳ
	void exitWM();

	//���ְ������
	void Add_Emp();

	//�����ļ� 
	void save();

	//��¼��ǰ�ļ��е�����
	int get_EmpNum();

	//2����ʾְ��
	void show_Emp();
	//3��ɾ��ְ��
	void delete_Emp();
	//�ж�ְ���Ƿ����i
	int isExist(int id);
	//4���޸�ְ��
	void fix_Emp();
	//5������ְ��
	void find_Emp();
	//6��Ա��������
	void Sort_Emp();
	//7������ļ�
	void clean();

	//��¼�ļ��е�����
	int m_EmpNum;
	//Ա�������ָ��
	worker ** m_EmpArray;

	//��־�ļ��Ƿ�Ϊ��
	bool FileIsEmpty;

	~workManager();

};