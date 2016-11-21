/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
void FindEvens(int* p, int nArraySize, int* n)
{   int m=0;//初始化m=0
	for(int i=0;i<nArraySize;i++)
	{  
		int k=2;
		if(*(p+i)%k==0)//判断p[i]是否为偶数
		{
			m+=1;//如果为偶数，m加一
		}
	}
	*n=m;//将m的值赋于n
	
}