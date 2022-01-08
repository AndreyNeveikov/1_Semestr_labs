//---------------------------------------------------------------------------

//#include <vcl.h>
//#pragma hdrstop

//#pragma argsused


#include <conio.h>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

void Input_value(double&); 	//Input value with protection against incorrect input

int main()
{
    double x, y, k, a, b, h, sum, razn, rez, n;

    cout << "Press 1 to select standard numbers, or any other to enter values from the keyboard " << endl;
    if (_getch() == '1')
    {
        cout << "You have chosen the standard numbers, they are: а=0.1 , b=1 , h = 0.1, n = 10" << endl;
        a = 0.1;
        b = 1.0;
        h = 0.1;
        n = 10;
    }
    else
    {
        cout << "enter initial value a" << endl;
        Input_value(a);
        cout << "enter concluding value b" << endl;
        Input_value(b);
        cout << "enter step of changing h" << endl;
        Input_value(h);
        cout << "enter number of iterations N " << endl;
        Input_value(n);
    }

    for (x = a; x <= b; x += h)
    {
        rez = sum = 1;
        for (k = 1; k <= n; ++k)
        {
            rez = rez * x * x / k;
            sum += rez * (2 * k + 1);
        }
        y = (1 + 2 * x * x) * exp(x * x);
        razn = fabs(y - sum);
        cout << "x=" << x << "\t s(x)=" << sum << "\t y(x)=" << y << "\t |y(x)-s(x)|=" << razn << endl;
    }

    system("pause");
    return 0;
}

void Input_value(double& Inputing_value)
{
    cin >> Inputing_value;
    while (cin.get() != '\n')
    {
        cout << "Incorrect input!" << endl;
        cout << "Input value again: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> Inputing_value;
    }
}

//---------------------------------------------------------------------------