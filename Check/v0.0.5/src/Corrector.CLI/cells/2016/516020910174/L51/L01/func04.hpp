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
double MAX(double x,double y)
{
	return(x > y ? x : y);
}                                                   //比较大小的函数

/***************************************
 * 计算各门课平均成绩及最高成绩
 * 输入 : 学生数组指针stu
 * 输入 : 学生数组大小size
 * 输出 : 各门课平均成绩数组指针average
 * 输出 : 各门课最高成绩数组指针high
 ***************************************/
void func(STUDENT* stu, int size, double* average, double* high)
{
	double sum1 = 0, sum2 = 0, sum3 = 0;
	high[0] = 0;
	high[1] = 0;
	high[2] = 0;
	for (int i = 0; i <size ; i++)
	{
		sum1 = sum1 + stu[i].course[0];                         
		sum2 = sum2 + stu[i].course[1];
		sum3 = sum3 + stu[i].course[2];                                //计算各课程总值
	}
	average[0] = sum1 / size;                                    
	average[1] = sum2 / size;
	average[2] = sum3 / size;                                         //计算各课程平均分
	for (int i = 0; i < size; i++)
	{
		high[0] = MAX(high[0], stu[i].course[0]);
		high[1] = MAX(high[1], stu[i].course[1]);
		high[2] = MAX(high[2], stu[i].course[2]);                    //比较各课程的最大值
	}
}
