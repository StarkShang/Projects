/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
void FindEvens(int* p, int nArraySize, int* n)
{
	int *m=p;
	*n=0;//初始化n值
	for(int i=1;i<=nArraySize;i++)//设置循环
	{
		if(*m%2==0)//如果为偶数
		{*n=*n+1;}//计数加1
	    m=m+1;//数组中的下一个数
	}	
}