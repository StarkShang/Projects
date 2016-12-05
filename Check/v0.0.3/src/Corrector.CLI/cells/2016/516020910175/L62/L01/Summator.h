#include "Calculator.h"
class Summator:public Calculator//子类，增加两数求和函数
{
public:
	void Add(float num1, float num2);
};