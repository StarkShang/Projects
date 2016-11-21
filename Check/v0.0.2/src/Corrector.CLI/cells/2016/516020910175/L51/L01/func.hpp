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
	int i,j;//i为课程循环变量，j为学生循环变量
	for(i=0;i<3;i++)//3门课循环3次
	{
		*(average+i)=0;//设初值0
		*(high+i)=stu->course[i];//设最高分基准值
		for(j=0;j<size;j++)//有size名学生，循环size次
		{
			*(average+i)+=(stu+j)->course[i];//同一门课分数求和
			*(high+i)=((stu+j)->course[i]>*(high+i))?(stu+j)->course[i]:*(high+i);//比大小找最高分
		}
		*(average+i)/=size;//一门课总分除人数得均分
	}
}