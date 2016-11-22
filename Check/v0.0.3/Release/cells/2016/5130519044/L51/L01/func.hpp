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
}stu;


/***************************************
 * 计算各门课平均成绩及最高成绩
 * 输入 : 学生数组指针stu
 * 输入 : 学生数组大小size
 * 输出 : 各门课平均成绩数组指针average
 * 输出 : 各门课最高成绩数组指针high
 ***************************************/
void func(STUDENT* stu, int size, double* average, double* high)
{
	int i,j,k,t,c;
	for(c=0;c<3;c++)
	{double sum=0;
		for(i=0;i<size-1;i++) //对每门课的成绩从高到低排序，i代表学生序号，j为i后面一个学生
		{sum+=stu[i].course[c];
			k=i;
			for(j=i+1;j<size;j++)
				if(stu[j].course[c]<stu[i].course[c]+i) k=j;
			t=stu[k].course[c];stu[k].course[c]=stu[i].course[c];stu[i].course[c]=t;
		}
		high[c]=stu[i].course[c]; //最高分放在high数组中
		average[c]=sum/size;      //平均分放在average数组中
	}
}