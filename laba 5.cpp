// laba 5.cpp

//---------------------------------------------------------------------------

//#include <vcl.h>
//#pragma hdrstop

//---------------------------------------------------------------------------

//#pragma argsused


#include <conio.h>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <ctime>

using namespace std;

//---------------------------------------------------------------------------

int main()
{

	int a[500], array_size = 5, Sum, initial_input, element_index, first_negative, initial_sum_index;

	cout << "Input array size" << endl;
	cin >> array_size;

	cout << "Press 1 to input elements by keyboard. Press another key to make random input." << endl;
	cin >> initial_input;

	if (initial_input == 1)
	{

		cout << "Input " << array_size << " elements\n" << endl;

		for (element_index = 0; element_index < array_size; element_index++)
		{
			cout << "Input " << element_index << " element\n";
			while (!(cin >> a[element_index]) && cin.get() != '\n')
			{
				cout << "Incorrect input a[" << element_index << "]! Try again!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> a[element_index];
			}
		}
	}
	else {

		for (element_index = 0; element_index < array_size; element_index++)

			a[element_index] = -50 + 100 * rand() / 32767;

		for (int element_index = 0; element_index < array_size; element_index++)
		{
			cout << "Your element: a[" << element_index << "]= " << a[element_index] << endl;
		}

	}

	first_negative = 0;
	initial_sum_index = 0;
	for (element_index = 0; element_index < array_size; ++element_index)
	{
		if (a[element_index] < first_negative)
		{
			first_negative = a[element_index];
			cout << "First negative element is: " << first_negative << endl;
			cout << "Index of the first negative element is: " << element_index << endl;
			break;
		}
	}

	initial_sum_index = element_index;

	if (first_negative == 0)
	{
		cout << "Unable to determine the sum. No negative elements" << endl;
		system("pause");
	}

	else
	{
		if (initial_sum_index == array_size - 1)
		{
			cout << "Unable to determine the sum. First negative element at the end of the array" << endl;
			system("pause");
		}

		else
		{
			Sum = 0;
			for (element_index; element_index < array_size; element_index++)
			{
				if (fmod(element_index, 2) == 0 && element_index > initial_sum_index)
					Sum += fabs(a[element_index]);
			}

			cout << "The sum of modules of elements in even positions in array and located after the first negative element is: " << Sum << endl;
			system("pause");
			return(0);
		}
	}
}