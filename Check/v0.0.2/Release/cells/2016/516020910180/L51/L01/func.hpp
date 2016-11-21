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

};STUDENT* stu;


/***************************************
 * 计算各门课平均成绩及最高成绩
 * 输入 : 学生数组指针stu
 * 输入 : 学生数组大小size
 * 输出 : 各门课平均成绩数组指针average
 * 输出 : 各门课最高成绩数组指针high
 ***************************************/


double ave(STUDENT* stu,int i,int size)
{
	double average=0;
	int j;
	for(j=0;j<size;j++)
		average+=stu[j].course[i];//计算平均
	average=average/size;
	return average;
}

double hi(STUDENT* stu,int i,int size)
{
	double high=0;
	int j;
	for(j=0;j<3;j++)
	{
		if(stu[j].course[i]>high)//计算最高分
			high=stu[j].course[i];
	}
	return high;
}

void func10(STUDENT* stu, int size, double* average, double* high)
{
	int i;
	for(i=0;i<3;i++)
	{
		high[i]=hi(stu,i,size);
		average[i]=ave(stu,i,size);
	}
	
}