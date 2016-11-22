/*******************************************
 * STUDENT结构体
 * int类型成员 : 学号id
 * char[1024]数组类型成员 : 姓名name
 * double[3]数组类型成员 : 三门课成绩course
 *******************************************/
struct STUDENT//定义结构体数组
{
	int id;//学号
	char name[1024];//字符数组类型
	double course[3];//成绩数组类型

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
	for(int j=0;j<=2;j++)//对三门课进行循环
	{
	double a=0,b=0,c=0;//定义变量
	for(int i=0;i<size;i++)//对学生进行循环
	{
		a=a+stu[i].course[j];//将该门课成绩累加
	    c=a/size;//计算平均值
		* (average+j)=c;//对平均分赋值
		if(stu[i].course[j]>b)//判断最高分
	    {b=stu[i].course[j];
		* (high+j)=b;}//对最高分赋值
	}
	
	}
}