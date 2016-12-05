#pragma once
#include "Person.h"

class Teacher:public Person
{
public:
   int TeacherID;//定义老师ID
   char Title[1024];//定义老师职称

};