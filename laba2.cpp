//---------------------------------------------------------------------------

#include <conio.h>
#include <iostream>
#include <math.h>
#include <stdio.h>


using namespace std;

//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    double z, x, y, a, c, fi;

    cout << "enter value a" << endl;
    cin >> a;

    while (cin.get() != '\n')
    {
        cout << "Incorrect input! Try again!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> a;
    }

    cout << "enter value c" << endl;
    cin >> c;

    while (cin.get() != '\n')
    {
        cout << "Incorrect input! Try again!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> c;
    }

    cout << "enter value z" << endl;
    cin >> z;

    while (cin.get() != '\n')
    {
        cout << "Incorrect input! Try again!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> z;
    }


    if (z <= 1)
    {
        x = pow(z, 2) + 1;
    }

    else  x = pow(z, 2) + 1;

    cout << "press 0 - 2x,  1 - x^2,  else - x/3" << endl;
    switch (_getch())
    {

    case '0':
        fi = 2 * x;
        y = a * pow(sin(x), 3) * fabs(pow(fi, 2) - 1) + c * log(fabs(x)) + exp(x);
        cout << "Function value = " << y << endl;
        break;

    case '1':
        fi = x * x;
        y = a * pow(sin(x), 3) * fabs(pow(fi, 2) - 1) + c * log(fabs(x)) + pow(2.71, x);
        cout << "Function value = " << y << endl;
        break;

    case '2': default:
        fi = x / 3.;
        y = a * pow(sin(x), 3) * fabs(pow(fi, 2) - 1) + c * log(fabs(x)) + pow(2.71, x);
        cout << "Function value = " << y << endl;
        break;
    }


    return 0;
    _getch();


}

//---------------------------------------------------------------------------
