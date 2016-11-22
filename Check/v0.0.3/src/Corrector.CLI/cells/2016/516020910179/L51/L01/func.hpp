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
};


/***************************************
 * 计算各门课平均成绩及最高成绩
 * 输入 : 学生数组指针stu
 * 输入 : 学生数组大小size
 * 输出 : 各门课平均成绩数组指针average
 * 输出 : 各门课最高成绩数组指针high
 ***************************************/
void func(STUDENT* stu, int size, double* average, double* high)
{double max;
	for(int i=0;i<3;i++)
	{
		double sum=0;
		for(int j=0;j<size;j++)
		{
			sum=sum+stu[j].course[i];//求各科总分和
		}
	average[i]=sum/size;//求平均分
	}
	for(int i=0;i<3;i++)
	{
		max=stu[0].course[i];
		for (int j=1;j<size;j++)
		{
			if(stu[j].course[i]>max)//求每组最大值
				max=stu[j].course[i];
		}
		*(high+i)=max;
	}
}