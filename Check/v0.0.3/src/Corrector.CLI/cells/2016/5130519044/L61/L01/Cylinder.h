class Cylinder
{
private:
	double len;
	double r;
public:
	Cylinder(double len, double r):len(len),r(r){} 
	//����һ���вεĹ��캯�����������ó�ʼ��������ݳ�Ա��ʼ��
	double Area();
	double Volume();
};