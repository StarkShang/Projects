#include "Calculator.h"
class Summator :public Calculator//子类
{
public:
	void Add(float num1, float num2)//计算
	{
		result = num1 + num2;//结果赋值给result
	}
};