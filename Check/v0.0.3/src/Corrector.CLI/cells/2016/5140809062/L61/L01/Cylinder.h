class Cylinder//定义圆柱体类
{
private://其中内部有保护变量高度和半径
	double len;
	double r;
public://公开部分有构造函数，截面圆面积计算函数，体积函数
	Cylinder(double len, double r);
	double Area();
	double Volume();
};

