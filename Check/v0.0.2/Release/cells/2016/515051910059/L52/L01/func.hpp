char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{int len1,len2;//定义需要用到的变量
char*l_num,*s_num;
int l_num_len,s_num_len;
for(int i=0;num1[i]!='\0';i++)//for循环求字符串num1的长度
len1=i;   
for(int i=0;num2[i]!='\0';i++)//for循环求字符串num2的长度
len2=i;   
if(len1<len2)//比较字符串长度的大小
{l_num=num2; 
l_num_len=len2;//将较长字符串复制到l_num
s_num=num1;
s_num_len=len1;//将较短字符串复制到s_num
}
else//同上
{l_num=num1;
l_num_len=len1;//将较长字符串复制到l_num
s_num=num2;
s_num_len=len2;//将较短字符串复制到l_num
}
for(int i=l_num_len,j=s_num_len;j>0;j--,i--)//将较长字符串与较短字符串右边对齐进行模拟相加
{if(((int)(l_num[i]-48)+(int)(s_num[j]-48))<=9) //当两数相加不大于9时
{l_num[i]=(char)(((int)l_num[i]-48)+(int)(s_num[j]-48)+48);//将两字符串右边对齐进行元素相加赋值给字符串l_num
}
else//当两数相加大于9时
{l_num[i]=(char)((((int)(l_num[i]-48))+((int)(s_num[j]-48)))%10+48);
l_num[i-1]=(char)((((int)(l_num[i-1])-48)+1)+48);//当两字符串对齐元素相加之和大于9，向前一位进1
}
}
if(((int)(l_num[l_num_len-s_num_len]-48)+(int)(s_num[0]-48))<=9)
{l_num[l_num_len-s_num_len]=(char)(((int)l_num[l_num_len-s_num_len]-48)+(int)(s_num[0]-48)+48);//计算最左边对齐位的值（值小于等于9）
buffer=l_num;//将l_num复制到buffer
}
else
{if(l_num_len!=s_num_len)//两字符串长度不等时
{l_num[l_num_len-s_num_len]=(char)(((int)l_num[l_num_len-s_num_len]-48)+(int)(s_num[0]-48)+48);//计算最左边对齐位的值（值大于9）
l_num[l_num_len-s_num_len-1]=(char)((((int)(l_num[l_num_len-s_num_len-1])-48)+1)+48);//若大于9，向前一位进1
buffer=l_num;//将l_num复制到buffer
}
else  //两字符串相等时
{l_num[0]=(char)((((int)(l_num[0]-48))+((int)(s_num[0]-48)))%10+48);//判断第一位有没有溢出
for(int i=0,j=1;i<=l_num_len;i++,j++)//进行for循环，字符顺次后移，第一位添一
{buffer[0]='1';
buffer[l_num_len+2]='\0';//末尾加终止符
buffer[j]=l_num[i];
}
}
}
return buffer;//返回指针buffer地址
} 