class Cylinder
{
private:
	double len;
	double r;
public:
	Cylinder(double len, double r):len(len),r(r){} 
	//定义一个有参的构造函数，参数的用初始化表对数据成员初始化
	double Area();
	double Volume();
};