struct Stack//定义结构体栈
{
	char elements[1024];
	int capacity;
	int count;
};

int push(struct Stack& stack, char in)//进栈操作
{
	if (stack.capacity == stack.count)//如果容量已满，返回-1
	{
		return -1;
	}
	else//栈未满，返回0，将in赋给栈的第stack.count个元素，栈现有人数加一
	{
		stack.elements[stack.count] = in;
		stack.count++;
		return 0;
	}
}

int pop(struct Stack& stack, char& out)//出栈操作
{
	if (0 == stack.count)//如果栈已经为空，返-1
	{
		return -1;
	}
	else//否则，栈已有人数减一，将栈的out元素删除
	{
		stack.count--;
		out = stack.elements[stack.count];
		return 0;
	}
}

char cal(char optor, char opnd1, char opnd2)//定义函数，将char型转化成四则运算加减乘除运算，后返回char型运算结果
{
	int n1=(int)opnd1-48;
	int n2=(int)opnd2-48;
	int n;
	char r;
	switch((int)optor)
	{
	case 42:n=n1*n2;break;
	case 43:n=n1+n2;break;
	case 45:n=n1-n2;break;
	case 47:n=n1/n2;break;
	}
	r=n+48;
	return r;
}

int solve(char* expression, int len)//函数solve来计算算数表达式
{
	int i=0;
	Stack stack;
	stack.count=0;
	stack.capacity=1024;//定义并初始化变量
	char a[3],n,m;//定义变量
	while(i<len-1)//循环语句计算给定的表达式
	{
		int j=0;
		while(expression[i]!=')'&&expression[i]!='\0')//入栈直至碰见‘）’，将‘括号内的表达式放入栈中
		{
			push(stack,expression[i]);
			i++;
		}
		i++;
		while(j<3)
		{
			pop(stack,a[j]);
			j++;
		}
		n=cal(a[1],a[2],a[0]);
		pop(stack,m);
		push(stack,n);
	}
	return ((int)stack.elements[0]-48);//返回算数表达式的值
}