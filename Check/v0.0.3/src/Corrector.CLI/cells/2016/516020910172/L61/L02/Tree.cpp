#include"Tree.h";//引入头文件类的声明
Tree::Tree(int age)//重载函数对age初始化
{
	this->age=age;
}
 void Tree::Grow(int years)//对成员变量age加上year
 {
	 age=age+years;//计算新的age
 }
 int Tree::ShowAge()//显示private内的age
 {
	 int a;
	 a=age;
	 return(a);
 }