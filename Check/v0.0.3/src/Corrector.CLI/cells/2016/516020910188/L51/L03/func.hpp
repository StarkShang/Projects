/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
void FindEvens(int* p, int nArraySize, int* n)
{
	for(int i=1;i<=nArraySize;i++,p++)//循环数组每一个数
		if((*p)%2==0) *n=*n+1;//判断数字是否为偶数并进行计数
}