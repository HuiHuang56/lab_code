
/*************************************************
** 任务 : 设计点类Point，通过该类实现与点相关的各种操作
** 功能 : 空间点坐标的初始化, 坐标修改, 坐标位置输出
**        基于该Point类设计一个友元函数和一个友元类, 实现计算两个点之间的直线距离.
** 作者 : Huihuang
** 创建 : 2020-11-14
/**************************************************/

#include<cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

/*----------------------------------*
			  点类定义
*-----------------------------------*/
class Point
{
private:
	double x, y, z;
public:
	//构造函数
	Point(double& X, double& Y, double& Z)
	{
		x = X; y = Y; z = Z;
	}

	//析构函数
	~Point()
	{ }

	//友元函数(计算两点间直线距离)
	friend double Distance(Point A,Point B)
	{
		double t, D;
		t = (A.x - B.x) * (A.y - B.x) + (A.y - B.y) * (A.y - B.y) + (A.z - B.z) * (A.z - B.z);
		D = sqrt(t);
		return D;
	}

	//坐标修改
	void NewPoint(double& X, double& Y, double& Z)
	{
		x = X; y = Y; z = Z;
	}

	//坐标位置输出
	void PrintPoint()
	{
		cout << " x=" << x << ",  y=" << y << ",  z=" << z << endl;
	}
};








/*----------------------------------*
			  主函数
*-----------------------------------*/
int main()
{
	cout << "********点类设计与测试********" << endl << endl;

	double x, y, z;

	cout << "**********1.坐标输入**********" << endl << endl;

	cout << "请输入点A的空间坐标：";
	cin >> x >> y >> z;
	Point A(x, y, z);
	cout << "请输入点B的空间坐标：";
	cin >> x >> y >> z;
	Point B(x, y, z);

	cout << endl << "**********2.坐标修改**********" << endl << endl;

	cout << "请重新输入点A的空间坐标：";
	cin >> x >> y >> z;
	A.NewPoint(x, y, z);

	cout << endl << "**********3.坐标输出**********" << endl << endl;

	cout << "A点坐标：";
	A.PrintPoint();
	cout << "B点坐标：";
	B.PrintPoint();

	cout << endl << "*****4.计算两点间直线距离*****" << endl << endl;

	cout << "A,B两点间的直线距离为:" << Distance(A, B) << endl;

	cout << endl << "***********测试完毕!**********" << endl << endl;
	system("pause");
	return 0;
}