Tree::Tree(int age)//��ʼ����Ա
{
	this->age = age;//��ֵ
}
void Tree::Grow(int years)//�����Ա�������㵱ǰ������
{
	age += years;//����
}
int Tree::ShowAge()//�����Ա������ʾ��ǰ����
{
	return age;//��������ֵ
}