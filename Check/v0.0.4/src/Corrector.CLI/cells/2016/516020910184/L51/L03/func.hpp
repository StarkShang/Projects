/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
void FindEvens(int* p, int nArraySize, int* n)
{
	int i;//定义变量
	for(i=0;i<nArraySize;i++)//执行循环语句从数组第一个元素到最后一个元素
	{
		if(*(p+i)%2==0)//如果数组p的第i+1个元素是偶数
			*n=*n+1;//偶数的个数值n加一
	}
}