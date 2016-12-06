#include"Calculator.h"//包含头文件
class Subtractor: public Calculator//建立Summator类 public继承Calculator类, 在类中新建 void 型函数Add(float num1, float num2)
{
public:
	void Sub(float num1, float num2);
};