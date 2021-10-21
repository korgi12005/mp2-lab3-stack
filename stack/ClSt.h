#pragma once

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
	void Clear() { NumLast = -1; }//отчистить стек
	void Push(const T& el) {//положить
		if (Full())
			throw "Full stack";
		pStack[++NumLast] = el;
	}
	T Pop() {//взять
		if (Empty())
			throw "Empty stack";
		return pStack[NumLast--];
	}
	T Top()const {
		if (Empty())
			throw "Empty stack";
		return pStack[NumLast--];
	}
};