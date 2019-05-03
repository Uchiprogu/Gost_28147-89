// Gost_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
//#include <vcl.h>
#include <stdio.h>
//#include <curses.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
//#include <Arduino.h>
using namespace std;
void print(const string& str);
template< class T >
void input(vector<T> &arr, const int sizeKey = 0);

void input_drives(vector<string> &arr,string &drives_1, string &drives_2,const int count = 0, const int sizeKey = 32);

void printInputM(vector<string>& Text);
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "Russian");
	vector<string> Stroka;
	string drives_1, drives_2;
				//	 Ladyship it daughter securing procured or am moreover mr. Put si
				//	 r she exercise vicinity cheerful wondered. Continual say suspici
				//	 on provision you neglected sir curiosity unwilling. Simplicity e
				//	 nd themselves increasing led day sympathize yet. General windows
				//	 effects not are drawing man garrets. Common indeed garden you hi
				//	 s ladies out yet. Preference imprudence contrasted to remarkably
				//	 in on. Taken now you him trees tears any. Her object giving end 
				//	 sister except oppose.";
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "1) Открытые данные разбиваются на блоки по 64 бита" << endl;
	cout << "-----------------------------------------------------------------------" << endl;

	input(Stroka, 64);
	printInputM(Stroka);

	cout << "-----------------------------------------------------------------------" << endl;
	cout << "2) ввод первого блока в накопители N1 и N2" << endl;
	cout << "-----------------------------------------------------------------------" << endl;

	input_drives(Stroka, drives_1, drives_2);
	print(drives_1);
	print(drives_2);
	return 0;
}
//---------------------------------------------------------------------------
void print(const string& str)
{
	cout << "-----------" << endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	cout << endl;
	cout << "-----------" << endl;

}

template<class T>
void input(vector<T>& arr, const int sizeKey)
{
	std::string str;

	// I'm confused about whether you want a line, or a word.
	// this gets a line
	//std::getline(std::cin, str);
	str = ("Ladyship it daughter securing procured or am moreover mr. Put sir she exercise vicinity cheerful wondered. Continual say suspicion provision you neglected sir curiosity unwilling. Simplicity end themselves increasing led day sympathize yet. General windows effects not are drawing man garrets. Common indeed garden you his ladies out yet. Preference imprudence contrasted to remarkably in on. Taken now you him trees tears any. Her object giving end sister except oppose.");
	// this gets a word
	//std::cin >> str;

	int count = str.size();
	int countStr = 0;
	bool cStr = 0;
	if (count %sizeKey == 0)
	{
		countStr = count / sizeKey;
		cStr = 0;
	}
	else
	{
		countStr = 1 + count / sizeKey;
		cStr = 1;
	}

	for (int i = 0; i < countStr; i++)
	{
		string tmp;
		if (i == (countStr - 1) && cStr == 1)
		{
			tmp = str.substr(sizeKey*i, sizeKey);
			int tSize = tmp.size();
			for (int i = tSize; i < sizeKey; i++)
				tmp.push_back('*');
		}
		else
			tmp = str.substr(sizeKey*i, sizeKey);



		arr.push_back(tmp);
	}



}
void input_drives(vector<string> & arr, string &drives_1, string &drives_2, const int count, const int sizeKey)
{
	string tmp = arr[count];
	for (int i = 0; i < 64; i++)
	{
		if( i < sizeKey)
			drives_1.push_back(tmp[i]);
		if (i > sizeKey - 1 && i <64)
			drives_2.push_back(tmp[i]);
	}

}
void printInputM(vector<string>& Text)
{
	for (int i = 0; i < Text.size(); i++)
	{
		for (int j = 0; j < Text.at(i).size(); j++)
			cout << Text.at(i)[j];
		cout << endl;
	}
}