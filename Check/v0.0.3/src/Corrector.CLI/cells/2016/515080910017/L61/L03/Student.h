#pragma once
#include "Person.h"

class Student:public Person
{	
public:
	char StudentId[1024];
	char Class[1024];
	char Major[1024];
}
