#pragma once
#include "Person.h"

class Student: public Person
{	
public:
	int  Class;
	int  StudentId;
	char  Major[1024];
};