#pragma once

class Person
{
public:
	Person(char Name[1024],bool Gender,int Age)
	{
	Name=Name;
	Gender=Gender;
    Age=Age;
	}
	~Person(){}
	char Name[1024];
	bool Gender;
	int Age;
};