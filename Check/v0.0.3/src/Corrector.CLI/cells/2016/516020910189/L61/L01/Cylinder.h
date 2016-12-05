class Cylinder  //声明Cylinder类
{
private:
	double len; //private成员变量len长度
	double r;   //private成员变量r半径
public:
	Cylinder(double len, double r);  //public构造函数，参数为长度与半径
	double Area(); //计算圆柱体表面积
	double Volume(); //计算圆柱体体积
};