/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
void FindEvens(int* p, int nArraySize, int* n)
{
	for(int i=0;i<nArraySize;i++)//设置数组中每个数的循环
	{
		if (*(p+i)%2==0)//检验第n个数是否为偶数
			(*n)++;
	}
}