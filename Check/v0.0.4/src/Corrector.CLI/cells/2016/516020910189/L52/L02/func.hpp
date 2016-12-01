using namespace std;
struct Stack  //����ջ�ṹ��
{
	char elements[1024];
	int capacity;
	int count;
}exps;

int push(struct Stack& stack, char in) //��ջ�������ջ���
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

int pop(struct Stack& stack, char& out) //��ջ�������ջ���
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

char cal(char optor, char opnd1, char opnd2) //��������������
{
	if (optor == '*')  //�˷�����
	{
		int m = (int(opnd1-48) )*(int(opnd2) -48);
		return (char)(m+48);
	}
	if (optor == '/') //��������
	{
		int m = (int(opnd2)-48 )/(int(opnd1)-48 );
		return (char)(m+48) ;
	}
	if (optor == '+')  //�ӷ�����
	{
		int m = (int(opnd1)-48) + (int(opnd2) -48);
		return (char)(m+48) ;
	}
	if (optor == '-')  //��������
	{
		int m = (int(opnd2)-48 ) - (int(opnd1)-48 );
		return (char)(m+48) ;
	}
}

int solve(char* expression, int len) //�����������ʽ
{
	exps.capacity = len;
	exps.count = 0;
	int i = 0,j=0;  //�������
	char fout[4], result;
	while (i<len)
	{
		if (expression[i] != ')') //��ջ�ַ���')'
		{
			push(exps, expression[i]);
		}
		else
		{
			for (j = 0; j < 4; j++)
			{
				pop(exps, fout[j]);  //��ջ��'('
			}
			result = cal(fout[1], fout[0], fout[2]); //����һ�����㵥Ԫ
			push(exps, result);
		}
		i++;
	}
	for (j = 0; j < 3; j++)
	{
		pop(exps, fout[j]);
	}
	result = cal(fout[1], fout[0], fout[2]);  //�������һ�����㵥Ԫ
	return ((int)result-48); //����int�ͼ�����
}