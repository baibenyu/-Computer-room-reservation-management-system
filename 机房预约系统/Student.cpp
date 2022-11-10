#include "Student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->id = id;
	this->name = name;
	this->pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.RoomId and ifs >> c.maxnum)
	{
		this->vCom.push_back(c);
	}

	ifs.close();
}

void Student::operMenu()
{
	cout << "欢迎学生代表:" << this->name << endl;
	cout << "请选择您的操作:1.申请机房 2.我的预约 3.所有预约 4.取消预约 0.注销登录" << endl;
}

void Student::applyOrder()
{
	cout << "机房开放时间为周一到周五!" << endl;
	cout << "请输入申请预约的时间:1.周一 2.周二 3.周三 4.周四 5.周五" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	
	while (true)
	{
		cin >> date;
		if (date >= 1 and date <= 5)
		{
			break;
		}
		cout << "输入值必须为在1-5之间的整数,请重新输入!" << endl;
	}

	cout << "请输入申请的时间段:1.上午 2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 and interval <= 2)
		{
			break;
		}
		cout << "输入值必须为在1-2之间的整数,请重新输入!" << endl;
	}

	cout << "请选择机房:" << endl;
	cout << "1号机房容量:" << vCom[0].maxnum << endl;
	cout << "2号机房容量:" << vCom[1].maxnum << endl;
	cout << "3号机房容量:" << vCom[2].maxnum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 and room <= 3)
		{
			break;
		}
		cout << "输入值必须为在1-3之间的整数,请重新输入!" << endl;
	}

	cout << "预约成功!进入审核阶段..." << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->id << " ";
	ofs << "stuName:" << this->name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder()
{
	OrderFile of;
	if (of.size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		if (atoi(of.orderData[i]["stuId"].c_str()) == this->id)
		{
			cout << "预约日期:周" << of.orderData[i]["date"];
			cout << "时段:" << (of.orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房:" << of.orderData[i]["roomId"];
			string status = "状态";

			if (of.orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.orderData[i]["status"] == "2")
			{
				status += "预约通过";
			}
			else if(of.orderData[i]["status"] == "-1")
			{
				status += "审核未通过,预约失败";
			}
			else
			{
				status += "预约取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{

}

void Student::cancelOrder()
{

}