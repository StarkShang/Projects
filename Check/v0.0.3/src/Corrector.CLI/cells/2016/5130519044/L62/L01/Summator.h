#include "Calculator.h"

class Summator:public Calculator
{
public:
	float num1;
	float num2;
	void Add(float num1,float num2);
	Summator():num1(num1),num2(num2){}
};