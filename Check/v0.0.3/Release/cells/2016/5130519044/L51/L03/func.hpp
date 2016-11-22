/****************************
 * 寻找数组内偶数的个数
 * 输入 : 数组首地址p
 * 输入 : 数组长度nArraySize
 * 输出 : 偶数的个数n
 ****************************/
#include<cmath>
void FindEvens(int* p, int nArraySize, int* n) //指针型形参p，指向数组p的元素；指针型形参n，指向偶数个数n
{int i;
	for(i=0;i<nArraySize;i++)
		if(0==*(p+i)%2) *n+=1; //如果所指向的数组元素为偶，所指向的偶数个数n加1
}