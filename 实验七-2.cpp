
/*************************************************
** 任务 : 以Location为基类，派生出三维空间坐标点类Point
**        再利用三维空间点类Point派生出一个三维空间下的球体类Sphere
** 要求 : 二维空间点类Location（数据成员x，y；函数成员move函数和show()函数）
**        定义Point点类和球体类Sphere中各自特有的move函数和show()函数
** 作者 : Huihuang
** 创建 : 2020-12-4
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;


/*----------------------------------*
			Location类定义
*-----------------------------------*/

class Location
{
protected:
	double x, y;
public:
	Location(double X = 0, double Y = 0) //有参构造
	{
		cout << "Location() is called" << endl;
		x = X; y = Y;
	}

	~Location() //析构函数
	{
		cout << "~Location() is called" << endl;
	}

	void move() //移动该类对象的坐标位置
	{
		cout << "移动直角坐标位置，请重新输入坐标(x,y)=";
		cin >> x >> y;
	}

	void show() //输出当前类对象的信息
	{
		cout << "当前直角坐标为：(" << x << "," << y << ")" << endl;
	}
};


/*----------------------------------*
			 Point点类
*-----------------------------------*/

class Point :public Location  //公有继承
{
protected:
	double z;
public:
	Point(double X,double Y,double Z = 0) :Location(X,Y),z(Z)
	{
		cout << "Point() is called" << endl;
	}

	~Point()
	{
		cout << "~Point() is called" << endl;
	}

	void move() //移动该类对象的坐标位置
	{
		cout << "移动空间坐标位置，请重新输入坐标(x,y,z)=";
		cin >> x >> y >> z;
	}

	void show() //输出当前类对象的信息
	{
		cout << "当前空间坐标为：(" << x << "," << y << "," << z << ")" << endl;
	}
};


/*----------------------------------*
			Sphere球体类
*-----------------------------------*/

class Sphere :public Point  //公有继承
{
protected:
	double r;
public:
	Sphere(double X, double Y, double Z, double R = 0) :Point(X, Y, Z), r(R)
	{
		cout << "Sphere() is called" << endl;
	}

	~Sphere()
	{
		cout << "~Sphere() is called" << endl;
	}

	void move() //移动该类对象的坐标位置
	{
		cout << "改变球体位置和大小，请重新输入坐标(x,y,z)=";
		cin >> x >> y >> z;
		cout << "请重新输入半径r=";
		cin >> r;
	}

	void show() //输出当前类对象的信息
	{
		cout << "当前球心坐标为：(" << x << "," << y << "," << z << ")" ;
		cout << ";    半径为：" << r << endl;
	}
};


/*----------------------------------*
			   主函数
*-----------------------------------*/

int main()
{
	Location l(3, 4);
	Point p(7.2,99,3.14);
	Sphere s(66, 3, 7, 18);
	cout << "-----------1.Location类----------" << endl;
	l.show();
	l.move();
	l.show();

	cout << "-----------2.Point类-------------" << endl;
	p.show();
	p.move();
	p.show();

	cout << "-----------3.Sphere类------------" << endl;
	s.show();
	s.move();
	s.show();
	system("pause");
	return 0;
}