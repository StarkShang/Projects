void Cylinder::Cylinder(double Len, double R)//�����ʼ�����غ���
{
	Len = len;
	R = r;//����ֵ
}
double Cylinder::Area()//���ⶨ���Ա����
{
	double S;
	S = 2 * 3.14*Len*R + 3.14 * 2 * R*R;//��������
	cout << S << endl;//���ó�Ա������������
	return 0;
}
double Cylinder::Volume()//���ⶨ���Ա����
{
	double V;
	V = 3.14*R*R*Len;//�������
	cout << V << endl;//���ó�Ա����������
	return 0;
}