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
	for (int j = 0; j < 3; j++)
	{
		*(average + j) = 0;//成绩总和赋初值
		for (int i = 0; i < size; i++)
		{
			*(average + j) += stu[i].course[j];
		}
		*(average+j)/= size;//计算平均
		*(high + j) = stu[0].course[j];//最大值赋初值
		for (int i = 1; i < size; i++)
		{
			if (stu[i].course[j] > *(high+j))
				*(high+j) = stu[i].course[j];//得到最大值
		}
	}
}