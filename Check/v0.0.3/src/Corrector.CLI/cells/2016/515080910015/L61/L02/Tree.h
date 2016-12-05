class Tree //声明Tree类
{
private:
	int age;  //类成员变量树龄
public:
	Tree(int age); //声明带参数的构造函数
	void Grow(int years); //声明计算现在树龄的函数
	int ShowAge(); //声明显示现在树龄的函数
};