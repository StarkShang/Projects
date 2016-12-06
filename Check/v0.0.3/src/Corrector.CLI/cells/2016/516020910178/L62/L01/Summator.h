#include"Calculator.h"//包含头文件
class Summator:public Calculator//建立Subtractor 类public继承Calculator 类, 在类中新建void型Sub函数 
{
public:
	void Add(float num1, float num2);
};