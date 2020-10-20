
/*----------------头文件--------------*/
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include <windows.h>
#include<iostream>
using namespace std;

//1.1求解一元二次方程的根
void Root()
{
    double a, b, c, disc, x1, x2, realpart, imagpart;    //实部，虚部
    printf("请输入一元二次方程的系数a，b，c（中间用空格隔开）：");
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("The equation ");
    if (fabs(a) <= 1e-6)              //a<0,不是二次方程
        printf("is not quadratic\n");
    else
    {
        disc = b * b - 4 * a * c;
        /*求disc=b^2-4ac，由于disc是实数，而实数在计算和存储时会有一些微小误差，
        因此不能直接进行如下判断：“if (disc==0)...” 。解决方法：判别disc的绝对
        值是否小于一个很小的数1e-6，如果小于此数，就认为disc等于0*/

        if (fabs(disc) <= 1e-6)       //△=0，有两个相等实根
            printf("has two equal roots:%8.4f\n", -b / (2 * a));
        else
            if (disc > 1e-6)          //△>0，有两个不等实根
            {
                x1 = (-b + sqrt(disc)) / (2 * a);
                x2 = (-b - sqrt(disc)) / (2 * a);
                printf("has distinct real roots:%8.4f and %8.4f\n", x1, x2);
            }
            else                      //△<0，有两个共轭复根
            {
                realpart = -b / (2 * a);
                imagpart = sqrt(-disc) / (2 * a);
                printf("has complex roots:\n");
                printf("%8.4f+%8.4fi\n", realpart, imagpart);
                printf("%8.4f-%8.4fi\n", realpart, imagpart);
            }
    }
    printf("\n");
}

//1.2对两个具有相同类型数据的交换
void swap()
{
    double a, b, t;
    cout << "请输入两个具有相同类型的数据a和b（中间用空格隔开）：";
    cin >> a >> b;
    t = a;
    a = b;
    b = t;
    cout << "交换后a=" << a << "  b=" << b << endl;
    cout << endl;
}

//2.计算输出三角形的面积
void area()
{
    double a, b, c;
    double s, area;
    printf("请输入三角形的三条边长（例如a = 3.67;b = 5.43;c = 6.21）：");
    scanf("%lf%lf%lf", &a, &b, &c);
    s = (a + b + c) / 2.0;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("a=%f\tb=%f\tc=%f\n", a, b, c);
    printf("area=%f\n", area);
    printf("\n");
}

//3.输入年月日，输出这一天是该年的第几天、第几周
void date()
{
    int i, n = 0;
    int year, month, week, day;   
    int a[2][12] = { {31,29,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31} };
    cout << "请输入年 月 日(中间用空格隔开):";
    cin >> year >> month >> day;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        cout << "该年为闰年，共366天，2月有29天"<<endl;
        for (i = 0; i < month-1; i++)
        {
            n += a[1][i];
        }
        n += day;
        week = n / 7 + 1;
        printf("这一天是该年的第%d天 第%d周\n", n, week);
    }
    else
    {
        cout << "该年为平年，共365天，2月有28天" << endl;
        for (i = 0; i < month-1; i++)
        {
            n += a[2][i];
        }
        n += day;
        week = n / 7 + 1;
        printf("这一天是该年的第%d天 第%d周\n", n, week);
    }
}


int main()
{
    printf("**********************************************\n");
    printf("               C++实现下列任务                 \n");
    printf("                  HuiHuang                    \n");
    printf("**********************************************\n");
    void Root();
    void swap();
    void area();
    void date();
    Root();
    swap();
    area();
    date();
    system("pause");
    return 0;
}

