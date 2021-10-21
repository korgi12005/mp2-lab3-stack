#pragma once

#include <string>

using namespace std;
template <class T>
class TStack {
private:
	int size;
	T* pStack;
	int NumLast;
public:
	TStack(int _size = 10): size(_size), NumLast(-1)
	{
		if (_size < 0)
			throw _size;
		pStack = new T[size];
	}
	~TStack() {	delete[] pStack;}
	TStack(const TStack<T> &bf)
	{
		size = bf.size;
		NumLast = bf.NumLast;
		pStack = new T[size];
		for (int i = 0; i <= NumLast; i++) {
			pStack[i] = bf.pStack[i];
		}
	}
	bool Empty() const {
		if (NumLast == -1)
			return true;
		else return false;
	}
	bool Full() const {
		if (NumLast == size-1)
			return true;
		else return false;
	}
	void Clear() { NumLast = -1; }//��������� ����
	void Push(const T& el) {//��������
		if (Full())
			throw "Full stack";
		pStack[++NumLast] = el;
	}
	T Pop() {//�����
		if (Empty())
			throw "Empty stack";
		int bf = NumLast;
		return pStack[bf];
	}
	T Top()const {
		if (Empty())
			throw "Empty stack";
		int bf = NumLast-1;
		return pStack[bf];
	}
};

//2 + 5 * 4 = 22 - ��������� ������
// op1 op2 +  - ���������� ������ (�������� ������������ ����� ��������)
// 2 + 5 * 4 - 3 = 2 5 4 * + 3 -
// 1 / (2 + 5 * 4 - 3) = 1 2 5 4 * + 3 - /
//���������� ����� � ���� ������� �� �������� ��������� � ������ ��������� ������� � ����
//������ � ��������������� �����������
// 2 3 ������������ ����� � ����� ���������� �����
// 2 3 - + ������������ ����� � ����� �� ����� �����
/*
class TCalculator {
	string expr;
	string postfix;// 2 5 4 * + 3 -
	TStack<char> st_char;
	TStack<double> st_double;
public:
	TCalculator(string _expr="1")  {
		expr = _expr;
		TStack<char> _st(expr.length);
		st_char = _st;
	}
	double calc();
};
double TCalculator::calc() {
	for (int i = 0; i < postfix.length; i++) {
		if (postfix[i] >= '1' && postfix[i] <= '9') {
			double tmp = stod(&postfix[i]);// ������� ��������� �� ���� ������� ������� ��� ����� ��������� string to double
			st_double.Push(tmp);
		}
		if (postfix[i] == '+' || postfix[i]=='-' || postfix[i]=='*') {
			if (st_double.Empty) {
				throw "err";
			}
			double two = st_double.Pop;
			double first=st_double.Pop;
			switch (postfix[i])
			{
			case '+':
				st_double.Push(first + two);
				break;
			case '-':
				st_double.Push(first - two);
				break;
			case '*':
				st_double.Push(first * two);
				break;
			default:
				throw 0;
				break;
			}
			
		}

	}
	if (st_double.Top >= 1)
		throw "err";
	return st_double.Pop();
}
*/
//-------------------------------------------------------------------------------------------------------------------------------------------------
/*
�������� ���������� ������ ������� ���� 
����� ������� � ������� � �������� ����� � 2 ���������
������� ������� ������ ������ ���� ����� ����� � ������ ������ ������ ����� �� ��� ������ x2
�������� ������� ���� ������� ��������� 
��� � ���� � ������ � ������ ���� ���������
��� �� ������ �� ������� � ������
�������� � ���� ���������� ����������� � ������� ������ ����������� �������������
*/
template <class T>
class TDStack {
	T* mas;
	int size;
	int NumLast1, NumLast2;

public:
	TDStack(int _size = 10) : size(_size), NumLast1(-1), NumLast2(NumLast1+1)
	{
		if (_size < 0)
			throw _size;
		mas = new T[size];
	}
	~TDStack(){ delete[] mas; }
	TDStack(const TStack<T>& bf)
	{
		size = bf.size;
		NumLast1 = bf.NumLast1;
		NumLast2 = bf.NumLast2;
		mas = new T[size];
		for (int i = 0; i <= NumLast1; i++) {
			mas[i] = bf.mas[i];
		}
		for (int i = NumLast1; i <= NumLast2; i++) {
			mas[i] = bf.mas[i];
		}
	}

	bool Empty1() const {
		if (NumLast1 == -1)
			return true;
		else return false;
	}
	bool Empty2() const {
		if (mas[NumLast2] == Top1())
			return true;
		else return false;
	}
	bool Full() const {
		if (NumLast2 == size - 1 || NumLast1==size-1)
			return true;
		else return false;
	}
	
	void Push1(const T& el) {//��������
		if (Full())
			throw "Full stack";
		mas[++NumLast1] = el;
		NumLast2++;
	}
	void Push2(const T& el) {//��������
		if (Full())
			throw "Full stack";
		mas[++NumLast2] = el;
	}
	T Pop1() {//�����
		if (Empty1())
			throw "Empty stack";
	
		return mas[NumLast1--];
	}
	T Pop2() {//�����
		if (Empty2())
			throw "Empty stack";
		return mas[NumLast2--];
	}
	T Top1()const {
		if (Empty1())
			throw "error";
		else
		return mas[NumLast1];
	}
	T Top2()const {
		if (Empty2())
			throw "Empty stack";
		return mas[NumLast2];
	}

};