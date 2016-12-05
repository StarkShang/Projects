#include "Cylinder.h"
 Cylinder::Cylinder(double len, double r)  //成员函数
 { 
	 this->len=len;      //对成员变量长len初始化
     this->r=r;            //对成员变量半径r初始化
 }
 double Cylinder::Area()    //成员函数
 {
	 double s;
	 s=2*3.14*r*len+3.14*r*r;  //计算 Cylinder表面积
	 return s;                  //返回表面积
 }
 double Cylinder::Volume()     //成员函数
 {
	 double v;
	 v=3.14*r*r*len;      //计算 Cylinder体积
	 return v;           //返回体积
 }