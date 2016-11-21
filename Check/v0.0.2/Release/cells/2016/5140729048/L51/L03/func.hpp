/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
void FindEvens(int* p, int nArraySize, int* n)
{
	int i=0;//定义变量
	for(i=0;i<nArraySize;i++)
	{
		if ((*(p+i))%2==0)
		(* n)++;//逐个检查，偶数就计数+1
	}
}