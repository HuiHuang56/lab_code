
#define _CRT_SECURE_NO_WARNINGS

/*************************************************
** 任务 : 设计字符串类string，通过该类实现与字符串相关的各种操作
** 功能 : 字符串连接、字符串比较、字符串增删改查操作、字符串反转操作、字符串长度计算等。
** 作者 : Huihuang
** 创建 : 2020-11-5
/**************************************************/

#include <cstring>
#include <iostream>
using namespace std;
const int N = 20;

/*----------------------------------*
			 字符串类定义
*-----------------------------------*/
class String
{
private:
	char* p_str;
	int length;

public:
	String();
	String(const char* str);
	~String();
	bool empty();                       //判断字符串是否为空
	int size();                         //计算字符串长度
	char* display();                    //输出字符串
	void reverse();                     //字符串反转

	int compare(const String& s);       //比较当前字符串和s的大小
	int append(String& s);              //把字符串s连接到当前字符串结尾
	int insert(String& s, int pos = 0); //在当前字符串第 pos 位置前插入字符串 s
	int erase(int pos = 0, int n = 0);  //删掉当前字符串 pos 开始，长度为 n 的字符
};


/*----------------------------------*
		  字符串类成员函数
*-----------------------------------*/

//无参构造函数
String::String() :p_str(NULL), length(0) {}

//有参构造函数
String::String(const char * str)
{
	length = strlen(str);
	p_str = new char[length + 1];
	strcpy(p_str, str);
	p_str[length] = '\0';
}

//析构函数
String::~String()
{
	delete[] p_str;
}

//判断字符串是否为空
bool String::empty() 
{

	return length ==0 ? 1 : 0;
}

//计算字符串长度
int String::size() 
{
	return length;
}

//输出字符串
char * String::display() 
{
	return p_str;
}

//字符串反转
void String::reverse() 
{
	String res;
	res.length = length;
	res.p_str = new char[length + 1];
	for (int i = 0; i < length; ++i)
		res.p_str[i] = p_str[length -1-i];
	res.p_str[length] = '\0';
	strcpy(p_str, res.p_str);
}


//字符串连接
int String::append(String & s) 
{   //把字符串s连接到当前字符串结尾
	int len = length + s.length;
	String res;
	res.length = len;
	res.p_str = new char[len + 1];
	for (int i = 0; i < length; ++i)
		res.p_str[i] = p_str[i];
	for (int i = length; i < len; ++i)
		res.p_str[i] = s.p_str[i - length];
	res.p_str[len] = '\0';

	length = len;
	p_str = new char[len + 1];
	strcpy(p_str, res.p_str);
	return 1;
}

//字符串比较
int String::compare(const String & s) 
{   //比较当前字符串和s的大小 （返回值：1大于，-1小于，0等于）
	int len = min(length, s.length);
	int j = 0;
	for (int i = 0; i < len; ++i) 
	{
		if (p_str[i] != s.p_str[i])
		{
			j = i;
			break;
		}
	}
	if (p_str[j] > s.p_str[j])
		cout << "s1 > s2\n" << endl;
	else if (p_str[j] < s.p_str[j])
		cout << "s1 < s2\n" << endl;
	else
		cout << "s1 = s2\n" << endl;
	return 0;
}

//字符串插入
int String::insert(String & s, int pos) 
{   //在当前字符串第 pos 位置前插入字符串 s
	if (pos < 0 || pos > length) 
	{
		cout << "out of range\n";
		return 0;
	}
	int len = length + s.length;
	String res;
	res.length = len;
	res.p_str = new char[len + 1];
	for (int i = 0; i < pos; ++i)
		res.p_str[i] = p_str[i];
	for(int i = pos; i < pos + s.length; ++i)
		res.p_str[i] = s.p_str[i-pos];
	for(int i = pos+s.length; i < len; ++i)
		res.p_str[i] = p_str[i - s.length];
	res.p_str[len] = '\0';

	length = len;
	p_str = new char[len + 1];
	strcpy(p_str, res.p_str);
	return 1;
}

//字符串删除
int String::erase(int pos, int n) 
{   //删掉当前字符串 pos 开始，长度为 n 的字符
	if(pos < 0 || pos+n > length)
	{
		cout << "out of range\n";
		return 0;
	}
	int len = length - n;
	String res;
	res.length = len;
	res.p_str = new char[len + 1];
	for (int i = 0; i < pos; ++i)
		res.p_str[i] = p_str[i];
	for (int i = pos + n; i < length; ++i)
		res.p_str[i - n] = p_str[i];
	res.p_str[len] = '\0';

	length = len;
	p_str = new char[len + 1];
	strcpy(p_str, res.p_str);
	return 1;
}


/*----------------------------------*
			   主函数
*-----------------------------------*/
int main()
{
	cout << "********字符串类设计与测试********" << endl << endl;

	int n, pos;
	char str1[N], str2[N], str3[N], str4[N];
	
	cout << "---------1.字符串长度计算---------" << endl << endl;

	cout << "请输入第一个字符串s1：" << endl;
	cin >> str1;
	String s1(str1);
	cout << "请输入第二个字符串s2：" << endl;
	cin >> str2;
	String s2(str2);
	cout << "字符串s1的长度为：" << s1.size() << endl;
	cout << "字符串s2的长度为：" << s2.size() << endl << endl;
	
	cout << "-----------2.字符串比较-----------" << endl << endl;

	s1.compare(s2);
		
	cout << "-----------3.字符串连接-----------" << endl << endl;

	s1.append(s2);
	cout << "s2连接到s1末尾：" << endl << s1.display() << endl << endl;

	cout << "-----------4.字符串反转-----------" << endl << endl;

	s1.reverse();
	cout << "s1反转后" << s1.display() << endl << endl;
	s1.reverse();
	
	cout << "-----------5.字符串插入-----------" << endl << endl;

	cout << "请输入第三个字符串s3：" << endl;
	cin >> str3;
	String s3(str3);
	cout << "请输入你想插入s3的字符串s4：";
	cin >> str4;
	String s4(str4);
	cout << "请输入你想插入的位置pos(第一个字符的位置为0)：";
	cin >> pos;
	if (s3.insert(s4, pos))
		cout << "插入后的s3为：" << endl << s3.display() << endl << endl;


	cout << "-----------6.字符串删除-----------" << endl << endl;

	cout << "删掉当前字符串 pos 开始，长度为 n 的字符" << endl;
	cout << "请输入你想删除s3的位置pos(第一个字符的位置为0)：";
	cin >> pos;
	cout << "请输入长度n：";
	cin >> n;
	if (s3.erase(pos, n))
		cout << "删除后的s3为：" << endl << s3.display() << endl << endl;
	

	cout << "************测试完毕!***********" << endl << endl;
	system("pause");
	return 0;
}
