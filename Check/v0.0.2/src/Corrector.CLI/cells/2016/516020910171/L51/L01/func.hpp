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
void func(STUDENT* stu, int numOfStu, double* average, double* high)
{
	* average=average[3];//指针变量average指向数组average的首元素
	* high=high[3];//指针变量high指向数组high的首元素
	average[0]=stu[0].course[0];//赋值
	average[1]=stu[0].course[1];//赋值
	average[2]=stu[0].course[2];//赋值
	for(int i=1;i<numOfStu;i++)
	{
		average[0]=average[0]+stu[i].course[0];
	}
	for(int m=1;m<numOfStu;m++)
	{
		average[1]=average[1]+stu[m].course[1];
	}
	for(int n=1;n<numOfStu;n++)
	{
		average[2]=average[2]+stu[n].course[2];
	}
	average[0]=average[0]/numOfStu;//计算课程1平均成绩
	average[1]=average[1]/numOfStu;//计算课程2平均成绩
	average[2]=average[2]/numOfStu;//计算课程3平均成绩
	high[0]=stu[0].course[0];//初始数据课程一最高分为学生一成绩
	high[1]=stu[0].course[1];//初始数据课程二最高分为学生二成绩
	high[2]=stu[0].course[2];//初始数据课程三最高分为学生三成绩
	for(int c=1;c<numOfStu;c++)
	{
		if(stu[c].course[0]>=stu[c-1].course[0])//如果后一个同学的成绩高于前一个，将后一个同学的成绩设为最大值
			high[0]=stu[c].course[0];
		if(stu[c].course[1]>=stu[c-1].course[1])
			high[1]=stu[c].course[1];
		if(stu[c].course[2]>=stu[c-1].course[2])
			high[2]=stu[c].course[2];
	}
}