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
	int num1, num2;//����num1��num2��¼��������ַ�����ʾ����ʵ����
	num1 = opnd1 - 48;
	num2 = opnd2 - 48;
	if(optor == '+') return (num2 + num1 + 48);//�ֱ��ʾ�Ӽ��˳���������µ�����
	if(optor == '-') return (num2 - num1 + 48);
	if(optor == '*') return (num2 * num1 + 48);
	if(optor == '/') return (num2 / num1 + 48);
}

int solve(char* expression, int len)
{
	char opnd1, opnd2, optor, useless;//uselessֻ��Ϊpopʱ������õ�out�����ļĴ�
	struct Stack stack_num;//��ʼ��ջ
	stack_num.count=0;
	stack_num.capacity=1024;
	int i=0;
	while((expression[i] != '\0' && expression[i-1] != '\0') || stack_num.count != 1)//�ж�ѭ������ֹ
	{ //��ߵ����ж�ԭ������ַ����Ƿ��Ѿ����������ұߵ������ж�ջ���Ƿ�ֻ��һ��Ԫ�أ�����ͬʱ����ʱ��Ϊ���������ʱ�����ջ��ΨһԪ�ؼ�Ϊ����ֵ
		if (expression[i] != ')' && expression[i] != '\0') //��ʱiָ����һ��
		{
			push(stack_num, expression[i]);
			i=i+1;
		}
		else//��ʱ�����˶Դӡ�������������ǰ���ֵĴ���
		{
			pop(stack_num, opnd1);
			pop(stack_num, optor);
			pop(stack_num, opnd2);
			pop(stack_num, useless);
			push(stack_num, cal(optor, opnd1, opnd2));
			i=i+1;//������ɺ�����i����ָ�򡮣��� ������Ҫ��ָ�����һλ
		}
	}
	return (stack_num.elements[0]-48);
}