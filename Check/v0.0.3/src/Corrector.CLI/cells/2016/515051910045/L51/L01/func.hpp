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
	STUDENT* a=stu;
	for(int i=0;i<3;i++,average++,high++)    //分别对每科的成绩进行分析
	{   stu=a;                                //每回分析之前对数据初始化
		double sum=0,max=0;
		for(int j=0;j<size;j++,stu++)
	    {  
			sum=sum+(*stu).course[i];
			if((*stu).course[i]>max) max=(*stu).course[i];
		}
		*average=sum/size;
		*high=max;
	}	
}