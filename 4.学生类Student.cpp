
#define  _CRT_SECURE_NO_WARNINGS

/*************************************************
** 任务 : 设计学生类Student，处理学生信息（姓名、性别、学号、出生日期、家庭住址、6个科目的考试成绩）
** 对外接口:   构造函数：初始化学生类对象（无参构造，有参构造，拷贝构造，至少3种）
**            普通函数：获取学生任意信息，修改学生成绩信息，输出学生信息
**            析构函数：释放学生类对象内存空间
** 作者 : Huihuang
** 创建 : 2020-11-10
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

class Student
{
private:
	char* name;         //姓名
	char sex;          //性别：W女，F男
	char number[20];    //学号
	char breath[20];    //出生日期(20001101)
	char address[20];   //家庭住址
	double score;       //成绩
public:
	Student();	
	Student(char* na, char se, char* nu, char* br, char* ad, double sc);
	Student(const Student& per);
	~Student();
	char* Getname();
	void Display();     //显示学生信息
	void Input();       //输入学生信息
};   


/*----------------------------------*
		  学生类的成员函数
*-----------------------------------*/

//无参构造函数
Student::Student()
{
//	cout << "调用无参构造函数" << endl;
	name = NULL;
}

//有参构造函数
Student::Student(char* na, char se, char* nu, char* br, char* ad, double sc)
{
//	cout << "调用有参构造函数" << endl;
	if (na)
	{
		name = new char[strlen(na) + 1];   //避免浅拷贝
		strcpy(name, na);
	}
	sex = se;
	strcpy(number, nu);
	strcpy(breath, br);
	strcpy(address, ad);
	score = sc;
}

//拷贝构造函数
Student::Student(const Student& per)
{
	cout << "调用拷贝构造函数" << endl;
	if (per.name)
	{
		name = new char[strlen(per.name) + 1];
		strcpy(name, per.name);
	}
	sex = per.sex;
	strcpy(number, per.number);
	strcpy(breath, per.breath);
	strcpy(address, per.address);
	score = per.score;
}

//析构函数
Student::~Student()
{
//	cout << "调用析构函数" << endl;
	if (name)
		delete[]name;
}

//提取姓名
char* Student::Getname()
{
	return name;   //用于搜索是否存在此人
}

//显示学生信息
void Student::Display()
{
	cout << " 姓   名：" << name << endl;
	cout << " 性   别：" << sex << endl;
	cout << " 学   号：" << number << endl;
	cout << " 出生日期：" << breath<< endl;
	cout << " 家庭住址：" << address << endl;
	cout << " 考试成绩：" << score << endl;
}

//输入学生信息
void Student::Input()
{
	char na[20];
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
	cout << "输入出生日期：";
	cin >> breath;
	cout << "输入家庭地址：";
	cin >> address;
	cout << "输入考试成绩：";
	cin >> score;
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
	cout << "********0.退    出********" << endl;
}

//输入对象数组元素
void InputStu(Student* array)
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

//输出对象数组元素
void OutputStu(Student* array)
{
	cout << "学生总人数=" << sum << endl;
	for (int i = 0; i < sum; i++)
	{
		array[i].Display();
		cout << endl;
	}
}

//按姓名查询
int SearchStu(Student* array, char* na)
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
	
	cout << "*******学生类信息管理系统********" << endl << endl;
	cout << "-----------Huihuang------------" << endl << endl;
	cout << "----------2020-11-10-----------" << endl << endl;
	
	Student array[N];  //定义学生数组
	int choice;         //读入选项
	do
	{
		cout << endl;
		menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		if (choice >= 0 && choice <= 3)
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

			case 3:OutputStu(array); break;

			default:
				break;
			}
	} while (choice);

	cout << "************测试完毕!***********" << endl << endl;
	system("pause");
	return 0;
}