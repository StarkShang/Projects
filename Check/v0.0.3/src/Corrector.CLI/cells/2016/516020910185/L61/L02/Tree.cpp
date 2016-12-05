Tree::Tree(int age)//初始化成员
{
	this->age = age;//赋值
}
void Tree::Grow(int years)//类外成员函数计算当前树龄龄
{
	age += years;//计算
}
int Tree::ShowAge()//类外成员函数显示当前树龄
{
	return age;//返回树龄值
}