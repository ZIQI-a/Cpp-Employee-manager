#include "workManager.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
//�����ļ�
#include <fstream>
//�����ļ�����
#define FILENAME "empfile.txt"



//���ļ��Ĺ��캯��
workManager::workManager(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in );

	//isopen�жϺ����Ƿ�Ϊ��
	if (!ifs.is_open()) {
		//cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;
		
		this->FileIsEmpty = true;//��ʼ���ļ�Ϊ��

		ifs.close();
		return;
	}

	//�ļ��У�����Ϊ�յ������
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		
		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;
		
		this->FileIsEmpty = true;

		ifs.close();
		return;
	}

	int num = this->get_EmpNum();
	cout << "ְ������Ϊ�� " << num << endl;
	this->m_EmpNum = num;
	
}
//���ļ�����������
workManager::~workManager(){
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
	}
}

//չʾ�˵�
void workManager::showmenu(){
	cout << "----------------------------------------------------------------"<<endl;
	cout << "----------------------------------------------------------------"<<endl;
	cout << "************Welcome to working dog Manager System !!************"<<endl;
	cout << "************please pause your choose~***************************"<<endl;
	cout << "----------------------------------------------------------------"<<endl;
	cout << "------------        0.��                       -----------------"<<endl;
	cout << "------------        1.����������               -----------------"<<endl;
	cout << "------------        2.����չʾ                 -----------------"<<endl;
	cout << "------------        3.�����Ե�                 -----------------"<<endl;
	cout << "------------        4.��ƤǷ�ˣ�               -----------------"<<endl;
	cout << "------------        5.FBI close the door       -----------------"<<endl;
	cout << "------------        6.����վ�õ�        -----------------"<<endl;
	cout << "------------        7.����ģʽ                 -----------------"<<endl;
	cout << "----------------------------------------------------------------"<<endl;
	cout << "----------------------------------------------------------------"<<endl;
	cout <<endl;
}

//�˳�ϵͳ
void workManager::exitWM(){
	cout << "Go Away !! fuck you" <<endl;
	system("pause");
	exit(0);//�������ں���״̬ȫ���˳�
}

void workManager::Add_Emp() {
	cout << "����������ְ��������" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {

		//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		worker ** newSpace = new worker*[newSize];

		//��ԭ�ռ������ݴ�ŵ��¿ռ�
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "������� " << i+1 << "��Ա���ı�ţ�" << endl;
			cin >> id;

			cout << "������� " << i+1 << "��Ա����������" << endl;
			cin >> name;

			cout << "��Ա����ʲôְλ?" << endl;
			cout << "1�����²���ְͨ��" << endl;
			cout << "2�����ྭ��" << endl;
			cout << "3���ƺ����ϰ�" << endl;
			cin >> dSelect;

			worker * work = NULL;
			switch (dSelect) {
			case 1:
				work = new employee(id, name, 1);
				break;
			case 2:
				work = new manager(id,name,2);
				break;
			case 3:
				work = new boss(id, name, 3);
				break;
			default:
				cout << "����Ĳ��Ծ���" << endl;
				break;
			}
			newSpace[this->m_EmpNum + i] = work;
		}
		//�ͷ�ԭ���ռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//������������
		this->m_EmpNum = newSize;
		//��ʾ��Ϣ
		cout << "��ϲ�㣡�ɹ���� " << addNum << "����Ա�� " << endl;

		//������ϢΪ�ļ�
		this->save();

		//����ְ������Ϊ��
		this->FileIsEmpty = false;
	}
	else {
		cout << "��������ոư�" << endl;
	}
	system("pause");
	system("cls");
}

//�����ļ�
void workManager::save() {
	ofstream ofs;
	ofs.open(FILENAME,ios::out);

	for (int i = 0; i < this->m_EmpNum;i++) {
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_did << endl;
	}
	ofs.close();
}

int workManager::get_EmpNum() {
	//��ȡԴ�ļ��е�����
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	//������ŵı���
	int id;
	string name;
	int DId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> DId) {
		num++;
	}

	ifs.close();
	return num;
}

//2����ʾְ������
void workManager::show_Emp() {
	if (this->FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i]->showinfo();
		}
	}

	system("pause");
	system("cls");
}

//3��ɾ��ְ��
void workManager::delete_Emp() {
	if (this->FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��������Ҫɾ����Ա�����" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);

		if (index == -1) {
			cout << "�Ҳ�������ˣ��޷�ɾ��" << endl;
		}
		else {
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�!" << endl;
		}

	}
	system("pause");
	system("cls");
}
//���ݱ���ж�Ա���Ƿ���� �����ڷ���-1
int workManager::isExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_id = id) {
			index = i;
			break;
		}
	}
	return index;
}

//4���޸�ְ��
void workManager::fix_Emp(){
	if (this->FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "�����޸���Ϣ�ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "��Ա������������ְ���ţ�" << endl;
			cin >> newId;
			cout << "������������" << endl;
			cin >> newName;
			cout << "������ְλ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			
			worker * work = NULL;
			switch (dSelect)
			{
			case 1:
				work = new employee(newId, newName, dSelect);
			case 2:
				work = new manager(newId, newName, dSelect);
			case 3:
				work = new boss(newId, newName, dSelect);
			default:
				break;
			}
			//�������ݵ�������
			this->m_EmpArray[ret] = work;

			cout << "�޸ĳɹ�" << endl;

			//���浽�ļ���
			this->save();
		}
		else {
			cout << "���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//5������ְ��
void workManager::find_Emp() {
	if (this->FileIsEmpty) {
		cout << "�ļ������ڻ��¼��" << endl;
	}
	else {
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1�����" << endl;
		cout << "2������" << endl;
		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "�������ţ�" << endl;
			int id;
			cin >> id;
			
			int ret = this->isExist(id);
			if (ret != -1) {
				cout << "���ҳɹ���Ա����Ϣ���£� " << endl;
				
				this->m_EmpArray[ret]->showinfo();

			}
		}
		else if (select == 2) {
			string name;
			cout << "��������ҵ�����" << endl;
			cin >> name;

			bool flag = false;//��־�Ƿ�鵽��Ա��
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_name == name) {
					cout << "���ҳɹ���Ա��"
						<< this->m_EmpArray[i]->m_id << "��ŵ���ϢΪ��" << endl;

					this->m_EmpArray[i]->showinfo();
					flag = true;
				}
			}

			if (flag == false) {
			
				cout << "/�鲻�������" << endl;
			}
		}
		else {
			cout << "�������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//6������
void workManager::Sort_Emp() {
	if (this->FileIsEmpty) {
		cout << "�鲻���˻��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ������ʽ��" << endl;
		cout << "1����������" << endl;
		cout << "2����������" << endl;

		int select;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++) {
			int minormax = i;
			for (int j = i+1; j < this->m_EmpNum; j++) {
				if (select == 1) {
					if (this->m_EmpArray[minormax]->m_id > this->m_EmpArray[j]->m_id) {
						minormax = j;
					}
				}
				else if (select == 2) {
					if (this->m_EmpArray[minormax]->m_id < this->m_EmpArray[j]->m_id) {
						minormax = j;
					}
				}
				else {
					cout << "����ʽ���������������!" << endl;
					system("cls");
					return;
				}
				if (i != minormax) {
					worker * temp = m_EmpArray[i];
					m_EmpArray[i] = m_EmpArray[minormax];
					m_EmpArray[minormax] = temp;
				}
			}
		}
		cout << "������ϣ�������£�" << endl;
		this->save();
		this->show_Emp();
	}
}

//7����������ļ�
void workManager::clean() {
	cout << "�Ƿ�ȷ������ļ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;

	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->FileIsEmpty = true;
		}

		cout << "������ȫ�����" << endl;
	}
	else if (select == 2) {
		system("cls");
		return;
	}
	else {
		cout << "�������������" << endl;
	}
	system("pause");
	system("cls");

}