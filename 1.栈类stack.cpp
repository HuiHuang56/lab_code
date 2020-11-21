
/*************************************************
** 任务 : 设计栈类stack，通过该类实现与栈相关的各种基础操作
** 功能 : 栈内数据初始化、数据进栈、数据出栈、判断栈是空的还是满的、计算当前栈的大小等。
** 作者 : Huihuang
** 创建 : 2020-10-27
/**************************************************/
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int Maxsize = 10;

/*----------------------------------*
	          栈类定义
*-----------------------------------*/
class Stack
{
private:
	int top;             //栈顶访问指示器
	int date[Maxsize];   //存储栈数据
public:
	//构造函数
	Stack()
	{
		top = 0;
		memset(date, 0, sizeof(date));

		//memset函数,头文件<cstring>,将date中后sizeof(date)个字节的内容全部设为指定值0；
	}

	//析构函数
	~Stack()
	{ }

	//判断栈空
	bool isEmpty()
	{
		if (top == 0)
			return 1;
		else
			return 0;
	}

	//判断栈满
	bool isFull()
	{
		if (top == Maxsize)
			return 1;
		else
			return 0;
	}

	//入栈
	void push(double& e)
	{
		date[top] = e;
		top++;            //先入元素,后上移指示器
	}

	//出栈
	double pop()
	{
		top--;            //下移指示器到元素
		return date[top]; //输出元素
	}

	//计算当前栈的大小
	int sizeStack()
	{
		return top;
	}
};

int main()
{
	cout << "********栈类设计与测试********" << endl;

	//1.生成栈对象
	Stack ss;
	cout << "当前栈大小为： " << ss.sizeStack() << ", 允许继续入栈..." << endl << endl;

	//2.执行入栈操作
	double temp = 0;

	while (!ss.isFull())
	{
		cout << "压栈，请输入数据(输入0入栈终止)：";
		cin >> temp;

		//提前终止循环
		if (temp == 0)
		{
			cout << "***********入栈完毕!**********" << endl << endl;
			break;
		}

		ss.push(temp);
		cout << "成功入栈!" << endl;
	}

	//3. 输出栈内元素
	cout << "从栈顶依次输出当前栈内" << ss.sizeStack() << "个数据：" << endl;

	while (!ss.isEmpty())
	{
		cout << ss.pop() << " ";
	}
	cout << endl;
	cout << "***********出栈完毕!**********" << endl << endl;
	system("pause");
	return 0;
}