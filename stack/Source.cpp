#include <iostream>
#include <string>
#include "ClSt.h"

using namespace std;
void main() {
	//std::string str="(2+2)*2";//���� �� ������ using namespace std;
	
	//string str;// ���� ������ using namespace std;
	/*������ string
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
	//�������� ���� ���������� �������� ���� empty �� ������ true
	
	2)

	// (2+2)*2 �������� � ������ string
	//�������� �������� ������� ��������� �������� ������������ ������
	//��������� ��� ����� ����� ������������� � �� ����������
	TStack<char> sc;
	//������� ����������� �������� ������� ����������� ������
	//���� ���� ������ �� ��������� ����� ����������� � ����������� ���� �������� ������ �� ������� �����
	*/

	//-------------------------------------------------------------------------------------------------------------------------------------
	TDStack<int> st(6);
	st.Push1(2);
	st.Push1(3);
	st.Push2(4);
	cout << st.Pop1() << " - Top one \n";
	cout << st.Top2() << " - Top two \n";
	cout << st.Pop2() << " - Pop two \n";
	cout << st.Top2() << " - Top two \n";
	
	


}