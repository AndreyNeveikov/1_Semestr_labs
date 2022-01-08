//laba 4---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//#include <vcl.h>
//#pragma hdrstop

//---------------------------------------------------------------------------

//#pragma argsused

#include <conio.h>
#include <iostream>
#include <math.h>
#include <stdio.h>


typedef double (*TFun)(double, int);
void Input_value(double&);
void Input_value2(int&);
double Fun(double x, int n);  // Y(x)
double Sum(double x, int n);  // S(x)
double Razn(double x, int n); // |s-y|
void Out_Rez(double a, double b, double h, int n, TFun);

using namespace std;

int main()
{
	double a, b, h;
	int n;

	//Selecting value entry

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
		cout << "Enter the initial value of the limit 'a': ";
		Input_value(a);

		cout << "Enter the final limit value 'b': ";
		Input_value(b);

		cout << "Enter the value of the step for changing the initial value 'h': ";
		Input_value(h);

		cout << "Enter value 'n': ";
		Input_value2(n);
	}

	//Selecting function output

	cout << "Select operation: " << endl;
	cout << "1 - calculating function Y(x)" << endl;
	cout << "2 - calculating function S(x)" << endl;
	cout << "3 - calculating function |Y(x) - S(x)|" << endl;
	cout << "4 - output all functions " << endl;

	switch (_getch())
	{
	case '1':
		cout << "You choosed: Y(x). " << endl;
		Out_Rez(a, b, h, n, Fun);
		break;
	case '2':
		cout << "You choosed: S(x). " << endl;
		Out_Rez(a, b, h, n, Sum);
		break;
	case '3':
		cout << "You choosed: |Y(x) - S(x)|. " << endl;
		Out_Rez(a, b, h, n, Razn);
		break;
	default:
		cout << "You choosed outputing all functions\n" << endl;
		cout << endl;
		cout << "Y(x)" << endl;
		Out_Rez(a, b, h, n, Fun);
		cout << endl;
		cout << "S(x)" << endl;
		Out_Rez(a, b, h, n, Sum);
		cout << endl;
		cout << "|Y(x) - S(x)|" << endl;
		Out_Rez(a, b, h, n, Razn);
		break;
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

void Input_value2(int& Inputing_value)
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

double Fun(double x, int n)
{
	return (1 + 2 * x * x) * exp(x * x);
}

double Razn(double x, int n)
{
	return fabs(Fun(x, n) - Sum(x, n));
}

double Sum(double x, int n)
{
	double s, r;
	s = 1;
	r = 1;
	for (int k = 1; k <= n; ++k)
	{
		r = r * x * x / k;
		s += r * (2 * k + 1);
	}
	return s;
}
void Out_Rez(double a, double b, double h, int n, TFun f)
{
	unsigned short step = 1;
	double x;
	for (x = a; x <= b; x += h)
	{
		cout << "x = " << x << "F(x) = " << f(x, n) << endl;
	}
}
//---------------------------------------------------------------------------
