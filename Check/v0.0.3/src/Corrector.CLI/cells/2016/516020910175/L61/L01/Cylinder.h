class Cylinder//声明Cylinder类
{
private://private内容为长度len与半径r
	double len;
	double r;
public://public内容为构造函数，求表面积函数与求体积函数
	Cylinder(double len, double r);
	double Area();
	double Volume();
};