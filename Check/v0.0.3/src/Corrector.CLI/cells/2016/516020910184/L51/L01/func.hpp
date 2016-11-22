/*******************************************
 * STUDENT结构体
 * int类型成员 : 学号id
 * char[1024]数组类型成员 : 姓名name
 * double[3]数组类型成员 : 三门课成绩course
 *******************************************/
struct STUDENT
{
	int id;
	char name[1024];
	double course[3];

}stu;


/***************************************
 * 计算各门课平均成绩及最高成绩
 * 输入 : 学生数组指针stu
 * 输入 : 学生数组大小size
 * 输出 : 各门课平均成绩数组指针average
 * 输出 : 各门课最高成绩数组指针high
 ***************************************/
void func(STUDENT* stu, int size, double* average, double* high)
{
	int i;//定义变量
	average[0]=0;//初始化course0的平均值
	for(i=0;i<size;i++)//循环语句计算course0的平均值
	{
	average[0]=average[0]+(stu[i]).course[0];
	}
	average[0]=average[0]/size;
	average[1]=0;//初始化course1的平均值
	for(i=0;i<size;i++)//循环语句计算course1的平均值
	{
	average[1]=average[1]+(stu[i]).course[1];
	}
	average[1]=average[1]/size;
	average[2]=0;//初始化course2的平均值
	for(i=0;i<size;i++)//循环语句计算course2的平均值
	{
	average[2]=average[2]+(stu[i]).course[0];
	}
	average[2]=average[2]/size;

	high[0]=0;//初始化course0的最高分
	for(i=0;i<size;i++)//循环语句计算course0的最高分
	{
		if(high[0]<(stu[i]).course[0])
	   high[0]=(stu[i]).course[0];
	}
	for(i=0;i<size;i++)//循环语句计算course1的最高分
	{
		if(high[1]<(stu[i]).course[1])
	   high[1]=(stu[i]).course[1];
	}
	for(i=0;i<size;i++)//循环语句计算course2的最高分
	{
		if(high[2]<(stu[i]).course[2])
	   high[2]=(stu[i]).course[2];
	}
}

