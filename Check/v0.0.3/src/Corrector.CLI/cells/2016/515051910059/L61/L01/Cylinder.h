class Cylinder
{
private:
	double len;
	double r;
public:
	Cylinder(double len, double r);
	double Area();
	double Volume();
};
Cylinder::Cylinder(double len, double r)//Բ������뾶�ͳ��ȳ�ʼ��
{this->len=len;//��Բ������ʼ��
this->r=r;//��Բ������뾶��ʼ��
}
double Cylinder::Area()//������Բ��������ĺ���
{
return(r*r*3.14*2+2*3.14*r*len);//���ر������ֵ

}
double Cylinder::Volume()//������Բ������ĺ���
{
return(r*r*3.14*len);//���������ֵ
}