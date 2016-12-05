#include "Calculator.h"
class Subtractor:public Calculator//子类，增加两数求差函数
{
public:
	void Sub(float num1, float num2);
};