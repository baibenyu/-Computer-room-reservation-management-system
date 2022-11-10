#pragma once
#include"Identity.h"
#include"Manager.h"
#include<string>

void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "申请机房" << endl;
			stu->applyOrder();
		}
		else if (select == 2)
		{
			cout << "查看预约情况" << endl;
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			cout << "取消预约" << endl;
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

void LoginIn(string filename, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在!" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号:" << endl;
		cin >> id;
	}
	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1)
	{
		int fId;
		string fName = "";
		string fPwd = "";
		while (ifs >> fId and ifs >> fName and ifs >> fPwd)
		{
			if (id == fId and name == fName and pwd == fPwd)
			{
				cout << "学生登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId and ifs >> fName and ifs >> fPwd)
		{
			if (id == fId and name == fName and pwd == fPwd)
			{
				cout << "教师登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				return;
			}
		}
	}
	else
	{
		string fName;
		string fPwd;
		while (ifs >> fName and ifs >> fPwd)
		{
			if (name == fName and pwd == fPwd)
			{
				cout << "管理员登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "用户名与密码不匹配,请重新输入!" << endl;
	system("pause");
	system("cls");
	return;
}



int main()
{
	int select = 0;
	while (true)
	{
		cout << "欢迎使用白羽的机房预约系统!" << endl;
		cout << "请选择您的身份!(1.学生代表 2.老师 3.管理员 0.退出)" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "感谢使用,再见!" << endl;
			exit(0);
			break;
		default:
			cout << "输入有误!请重新输入!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}