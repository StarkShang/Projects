/*******************************************
 * STUDENT结构体
 * int类型成员 : 学号id
 * char[1024]数组类型成员 : 姓名name
 * double[3]数组类型成员 : 三门课成绩course
 *******************************************/
struct STUDENT
{
	int id;
	char name [1024];
	double course[3];

};


/***************************************
 * 计算各门课平均成绩及最高成绩
 * 输入 : 学生数组指针stu
 * 输入 : 学生数组大小size
 * 输出 : 各门课平均成绩数组指针average
 * 输出 : 各门课最高成绩数组指针high
 ***************************************/
void func18(STUDENT* stu, int size, double* average, double* high)
{  
	for(int p=0;p<3;p++)
{
	average[p]=0;
    high[p]=0;}//给数组赋初始值
	for(int i=0;i<size;i++)//循环所有学生数据
	{
		for(int k=0;k<3;k++)
       {  
	   average[k]=(stu[i].course[k]+average[k]*i)/(i+1);//计算平均成绩
	   if(stu[i].course[k]>high[k])
		high[k]=stu[i].course[k];//计算最高成绩
	
	}
	}
}