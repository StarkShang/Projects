int length(char* num)    //�ж����鳤��
{
	int n=0;
	while(num[n]!=NULL)
		n++;
	return n;
}
char* addTwoNumbers(char* num1, char* num2, char* buffer, int bufferLen)
{
	int k=0;
	for(int i=1;i<=length(num2)||i<=length(num1);i++)  //�������������һ������ʼ�ӷ�����
	 {  if(length(num2)<=length(num1))  //�ж�������Գ���
	     
		  {
		    if(i<=length(num2))       //�迼��������������ӵĹ�ͬ����
			  {  
				  buffer[length(num1)-i+1]=num1[length(num1)-i]+num2[length(num2)-i]+k-48;
		
			        if(buffer[length(num1)-i+1]>=58)    //�ж��Ƿ���Ҫ��λ
		             {
			           buffer[length(num1)-i+1]=buffer[length(num1)-i+1]-10;
		                k=1;
		              }
					else  k=0;
		     }
		   else if(i==length(num2)+1)       //���ǲ���Ҫ������ӵ�λ���ϵ���������λ������Ҫ���ǽ�λ
		      buffer[length(num1)-i+1]=num1[length(num1)-i]+k;
		    else if(i>length(num2)+1)      //���ǲ���Ҫ������ӵ�λ���ϵ���������λ�������迼�ǽ�λ
			   buffer[length(num1)-i+1]=num1[length(num1)-i];
		   
			 
		   buffer[length(num1)+1]='\0';   //���һλΪ ��\0��,�Ͽ�
          }
       if(length(num2)>length(num1))     //ͬ��һ�����
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
		  
		   buffer[length(num2)+1]='\0';      //���һλΪ ��\0��,�Ͽ�
		  }
		
	    
	}
	if(buffer[1]>=58)    //���ǵ�һλ�Ƿ�Ҫ��λ
		     {
				 buffer[1]=buffer[1]-10;
				 buffer[0]=49;

		      }
		   else buffer[0]=48;
	
	return buffer;

}