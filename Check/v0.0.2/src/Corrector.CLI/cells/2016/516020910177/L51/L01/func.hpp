/*******************************************
 * STUDENT结构体
 * int类型成员 : 学号id
 * char[1024]数组类型成员 : 姓名name
 * double[3]数组类型成员 : 三门课成绩course
 *******************************************/
struct STUDENT
{
	int id;              //int类型成员 : 学号id
    char name[1024];    //char[1024]数组类型成员 : 姓名name
    double course[3];  //double[3]数组类型成员 : 三门课成绩course
};


double max(double a,double b,double c)//定义函数求最大值
{   double max;
	max=a;
	if(max<b) max=b;
	if(max<c) max=c;
	return max;    //返回最大值

}
/***************************************
 * 计算各门课平均成绩及最高成绩
 * 输入 : 学生数组指针stu
 * 输入 : 学生数组大小size
 * 输出 : 各门课平均成绩数组指针average
 * 输出 : 各门课最高成绩数组指针high
 ***************************************/
void func07(STUDENT* stu, int size, double* average, double* high)
{   int i;
	for(i=0;i<size;i++)    // 循环求所需数据
	{
		average[i]=( stu[0].course[i]+stu[1].course[i]+ stu[2].course[i])/3;  //计算各门课平均成绩
	    high[i]=max(stu[0].course[i],stu[1].course[i], stu[2].course[i]) ;   //调用函数计算最高分
    }
}
