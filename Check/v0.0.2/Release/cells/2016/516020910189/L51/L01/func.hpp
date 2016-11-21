/*******************************************
 * STUDENT结构体
 * int类型成员 : 学号id
 * char[1024]数组类型成员 : 姓名name
 * double[3]数组类型成员 : 三门课成绩course
 *******************************************/
struct STUDENT
{
	int id;//学员id
	char name[1024];//姓名
	double course[3];//三门课成绩
};


/***************************************
 * 计算各门课平均成绩及最高成绩
 * 输入 : 学生数组指针stu
 * 输入 : 学生数组大小size
 * 输出 : 各门课平均成绩数组指针average
 * 输出 : 各门课最高成绩数组指针high
 ***************************************/
void func19(STUDENT* stu, int size, double* average, double* high)
{
	double Max(double a, double b);                                     //声明函数
	double sum1 = 0, sum2 = 0, sum3 = 0, max1 = 0, max2 = 0, max3 = 0;  //定义并初始化变量
	for (int i = 0; i < size; i++)                                      //计算成绩总和以及最大值
	{
		sum1 = sum1 + stu[i].course[0];
		sum2 = sum2 + stu[i].course[1];
		sum3 = sum3 + stu[i].course[2];
		max1 = Max(max1, stu[i].course[0]);
		max2 = Max(max2, stu[i].course[1]);
		max3 = Max(max3, stu[i].course[2]);
	}
	*average = sum1 / size;                                              //输出结果
	*(average + 1) = sum2 / size;
	*(average + 2) = sum3 / size;
	*high = max1;
	*(high + 1) = max2;
	*(high + 2) = max3;
}

//求最大值函数
double Max(double a, double b)
{
	return(a > b ? a : b);
}