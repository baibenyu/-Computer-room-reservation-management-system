#include"Manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->name = name;
	this->pwd = pwd;

	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.RoomId and ifs >> c.maxnum)
	{
		this->vCom.push_back(c);
	}
	cout << "当前机房的数量为: " << this->vCom.size() << endl;

	ifs.close();
}

void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败!" << endl;
		return;
	}

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.id and ifs >> s.name and ifs >> s.pwd)
	{
		vStu.push_back(s);
	}

	cout << "当前学生数量为:" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.empId and ifs >> t.name and ifs >> t.pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师人数为" << vTea.size() << endl;

	ifs.close();

	
}

void Manager::operMenu()
{
	cout << "欢迎尊贵的管理员:" << this->name << endl;
	cout << "请选择您的操作:1.添加账号 2.查看账号 3.查看机房 4.清空预约 0.注销登录" << endl;
}

bool Manager::checkRepeat(int id,int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->empId)
			{
				return true;
			}
		}
	}
	return false;
}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型:1.学生 2.老师" << endl;
	string filename;
	string tip;
	string errortip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip = "请输入学号: ";
		errortip = "学号重复,请重新输入:";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "请输入职工编号: ";
		errortip = "职工号重复,请重新输入:";
	}

	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}
	
	cout << "请输入姓名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功!" << endl;
	this->initVector();
	system("pause");
	system("cls");
	ofs.close();
}

void printStudent(Student& s)
{
	cout << "学号:" << s.id << " 姓名:" << s.name << " 密码:" << s.pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "学号:" << t.empId << " 姓名:" << t.name << " 密码:" << t.pwd << endl;
}

void Manager::showPerson()
{
	cout << "请选择查看内容:1.所有学生 2.所有老师" << endl;
	int select = 0;
	cin >> select;
	cout << "信息如下:" << endl;
	if (select == 1)
	{
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "机房信息如下:" << endl;
	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++)
	{
		cout << "机房编号: " << it->RoomId << "机房最大容量: " << it->maxnum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE,ios::trunc);
	ofs.close();

	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}

