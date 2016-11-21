/*******************************************
 * STUDENT结构体
 * int类型成员 : 学号id
 * char[1024]数组类型成员 : 姓名name
 * double[3]数组类型成员 : 三门课成绩course
 *******************************************/
struct STUDENT                              
{
	int id;                               //学号id
	char name[1024];                      //名字
	double course[3];                     //分数
};


/***************************************
 * 计算各门课平均成绩及最高成绩
 * 输入 : 学生数组指针stu
 * 输入 : 学生数组大小size
 * 输出 : 各门课平均成绩数组指针average
 * 输出 : 各门课最高成绩数组指针high
 ***************************************/
void func__(STUDENT* stu, int size, double* average, double* high)
{
	double sum[3] = { 0,0,0 };                   //定义变量 储存总分
	for (int i = 0; i < size; i++) {             //进入循环
		for (int j = 0; j < 3; j++) {            
			sum[j] += stu[i].course[j];          //计算总分
		}
	}
	average[0] = sum[0] / size;                  //求平均值
	average[1] = sum[1] / size; 
	average[2] = sum[2] / size;
	for (int i = 0; i < 3; i++) {                //进入循环
		high[i] = stu[0].course[i];              
		for (int j = 0; j < size; j++) {
			double d;
			if (high[i] < stu[j].course[i]) 
				high[i] = stu[j].course[i];     //得出最大值
		}
	}
}