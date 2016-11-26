#include<string.h>
#include<iostream>
using namespace std;
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int len1=strlen(num1);                          //ȡ�����ַ����ĳ���
	int len2=strlen(num2);
	char temp1[1024],temp2[1024],tempbuffer[1025];  //�����ַ����ĵ�λ����λ��ת
	int i,j;
	int nsum;                                       //ÿһλ��ӵĽ��
	int maxlen;
	int carrybit=0;                                 //carrybit�ж��Ƿ��λ����ʼΪ��

	j=0;
	for(i=len1-1;i>=0;i--) temp1[j++]=num1[i];      //�������ַ�����ת��ʹ�õ�λ���λ���룬�������
	temp1[j]='\0';
	j=0;
	for(i=len2-1;i>=0;i--) temp2[j++]=num2[i];
	temp2[j]='\0';

	if(len1<len2)                    //�������ַ����г����Ǹ��ĸ�λ��'0'����
	{
		maxlen=len2;
		for(i=len1;i<len2;i++) temp1[i]='0';
		temp1[len2]='\0';
	}
	else if(len1>len2)
	{
		maxlen=len1;
		for(i=len2;i<len1;i++) temp2[i]='0';
		temp2[len1]='\0';
	}
	else maxlen=len1;

	for(i=0;i<maxlen;i++)            //��������ת���ַ������൱��ԭ���ĵ�λ����λ�������
	{
		nsum=temp1[i]-'0'+temp2[i]-'0'+carrybit;
		if(nsum>9)
		{
			carrybit=1;
			tempbuffer[i]=nsum-10+'0';
		}
		else
		{
			carrybit=0;
			tempbuffer[i]=nsum+'0';
		}
	}
	tempbuffer[i]='\0';
	if(carrybit==1)                   //�����λһλ�н�λ�����ټ�һλ1����ת�������������'\0'
	{
		tempbuffer[maxlen++]=carrybit+'0';
		j=0;
		for(i=maxlen;i>=0;i--) buffer[j++]=tempbuffer[i];
		buffer[j+1]='\0';
	}
	else
	{
		j=0;
		for(i=maxlen-1;i>=0;i--) buffer[j++]=tempbuffer[i];
		buffer[j+1]='\0';
	}
	return buffer;
}