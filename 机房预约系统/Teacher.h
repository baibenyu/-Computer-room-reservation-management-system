#pragma once
#include"Identity.h"

class Teacher :public Identity
{
public:
	int empId;

	Teacher();
	Teacher(int empId, string name, string pwd);
	virtual void operMenu();
	void showAllOrder();
	void validOrder();
};