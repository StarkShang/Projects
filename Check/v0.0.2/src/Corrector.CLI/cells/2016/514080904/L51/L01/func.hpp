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
void func28(STUDENT* stu, int size, double* average, double* high)
{
	double sum;
	for(int i=0;i<3;i++)
	{
		high[i]=0.0,sum=0.0;
		for(int j=0;j<size;j++)
		{
			sum=sum+stu[j].course[i];
			if(high[i]<stu[j].course[i]) high[i]=stu[j].course[i];
		}
		average[i]=sum/size;
	}
}