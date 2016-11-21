/*******************************************
 * STUDENT结构体
 * int类型成员 : 学号id
 * char[1024]数组类型成员 : 姓名name
 * double[3]数组类型成员 : 三门课成绩course
 *******************************************/
struct STUDENT
{
	int id;//int类型成员 : 学号id
	char name[1024];//char[1024]数组类型成员 : 姓名name
	double course[3];//三门课成绩course
};


/***************************************
 * 计算各门课平均成绩及最高成绩
 * 输入 : 学生数组指针stu
 * 输入 : 学生数组大小numOfStu
 * 输出 : 各门课平均成绩数组指针average
 * 输出 : 各门课最高成绩数组指针high
 ***************************************/
void func__(STUDENT* stu, int numOfStu, double* average, double* high)
{
	int b;
	for (int i = 0; i<3 ; ++i)
	{
		 b=0;
		for(int j=0;j<numOfStu;j++)
		{
		    b=b+stu[j].course[i];//计算所有成绩
		}
		average[i]=b/numOfStu;//计算平均成绩
		
	}
	for(int k=1;k<numOfStu;k++)
	{
		for(int l=0;l<3;l++)
		{
			if(stu[k].course[l]>stu[k-1].course[l])
			{
				high[l]=stu[k].course[l];
			}
			else
			{

				high[l]=stu[k-1].course[l];//计算最高分
			}
		}
	}
		
	
}