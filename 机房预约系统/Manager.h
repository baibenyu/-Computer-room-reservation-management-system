#pragma once
#include"Identity.h"
#include"Student.h"
#include "Teacher.h"
#include"computerRoom.h"

class Manager :public Identity
{
public:
	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom>vCom;

	Manager();
	Manager(string name, string pwd);
	virtual void operMenu();
	void addPerson();
	void showPerson();
	void showComputer();
	void cleanFile();
	bool checkRepeat(int id, int type);
	void initVector();
};