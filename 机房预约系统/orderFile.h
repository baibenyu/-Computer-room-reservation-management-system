#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include"globalFile.h"
using namespace std;

class OrderFile
{
public:
	int size;
	
	OrderFile();

	void updateOrder();

	map<int, map<string, string>>orderData;
};