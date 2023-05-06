#include "workManager.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
//引入文件
#include <fstream>
//创建文件常量
#define FILENAME "empfile.txt"



//主文件的构造函数
workManager::workManager(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in );

	//isopen判断函数是否为空
	if (!ifs.is_open()) {
		//cout << "文件不存在" << endl;
		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;
		
		this->FileIsEmpty = true;//初始化文件为空

		ifs.close();
		return;
	}

	//文件有，数据为空的情况下
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		
		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;
		
		this->FileIsEmpty = true;

		ifs.close();
		return;
	}

	int num = this->get_EmpNum();
	cout << "职工个数为： " << num << endl;
	this->m_EmpNum = num;
	
}
//主文件的析构函数
workManager::~workManager(){
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
	}
}

//展示菜单
void workManager::showmenu(){
	cout << "----------------------------------------------------------------"<<endl;
	cout << "----------------------------------------------------------------"<<endl;
	cout << "************Welcome to working dog Manager System !!************"<<endl;
	cout << "************please pause your choose~***************************"<<endl;
	cout << "----------------------------------------------------------------"<<endl;
	cout << "------------        0.滚                       -----------------"<<endl;
	cout << "------------        1.上人了上人               -----------------"<<endl;
	cout << "------------        2.来吧展示                 -----------------"<<endl;
	cout << "------------        3.消灭卧底                 -----------------"<<endl;
	cout << "------------        4.你皮欠了？               -----------------"<<endl;
	cout << "------------        5.FBI close the door       -----------------"<<endl;
	cout << "------------        6.给我站好滴        -----------------"<<endl;
	cout << "------------        7.毁灭模式                 -----------------"<<endl;
	cout << "----------------------------------------------------------------"<<endl;
	cout << "----------------------------------------------------------------"<<endl;
	cout <<endl;
}

//退出系统
void workManager::exitWM(){
	cout << "Go Away !! fuck you" <<endl;
	system("pause");
	exit(0);//不论属于何种状态全部退出
}

void workManager::Add_Emp() {
	cout << "请输入增加职工数量：" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {

		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		worker ** newSpace = new worker*[newSize];

		//将原空间下内容存放到新空间
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "请输入第 " << i+1 << "个员工的编号：" << endl;
			cin >> id;

			cout << "请输入第 " << i+1 << "个员工的姓名：" << endl;
			cin >> name;

			cout << "该员工是什么职位?" << endl;
			cout << "1、破事部普通职工" << endl;
			cout << "2、烂泥经理" << endl;
			cout << "3、唐孩子老板" << endl;
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
				cout << "输入的不对劲？" << endl;
				break;
			}
			newSpace[this->m_EmpNum + i] = work;
		}
		//释放原来空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新人数个数
		this->m_EmpNum = newSize;
		//提示信息
		cout << "恭喜你！成功添加 " << addNum << "个新员工 " << endl;

		//保存信息为文件
		this->save();

		//更改职工数量为真
		this->FileIsEmpty = false;
	}
	else {
		cout << "输入错误！普钙啊" << endl;
	}
	system("pause");
	system("cls");
}

//保存文件
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
	//读取源文件中的数据
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	//创建存放的变量
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

//2、显示职工功能
void workManager::show_Emp() {
	if (this->FileIsEmpty) {
		cout << "文件不存在或记录为空!" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i]->showinfo();
		}
	}

	system("pause");
	system("cls");
}

//3、删除职工
void workManager::delete_Emp() {
	if (this->FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入需要删除的员工编号" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);

		if (index == -1) {
			cout << "找不到这个人，无法删除" << endl;
		}
		else {
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功!" << endl;
		}

	}
	system("pause");
	system("cls");
}
//根据编号判断员工是否存在 不存在返回-1
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

//4、修改职工
void workManager::fix_Emp(){
	if (this->FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "输入修改信息的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "号员工，请输入新职工号：" << endl;
			cin >> newId;
			cout << "请输入姓名：" << endl;
			cin >> newName;
			cout << "请输入职位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			//更改数据到数组中
			this->m_EmpArray[ret] = work;

			cout << "修改成功" << endl;

			//保存到文件中
			this->save();
		}
		else {
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//5、查找职工
void workManager::find_Emp() {
	if (this->FileIsEmpty) {
		cout << "文件不存在或记录空" << endl;
	}
	else {
		cout << "请输入查找的方式：" << endl;
		cout << "1、编号" << endl;
		cout << "2、姓名" << endl;
		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "请输入编号：" << endl;
			int id;
			cin >> id;
			
			int ret = this->isExist(id);
			if (ret != -1) {
				cout << "查找成功！员工信息如下： " << endl;
				
				this->m_EmpArray[ret]->showinfo();

			}
		}
		else if (select == 2) {
			string name;
			cout << "请输入查找的姓名" << endl;
			cin >> name;

			bool flag = false;//标志是否查到了员工
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_name == name) {
					cout << "查找成功！员工"
						<< this->m_EmpArray[i]->m_id << "编号的信息为：" << endl;

					this->m_EmpArray[i]->showinfo();
					flag = true;
				}
			}

			if (flag == false) {
			
				cout << "/查不到这个人" << endl;
			}
		}
		else {
			cout << "输入错误" << endl;
		}
	}
	system("pause");
	system("cls");
}

//6、排序
void workManager::Sort_Emp() {
	if (this->FileIsEmpty) {
		cout << "查不到人或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序方式：" << endl;
		cout << "1、升序排序" << endl;
		cout << "2、降序排序" << endl;

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
					cout << "排序方式输入错误，重新输入!" << endl;
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
		cout << "排序完毕！结果如下：" << endl;
		this->save();
		this->show_Emp();
	}
}

//7、清除所有文件
void workManager::clean() {
	cout << "是否确定清空文件" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;
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

		cout << "数据已全部清空" << endl;
	}
	else if (select == 2) {
		system("cls");
		return;
	}
	else {
		cout << "输入错啦！笨比" << endl;
	}
	system("pause");
	system("cls");

}