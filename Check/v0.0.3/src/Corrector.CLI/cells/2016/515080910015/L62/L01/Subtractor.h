#include "Calculator.h"

class Subtractor:public Calculator//声明派生类Subtractor
{
public:
	void Sub(float num1,float num2);//派生类公用成员函数
};