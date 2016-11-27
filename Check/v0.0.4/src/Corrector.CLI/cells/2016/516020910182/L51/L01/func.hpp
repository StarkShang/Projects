/*******************************************
 * STUDENT结构体
 * int类型成员 : 学号id
 * char[1024]数组类型成员 : 姓名name
 * double[3]数组类型成员 : 三门课成绩course
 *******************************************/
struct STUDENT
{
	int id;
	double course[3];
	char name[1024];
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
	double sum[3]={0,0,0};
	high[0]=0;
	high[1]=0;
	high[2]=0;
	for(int i=0;i<size;i++)
	{
		for(int n=0;n<3;n++)
		{
			sum[n]+=(*stu).course[n];
			if((*stu).course[n]>=high[n]) high[n]=(*stu).course[n];
		}
	}
	for(int m=0;m<3;m++)
	{
			*(average+m)=sum[m]/size;
	}
}