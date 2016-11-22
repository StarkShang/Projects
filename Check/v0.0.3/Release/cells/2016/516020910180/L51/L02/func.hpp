/***************************************
 * 求出x的偶数因子
 * 并按从小到大的顺序放在pp所指的数组中
 * 输入 : 整数x
 * 输出 : 偶数因子数组pp
 * 输出 : 因子个数n
 ***************************************/
int* factor(int* fac,int x,int& j)
{
	int i;
	j=0;
	for(i=1;i<=x;i++)
	{
		if(x%i==0&&i%2==0)//找偶数因子
		{
			fac[j]=i;
			j++;
		}
	}
	return fac;
}

int* order(int* fac,int t)
{
	int i;
	for(i=1;i<t;i++)//对每个数进行查找比较
	{
		int j=0;
		bool t=false;
		do//判断应该处于哪个数右边
		{
			if(fac[i]<fac[j])//如果原来此位置的数大于未排序的该数，则它与它之后的数向后移一位，它的位置给该数
			{
				t=true;
				int temp=fac[i],q;
				for(q=i;q>j;q--)//调换顺序
				{
					fac[q]=fac[q-1];
				}
				fac[j]=temp;
			}
			j++;
		}
		while(t==false&&j<i);//排完序后跳出循环
	}
	return fac;
}


void func(int x, int* pp, int& n)
{
	int* fac=pp;
	int j;
	n=0;
	fac=factor(fac,x,j);//找偶数因子
	pp=order(fac,j);//对偶数因子排序
	n=j;
}