/*******************************************
 * STUDENT结构体
 * int类型成员 : 学号id
 * char[1024]数组类型成员 : 姓名name
 * double[3]数组类型成员 : 三门课成绩course
 *******************************************/
struct STUDENT
{
	int id;             //学号id
	char name[1024]; //姓名name
	double course[3];//三门课成绩course
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
	double sum1 = 0, sum2 = 0, sum3 = 0;
	for (int i = 0; i < 3; i++)
	{
		sum1 = sum1 + stu[i].course[0];
		sum2 = sum2 + stu[i].course[1];
		sum3 = sum3 + stu[i].course[2];
	}                                     //计算各门课的成绩和
	double max(double a, double b);
	double max1=0, max2=0, max3=0;
	for (int i = 0; i < 3; i++)
	{
		max1 = max(max1, stu[i].course[0]);
		max2 = max(max2, stu[i].course[1]);
		max3 = max(max3, stu[i].course[2]);  //各门课的最高值
	}
	*average = sum1 / size;
	*(average + 1) = sum2 / size;
	*(average + 2) = sum3 / size;       //计算平均值
	*high = max1;
	*(high + 1) = max2;
	*(high + 2) = max3;
}
double max(double a, double b)//定义取最大值函数
{
	if (a >= b)return a;
	else return b;
}