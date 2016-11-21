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

	for(int i=0;i<size;i++)//依次取出不同课程成绩
	{
		double t=0,q=0;  //定义中间变量
		for(int j=0;j<size;j++)  //for循环取不同学生
			{
				t=t+stu[j].course[i]; //求某一课程的总分
		}*(average+i)=t/3;//各门课平均成绩赋值给数组指针average
	
		for(int k=0;k<size;k++)//for循环取不同学生
		{
			if(stu[k].course[i]>q)//对比取最高成绩
				{
					q=stu[k].course[i];
			}*(high+i)=q;//各门课最高成绩赋值给数组指针high
		}
	}
}
