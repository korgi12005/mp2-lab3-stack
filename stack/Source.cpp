#include <iostream>
#include <string>
#include "ClSt.h"

using namespace std;
void main() {
	std::string str="(2+2)*2";//���� �� ������ using namespace std;
	string str1;// ���� ������ using namespace std;
	/*������ string
	str.size();
	str.length();
	str[0];
	
	
	*/

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

}