#include <iostream>
#include "workManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;
#include <fstream>

//����Ա����̬
//void test() {
//	worker * worker = NULL;
//	worker = new employee(1, "����", 1);
//	worker->showinfo();
//	delete worker;
//
//	worker = new manager(2, "����", 2);
//	worker->showinfo();
//	delete worker;
//
//	worker = new boss(3, "����", 3);
//	worker->showinfo();
//	delete worker;
//}

int main(){

	workManager wm;
	while(1){
		//����һ����������������
		int choice = 0;
		wm.showmenu();
		cout << "����������Choose: " << endl;
		cin >> choice;

		switch(choice){
		case 0:
			wm.exitWM();
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.show_Emp();
			break;
		case 3:
			wm.delete_Emp();
			break;
		case 4:
			wm.fix_Emp();
			break;
		case 5:
			wm.find_Emp();
			break;
		case 6:
			wm.Sort_Emp();
			break;
		case 7:
			wm.clean();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}