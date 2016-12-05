class Cylinder  //声明Cylinder类
{
private:
	double len; //高
	double r;  //半径
public:
	Cylinder(double len, double r); //声明带参数的构造函数
	double Area();  //声明计算表面积的函数
	double Volume(); //声明计算体积的函数
};