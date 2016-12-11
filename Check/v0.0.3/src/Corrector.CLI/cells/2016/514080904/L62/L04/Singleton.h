#pragma once
#include <iostream>

class Singleton
{
private:
	Singleton();
	~Singleton();
private:
	static Singleton* instance;
public:
	static Singleton* GetInstance();
};

