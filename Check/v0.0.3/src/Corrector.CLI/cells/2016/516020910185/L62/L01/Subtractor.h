#include "Calculator.h"
class Subtractor:public Calculator//子类
{
public:
	void Sub(float num1, float num2)//计算
	{
		result = num1-num2;//结果赋值给result
	}
};