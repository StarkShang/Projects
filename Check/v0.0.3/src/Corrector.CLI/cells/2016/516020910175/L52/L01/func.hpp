#include<string.h>
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int i,j,k,m=0,len1=strlen(num1),len2=strlen(num2);//i,j,kΪѭ��������m��¼�Ƿ��λ
	if(strlen(num1)<strlen(num2))//���num1����С��num2������ָ���ֵ
	{
		char* x=num1;
		num1=num2;
		num2=x;
	}
	*(buffer+bufferLen-1)='\0';//��Buffer��ĩλΪ���ַ�
	for(i=len1-1,j=len2-1,k=bufferLen-2;j>=0;i--,j--,k--)//��ĩλ��ʼ��λ���
	{
		*(buffer+k)=*(num1+i)+*(num2+j)+m-48;
		if(*(num1+i)+*(num2+j)+m-48>'9') {m=1,*(buffer+k)-=10;}//������10��m��¼��λ���ַ�ֵ��10
		else m=0;
	}
	for(;i>=0;i--,k--)//���Ͻϳ��ַ�������λ
	{
		*(buffer+k)=*(num1+i)+m;
		if(*(num1+i)+m>'9') {m=1,*(buffer+k)-=10;}//�жϽ�λ����Ӧ�ı��ַ���ֵ
		else m=0;
	}
	if(m==0) buffer+=bufferLen-len1-1;
	else
	{
		*(buffer+k)='1';
		buffer+=bufferLen-len1-2;
	}//�ж����λ�Ƿ��λ���ֱ��ƶ�bufferָ�뵽��������λ

	return buffer;
}