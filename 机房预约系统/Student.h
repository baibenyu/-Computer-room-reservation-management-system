#pragma once
#include"Identity.h"
#include "orderFile.h"
#include "computerRoom.h"

class Student:public Identity
{
public:
	int id;
	vector<ComputerRoom>vCom;

	Student();
	Student(int id, string name, string pwd);
	virtual void operMenu();
	void applyOrder();
	void showMyOrder();
	void showAllOrder();
	void cancelOrder();


};