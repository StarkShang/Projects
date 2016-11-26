#include<string.h>
#include<iostream>
using namespace std;
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int len1=strlen(num1);                          //取两个字符串的长度
	int len2=strlen(num2);
	char temp1[1024],temp2[1024],tempbuffer[1025];  //用于字符串的低位、高位反转
	int i,j;
	int nsum;                                       //每一位相加的结果
	int maxlen;
	int carrybit=0;                                 //carrybit判断是否进位，初始为否

	j=0;
	for(i=len1-1;i>=0;i--) temp1[j++]=num1[i];      //将两个字符串反转，使得低位与低位对齐，方便相加
	temp1[j]='\0';
	j=0;
	for(i=len2-1;i>=0;i--) temp2[j++]=num2[i];
	temp2[j]='\0';

	if(len1<len2)                    //将两个字符串中长的那个的高位用'0'补齐
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

	for(i=0;i<maxlen;i++)            //将两个反转的字符串，相当于原数的低位到高位依次相加
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
	if(carrybit==1)                   //若最高位一位有进位，和再加一位1；反转结果，并在最后加'\0'
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