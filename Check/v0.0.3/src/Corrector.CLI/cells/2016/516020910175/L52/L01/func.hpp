#include<string.h>
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int i,j,k,m=0,len1=strlen(num1),len2=strlen(num2);//i,j,k为循环变量，m记录是否进位
	if(strlen(num1)<strlen(num2))//如果num1长度小于num2，交换指针的值
	{
		char* x=num1;
		num1=num2;
		num2=x;
	}
	*(buffer+bufferLen-1)='\0';//令Buffer的末位为空字符
	for(i=len1-1,j=len2-1,k=bufferLen-2;j>=0;i--,j--,k--)//从末位开始逐位相加
	{
		*(buffer+k)=*(num1+i)+*(num2+j)+m-48;
		if(*(num1+i)+*(num2+j)+m-48>'9') {m=1,*(buffer+k)-=10;}//若超过10，m记录进位，字符值减10
		else m=0;
	}
	for(;i>=0;i--,k--)//加上较长字符串的余位
	{
		*(buffer+k)=*(num1+i)+m;
		if(*(num1+i)+m>'9') {m=1,*(buffer+k)-=10;}//判断进位，相应改变字符的值
		else m=0;
	}
	if(m==0) buffer+=bufferLen-len1-1;
	else
	{
		*(buffer+k)='1';
		buffer+=bufferLen-len1-2;
	}//判断最高位是否进位，分别移动buffer指针到结果的最高位

	return buffer;
}