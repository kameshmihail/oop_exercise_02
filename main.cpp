/* Камеш М.А. группа М80-107Б-18
Создать класс BritishMoney для работы с денежными суммами в старой британской система. Сумма денег должна быть представлено тремя полями: типа unsigned long long для фунтов стерлингов, типа unsigned char – для шиллингов, unsigned char – для пенсов (пенни). Реализовать сложение сумм, вычитание, деление сумм, деление суммы на дробное число, умножение на дробное число и операции сравнения. 1 фунт = 20 шиллингов, 1 шиллинг = 12 пенни.
Операции сложения, вычитания, умножения, деления, сравнения (на равенство, больше и меньше) должны быть выполнены в виде перегрузки операторов.
Необходимо реализовать пользовательский литерал для работы с константами типа BritishMoney.*/


#include<iostream>
using namespace std;

class BritishMoney
{
private:

public:
    long double funts = 0, shillings = 0, pennies = 0;
    BritishMoney(long long r = 0, unsigned char i = 0, unsigned char k = 0)
    {
        funts = r;
        shillings = i;
        pennies = k;
    }
    void print()
    {
        cout << funts << " funts " << shillings << " shillings "  << pennies << " pennies "  << endl;
    }

    friend BritishMoney operator + (BritishMoney &, BritishMoney &);
    friend BritishMoney operator - (BritishMoney &, BritishMoney &);
    friend BritishMoney operator * (BritishMoney &, long double &);
    friend long double operator / (BritishMoney &, BritishMoney &);
    friend BritishMoney operator / (BritishMoney &, long double &);
    friend char operator > (BritishMoney &, BritishMoney &);
};

long double operator"" _fun(long double x )
{
    return x * 240;
}

long double operator"" _sh( long double x )
{
    return x * 12;
}

long double operator"" _pen( long double x )
{
    return x;
}

BritishMoney operator + (BritishMoney &c1, BritishMoney &c2)
{
    c1.pennies = (c1.pennies + c2.pennies + c1.funts + c2.funts + c1.shillings + c2.shillings);
    c1.funts = 0;
    c1.shillings = 0;
    if (c1.pennies > 0)
    {
        while(c1.pennies >= 12*20)
        {
            c1.pennies -= 12*20;
            c1.funts++;
        }
        while (c1.pennies >= 12)
        {
            c1.pennies -= 12;
            c1.shillings ++;
        }
    }
    else if (c1.pennies < 0)
    {
        c1.pennies*=(-1);
        while(c1.pennies >= 12*20)
        {
            c1.pennies -= 12*20;
            c1.funts++;
        }
        while (c1.pennies >= 12)
        {
            c1.pennies -= 12;
            c1.shillings ++;
        }
        c1.funts*=(-1);
    }
    return BritishMoney(c1.funts, c1.shillings, c1.pennies);
}


BritishMoney operator - (BritishMoney &c1, BritishMoney &c2)
{
    c1.pennies = (c1.funts + c1.shillings + c1.pennies) - (c2.funts + c2.shillings + c2.pennies);
    c1.funts = 0;
    c1.shillings = 0;
    if (c1.pennies > 0)
    {
        while(c1.pennies >= 12*20)
        {
            c1.pennies -= 12*20;
            c1.funts++;
        }
        while (c1.pennies >= 12)
        {
            c1.pennies -= 12;
            c1.shillings ++;
        }
    }
    else if (c1.pennies < 0)
    {
        c1.pennies*=(-1);
        while(c1.pennies >= 12*20)
        {
            c1.pennies -= 12*20;
            c1.funts++;
        }
        while (c1.pennies >= 12)
        {
            c1.pennies -= 12;
            c1.shillings ++;
        }
        c1.funts*=(-1);
    }
    return BritishMoney(c1.funts, c1.shillings, c1.pennies);
}

BritishMoney operator * (BritishMoney &c1, long double &temp)
{
    c1.pennies = (c1.funts+c1.shillings+c1.pennies) * temp;
    c1.funts = 0;
    c1.shillings = 0;
    if (c1.pennies > 0)
    {
        while(c1.pennies >= 12*20)
        {
            c1.pennies -= 12*20;
            c1.funts++;
        }
        while (c1.pennies >= 12)
        {
            c1.pennies -= 12;
            c1.shillings ++;
        }
    }
    else if (c1.pennies < 0)
    {
        c1.pennies*=(-1);
        while(c1.pennies >= 12*20)
        {
            c1.pennies -= 12*20;
            c1.funts++;
        }
        while (c1.pennies >= 12)
        {
            c1.pennies -= 12;
            c1.shillings ++;
        }
        c1.funts*=(-1);
    }
    return BritishMoney(c1.funts, c1.shillings, c1.pennies);
}


BritishMoney operator / (BritishMoney &c1, long double &temp)
{
    c1.pennies = (c1.funts+c1.shillings+c1.pennies)/ temp;
    c1.funts = 0;
    c1.shillings = 0;
    if (c1.pennies > 0)
    {
        while(c1.pennies >= 12*20)
        {
            c1.pennies -= 12*20;
            c1.funts++;
        }
        while (c1.pennies >= 12)
        {
            c1.pennies -= 12;
            c1.shillings ++;
        }
    }
    else if (c1.pennies < 0)
    {
        c1.pennies*=(-1);
        while(c1.pennies >= 12*20)
        {
            c1.pennies -= 12*20;
            c1.funts++;
        }
        while (c1.pennies >= 12)
        {
            c1.pennies -= 12;
            c1.shillings ++;
        }
        c1.funts*=(-1);
    }
    return BritishMoney(c1.funts, c1.shillings, c1.pennies);
}

long double operator / (BritishMoney &c1, BritishMoney &c2)
{
    return (c1.funts+c1.shillings+c1.pennies)/(c2.funts+c2.shillings+c2.pennies);
}

char operator > (BritishMoney &c1, BritishMoney &c2)
{
    if ((c1.funts+c1.shillings+c1.pennies) - (c2.funts+c2.shillings+c2.pennies) > 0)
    {
        return '>';
    }
    else if ((c1.funts+c1.shillings+c1.pennies) - (c2.funts+c2.shillings+c2.pennies) < 0)
    {
        return '<';
    }
    else if ((c1.funts+c1.shillings+c1.pennies) - (c2.funts+c2.shillings+c2.pennies) == 0)
    {
        return '=';
    }
}


int main()
{
    long double temp = 3;
    char compare;
    BritishMoney c1, c2, c3;
    cout << "This program does arithmetic operation with British currencies : funts, shillings and pounds. It adds, substracts, multiplies, devides and compares sums and sums with numbers" << endl;
    cout << "Addition" << endl;
    c1.funts = 1.0_fun;
    c1.shillings = 4.0_sh;
    c1.pennies = 6.0_pen;
    c2.funts = 0.0_fun;
    c2.shillings = 0.5_sh;
    c2.pennies = 4.0_pen;
    c3 = c1 + c2;
    c3.print();
    c1.funts = 180.0_fun;
    c1.shillings = 412.7_sh;
    c1.pennies = 761.3_pen;
    c2.funts = 832.0_fun;
    c2.shillings = 123.0_sh;
    c2.pennies = -125.4_pen;
    c3 = c1 + c2;
    c3.print();
    cout << "Substraction" << endl;
    c1.funts = 5.0_fun;
    c1.shillings = 4.0_sh;
    c1.pennies = 7.0_pen;
    c2.funts = 3.0_fun;
    c2.shillings = 6.0_sh;
    c2.pennies = 9.0_pen;
    c3 = c1 - c2;
    c3.print();
    c1.funts = 245.2_fun;
    c1.shillings = 186.2_sh;
    c1.pennies = 367.3_pen;
    c2.funts = 393.2_fun;
    c2.shillings = 123.4_sh;
    c2.pennies = 252.8_pen;
    c3 = c1 - c2;
    c3.print();
    cout << "Multiplication by number" << endl;
    c1.funts = 6.0_fun;
    c1.shillings = 7.0_sh;
    c1.pennies = 11.0_pen;
    temp = 0;
    c3 = c1 * temp;
    c3.print();
    c1.funts = 5.4_fun;
    c1.shillings = 3.6_sh;
    c1.pennies = 1.3_pen;
    temp = -23.7;
    c3 = c1 * temp;
    c3.print();
    cout << "Division by sum" << endl;
    c1.funts = 5.0_fun;
    c1.shillings = 5.0_sh;
    c1.pennies = 5.0_pen;
    c2.funts = 1.0_fun;
    c2.shillings = 1.0_sh;
    c2.pennies = 1.0_pen;
    temp = c1 / c2;
    cout << temp << endl;
    c1.funts = 120.0_fun;
    c1.shillings = 5.4_sh;
    c1.pennies = 7.0_pen;
    c2.funts = 73.0_fun;
    c2.shillings = 13.0_sh;
    c2.pennies = 4.0_pen;
    temp = c1 / c2;
    cout << temp << endl;
    cout << "Division by number" << endl;
    c1.funts = 4.0_fun;
    c1.shillings = 4.0_sh;
    c1.pennies = 8.0_pen;
    temp = 2;
    c3 = c1 / temp;
    c3.print();
    c1.funts = 542.0_fun;
    c1.shillings = 340.0_sh;
    c1.pennies = 23.0_pen;
    temp = 41.6;
    c3 = c1 / temp;
    c3.print();
    cout << "Comparison" << endl;
    c1.funts = 5.0_fun;
    c1.shillings = 6.0_sh;
    c1.pennies = 7.0_pen;
    c2.funts = 3.0_fun;
    c2.shillings = 30.0_sh;
    c2.pennies = 15.0_pen;
    compare = c1 > c2;
    cout << "Sum1 " << compare << " Sum2" << endl;
    c1.funts = 126.0_fun;
    c1.shillings = 7.0_sh;
    c1.pennies = 5.0_pen;
    c2.funts = 124.0_fun;
    c2.shillings = 73.4_sh;
    c2.pennies = 7.0_pen;
    compare = c1 > c2;
    cout << "Sum1 " << compare << " Sum2" << endl;
    return 0;
}
