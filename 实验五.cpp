/*设计一个栈类stack，通过该类实现与栈相关的各种基础操作*/
#include <iostream>
#define Maxsize 10
using namespace std;

class Stack
{
private:
	int date[Maxsize];
	int top;
public:
	//栈内数据初始化
	void initstack()
	{
		top = -1;
	}
	//进栈
	int push(Stack S, int x)
	{
		if (stackfull(S))
		{
			cout << "栈满！" << endl;
			return 0;
		}
		else
		{ 
			cout << "进栈" << endl;
			top++;
			date[top] = x;
		}
		cout << "当前栈内元素为：";
		for (int j = 0; j <= top; j++)
		{
			cout << date[j] << "  ";
		}
		cout << endl;
		return 0;
	}
	//出栈
	int pop(Stack S)
	{
		if (stackempty(S))
		{
			cout << "栈空！" << endl;
			return 0;
		}
		else
		{
			cout << "出栈" << endl;
			top--;
			cout << "当前栈内元素为：";
			for (int j = 0; j <= top; j++)
			{
				cout << date[j] << "  ";
			}
			cout << endl;
			return date[top+1];
		}	
	}

	//计算当前栈的大小
	void size(Stack S)
	{
		cout << endl;
		int i;
		i = top + 1;
		cout << "当前栈的大小为：" << i << endl;
	}
	//判断栈空
	int stackempty(Stack S)
	{
		if (top == -1)
			return 1;
		else
			return 0;
	}
	//判断栈满
	int stackfull(Stack S)
	{
		if (top == Maxsize - 1)
			return 1;
		else
			return 0;
	}
};

int main()
{
	Stack S;
	S.initstack();
	S.push(S, 8);
	S.push(S, 4);
	S.push(S, -3);
	S.push(S, 19);
	S.pop(S);
	S.pop(S);
	S.size(S);	
}

