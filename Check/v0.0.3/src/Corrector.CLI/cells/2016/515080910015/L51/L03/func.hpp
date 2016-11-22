/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
void FindEvens(int* p, int nArraySize, int* n)
{
	for(int*a=p;a<(p+nArraySize);a++)//用for循环查找偶数个数
	{
		if(*a%2==0)  //判断指针地址元素是否为偶数
			*n=*n+1;  //计算偶数个数
	}
}