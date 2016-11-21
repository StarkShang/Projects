/***************************************
 * 求出x的偶数因子
 * 并按从小到大的顺序放在pp所指的数组中
 * 输入 : 整数x
 * 输出 : 偶数因子数组pp
 * 输出 : 因子个数n
 ***************************************/
void func__(int x, int* pp, int& n)
{
	int i=0;
	int p=0;
	n=0;
	for (i=1;i<=x/2;i++)//对所有可能为x因数的数判断
	{
		if (i%2==0)//判断其是否为偶数
		{
			if (x%i==0)//是否为因数
			{
			  *(pp+p)=i;//赋值数组
			  p++;//数组数量加一
			  n++;
			}
		}
	}
}