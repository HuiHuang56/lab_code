
/*************************************************
** 任务 : 设计一个抽象基类Shapes, 该类内声明了一个纯虚函数display(),以表示图形输出的接口
** 要求 : Shapes类公有派生出了2个子类： Rectangle类，Circle类，主函数内定义抽象类Shapes
**        类型的指针数组Shapes *p[2]。要求当它其中的每个基类指针指向某个派生类对象时，
**        可以通过该指针访问到派生类各自的同名成员函数display()
** 作者 : Huihuang
** 创建 : 2020-12-12
/**************************************************/

#include <iostream>
using namespace std;

//−−−−−−−−−−−−−−−−−−抽象类Base−−−−−−−−−−−−−−−−−−−
class Shapes
{
public:
	virtual void display() = 0;//纯虚函数
};

//−−−−−−−−−−−−−−−−−具体类Rectangle−−−−−−−−−−−−−−
class Rectangles :public Shapes //公有继承自基类
{
private:
	double a, b;//长和宽
public:
	Rectangles(double _a, double _b)
	{
	    a = _a;
		b = _b;
	}
	~Rectangles() {}

	void display()//虚函数(和基类的display的函数原型相同)
	{
		cout << "矩形边长为: " << a << b << endl;
		cout << "矩形面积为: " << a * b << endl;
	}
};

//−−−−−−−−−−−−−−−−−具体类Circle−−−−−−−−−−−−−−
class Circles : public Shapes //公有继承自基类
{
private:
	double r;//半径
public:
	Circles(double _r)
	{
		r = _r;
	}
	~Circles(){}

	void display() //虚函数(和基类的display函数原型相同)
	{
		cout << "−−−−−−−−−−−−−−−−−−" << endl;
		cout << "圆的半径为: " << r << endl;
		cout << "圆的面积为: " << 3.14*r*r << endl;
		cout << "−−−−−−−−−−−−−−−−−−" << endl;
	}
};


/********************主函数**********************/
int main()
{
	Shapes *p[2]; //定义指针数组,数组内存放2个指针变量
	Rectangles rectangle(3, 4);//矩形对象
	Circles circle(2); //圆对象

	p[0] = &rectangle;//这里指哪,下面p[0]−>display()就打哪: 打矩形函数
	p[1] = &circle; //这里指哪,下面p[1]−>display()就打哪: 打圆形函数

	p[0]-> display();
	p[1]-> display();
    return 0;
}
