struct Stack
{
	char elements[1024];
	int capacity;
	int count;
};

int push(struct Stack& stack, char in)
{
	if (stack.capacity == stack.count)
	{
		return -1;
	}
	else
	{
		stack.elements[stack.count] = in;
		stack.count++;
		return 0;
	}
}

int pop(struct Stack& stack, char& out)
{
	if (0 == stack.count)
	{
		return -1;
	}
	else
	{
		stack.count--;
		out = stack.elements[stack.count];
		return 0;
	}
}

char cal(char optor, char opnd1, char opnd2)
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

int solve(char* expression, int len)
{
	int i=0;
	Stack stack;
	stack.count=0;
	stack.capacity=1024;
	char a[3],n,m;
	while(i<len-1)
	{
		int j=0;
		while(expression[i]!=')'&&expression[i]!='\0')
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
	return ((int)stack.elements[0]-48);
}