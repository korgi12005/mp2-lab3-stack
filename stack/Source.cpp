#include <iostream>
#include <string>
#include "ClSt.h"
#include "Calcul.h"

using namespace std;
void main() {
	//std::string str="(2+2)*2";//если не писать using namespace std;

	//string str;// если писать using namespace std;
	/*методы string
	str.size();
	str.length();
	str[0];


	*/
	/*
	cin >> str;
	int size = str.length();
	TStack<int> St(size);
	bool fl=true;
	for (int i = 0; i < size; i++) {
		if (str[i] == '(') {
			St.Push(str[i]);
		}
		if (str[i] == ')' && St.Empty() == true) {
			fl = false;
		}
		if (str[i] == ')' && St.Empty()==false) {
			St.Pop();
		}

	}
	if (St.Empty() == 0) {
		fl = false;
	}
	if (fl == true) {
		cout << "all good";
	}
	else
	{
		cout << "error";
	}

	TCalculator calc;
	*/

	/*
	1)
	TStack<int> st(10);
	st.Push(5); st.Push(2);
	//очистить стэк вытаскивая элементы пока empty не станет true

	2)

	// (2+2)*2 записано в строке string
	//написать алгоритм который проверяет верность расставления скобок
	//коректная это число скобо соответствует и их вложеность
	TStack<char> sc;
	//увидели открывающую положили увидели закрывающую вынули
	//если стэк пустой то правильно иначе неправильно и неправильно если пытаемся вынуть из пустого стэка
	*/

	//-------------------------------------------------------------------------------------------------------------------------------------

	//string tmp = "2.3+3.4";
	//size_t ind;
	//double dbf = stod(tmp, &ind);
	//cout << "str=" << tmp << "\n";
	//cout << "d=" << dbf << "\n";
	//cout << "ind=" << ind << "\n";

	TCalculator cal;
	string ex;
	cin >> ex;
	cal.SetExpr(ex);//написать метод 
	
	cout << cal.GetPostfix();//написать метод и переопред cout
	try {
		cout << cal.CalcOne();
	}
	catch (int a) {
		cout << "uncorrect expr " << a+1 << endl;
	}
	catch (char b) {
		cout << "uncorrect brackate " <<  endl;
	}
	/*
	для перевода строки в число мы воспользовались стандартной функцией для перевода
	
	*/
	
}
