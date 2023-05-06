#pragma once //防止头文件重复
#include <iostream>
#include "worker.h"
using namespace std;
//引入文件
#include <fstream>
//创建文件常量
#define FILENAME "empfile.txt"

class workManager{
public:
	workManager();

	//展示菜单函数
	void showmenu();

	//退出系统
	void exitWM();

	//添加职工函数
	void Add_Emp();

	//保存文件 
	void save();

	//记录当前文件中的人数
	int get_EmpNum();

	//2、显示职工
	void show_Emp();
	//3、删除职工
	void delete_Emp();
	//判断职工是否存在i
	int isExist(int id);
	//4、修改职工
	void fix_Emp();
	//5、查找职工
	void find_Emp();
	//6、员工排序功能
	void Sort_Emp();
	//7、清空文件
	void clean();

	//记录文件中的人数
	int m_EmpNum;
	//员工数组的指针
	worker ** m_EmpArray;

	//标志文件是否为空
	bool FileIsEmpty;

	~workManager();

};