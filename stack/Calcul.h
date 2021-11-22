#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "ClSt.h"

using namespace std;

bool isOperator(char i) {
	if (i == '+' || i == '-' || i == '/' || i == '*' || i == '^')
		return true;
	return false;
}


class TCalculator {
	string expr; // выражение например (2+2)*3
	string postfix;//то же выражение записанное  в постфиксном виде 2 5 4 * + 3 -
	TStack<char> st_char;
	TStack<double> st_double;
public:

	/*
	везде где работаем со стеком проверять не пустой ли он 
	если пустой то  
	выражение составлено неправильно


	*/
	double CalcOne() {
		string input = "(" + expr + ")";
		st_char.Clear();
		st_double.Clear();
		for (int i = 0; i < input.size(); i++) {
			if (input[i] >= '0' && input[i] <= '9') {
				size_t ind;
				double num = stod(&input[i], &ind);
				st_double.Push(num);
				i += ind - 1;
			}
			if (input[i] == '(') {
				st_char.Push('(');
			}
			if (input[i] == ')') {
				while (st_char.Top() != '(') {
					if (st_double.TopNum() >= 1) {
						double two = st_double.Pop();
						double first = st_double.Pop();

						switch (st_char.Pop())
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
						case '/':
							st_double.Push(first / two);
							break;
						case '^':
							st_double.Push(pow(first, two));
							break;
						default:
							throw 0;
							break;
						}
					}
					else { throw st_double.TopNum(); }
				}

				st_char.Pop();

			}
			if (isOperator(input[i])) {
				while (Priority(st_char.Top()) >= Priority(input[i]) ) {
					
					if (st_double.TopNum() >= 1) {
						double two = st_double.Pop();
						double first = st_double.Pop();

						switch (st_char.Pop())
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
						case '/':
							st_double.Push(first / two);
							break;
						case '^':
							st_double.Push(pow(first, two));
							break;
						default:
							throw 0;
							break;
						}
					}
					else { throw st_double.TopNum(); }


				}
				st_char.Push(input[i]);
			}
		}
		
		

		if (st_double.TopNum() == -1) {
			throw st_double.TopNum();
		}
		else {
			if (st_double.TopNum() == 0 && st_char.Empty())
				return st_double.Pop();
			else
				throw st_double.TopNum();
		}
	}
	



	string GetPostfix() {
		return postfix;
	}

	friend ostream& operator<<(ostream& os, TCalculator& bf)
	{
		for (int i = 0; bf.postfix[i] != '\0'; i++)
			os << bf.postfix[i] << ' ';
		return os;
	}

	void SetExpr(string bf) {
		expr = bf;
		
	}

	int Priority(char op) {//функций присваения каждой операции приоретета доделать!!!!
		// у скобки ( приоретет 0
		// +- 1   */ 2   ^ 3
		if (op == '+' || op == '-')
			return 1;
		if (op == '*' || op == '/')
			return 2;
		if (op == '^')
			return 3;
		if (op == '(' || op == ')')
			return 0;
	}

	void ToPostfix();

	TCalculator(string _expr = "1") {
		expr = _expr;
		
	}
	double calc();
};
double TCalculator::calc() {
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] >= '1' && postfix[i] <= '9') {
			double tmp = stod(&postfix[i]);// функция принимает на вход строчку которую она будет конвертир string to double
			st_double.Push(tmp);
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
			if (st_double.Empty()) {
				throw "err";
			}
			double two = st_double.Pop();
			double first = st_double.Pop();
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
			case '/':
				st_double.Push(first / two);
				break;
			case '^':
				st_double.Push(pow(first, two));
				break;
			default:
				throw 0;
				break;
			}

		}

	}
	if (st_double.TopNum() >= 1)
		throw "err";
	return st_double.Pop();
}

void TCalculator::ToPostfix() {
	string infis = "(" + expr + ")";
	//почистить стек от предыдущих действий
	st_char.Clear();
	st_double.Clear();
	for (int i = 0; i < infis.length(); i++) {
		if (infis[i] <= '9' && infis[i] >= '0') {
			postfix += infis[i] ;
			postfix += ' ';
		}
		if (infis[i] == '(') {
			st_char.Push('(');
		}
		if (infis[i] == ')') {
			while (st_char.Top() != '(') {
				postfix += st_char.Pop() ;
				postfix += ' ';
			}
			st_char.Pop();//удаление открывающей скобки
		}
		if (isOperator(infis[i])) {
			int prioret = Priority(infis[i]);
			while (Priority(st_char.Top()) >= Priority(infis[i]) && st_char.Empty()==false) {
				postfix += st_char.Pop();
				postfix += ' ';

			}
			st_char.Push(infis[i]);
		}
	}


}

