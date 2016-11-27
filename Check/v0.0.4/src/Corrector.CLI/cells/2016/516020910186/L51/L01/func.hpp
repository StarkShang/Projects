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
{
	for(int i=0;i<3;i++)//根据课程数目设置循环
	{
		double a=0;double max=0;//初始化总分和最大值
		for(int m=0;m<size-1;m++)//根据学生人数设置循环
		{
			a=a+stu[m].course[i];//求总分
            if(stu[m].course[i]<stu[m+1].course[i])
			{max=stu[m+1].course[1];}//求最大值
		}
		a=a+stu[size-1].course[i];
		average[i]=a/size;//找到平均数
		high[i]=max;//找到最大值
	}
}

		

	
