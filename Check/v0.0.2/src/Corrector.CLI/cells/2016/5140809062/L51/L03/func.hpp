/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
void FindEvens(int* p, int nArraySize, int* n)
{
	for (int i=0;i<nArraySize;i++)//逐个检验P，看看有没有偶事
		{
			if ((*(p+i))%2==0)//若有偶数则使N加一
			*n=*n+1;
		}
}