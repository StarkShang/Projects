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
}


/***************************************
* 计算各门课平均成绩及最高成绩
* 输入 : 学生数组指针stu
* 输入 : 学生数组大小size
* 输出 : 各门课平均成绩数组指针average
* 输出 : 各门课最高成绩数组指针high
***************************************/
void func15(STUDENT* stu, int size, double* average, double* high)
{
	double d, max;//定义中间变量
	for (int j = 0; j < 3; j++)//循环计算三个课程的平均分
	{
		d = 0;
		for (int i = 0; i < size; i++)//循环计算该课程所有学生得分总分
		{
			d = d + (stu[i].course[j]);
		}
		*(average + j) = d / size;//计算均分
	}
	for (int k = 0; k < 3; k++)//循环计算三个课程的最高分
	{
		for (int l = 0; l < size - 1; l++)//循环计算该课程的最高分
		{
			max = stu[l].course[k];
			if (stu[l].course[k] < stu[l + 1].course[k])//若后一个同学分数更高，
				max = stu[l + 1].course[k];//则max改为该同学分数
		}
		*(high + k) = max;//得出最高分
	}
}