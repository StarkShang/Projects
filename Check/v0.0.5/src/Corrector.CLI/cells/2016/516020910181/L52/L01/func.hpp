char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int a, b,len;                               //定义整形变量
	int c, d, e;                              
	a = strlen(num1);                           //把num1的长度赋给a
	b = strlen(num1);                           //把num2的长度赋给b
	len = a;
	if (b > a)
		len = b;                                //把a，b中较大的赋给len
	for (int i = 1; i <= len; i++) {            
		num1[len - i] = num1[a - i];
		num2[len - i] = num2[b - i];
	}                                           //使a,b左对齐
	if (len == a) {                                
		for (int i = 0; i <= a - b - 1; i++)
			num2[i] = '0';
	}
	else {
		for (int i = 0; i <= b - a - 1; i++)
			num1[i] = '0';                      //空位用0补齐
	}
	for (int i = 0; i <= len; i++)
		buffer[i] = '0';                        //空位用0补齐
	for (int i = len ; i >= 1; i--) {           
		c = int(num1[i-1]) - 48;
		d = int(num2[i-1]) - 48;
		e = c + d;                              //加
		if (e > 9) {
			e -= 10;
			buffer[i] = e + 30 + int(buffer[i]) - 30;
			buffer[i - 1] = '1';                //若要进位 就进位
		}
		else
			buffer[i] = e + 30+int(buffer[i])-30; 
	}
	buffer[len + 1] = '\0';                    //为了不让有那么多烫
	if (buffer[0] == '0') {                    //如果首位为0
		for (int i = 0; i <= len + 1; i++)     //消除之
			buffer[i] = buffer[i + 1];
	}
	
	return buffer;                                
}