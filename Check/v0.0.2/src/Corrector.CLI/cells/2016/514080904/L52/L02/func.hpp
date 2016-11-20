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
	int num1, num2;//利用num1，num2记录做运算的字符所表示的真实数字
	num1 = opnd1 - 48;
	num2 = opnd2 - 48;
	if(optor == '+') return (num2 + num1 + 48);//分别表示加减乘除四种情况下的运算
	if(optor == '-') return (num2 - num1 + 48);
	if(optor == '*') return (num2 * num1 + 48);
	if(optor == '/') return (num2 / num1 + 48);
}

int solve(char* expression, int len)
{
	char opnd1, opnd2, optor, useless;//useless只作为pop时候对无用的out变量的寄存
	struct Stack stack_num;//初始化栈
	stack_num.count=0;
	stack_num.capacity=1024;
	int i=0;
	while((expression[i] != '\0' && expression[i-1] != '\0') || stack_num.count != 1)//判断循环的终止
	{ //左边的是判断原输入的字符串是否已经被遍历，右边的则是判断栈中是否只有一个元素，两者同时满足时则为运算结束的时候，输出栈中唯一元素即为运算值
		if (expression[i] != ')' && expression[i] != '\0') //此时i指向下一个
		{
			push(stack_num, expression[i]);
			i=i+1;
		}
		else//此时包括了对从‘（’到‘）’前数字的处理
		{
			pop(stack_num, opnd1);
			pop(stack_num, optor);
			pop(stack_num, opnd2);
			pop(stack_num, useless);
			push(stack_num, cal(optor, opnd1, opnd2));
			i=i+1;//处理完成后由于i仍是指向‘）’ 所以需要将指针后移一位
		}
	}
	return (stack_num.elements[0]-48);
}