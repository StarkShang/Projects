class Cylinder                           //定义类
{
private:
	double len;                           //高度
	double r;                             //半径
public:
	Cylinder(double len, double r);
	double Area();                       //表面积
	double Volume();                     //体积
};