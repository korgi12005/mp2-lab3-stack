#pragma once

#include <string>

using namespace std;
template <class T>
class TStack {
private:
	int Size;
	T* stack;
	int NumLast;
public:
	TStack(int _Size = 10) : Size(_Size), NumLast(-1)
	{
		if (Size < 0)
			throw Size;
		stack = new T[Size];
	}

	TStack(const TStack<T>& ts) : Size(ts.Size), NumLast(ts.NumLast)
	{
		stack = new T[Size];
		for (int i = 0; i <= NumLast; i++)
		{
			stack[i] = ts.stack[i];
		}
	}

	friend std::ostream& operator<< (std::ostream& ostr, const TStack& ts)
	{
		for (int i = 0; i <= ts.NumLast; i++)
			ostr << ts.stack[i] << " ";
		return ostr;
	}

	bool Empty() const 
	{
		return (NumLast == -1);
	}

	bool Full() const 
	{
		return (NumLast == Size - 1);
	}

	bool operator== (const TStack& ts) const
	{
		if (NumLast != ts.NumLast) return false;
		for (int i = 0; i <= NumLast; i++)
			if (stack[i] != ts.stack[i]) return false;
		return true;
	}

	bool operator!= (const TStack& ts) const
	{
		return !(*this == ts);
	}

	void Clear()
	{
		NumLast = -1;
	}

	void Push(const T& elem)
	{
		if (Full())
			throw NumLast;
		stack[++NumLast] = elem;
	}

	T& Pop()
	{
		if (Empty())
			throw NumLast;
		return stack[NumLast--];
	}

	T& Top() const
	{
		if (Empty())
			throw NumLast;
		return stack[NumLast];
	}
	int TopNum() const 
	{
		return NumLast;
	}
	~TStack()
	{
		delete[] stack;
	}
};

//2 + 5 * 4 = 22 - инфиксная запись
// op1 op2 +  - посфиксная запись (операция записывается после операнда)
// 2 + 5 * 4 - 3 = 2 5 4 * + 3 -
// 1 / (2 + 5 * 4 - 3) = 1 2 5 4 * + 3 - /
//складываем числа в стек доходим до операции выполняем и кладем результат обратно в стек
//работа с арифметическими выражениями
// 2 3 обнаружиться когда в стеке остануться числа
// 2 3 - + обнаружиться когда в стеке не будет чисел


/*
алгоритм перевода из одной формы в другую
исходная строка 2+3*4^5
постфикс строка 2 3 4 5 ^ * +



*/




//-------------------------------------------------------------------------------------------------------------------------------------------------
/*
написать реализацию класса двойной стек 
нужно хранить в массиве и работать сразу с 2 массивами
создать одномер массив первый стек будет начин с начала памяти второй сразу за ним память x2
написать простой мейн который тестирует 
пуш в один в другой и печать всех элементов
поп из одного из другого и печать
оформить в виде отдельного репозитория и скинуть ссылку репозитория преподователю
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
	
	void Push1(const T& el) {//положить
		if (Full())
			throw "Full stack";
		mas[++NumLast1] = el;
		NumLast2++;
	}
	void Push2(const T& el) {//положить
		if (Full())
			throw "Full stack";
		mas[++NumLast2] = el;
	}
	T Pop1() {//взять
		if (Empty1())
			throw "Empty stack";
	
		return mas[NumLast1--];
	}
	T Pop2() {//взять
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