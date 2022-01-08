// laba 7.cpp 

/* 9. Дана строка символов, состоящая из цифр, разделенных пробелами.
	  Вывести на экран числа этой строки в порядке возрастания их значений. */

	  //#include <vcl.h>
	  //#pragma hdrstop

	  //---------------------------------------------------------------------------

	  //#pragma argsused


#include <conio.h>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <iomanip>


using namespace std;

void Output_array(int*, int);    //Output one-dimensional array
void Input_array_of_char(char* s);  //Allows you to enter data into a char array with protection against numbers and punctuation marks

int main()
{
	//Creating and filling the string

	setlocale(LC_ALL, "rus");

	char inputing_string[1000];

	cout << "Input string with a few numbers: " << endl << "(For example: -8 976 56 -25 1)\n " << endl;
	Input_array_of_char(inputing_string);
	cout << "Your string is:" << inputing_string << endl;

	int srting_lengh = strlen(inputing_string), element_index, Number_of_digits = 0;

	//Determine the number of digits in a line

	for (element_index = 0; element_index < srting_lengh; element_index++)
	{
		while (element_index < srting_lengh && inputing_string[element_index] == ' ')
		{
			element_index++;
		}
		if (element_index < srting_lengh)
		{
			Number_of_digits++;
		}
		while (element_index < srting_lengh && inputing_string[element_index] != ' ')
		{
			element_index++;
		}

	}

	cout << "\nThere is " << Number_of_digits << " numbers in your string.\n " << endl;

	//Extract single numbers from a string

	int* array_of_numbers = new int[Number_of_digits];
	int number, B_element_index = 0, /*beggining element index*/ E_element_index = 0, /*ending element index*/ index_of_numbers = 0;
	char temporary_string[10];

	for (element_index = 0; element_index < srting_lengh; element_index++)
	{
		while (element_index < srting_lengh && inputing_string[element_index] == ' ')
		{
			element_index++;
		}
		B_element_index = element_index; //The element index at which the number begins
		while (element_index < srting_lengh && inputing_string[element_index] != ' ')
		{
			element_index++;
		}
		E_element_index = element_index; //The index of the element that the number ends with
		strncpy_s(temporary_string, inputing_string + B_element_index, E_element_index - B_element_index);
		number = atoi(temporary_string);
		array_of_numbers[index_of_numbers] = number;
		index_of_numbers++;
	}

	//Sorting "bubble with permutations"

	int tmp;

	for (element_index = 0; element_index < Number_of_digits - 1; element_index++)
	{
		for (index_of_numbers = element_index + 1; index_of_numbers < Number_of_digits; index_of_numbers++)
		{
			if (array_of_numbers[element_index] > array_of_numbers[index_of_numbers])
			{
				tmp = array_of_numbers[index_of_numbers];
				array_of_numbers[index_of_numbers] = array_of_numbers[element_index];
				array_of_numbers[element_index] = tmp;
			}
		}
	}

	//Output result of sorting

	cout << "Numbers of a given string in ascending order of their values: " << endl;
	Output_array(array_of_numbers, Number_of_digits);

	delete[]array_of_numbers;

	system("pause");
	return 0;
}

void Output_array(int* _1d_array, int array_size)
{
	for (int element_index = 0; element_index < array_size; element_index++)
		cout << _1d_array[element_index] << " ";
	cout << endl;
}

void Input_array_of_char(char* array_of_char)
{
	//array_of_char[0] = ' ';
	int element_index = 0;
	while (1)
	{
		array_of_char[element_index] = _getch();
		if (array_of_char[element_index] == 13)
		{
			break;
		}
		if (isdigit(array_of_char[element_index]) == 0 && array_of_char[element_index] != ' ' && (array_of_char[element_index] == '-' && array_of_char[element_index - 1] == '-'))
		{
			continue;
		}
		cout << array_of_char[element_index];
		element_index++;
	}
	array_of_char[element_index] = '\0';
	cout << endl;
}
