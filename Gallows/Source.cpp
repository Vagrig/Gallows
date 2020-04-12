#include <iostream>
#include <string>
#include <windows.h>
#include <ctype.h>
#include <regex>
#include <algorithm>
#include <iomanip>

using namespace std;

void print(int value);
void output(string *tempArr, int size, int center);
void wrongOutput(char wrongLetters[], int sizeSTAT, int value);

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string word, letter;
	char ch;
	bool flag = true, temp = true, check = true, checkWrong = true,
		access = true, space = true, reg = false;
	int wrong = 0, count = 0, value = 0, center, size;
	const int sizeSTAT = 11;
	do
	{
		cout << "\n\n\t\t\t\t\t������� ���������� �����: ";
		cin >> word;
		cin.ignore(32767, '\n');
		cmatch result;
		regex regular("^[a-zA-Z�-���-ߨ]+$");
		reg = false;
		if (!(regex_match(word.c_str(), result, regular)))
		{
			reg = true;
			system("cls");
			cout << "\n\t\t\t\t\t\t������������ ����!\n";
		}
	} while (reg);
	size = word.size();
	string *arr = new string[size];
	string *tempArr = new string[size];
	char wrongLetters[sizeSTAT];
	system("cls");
	center = word.size() + word.size();
	cout << "\n\n\n";
	cout << setw((57 - center) + center / 2) << " ";
	for (int i = 0; i < word.size(); i++)
	{
		arr[i] = tolower(word[i]);
		tempArr[i] = "_";
		cout << tempArr[i] + " ";
	}
	while(flag)
	{
		cout << "\n\n\t\t\t\t\t\t�������� �����: ";
		cin >> letter;
		ch = *letter.c_str();
		if (!((ch >= 'a' && ch <= 'z') || (ch >= '�' && ch <= '�') || 
			(ch >= 'A' && ch <= 'Z') || (ch >= '�' && ch <= '�')) ||
			(letter.size() > 1))
		{
			system("cls");
			cout << "\n\t\t\t\t\t\t������������ ����!\n\n";
			output(tempArr, size, center);
			cout << endl << endl;
			wrongOutput(wrongLetters, sizeSTAT, value);
			continue;
		}
		transform(letter.begin(), letter.end(), letter.begin(), tolower);
		system("cls");
		for (int i = 0; i < word.size(); i++)
		{
			if (arr[i] == letter)
				if (tempArr[i] != arr[i])
				{
					tempArr[i] = letter;
					count++;
					check = false;
				}
				else
				{
					if (temp)
					{
						cout << "\n\t\t\t\t\t    �� ��� ������� ��� �����!\n";
						temp = false;
						space = false;
						check = false;
						break;
					}
				}
		}
		temp = true;
		if (check)
		{
			for (int i = 0; i < value; i++)
			{
				if (wrongLetters[i] == *letter.c_str())
				{
					checkWrong = false;
					space = false;
					cout << "\n\t\t\t\t\t    �� ��� ������� ��� �����!\n";
				}
			}
			if (checkWrong)
			{
				space = false;
				wrongLetters[value] = *letter.c_str();
				value++;
				wrong++;
				cout << "\n\t\t\t\t\t    ����� ����� ��� � �����!\n";
			}
			checkWrong = true;
		}
		check = true;
		if (space)
		{
			cout << endl << endl;
		}
		space = true;
		cout << endl;

		output(tempArr, size, center);
		if (value > 0)
		{
			cout << endl << endl;
			wrongOutput(wrongLetters, sizeSTAT, value);
		}
		if (wrong == 11)
		{
			string str = "���������� ����� ����: " + word;
			cout << "\n\n\t\t\t\t\t\t    ��������!" << endl;
			cout << setw(57 + str.length() / 2) << str << endl;
			break;
		}
		if (count == word.size())
		{
			cout << "\n\n\t\t\t\t\t\t     ������!" << endl;
			break;
		}
	}
	cout << endl;
	system("pause");
	delete[] arr;
	delete[] tempArr;
	return 0;
}

// ����� �� �����
void output(string *tempArr, int size, int center)
{
	cout << setw((57 - center) + center / 2) << " ";
	for (int i = 0; i < size; i++)
	{
		cout << tempArr[i] << " ";
	}
}

// ����� ������������ ����
void wrongOutput(char wrongLetters[], int sizeSTAT, int value)
{
	string temp, line = "������������ �����: ";
	string *mass = new string[value];
	for (int i = 0; i < value; i++)
	{
		mass[i] = wrongLetters[i];
		temp += "\"" + mass[i] + "\" ";
	}
	line += temp;
	cout << setw(57 + line.length() / 2) << line << endl;
	print(value);
}

// ����� ��������
void print(int value)
{
	cout << endl;
	if (value == 1)
	{
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
	}	
	else if (value == 2)
	{
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t   /" << endl;
	}			 
	else if (value == 3)
	{
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t   / \\" << endl;
	}			
	else if (value == 4)
	{
		cout << "\t\t\t\t\t\t     _______" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t   / \\" << endl;
	}
	else if (value == 5)
	{
		cout << "\t\t\t\t\t\t     _______" << endl;
		cout << "\t\t\t\t\t\t    |       |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t   / \\" << endl;
	}
	else if (value == 6)
	{
		cout << "\t\t\t\t\t\t     _______" << endl;
		cout << "\t\t\t\t\t\t    |       |" << endl;
		cout << "\t\t\t\t\t\t    |       O" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t   / \\" << endl;
	}
	else if (value == 7)
	{
		cout << "\t\t\t\t\t\t     _______" << endl;
		cout << "\t\t\t\t\t\t    |       |" << endl;
		cout << "\t\t\t\t\t\t    |       O" << endl;
		cout << "\t\t\t\t\t\t    |       |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t   / \\" << endl;
	}
	else if (value == 8)
	{
		cout << "\t\t\t\t\t\t     _______" << endl;
		cout << "\t\t\t\t\t\t    |       |" << endl;
		cout << "\t\t\t\t\t\t    |       O" << endl;
		cout << "\t\t\t\t\t\t    |      /|" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t   / \\" << endl;
	}
	else if (value == 9)
	{
		cout << "\t\t\t\t\t\t     _______" << endl;
		cout << "\t\t\t\t\t\t    |       |" << endl;
		cout << "\t\t\t\t\t\t    |       O" << endl;
		cout << "\t\t\t\t\t\t    |      /|\\" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t   / \\" << endl;
	}
	else if (value == 10)
	{
		cout << "\t\t\t\t\t\t     _______" << endl;
		cout << "\t\t\t\t\t\t    |       |" << endl;
		cout << "\t\t\t\t\t\t    |       O" << endl;
		cout << "\t\t\t\t\t\t    |      /|\\" << endl;
		cout << "\t\t\t\t\t\t    |      /" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t   / \\" << endl;
	}
	else if (value == 11)
	{
		cout << "\t\t\t\t\t\t     _______" << endl;
		cout << "\t\t\t\t\t\t    |       |" << endl;
		cout << "\t\t\t\t\t\t    |       O" << endl;
		cout << "\t\t\t\t\t\t    |      /|\\" << endl;
		cout << "\t\t\t\t\t\t    |      / \\" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t    |" << endl;
		cout << "\t\t\t\t\t\t   / \\" << endl;
	}
}