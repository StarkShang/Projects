class Tree //声明Tree类
{
private:
	int age; //成员变量ages树龄
public:
	Tree(int age); //重载构造函数
	void Grow(int years); //对成员变量ages加上years
	int ShowAge(); //输出ages
};