class Tree
{
private:
	int age;
public:
	Tree(int age);
	void Grow(int years);
	int ShowAge();
};
Tree::Tree(int age)//定义树龄的函数
{this->age=age;//给树龄赋值
}
void Tree::Grow(int years)//定义树龄增长的函数
{age=age+years;//树龄增长表达式
}
int Tree::ShowAge()//定义显示树龄的函数
{return age;//返回树龄的值
}