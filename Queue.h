#pragma once
#include <iostream>

template<class T>
class queue
{
public:
	queue(static int newSize=100);  //ctor;
	queue(int size, const T& item);  //param ctor; /// = T());//esa asem vor item-in default constructrov skzbnarjeqavori
	~queue(); //dtor;
	queue(const queue<T>& src); // copy ctor
	queue(queue<T>&& src);   // move ctor;
	queue<T>& operator=(const queue<T> &src); // assignment operator;
	queue<T>& operator=(queue<T>&& src); // move assingnment;
	void push(const T& item);
	void pop();
	T& front();
	T& rear();
	bool empty();
	bool full();
	int size() const;
	void clear();

private:
	int _size;
	int _front;
	int _rear;
	T* _queue;
};