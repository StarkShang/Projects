class Tree
{
private:
	int age;
	int years;
public:
	Tree(int age=15);                  //初始化年龄为15岁
	void Grow(int years=5);            //初始化成长了5年
	int ShowAge();
};