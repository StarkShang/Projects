/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
void FindEvens(int* p, int nArraySize, int* n)
{
	* p=p[0];//指针变量p指向p数组的首元素
	for(int i=0;i<nArraySize;i++)
	{
		if(p[i]%2==0)//判别元素是否为偶数
			*n=*n+1;//如果是偶数个数增加一个
	}
} 