#include"Calculator.h";
float Calculator::GetResult()//在类外定义函数
{
	float a;//定义变量
	a=result;//获取protected的result的值
	return (a);//返回result的值
}