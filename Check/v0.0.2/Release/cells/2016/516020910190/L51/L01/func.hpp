/*******************************************
 * STUDENT结构体
 * int类型成员 : 学号id
 * char[1024]数组类型成员 : 姓名name
 * double[3]数组类型成员 : 三门课成绩course
 *******************************************/
struct STUDENT
{
	int id;
	char name[10];
	float course[3];
};


/***************************************
 * 计算各门课平均成绩及最高成绩
 * 输入 : 学生数组指针stu
 * 输入 : 学生数组大小size
 * 输出 : 各门课平均成绩数组指针average
 * 输出 : 各门课最高成绩数组指针high
 ***************************************/
float max(float ,float,float );//声明函数max
void func__(STUDENT* stu, int size, double* average, double* high)//定义func函数
{   
	for(int i=0;i<size;i++)
	{   
      average[i] =(stu[i].course[0]+stu[i].course[1]+stu[i].course[2])/3;//求出每位同学平均成绩
		high[i]=max(stu[i].course[0],stu[i].course[1],stu[i].course[2]);//求出每位同学最高成绩
	}
}
	float max(float a,float b,float c)//定义max函数
	{
		if(a<b) 
			a=b;//先求a,b的最大值，并将最大值赋值于a
		return (a>c?a:c);//返回最大值
	}
	
