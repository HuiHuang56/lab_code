
/*************************************************
** 任务 : 熟悉类三种继承的定义形式,并深刻理解三种继承关系。请采用三种不同的继承方式
**        由base类分别派生出三个子类：derived1，derived2，derived3， 
** 要求 : 基类base，内含有数据成员，函数成员（print（），统计类对象创建个数的函数 static int statistic（））
** 作者 : Huihuang
** 创建 : 2020-12-3
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;


/*----------------------------------*
			  Base类定义
*-----------------------------------*/

class Base           //作为基类
{
//------------------成员数据------------------

public:
	int a;
protected:
	int b;
private:
	int c;
	static int count;

//------------------成员函数------------------

public:
	Base(int pub = 0, int pro = 0, int pri = 0) //有参构造
	{
		count++;
		cout << "Base() is called" << endl;

		this->a = pub;
		this->b = pro;
		this->c = pri;
	}

	~Base() //析构函数
	{
		count--;
		cout << "~Base() is called" << endl;
	}

	void print() //输出类的数据
	{
		cout << "基类对象成员数据:" << a << " " << b << " " << c << endl;
	}

	static int statistic() //统计类对象创建个数
	{
		cout << "对象创建个数为:" << count << endl;
	}
};
int Base::count = 0;


//--------------------研究三种不同的继承方式------------------------

class Derived1:public Base  //公有继承
{
private:
	int bb;
public:
	Derived1(int b = 2) :Base(2, 2, 2)
	{
		cout << "Derived1() is called" << endl;
		this->bb = b;
	}
	~Derived1()
	{
		cout << "~Derived1() is called" << endl;
	}

	void display()//探索公有继承
	{
		//基类数据传承探索
		a = 200;//a仍为公有数据,子类内可以直接访问
		b = 200;//b仍为保护数据,子类内可以直接访问
		//c = 200;//报错,基类私有成员在子类不可见

		//基类函数传承探索
		Base::print();
		cout << "自身添加数据成员: bb = "<<bb << endl;
	}
};

class Derived2: protected Base //保护继承
{
private:
	int cc;
public:
	Derived2(int c = 3) :Base(3, 3, 3)
	{
		cout << "Derived2() is called" << endl;
		this->cc = c;
	}
	~Derived2()
	{
		cout << "~Derived2() is called" << endl;
	}

	void display()//探索保护继承
	{
		//基类数据传承探索
		a = 300;//a变为保护数据,类内可以直接访问
		b = 300;//b变为保护数据,类内可以直接访问
		//c = 300;//报错,基类私有成员在子类不可见

		//基类函数传承探索
		Base::print();
		cout << "自身添加数据成员: cc = " << cc << endl;
	}
};

class Derived3 : private Base  //私有继承
{
private:
	int dd;
public:
	Derived3(int d = 4) : Base(4, 4, 4)
	{
		cout << "Derived3() is called" << endl;
		this->dd = d;
	}

	~Derived3()
	{
		cout << "~Derived3() is called" << endl;
	}

	void display()//探索私有继承
	{
		//基类数据传承探索
		a = 400;//a变为私有数据,子类内可以直接访问
		b = 400;//b变为私有数据,子类内可以直接访问
		//c = 400;//报错,基类私有成员在子类不可见

		//基类函数传承探索
		Base::print();
		cout << "自身添加数据成员: dd = " << dd << endl;
	}
};


/*----------------------------------*
			   主函数
*-----------------------------------*/

int main()
{

	//功能1:通过比较类的大小,证明无论哪种继承方式都会全盘接受基类成员,包括私有的成员

#if 1

	cout << "基类Base的大小为: " << sizeof(Base) << endl;
	cout << "--类Derived1的大小为: " << sizeof(Derived1) << endl;
	cout << "--类Derived2的大小为: " << sizeof(Derived2) << endl;
	cout << "--类Derived3的大小为: " << sizeof(Derived3) << endl;

	cout << "---------------------------------" << endl;

#endif
	
	//功能2:构造函数和析构函数的调用

#if 1

	Base a;
	a.print();
	cout << "---------------" << endl;

	Derived1 b;
	b.display();
	cout << "---------------" << endl;

	Derived2 c;
	c.display();
	cout << "---------------" << endl;

	Derived3 d;
	d.display();
	cout << "---------------" << endl;

#endif

	//功能3:三种继承的使用(类外访问探索)

#if 0
	//------------类B--公有继承--类A---------------
	B b;//派生类B的对象

	  b.a_pub = 200; //正确, 子类内仍然为公有成员,类内外均可访问
	//b.a_pro = 200; //错误,子类内仍然为保护成员,类内可直接访问,类外部可以
	//b.a_pri = 200; //错误,基类私有成员在子类内外均不可见

	//b.dispaly();   //正确,访问的是子类自身的公有成员
	//b.A::dispaly();//正确, 子类内函数仍然为公有成员,类内外均可访问

#endif
	
#if 0
	//------------类C--保护继承--类A---------------
	C c;//派生类C的对象
	//c.a_pub = 300;//错误,变为子类保护成员,无法类外直接访问
	//c.a_pro = 300;//错误,变为子类保护成员,无法类外直接访问
	//c.a_pri = 300;//错误,基类私有成员在子类内外均不可见

	//c.display();    //正确,访问的是子类自身的公有成员
	//c.A::dispaly(); //错误,变为子类的保护函数,不可类外访问

	
#endif

#if 0
	//------------类D--私有继承--类A---------------

	D d;//派生类D的对象

	//d.a_pub = 400; //报错,变为子类的私有成员,无法类外直接访问
	//d.a_pro = 400; //报错,变为子类的私有成员,无法类外直接访问
	//d.a_pri = 400; //报错,基类私有成员在子类内外均不可见

	//d.dispaly();    //报错,变为子类私有成员,无法类外直接访问
	//d.A::dispaly(); //错误,变量子类私有函数,无法类外直接访问

#endif
	
	system("pause");
	
	return 0;
}
