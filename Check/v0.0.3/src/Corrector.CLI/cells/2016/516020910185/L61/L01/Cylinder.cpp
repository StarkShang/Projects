void Cylinder::Cylinder(double Len, double R)//定义初始化重载函数
{
	Len = len;
	R = r;//赋初值
}
double Cylinder::Area()//类外定义成员函数
{
	double S;
	S = 2 * 3.14*Len*R + 3.14 * 2 * R*R;//计算表面积
	cout << S << endl;//调用成员函数输出表面积
	return 0;
}
double Cylinder::Volume()//类外定义成员函数
{
	double V;
	V = 3.14*R*R*Len;//计算体积
	cout << V << endl;//调用成员函数输出体积
	return 0;
}