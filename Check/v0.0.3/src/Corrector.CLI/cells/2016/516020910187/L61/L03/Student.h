#pragma once
#include "Person.h"

class Student:public Person
{	
public:
	int StudentId;
	char Class[1024];
	char Major[1024];
};