/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
void FindEvens(int* p, int nArraySize, int* n)
{
	int a=0;//定义并初始化变量
	for(int i=0;i<nArraySize;i++)//循环数组内数据
	{
		if(*(p+i)%2==0)//判断是否是偶数
		{a=a+1;}//累加偶数个数
	}
	* n=a;//赋值
}