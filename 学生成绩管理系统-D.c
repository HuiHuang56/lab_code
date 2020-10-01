
/*----------------头文件--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

/*----------------------------------*
	   学生信息-结构体设计
*-----------------------------------*/

typedef struct student
{
	char number[20];  //学号
	char name[20];    //姓名
	float dailyScore;   //平时成绩
	float experiScore;  //实验成绩
	float finalScore;   //期末成绩
	float generalScore; //总评成绩
}SS;


/*----------------函数定义-------------*/

//1.1手动输入学生基本数据
void readData(SS stu[], int N)
{
	printf("请按照如下格式输入学生信息:学号,姓名,平时成绩,期末成绩\n ");
	for (int i = 0; i < N; i++)
	{
		printf("第%d个学生:", i + 1);
		scanf("%s %s %f %f %f", stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiScore, stu[i].finalScore);
		printf("\n");
	}
	printf("------成绩录入完毕！--------\n");
}

//1.2从文件里读取学生基本数据
SS* readDataFromFile(int* N)
{
	printf("\n\n------第一步: 从文件读取学生的成绩信息--------\n\n");
	SS* stu;// 开辟新空间,存取文件中的每个学生信息
	FILE* fp = NULL;
	int count = 0;
	int index = 0;
	fp = fopen("data.txt", "r");

	//1.获取学生数目
	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}
	printf("学生数目为：%d\n\n", count);
	
	//2.给所有学生分配存储空间
	stu = (SS*)malloc(count * sizeof(SS)); //开辟动态内存区，将地址转换成SS*型，然后放在stu中

	//3.读取每条学生的信息
	int i = 0;
	printf("   学号       姓名  平时成绩  实验成绩  期末成绩\n\n");
	while((!feof(fp)))
	{
		fscanf(fp, "%s %s %f %f %f", stu[i].number, stu[i].name, &stu[i].dailyScore, &stu[i].experiScore, &stu[i].finalScore);
		printf("%s %7s %8.2f %8.2f %9.2f\n", stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiScore, stu[i].finalScore);
		++i;
	}
	printf("\n------信息读取完毕!-------\n");
	fclose(fp);
	return stu;
}

//2.计算N个学生各自的总评成绩
void calcuScore(SS stu[], int N)
{
	printf("\n\n------第二步: 计算每个学生的总评成绩---------\n\n");
	printf("   学号      总评成绩\n\n");
	for (int i = 0; i < N; i++)
	{
		stu[i].generalScore = 0.2 * stu[i].dailyScore + 0.2 * stu[i].experiScore + 0.6 * stu[i].finalScore;
		// 总成绩公式：总成绩 = 0.2 * 平时成绩 + 0.2 * 实验成绩 + 0.6 * 期末成绩
		printf("%s %8.2f\n",stu[i].number,stu[i].generalScore);
	}
	printf("\n------总评成绩计算完毕!-------\n");
}

//3.根据总评成绩排名
int cmpBigtoSmall(const void* a, const void* b)
{
	SS* aa = (SS*)(a);
	SS* bb = (SS*)(b);
	if ((*aa).generalScore < (*bb).generalScore)  return 1;
	else if ((*aa).generalScore > (*bb).generalScore)  return -1;
	else
		return 0;
}

void sortScore(SS stu[], int N)
{
	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);
}

//4.按照一定的格式输出N个学生的信息
void printOut(SS stu[], int N)
{
	printf("\n------第三步: 根据总成绩输出学生排名信息!------\n\n");
	printf("排名    学号       姓名  平时成绩  实验成绩  期末成绩  总评成绩\n\n");
	for (int i = 0; i < N; i++)
	{
		printf("%2d   %s %7s %8.2f %9.2f %9.2f %9.2f\n", i + 1, stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiScore, stu[i].finalScore, stu[i].generalScore);
	}
	printf("\n------排名信息如上表!-------\n");
}

//5.输入学号查询某个学生的成绩信息
void inquire(SS stu[], int N)
{
	printf("\n------第四步: 通过学号查询某个学生的信息!------\n\n");
	char ID[20];
	printf("请正确输入要查询学生的学号：");
	scanf("%s", ID);
	for (int i = 0; i < N; i++)
	{
		if (strcmp(stu[i].number, ID) == 0)
		{
			printf("\n排名    学号       姓名  平时成绩  实验成绩  期末成绩  总评成绩\n\n");
			printf("%2d   %s %7s %8.2f %9.2f %9.2f %9.2f\n", i + 1, stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiScore, stu[i].finalScore, stu[i].generalScore);
		}
	}
	printf("\n------信息查询完毕!-------\n\n");
}

//6.计算全班学生总评成绩的均值和标准方差
void analyse(SS stu[], int N)
{
	printf("\n------第五步：计算全班学生总评成绩的均值和标准方差------\n\n");
	float sum=0, σ=0;       //方差s，标准方差σ=s开根号
	for (int i = 0; i < N; i++)
	{
		sum += stu[i].generalScore;
	}
	sum = sum / (float)N;   //强制类型转换(类型名)(表达式)
	for (int i = 0; i < N; i++)
	{
		σ += (stu[i].generalScore - sum) * (stu[i].generalScore - sum);
	}
	σ = sqrt(σ / (float)N);
	printf("全班学生总评成绩的均值为:%6.2f\n", sum);
	printf("全班学生总评成绩的标准方差分别为:%6.2f\n", σ);
}

/*----------------------------------*
	           主函数
*-----------------------------------*/

int main()
{
	printf("**********************************************\n");
	printf("               学生成绩管理系统                \n");
	printf("                  HuiHuang                    \n");
	printf("**********************************************\n");
	/*-1.变量初始化-*/
	int N = 0;            //学生总数
	SS* pstu = NULL;    //学生数组-结构体数组指针实现

	//2.读取学生信息
	pstu = readDataFromFile(&N);

	/*-3.计算学生总成绩（总成绩 = 0.2*平时成绩+ 0.2*实验成绩 + 0.6*期末成绩)--*/
	calcuScore(pstu, N);

	/*-4.根据学生总成绩排名-*/
	sortScore(pstu, N);

	/*-5.按照排名输出学生信息-*/
	printOut(pstu, N);

	/*-6.通过学号查询学生信息-*/
	inquire(pstu, N);

	/*-7.计算全班学生总评成绩的均值和标准方差-*/
	analyse(pstu, N);

	/*-8.释放动态内存空间-*/
	free(pstu);


	system("pause");
	return 0;
}
