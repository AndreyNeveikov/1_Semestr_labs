// laba 7.cpp 

/* 12. Дана строка, состоящая из слов, разделенных пробелами. Вывести на
экран порядковый номер слова, содержащего k - ю позицию, если в k - й позиции
пробел, то номер предыдущего слова.Значение k ввести с клавиатуры. */

//#include <vcl.h>
//#pragma hdrstop
//#pragma argsused

#include <conio.h>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

void Input_array_of_char(char* s);  //Allows you to enter data into a char array with protection against numbers and punctuation marks
void Input_value(int&); 	//Input value with protection against incorrect input

int main()
{
	//Creating and filling an array

	setlocale(LC_ALL, "rus");

	char inputing_string[1000];
	int position_number, word_counter = 0, number_of_letter = 0;

	cout << "Input string with a few words in english: " << endl;
	Input_array_of_char(inputing_string);
	cout << "Your string is: " << inputing_string << endl << endl;

	//Matching of the position number and element with rotection against incorrect input of position number

	cout << "Input the position number of the required element" << endl;
	Input_value(position_number);

	while (position_number > strlen(inputing_string) || position_number > 1000 || position_number < 1)
	{
		cout << "Element number is greater than the number of the last entered element or less than 1! Try again!" << endl;
		Input_value(position_number);
	}
	cout << "Position number matches element: '" << inputing_string[position_number - 1] << "'" << endl;

	//Output the ordinal number of the word containing the desired position

	for (number_of_letter = 0; number_of_letter < position_number; number_of_letter++)
		if (inputing_string[number_of_letter] == ' ')
		{
			word_counter++;

			if (inputing_string[number_of_letter] == ' ' && inputing_string[number_of_letter + 1] == ' ')
				word_counter = word_counter - 1;
		}


	if (inputing_string[position_number - 1] == ' ' && inputing_string[number_of_letter + 1] != ' ')
		word_counter = word_counter - 1;

	if (inputing_string[0] == ' ')
		word_counter = word_counter - 1;

	cout << "Your string contains " << word_counter + 1 << " words to a given element number" << endl << endl;

	system("pause");
	return 0;
}

void Input_array_of_char(char* array_of_char)
{
	int element_index = 0;
	while (1)
	{
		array_of_char[element_index] = _getch();
		if (array_of_char[element_index] == 13)
			break;
		if (isalpha(array_of_char[element_index]) == 0 && array_of_char[element_index] != ' ')
			continue;
		cout << array_of_char[element_index];
		element_index++;
	}
	array_of_char[element_index] = '\0';
	cout << endl;
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