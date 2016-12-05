class Cylinder
{
private:
	double len;
	double r;
public:
	Cylinder(double len, double r);
	double Area();
	double Volume();
};
Cylinder::Cylinder(double len, double r)//圆柱底面半径和长度初始化
{this->len=len;//给圆柱长初始化
this->r=r;//给圆柱底面半径初始化
}
double Cylinder::Area()//定义求圆柱表面积的函数
{
return(r*r*3.14*2+2*3.14*r*len);//返回表面积的值

}
double Cylinder::Volume()//定义求圆柱体积的函数
{
return(r*r*3.14*len);//返回体积的值
}