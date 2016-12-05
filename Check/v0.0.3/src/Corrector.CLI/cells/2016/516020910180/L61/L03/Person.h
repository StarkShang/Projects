#pragma once

class Person
{
private:
	char Name[1024];
	bool Gender;
	int Age;
public:
	Person(char*Name,bool Gender,int Age)
	{
		int i=0;
		while(Name[i]!='\0')
			this->Name[i]=Name[i];
		this->Gender=Gender;
		this->Age=Age;
	}
};