#pragma once
#include "Person.h"
using namespace std;

class Teacher:public Person
{public:
    int TeacherID;  //派生类新增加的工号、职称成员
    char* Title;
};