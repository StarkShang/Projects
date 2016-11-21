/***************************************
 * 求出x的偶数因子
 * 并按从小到大的顺序放在pp所指的数组中
 * 输入 : 整数x
 * 输出 : 偶数因子数组pp
 * 输出 : 因子个数n
 ***************************************/
#include<cmath>
void func30(int x, int* pp, int& n)
{
	int i; //i为待验证是否为因子
	for(i=2;i<=x;i+=2) //只验证偶数是否为因子
		if(0==x%i)
		{
			*(pp+n)=i; //若是，记在pp数组
			n+=1;
		}
}