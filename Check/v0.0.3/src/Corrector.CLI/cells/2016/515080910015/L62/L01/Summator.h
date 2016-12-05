#include "Calculator.h"
class Summator:public Calculator//声明派生类Summator
{
public:
	void Add(float num1,float num2);//派生类公用成员函数
};