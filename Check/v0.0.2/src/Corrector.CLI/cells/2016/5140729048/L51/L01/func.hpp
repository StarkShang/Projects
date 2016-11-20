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
	double course[3];//根据要求定义变量

};


/***************************************
 * 计算各门课平均成绩及最高成绩
 * 输入 : 学生数组指针stu
 * 输入 : 学生数组大小size
 * 输出 : 各门课平均成绩数组指针average
 * 输出 : 各门课最高成绩数组指针high
 ***************************************/
void func29(STUDENT* stu, int size, double* average, double* high)
{
	int i=0;
	for(i=0;i<size;i++)//逐个赋值
	{
	* (average+i)=((* (stu+i)).course[0]+(* (stu+i)).course[1]+(* (stu+i)).course[2])/3;//平均分
	if((* (stu+i)).course[0]>=(* (stu+i)).course[1]) * (high+i)=(* (stu+i)).course[0];
	else * (high+i)=(* (stu+i)).course[1];
	if(* (high+i)<=(* (stu+i)).course[2]) * (high+i)=(* (stu+i)).course[2];
	else 1;//选出最高分
	}
}