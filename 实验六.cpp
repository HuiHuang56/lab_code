
#define  _CRT_SECURE_NO_WARNINGS

/*************************************************
** 任务 : 设计研究生类，在main函数内定义研究生对象数组，然后单独定义普通研究生对象和
**        常研究生对象，最后输出各对象的基本信息、成绩等级和所有研究生的平均成绩。
** 函数 : 初始化与释放研究生对象数据（三构一析）
**        普通成员函数：输出研究生基本数据信息
**        常成员函数：输出研究生的基本数据信息；
**        友元函数：计算每个研究生对象的成绩等级
** 作者 : Huihuang
** 创建 : 2020-11-21
/**************************************************/

#include<cstdlib>
#include<cstring>
#include <iostream>
using namespace std;
const int N = 10;
int sum = 0; 


/*----------------------------------*
			 学生类的定义
*-----------------------------------*/

class Graduate
{
private:
	char* name;         //姓名
	char sex;           //性别：W女，F男
	char number[20];    //学号
	char research[20];  //研究领域
	char tutor[20];     //指导教师
	char university[20];//学校名称
	double score[6];    //入学成绩
	double average;     //平均成绩
	char grade;         //成绩等级
public:
	Graduate();	
	Graduate(char* na, char se, char* nu, char* re, char* tu, char* un, double* sc);
	Graduate(const Graduate& per);
	~Graduate();
	char* Getname();    //获取姓名
	void Display();     //普通成员函数显示学生信息
	void Display()const;//常成员函数显示学生信息
	void Input();       //输入学生信息
	void Average();   //计算平均成绩
	void Grade();//根据平均成绩输出成绩等级
	void DisplayGrade();//显示平均成绩输出成绩等级
};   


/*----------------------------------*
		  学生类的成员函数
*-----------------------------------*/

//无参构造函数
Graduate::Graduate()
{
//	cout << "调用无参构造函数" << endl;
	name = NULL;
}

//有参构造函数
Graduate::Graduate(char* na, char se, char* nu, char* re, char* tu, char* un, double* sc)
{
//	cout << "调用有参构造函数" << endl;
	if (na)
	{
		name = new char[strlen(na) + 1];   //避免浅拷贝
		strcpy(name, na);
	}
	sex = se;
	strcpy(number, nu);
	strcpy(research, re);
	strcpy(tutor, tu);
	strcpy(university, un);
	*score = *sc;
}

//拷贝构造函数
Graduate::Graduate(const Graduate& per)
{
	cout << "调用拷贝构造函数" << endl;
	if (per.name)
	{
		name = new char[strlen(per.name) + 1];
		strcpy(name, per.name);
	}
	sex = per.sex;
	strcpy(number, per.number);
	strcpy(research, per.research);
	strcpy(tutor, per.tutor);
	strcpy(university, per.university);
	*score = *per.score;
}

//析构函数
Graduate::~Graduate()
{
//	cout << "调用析构函数" << endl;
	if (name)
		delete[]name;
}

//提取姓名
char* Graduate::Getname()
{
	return name;   //用于搜索是否存在此人
}

//普通成员函数显示学生信息
void Graduate::Display()
{
	double* p = score;
	cout << "姓   名：" << name << endl;
	cout << "性   别：" << sex << endl;
	cout << "学   号：" << number << endl;
	cout << "研究领域：" << research<< endl;
	cout << "指导教师：" << tutor << endl;
	cout << "学校名称：" << university << endl;
	cout << "依次输出面对对象、操作系统、高等数学、离散属性、毛概、教育学6门考试成绩：" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << *(p + i) << "  ";
	}
}

//常成员函数显示学生信息
void Graduate::Display()const
{
	const double* p = score;
	cout << "姓   名：" << name << endl;
	cout << "性   别：" << sex << endl;
	cout << "学   号：" << number << endl;
	cout << "研究领域：" << research << endl;
	cout << "指导教师：" << tutor << endl;
	cout << "学校名称：" << university << endl;
	cout << "依次输出面对对象、操作系统、高等数学、离散属性、毛概、教育学6门考试成绩：" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << *(p + i) << "  ";
	}
}

//显示平均成绩与成绩等级
void Graduate::DisplayGrade()
{
	cout << "姓   名：" << name << endl;
	cout << "平均成绩：" << average << endl;
	cout << "成绩等级：" << grade << endl;
}

//输入学生信息
void Graduate::Input()
{
	char na[20];
	double* p = score;
	cout << "输入姓   名：";
	cin >> na;
	if (name)
		delete[]name;
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	cout << "输入性   别：";
	cin >> sex;
	cout << "输入学   号：";
	cin >> number;
	cout << "输入研究领域：";
	cin >> research;
	cout << "输入指导教师：";
	cin >> tutor;
	cout << "输入学校名称：";
	cin >> university;
	cout << "依次输入面对对象、操作系统、高等数学、离散属性、毛概、教育学6门考试成绩：" << endl;
	for (int i = 0; i < 6; i++)
	{
		cin >> *(p + i);
	}
}

//计算平均成绩
void Graduate::Average()
{
	double a = 0;
	double* p = score;
	for (int i = 0; i < 6; i++)
	{
		a = a + *(p + i);
	}
	average = (a / 6);
}

//根据平均成绩输出成绩等级
void Graduate::Grade()
{
	int n = average;
	switch (n / 10)
	{
	case 10:
	case 9:grade = 'A'; break;
	case 8:grade = 'B'; break;
	case 7:grade = 'C'; break;
	case 6:grade = 'D'; break;
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:grade = 'E'; break;
	default:break;
	}
}

/*----------------------------------*
			  普通函数
*-----------------------------------*/

//定义菜单函数
void menu()
{
	cout << "********1.录入信息********" << endl;
	cout << "********2.查询信息********" << endl;
	cout << "********3.浏览信息********" << endl;
	cout << "********4.浏览信息********" << endl;
	cout << "********5.成绩等级********" << endl;
	cout << "********0.退    出********" << endl;
}

//输入对象数组元素
void InputStu(Graduate* array)
{
	char ch;
	do
	{
		array[sum].Input();  //调用成员函数完成一个学生对象的数据输入
		sum++;
		cout << "继续输入吗？(Y or N)" << endl;
		cin >> ch;
	} while(ch=='Y');
}

//普通成员函数输出对象数组元素
void OutputStu1(Graduate* array)
{
	cout << "普通成员函数输出对象数组元素" << endl;
	cout << "研究生总人数=" << sum << endl;
	for (int i = 0; i < sum; i++)
	{
		array[i].Display();
		cout << endl;
	}
}

//常成员函数输出对象数组元素
void OutputStu2(Graduate* array)
{
	cout << "常成员函数输出对象数组元素" << endl;
	cout << "研究生总人数=" << sum << endl;
	for (int i = 0; i < sum; i++)
	{
		array[i].Display();
		cout << endl;
	}
}

//输出对象数组所有研究生的平均成绩与成绩等级
void OutputStuGrade(Graduate* array)
{
	cout << "研究生总人数=" << sum << endl;
	for (int i = 0; i < sum; i++)
	{
		array[i].Average();
		array[i].Grade();
		array[i].DisplayGrade();
		cout << endl;
	}
}

//按姓名查询
int SearchStu(Graduate* array, char* na)
{
	int i, j = N;
	for (i = 0; i < sum; i++)
	{
		if (strcmp(array[i].Getname(), na) == 0)
			j = i;
	}
	return j;
}


/*----------------------------------*
			   主函数
*-----------------------------------*/
int main()
{
	
	cout << "*******研究生类信息管理系统******" << endl << endl;
	cout << "-----------Huihuang------------" << endl << endl;
	cout << "----------2020-11-10-----------" << endl << endl;
	
	Graduate array[N];  //定义学生数组
	int choice;         //读入选项
	do
	{
		cout << endl;
		menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		if (choice >= 0 && choice <= 5)
			switch (choice)
			{
			case 1:InputStu(array); break;

			case 2:cout << "请输入要查询的学生姓名：" << endl;
				char na[20];
				cin >> na;
				int i;
				i = SearchStu(array, na);
				if (i == N)
					cout << "查无此人！" << endl;
				else
					array[i].Display();
				break;

			case 3:OutputStu1(array); break;//普通成员函数输出对象数组元素
				
			case 4:OutputStu2(array); break;//常成员函数输出对象数组元素

			case 5:cout << "输出所有研究生的平均成绩与成绩等级" << endl;
				OutputStuGrade(array); break;
			default:
				break;
			}
	} while (choice);

	cout << "************测试完毕!***********" << endl << endl;
	system("pause");
	return 0;
}