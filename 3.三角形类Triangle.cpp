
/*************************************************
** 任务 : 设计三角形类Triangle，通过该类实现与三角形相关的操作
** 功能 : 判断能否构成三角形、输出三角形周长、面积、类型（直角，锐角，还是钝角三角形）。
** 作者 : Huihuang
** 创建 : 2020-11-7
/**************************************************/

#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
const int Maxsize = 10;

/*----------------------------------*
	          三角形类定义
*-----------------------------------*/

class Triangle
{
private:
	double a, b, c;
public:
	//构造函数
	Triangle(double A,double B,double C)
	{
		a = A; b = B; c = C;
	}

	//析构函数
	Triangle()
	{ }

	//判断能否构成三角形
	int isTriangle()
	{
		if (a + b <= c || a + c <= b || b + c <= a)
			return 0;
		else
			return 1;
	}

	//计算三角形周长
	double perimeter()
	{
		if (isTriangle())
		{
			return a + b + c;
		}
		else
			return 0;
	}

	//计算三角形面积
	double area()
	{
		if (isTriangle())
		{
			double p, S;
			p = 0.5 * (a + b + c);
			S = sqrt(p * (p - a) * (p - b) * (p - c));
			return S;
		}
		else
			return 0;
	}

	//输出三角形类型（直角，锐角，还是钝角三角形）
	void type()
	{
		double cos_A, cos_B, cos_C;
		cos_A = (b * b + c * c - a * a) / (2 * b * c); //余弦定理
		cos_B = (a * a + c * c - b * b) / (2 * a * c);
		cos_C = (a * a + b * b - c * c) / (2 * a * b);
		if (cos_A < 0 || cos_B < 0 || cos_C < 0)
			cout << "钝角三角形" << endl;
		else if (cos_A == 0 || cos_B == 0 || cos_C == 0)
			cout << "直角三角形" << endl;
		else if (cos_A > 0 && cos_B > 0 && cos_C > 0)
			cout << "锐角三角形" << endl;
	}
};


/*----------------------------------*
			   主函数
*-----------------------------------*/
int main()
{
	cout << "********三角形类设计与测试********" << endl<<endl;
	double r1, r2, r3;
	cout << "请输入三角形的三条边（r1 r2 r3）：";
	cin >> r1 >> r2 >> r3;
	Triangle T(r1, r2, r3);
	cout << "三角形的周长为：" << T.perimeter()<<endl;
	cout << "三角形的面积为：" << T.area()<<endl;
	cout << "三角形的类型为：";
	T.type();
	cout << endl;
	cout << "************测试完毕!***********" << endl << endl;
	system("pause");
	return 0;
}