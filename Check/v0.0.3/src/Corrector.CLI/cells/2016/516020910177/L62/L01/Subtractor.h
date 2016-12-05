#include"Calculator.h"
class Subtractor: public Calculator //建立 Subtractor 类 public 继承 Calculator 类
{
public:
    void Sub(float num1, float num2); //实现 num1 减去 num2 的功能
};