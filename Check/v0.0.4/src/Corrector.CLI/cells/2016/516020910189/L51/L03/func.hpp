/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
void FindEvens(int* p, int nArraySize, int* n)
{
	*n = 0; //偶数个数初始化
	for (int i = 0; i < nArraySize; i++)
	{
		if (0 == *(p + i) % 2)   //判断为偶数
		{
			*n = *n + 1;           //偶数个数加一
		}
	}
}