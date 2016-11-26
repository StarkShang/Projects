int length(char* num)    //判断数组长度
{
	int n=0;
	while(num[n]!=NULL)
		n++;
	return n;
}
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int k=0;
	for(int i=1;i<=length(num2)||i<=length(num1);i++)  //从两个数组最后一个数开始加法运算
	 {  if(length(num2)<=length(num1))  //判断数组相对长度
	     
		  {
		    if(i<=length(num2))       //需考虑两数均参与相加的共同部分
			  {  
				  buffer[length(num1)-i+1]=num1[length(num1)-i]+num2[length(num2)-i]+k-48;
		
			        if(buffer[length(num1)-i+1]>=58)    //判断是否需要进位
		             {
			           buffer[length(num1)-i+1]=buffer[length(num1)-i+1]-10;
		                k=1;
		              }
					else  k=0;
		     }
		   else if(i==length(num2)+1)       //考虑不需要两数相加的位数上的数，超出位数，但要考虑进位
		      buffer[length(num1)-i+1]=num1[length(num1)-i]+k;
		    else if(i>length(num2)+1)      //考虑不需要两数相加的位数上的数，超出位数，不需考虑进位
			   buffer[length(num1)-i+1]=num1[length(num1)-i];
		   
			 
		   buffer[length(num1)+1]='\0';   //最后一位为 ‘\0‘,断开
          }
       if(length(num2)>length(num1))     //同上一组程序
		  {
		    if(i<=length(num1))
			  { 
				  buffer[length(num2)-i+1]=num1[length(num1)-i]+num2[length(num2)-i]+k-48;
		
		           if(buffer[length(num2)-i+1]>=58)
		            {
			          buffer[length(num2)-i+1]=buffer[length(num2)-i+1]-10;
		              k=1;
		            }
				   else k=0;
		      }
		    else if(i==length(num1)+1)
		      buffer[length(num2)-i+1]=num1[length(num2)-i]+k;
		     else if(i>length(num2)+1)
			   buffer[length(num2)-i+1]=num1[length(num2)-i];
		  
		   buffer[length(num2)+1]='\0';      //最后一位为 ‘\0‘,断开
		  }
		
	    
	}
	if(buffer[1]>=58)    //考虑第一位是否要进位
		     {
				 buffer[1]=buffer[1]-10;
				 buffer[0]=49;

		      }
		   else buffer[0]=48;
	
	return buffer;

}