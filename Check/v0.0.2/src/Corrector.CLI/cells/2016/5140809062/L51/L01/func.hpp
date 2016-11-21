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
	for (int i=0;i<3;i++)//接下来要得到平均值
	{average[i]=0;}//初始化品均值数组
	for (int i=0;i<3;i++)//对每门课
	{
		for (int j=0;j<size;j++)//对每个学生
		average[i]+=stu[j].course[i]/size;//把每个学生的成绩加进平均数理
	}


	for (int i=0;i<3;i++)//接下来要得到最高值
	{
		double max=stu[0].course[i];//初始化最高值
		for (int j=0;j<size;j++)//此循环为找到最高值
			{
				if (stu[j].course[i]>max)
				max=stu[j].course[i];
			}
		high[i]=max;//吧最高值赋值给数组
	}


}