using namespace std;
struct Stack  //定义栈结构体
{
	char elements[1024];
	int capacity;
	int count;
}exps;

int push(struct Stack& stack, char in) //入栈并输出入栈结果
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

int pop(struct Stack& stack, char& out) //出栈并输出出栈结果
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

char cal(char optor, char opnd1, char opnd2) //计算两个数运算
{
	if (optor == '*')  //乘法运算
	{
		int m = (int(opnd1-48) )*(int(opnd2) -48);
		return (char)(m+48);
	}
	if (optor == '/') //减法运算
	{
		int m = (int(opnd2)-48 )/(int(opnd1)-48 );
		return (char)(m+48) ;
	}
	if (optor == '+')  //加法运算
	{
		int m = (int(opnd1)-48) + (int(opnd2) -48);
		return (char)(m+48) ;
	}
	if (optor == '-')  //减法运算
	{
		int m = (int(opnd2)-48 ) - (int(opnd1)-48 );
		return (char)(m+48) ;
	}
}

int solve(char* expression, int len) //计算算数表达式
{
	exps.capacity = len;
	exps.count = 0;
	int i = 0,j=0;  //定义变量
	char fout[4], result;
	while (i<len)
	{
		if (expression[i] != ')') //入栈字符至')'
		{
			push(exps, expression[i]);
		}
		else
		{
			for (j = 0; j < 4; j++)
			{
				pop(exps, fout[j]);  //出栈至'('
			}
			result = cal(fout[1], fout[0], fout[2]); //计算一个计算单元
			push(exps, result);
		}
		i++;
	}
	for (j = 0; j < 3; j++)
	{
		pop(exps, fout[j]);
	}
	result = cal(fout[1], fout[0], fout[2]);  //计算最后一个计算单元
	return ((int)result-48); //返回int型计算结果
}