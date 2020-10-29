
/*----------------头文件--------------*/
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<time.h>
#include <iomanip>
#include<iostream>
using namespace std;


/*-----------------------------------*
		  一.斐波那契数列
*------------------------------------*/

int Fib(int n)
{
	int a = 1, b = 1, c;
	if (n <= 0)
		return 0;
	if (1 == n)
		return 1;
	if (2 == n)
		return 1;
	if (n > 2)
	{
		for (int i = 3; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return b;
	}
}

void Fibonacci()
{
	cout << "-------------- 任务一 --------------" << endl;
	cout << endl;
	cout << "请输入所求的斐波拉契数列的项数 N = ";
	int n;
	cin >> n;
	
	int* term = new int[n];  // 动态分配内存空间，存储前N项

	cout << "计算斐波拉契数列的前" << n << "项如下：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "term[" << i << "] = ";
		int m = Fib(i + 1);
		cout << m << endl;
	}
	delete[] term;           //释放动态内存空间
	cout << endl;
}


/*-----------------------------------*
			二.函数f(x)=0的根
*------------------------------------*/

const double eps = 1e-6; //ep是精度

//定义方程
double function(double x)       
{
	double temp = pow(x, 3) - 3 * pow(x, 2) + 2 * x;
	return temp;
}

//采用二分法寻找任意函数的一个零点(实根)
double Search(double& left, double& right)
{
	int count = 0;
	double middle = 0.5 * (left + right);

	while (fabs(function(middle)) > eps)
	{
		//cout << "开始第" << ++count << "次搜索..." << endl;

		if (function(left) * function(middle) < 0)
		{
			right = middle;
		}
		else
		{
			left = middle;
		}
		middle = 0.5 * (left + right);
	}
	return middle;
}

void Root()
{
	cout << "-------------- 任务二 --------------" << endl;
	cout << endl;

	double min, max;

	// 1. 输入函数自变量搜索范围
	cout << "请输入搜索左边界min = "; cin >> min;
	cout << "请输入搜索右边界max = "; cin >> max;
	
	//3.二分法,在[a,b]区间搜索给定方程的一个根(零点)

	double root = Search(min, max);

	cout << "二分法求得方程在给定区间的近似根为：" << setprecision(10)<< root << endl;
}


/*-----------------------------------*
			三.控制台窗口游戏
*------------------------------------*/

void Game()
{
	cout << "-------------- 任务三 --------------" << endl;
	cout << endl;
	const int Max = 10, Min = 1;
	int iRnd, iGuess;
	srand(time(0));
	iRnd = rand() % (Max + 1 - Min) + Min;
	do
	{
		printf("请选择一个在[%d,%d]间的数：", Min, Max);
		scanf("%d", &iGuess);
		if (iGuess > iRnd)
			printf("%d偏大\n", iGuess);
		else if (iGuess < iRnd)
			printf("%d偏小\n", iGuess);
		else if (iGuess = iRnd)
			printf("Ok!You are right!\n");
	} while (iGuess != iRnd);
	cout << endl;
}


/*-----------------------------------*
                主函数
*------------------------------------*/
int main()
{
	//1.斐波那契数列
	void Fibonacci();
	Fibonacci();

	//2.二分法计算函数f(x)=0的根
	void Root();
	Root();

	//3.猜数游戏
	void Game();
	Game();
	system("pause");
    return 0;
}