// laba 6.cpp 

/* 12. В матрице размером n найти сумму элементов, лежащих ниже побочной диагонали,
и произведение элементов, лежащих выше побочной диагонали.*/


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
#include <iomanip>

using namespace std;


void Input_value(int&); 	//Input value with protection against incorrect input
void Fill_in_2d_array_randomly(int**, int, int);	//Fill in two-dimensional array randomly

//---------------------------------------------------------------------------

int main()
{
	//Creation of two-dimensional dynamic array

	int** _2d_array;
	int Sum = 0, Product = 1, number_of_rows, number_of_columns, element_index_in_row, element_index_in_column, way_of_input;
	cout << "Input size of matrix. (number of rows and columns) \n";

	Input_value(number_of_rows);
	number_of_columns = number_of_rows;
	if (number_of_rows < 3)
	{
		cout << "There are not enough elements below the main diagonal and above the side diagonal! \nPlease enter a value greater than two." << endl;
	}

	else
	{
		_2d_array = new int* [number_of_rows];
		for (element_index_in_row = 0; element_index_in_row < number_of_rows; ++element_index_in_row)
			_2d_array[element_index_in_row] = new int[number_of_columns];

		//Ways of filling in array

		cout << "Choose the way of input. " << endl;
		cout << "Press 1 to input from keyboard or press another key to input randomly. " << endl;
		cin >> way_of_input;

		//Keyboard input

		if (way_of_input == 1)
		{
			for (element_index_in_row = 0; element_index_in_row < number_of_rows; ++element_index_in_row)
				for (element_index_in_column = 0; element_index_in_column < number_of_columns; ++element_index_in_column)
				{
					cout << "a[" << element_index_in_row + 1 << "] [" << element_index_in_column + 1 << "] = ";
					cin >> _2d_array[element_index_in_row][element_index_in_column];
				}

			for (element_index_in_row = 0; element_index_in_row < number_of_rows; ++element_index_in_row)
			{
				for (element_index_in_column = 0; element_index_in_column < number_of_columns; ++element_index_in_column)
				{
					cout << setw(7) << _2d_array[element_index_in_row][element_index_in_column];
				}
				cout << endl;
			}
		}

		//Random input

		else
		{
			cin.clear();
			srand(time(0));
			Fill_in_2d_array_randomly(_2d_array, number_of_rows, number_of_columns);
		}

		//Search for the product of elements above the side diagonal

		for (element_index_in_row = 0; element_index_in_row < number_of_rows - 1; ++element_index_in_row)

			for (element_index_in_column = 0; element_index_in_column < number_of_rows - 1 - element_index_in_row; ++element_index_in_column)
			{
				Product *= _2d_array[element_index_in_row][element_index_in_column];
			}

		cout << "The product of elements above the side diagonal is: " << Product << endl;

		//Search for the sum of elements below the side diagonal

		for (element_index_in_row = number_of_rows - 1; element_index_in_row >= 0; --element_index_in_row)

			for (element_index_in_column = number_of_columns - 1; element_index_in_column >= number_of_rows - element_index_in_row; --element_index_in_column)
			{
				Sum += _2d_array[element_index_in_row][element_index_in_column];
			}

		cout << "The sum of elements below the side diagonal is: " << Sum << endl;

		//Freeing memory

		for (element_index_in_row = 0; element_index_in_row < number_of_rows; ++element_index_in_row)
			delete[] _2d_array[element_index_in_row];
		delete[] _2d_array;
	}
}


void Input_value(int& Inputing_value)
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


void Fill_in_2d_array_randomly(int** _2d_array, int number_of_rows, int number_of_columns)
{
	int min_limit, max_limit, element_index_in_row1, element_index_in_column1;
	cout << "Enter a range of random numbers (minimal limit and maximal limit): \n \nInput minimal limit: " << endl;
	Input_value(min_limit);
	cout << "Input maximal limit:" << endl;
	Input_value(max_limit);
	cout << endl;

	for (element_index_in_row1 = 0; element_index_in_row1 < number_of_rows; ++element_index_in_row1)
	{
		for (element_index_in_column1 = 0; element_index_in_column1 < number_of_columns; ++element_index_in_column1)
		{
			_2d_array[element_index_in_row1][element_index_in_column1] = min_limit + (max_limit - min_limit) * rand() / 32767.;
			cout << setw(7) << _2d_array[element_index_in_row1][element_index_in_column1];
		}
		cout << endl;
	}
	cout << endl;
}
