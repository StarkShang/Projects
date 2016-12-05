class Tree
{
private:
	int age;     // 成员变量 树龄age
public:
	Tree(int age);           //用于初始化树龄
	void Grow(int years);    //用于计算成长相应年数后树树龄
	int ShowAge();          //输出现在的树龄
};