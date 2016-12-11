#include "Calculator.h"

class Subtractor:public Calculator
{
public:
	float num1;
	float num2;
	void Sub(float num1,float num2);
	Subtractor():num1(num1),num2(num2){}
};