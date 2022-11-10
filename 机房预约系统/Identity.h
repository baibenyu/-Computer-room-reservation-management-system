#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include"globalFile.h"
using namespace std;

class Identity
{
public:
	string name;
	string pwd;
	
	virtual void operMenu() = 0;

};