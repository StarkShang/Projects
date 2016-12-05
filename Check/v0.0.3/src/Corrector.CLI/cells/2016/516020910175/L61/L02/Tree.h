class Tree//声明树类，成员变量为树龄，成员函数为构造，成长，显示树龄
{
private:
	int age;
public:
	Tree(int age);
	void Grow(int years);
	int ShowAge();
};