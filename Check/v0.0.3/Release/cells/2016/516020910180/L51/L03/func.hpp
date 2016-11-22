/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
void FindEvens(int* p, int nArraySize, int* n)
{
	int i;
	for(i=0;i<nArraySize;i++)//找偶数
	{
		if(p[i]%2==0)
			(*n)++;
	}
}