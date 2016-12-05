#include <iostream>
#include "Calculator.h"
class Subtractor :public Calculator                                  //定义subtractor类并引用calculator类
{
public:
	void Sub(float num1, float num2); 
};