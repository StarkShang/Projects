class Tree
{
private:
	int age;
public:
	Tree(int age);
	void Grow(int years);
	int ShowAge();
};
Tree::Tree(int age)//��������ĺ���
{this->age=age;//�����丳ֵ
}
void Tree::Grow(int years)//�������������ĺ���
{age=age+years;//�����������ʽ
}
int Tree::ShowAge()//������ʾ����ĺ���
{return age;//���������ֵ
}