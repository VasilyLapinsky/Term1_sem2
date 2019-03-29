// Семестровая2.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cout << "Enter size and after string ";
	cin >> n;
	cout << endl;
	char* mas = new char[n + 2];

	cin.getline(mas, n);
	for (int i = 0; i < n; ++i)
		cout << mas[i];
	cout << endl;
	int k1 = 0;
	bool b = true;
	for (int i = 0; i < n; ++i){
		b = true;
		for (int j = 65; j < 91 && b; ++j){
			if (mas[i] == (char)j){
				++k1;
				b = false;
			}
		}
	}
	int k2 = 0;
	for (int i = 0; i < n; ++i){
		if (mas[i] == '_') ++k2;
	}
	bool java, cpp;
	if (k1 != 0 && k2 == 0){
		java = true;
		cpp = false;
	}
	else if (k1 == 0 && k2 != 0){
		cpp = true;
		java = false;
	}
	else if (k1 != 0 && k2 != 0){
		cpp = false;
		java = false;
		cout << "Error!" << endl;
	}
	else if (k1 == 0 && k2 == 0){
		cpp = false;
		java = false;
		for (int i = 0; i < n; ++i)
			cout << mas[i];
		cout << endl;
	}
	if (java){
		int r = 0;
		for (int i = 0; i < n; ++i){
			b = true;
			for (int j = 65; j < 91 && b; ++j){
				if (mas[i] == (char)j){
					cout << '_' << (char)(j+32);
					b = false;
				}
			}
			if (b){
				cout<< mas[i];
				++r;
			}
		}
	}
	if (cpp){
		int r = 0;
		for (int i = 0; i < n - 1; ++i){
			if (mas[i] == '_'){
				b = false;
				for (int j = 97; j < 123 && !b; ++j){
					if (mas[i + 1] == (char)j){
						cout << (char)(j-32);
						++i;
						b = true;
					}
				}
			}
			else{
				cout << mas[i];
			}

		}
		if (mas[n - 1] == '_'){
		cout << '\0';
		}
		else{
			cout << mas[n-1 ];
		}
	}
	cout << endl;
	delete[] mas;

	system("pause");
	return 0;
}

