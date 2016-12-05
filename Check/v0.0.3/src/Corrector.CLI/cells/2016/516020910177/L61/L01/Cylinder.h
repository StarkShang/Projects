class Cylinder
{
private:
	double len;   //成员变量 长度len
	double r;     //成员变量  半径r
public: 
	Cylinder(double len, double r);   //初始化长度和半径
	double Area();               //计算Cylinder表面积
	double Volume();               //计算Cylinder体积
};