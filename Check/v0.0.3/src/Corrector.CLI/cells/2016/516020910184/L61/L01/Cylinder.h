class Cylinder//定义类Cylinder包含private的高度len和半径r
{
private:
	double len;
	double r;
public://声明public类函数
	Cylinder(double len, double r);//带参数的构造函数
	double Area();//double型面积函数声明
	double Volume();//体积函数声明
};
