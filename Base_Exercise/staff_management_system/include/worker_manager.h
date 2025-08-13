#pragma once

#include<iostream>

using namespace std;

class WorkerManager {
public:
	//构造函数
	WorkerManager();

	void showMenu();
	void exitSystem();
	void safeClearScreen();

	//析构函数
	~WorkerManager();

};