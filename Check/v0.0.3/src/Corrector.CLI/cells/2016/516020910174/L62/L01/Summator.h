#include <iostream>
#include "Calculator.h"
class Summator:public Calculator                                        //建立类函数summator并继承calculator
{
public:
	void Add(float num1, float num2);                          
};