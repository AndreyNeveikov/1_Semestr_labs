/// laba 8.cpp

/* Написать программу обработки файла типа запись, содержащую следующие пункты меню:
«Создание», «Просмотр», «Коррекция»(добавление новых данных или редактирование старых),
«Решение индивидуального задания».
Каждая запись должна содержать следующую информацию о студентах :
– фамилия и инициалы;
– год рождения;
– номер группы;
– оценки за семестр : по физике, математике, информатике, химии;
– средний балл.
Организовать ввод исходных данных, средний балл рассчитать по введенным оценкам.

 12.  Распечатать анкетные данные студентов, имеющих оценки 7 или 8 по физике и оценки 9 или 10 по высшей математике.*/

 //#include <vcl.h>
 //#pragma hdrstop

 //---------------------------------------------------------------------------

 //#pragma argsused


#include <conio.h>
#include <io.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

struct Student_data
{
	char FIO[50];
	int Year_of_Birth;
	char Group[11];
	int mathematics;
	int chemistry;
	int programming;
	int physics;
	double average_mark()
	{
		return (mathematics + chemistry + programming + physics) / 4.;
	}
};

void Output_Student_data(Student_data s);
void Input_array_of_char_alpha(char* s);
void Input_array_of_char_digit(char* s);
void Input_value(int&);
void Fill_in_Student_data(char&, int&, char&, int&, int&, int&, int&);
void Change_document_info(char);
void Read_student_data();
void Output_student_with_necessary_marks();

int main()
{
	setlocale(LC_ALL, "rus");

	cout << "Здравствуйте!Данная программа позволяет работать с базой данных студентов содержащей следующие параметры : \n - ФИО\n - Год рождения\n - Группу\n - Отметки по математике, химии, информатике, физике \n - Средний балл студента\n" << endl;
	cout << "Выберите режим выполнения программы:\n Нажмите 1 для cоздания нового файла\n Нажмите 2 для добавления информации к уже существуюшим данным\n Нажмите 3 для просмотра информации о студентах\n Нажмите 4 для вывода информации о студентах, имеющих оценки 7 или 8 по физике и оценки 9 или 10 по высшей математике\n Нажмите любую другую клавишу для выхода из программы" << endl;

	switch (_getch())
	{
	case '1':
		cout << "\nСоздание нового файла ..." << endl;
		Change_document_info('w');
		break;

	case '2':
		cout << "\nДобавление к уже существуюшим данным ..." << endl;
		Change_document_info('a');
		break;

	case '3':
		cout << "\nПросмотр информации о студентах ..." << endl;
		Read_student_data();
		break;

	case '4':
		cout << "\nВывод информации о студентах, имеющих оценки 7 или 8 по физике и оценки 9 или 10 по высшей математике ..." << endl;
		Output_student_with_necessary_marks();
		break;

	default:
		cout << "\nЗавершение работы...\n Если вы закрыли программу случайно, пожалуйста, запустите программу снова и выберите вариант от 1 до 4" << endl;
		break;
	}
}

void Fill_in_Student_data(char* FIO, int& Birth_date, char* Group, int& mathematics, int& chemistry, int& programming, int& physics)
{
	cout << "Введите ФИО студента: " << endl;
	Input_array_of_char_alpha(FIO);

	cout << "Введите год рождения студента: ";
	Input_value(Birth_date);

	cout << "Введите номер группы студента: " << endl;
	Input_array_of_char_digit(Group);

	cout << "Введите отметку по математике студента: " << endl;
	Input_value(mathematics);

	cout << "Введите отметку по химии студента: " << endl;
	Input_value(chemistry);

	cout << "Введите отметку по программированию студента: " << endl;
	Input_value(programming);

	cout << "Введите отметку по физике студента: " << endl;
	Input_value(physics);
}

void Output_Student_data(Student_data s)
{
	printf("\n%s, Год рождения: %i, Группа: %s, Математика:%i, Химия:%i, Информатика:%i, Физика:%i. Средний балл:%2.1f", s.FIO, s.Year_of_Birth, s.Group, s.mathematics, s.chemistry, s.programming, s.physics, s.average_mark());
}

void Output_student_with_necessary_marks()
{
	FILE* File_record;
	errno_t error_kod;
	error_kod = fopen_s(&File_record, "Students.txt", "r");
	Student_data students;
	if (error_kod == 1)
		cout << "Невозможно открыть файл" << endl;
	else
	{
		while (fread(&students, sizeof(Student_data), 1, File_record))
		{
			if (students.physics > 6 && students.physics < 9 && students.mathematics > 8)
			{
				Output_Student_data(students);
				cout << endl;
			}
		}
	}
	fclose(File_record);
}

void Input_value(int& Inputing_value)
{
	cin >> Inputing_value;
	while (cin.get() != '\n')
	{
		cout << "Некорректный ввод!" << endl;
		cout << "Попробуйте ввести данные заново: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> Inputing_value;
	}
}

void Input_array_of_char_alpha(char* array_of_char)
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

void Input_array_of_char_digit(char* array_of_char)
{
	int element_index = 0;
	while (1)
	{
		array_of_char[element_index] = _getch();
		if (array_of_char[element_index] == 13)
		{
			break;
		}
		if (isdigit(array_of_char[element_index]) == 0 && array_of_char[element_index] != ' ')
		{
			continue;
		}
		cout << array_of_char[element_index];
		element_index++;
	}
	array_of_char[element_index] = '\0';
	cout << endl;
}

void Change_document_info(char mode)
{
	FILE* File_record;
	errno_t error_kod;
	error_kod = fopen_s(&File_record, "Students.txt", &mode);
	if (error_kod == 1)
		cout << "Невозможно открыть файл" << endl;
	else
	{
		int number_of_students, student_index = 0;
		cout << "Сколько студентов хотите добавить?" << endl;
		Input_value(number_of_students);
		Student_data student;
		while (student_index < number_of_students)
		{
			Fill_in_Student_data(student.FIO, student.Year_of_Birth, student.Group, student.mathematics, student.chemistry, student.programming, student.physics);
			fwrite(&student, sizeof(Student_data), 1, File_record);
			student_index++;
		}
	}
	fclose(File_record);
}

void Read_student_data()
{
	FILE* File_record;
	errno_t error_kod;
	error_kod = fopen_s(&File_record, "Students.txt", "r");
	Student_data students;
	if (error_kod == 1)
		cout << "Невозможно открыть файл" << endl;
	else
	{
		while (fread(&students, sizeof(Student_data), 1, File_record))
		{
			Output_Student_data(students);
			cout << endl;
		}
	}
	fclose(File_record);
}
