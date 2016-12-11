class Tree
{
private:
	int age;
public:
	Tree(int age):age(age){} //用参数初始化表初始化age
	void Grow(int years);
	int ShowAge();
};