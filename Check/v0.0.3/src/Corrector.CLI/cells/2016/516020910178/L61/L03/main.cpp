#include <iostream>
#include "Teacher.h"
#include "Student.h"

int main(int argc, char const *argv[])
{
	Teacher teacher;
	std::cout << "Define a teacher" << std::endl;
	// char* : Name[1024]
	std::cout << "\tname : ";
	std::cin >> teacher.Name;
	// bool : Gender (0 : female, 1 : male)
	std::cout << "\tgender : ";
	std::cin >> teacher.Gender;
	// int : Age
	std::cout << "\tage : ";
	std::cin >> teacher.Age;
	// int : Id
	std::cout << "\tteacher id : ";
	std::cin >> teacher.TeacherID;
	// char* : Title[1024]
	std::cout << "\ttitle : ";
	std::cin >> teacher.Title;

	Student student;
	std::cout << "Define a student" << std::endl;
	// char* : Name[1024]
	std::cout << "\tname : ";
	std::cin >> student.Name;
	// bool : Gender (0 : female, 1 : male)
	std::cout << "\tgender : ";
	std::cin >> student.Gender;
	// int : Age
	std::cout << "\tage : ";
	std::cin >> student.Age;
	// int : Age
	std::cout << "\tstudent id : ";
	std::cin >> student.StudentId;
	// int : Class[1024]
	std::cout << "\tclass : ";
	std::cin >> student.Class;
	// cgar* : Major[1024]
	std::cout << "\tmajor : ";
	std::cin >> student.Major;

	std::cout << "Teacher " << teacher.Name << " is " << teacher.Age << "year(s) old. ";
	std::cout << (teacher.Gender ? "His " : "Her ") << "teacher id is " << teacher.TeacherID << ", and "
			  << (teacher.Gender ? "his " : "her ") << "title is " << teacher.Title << "." << std::endl;
	std::cout << "Student " << student.Name << " is " << student.Age << "year(s) old. ";
	std::cout << (student.Gender ? "His " : "Her ") << "student id is " << student.StudentId << ", and "
			  << (student.Gender ? "his " : "her ") << "class is " << student.Class << "."
			  << (student.Gender ? "His " : "Her ") << "major is " << student.Major << "."<< std::endl;

	return 0;
}