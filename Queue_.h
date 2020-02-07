#pragma once
#include<assert.h>
#include"Queue.h"


template<class T>
inline queue<T>::queue(int newSize) :_size(newSize), _rear(-1), _front(-1)
{
	std::cout << "Queue param ctor \n";
	_queue = new T[_size];
	
}


template<class T>
inline queue<T>::queue(int size, const T& item) : _size(size)/* _count(size), _flag(false)*/
{
	std::cout << "Param ctor \n";
	_queue = new T[_size];
	for (int i = 0; i < _size; ++i)
	{
		_queue[i] = item;
	}
}

template<class T>
inline queue<T>::~queue()
{
	
	std::cout << "Queue dtor \n";
	delete[]_queue;
	_queue = nullptr;
	
}

template<class T>
inline queue<T>::queue(const queue<T>& src)
{
	std::cout << "Queue copy ctor \n";
	_size = src._size;
	_rear = src._rear;
	_front = src._front;
	_queue = new T[_size];
		for (int i = 0; i < _size; ++i)
		{
			_queue[i] = src._queue[i];
		}
}

template<class T>
inline queue<T>::queue(queue<T>&& src)
{
	std::cout << "Queue move ctor \n";
	_size = src._size;
	_rear = src._rear;
	_front = src._front;
	_queue = src._queue;
	src._rear = 0;
	src._front = 0;
	src._size = 0;
	src._queue = nullptr;
}

template<class T>
inline queue<T>& queue<T>::operator=(const queue<T>& src)
{
	if (this != &src)
	{
		delete[] _queue;
		std::cout << "Queue assignment \n";
		_size = src._size;
		_rear = src._rear;
		_front = src._front;
		_queue = new T[_size];

		for (int i = 0; i < _size; ++i)
		{
			_queue[i] = src._queue[i];
		}
	//de en kanchvuma erb nor obyekta stexcvum,vorpes koctrucora en,isk es uxaki veragrman hamara
	}
	

	
		return (*this);
}

template<class T>
inline queue<T>& queue<T>::operator=(queue<T>&& src)
{
	if (this != &src)
	{
		delete[] _queue;

		std::cout << "Queue move assigment \n";
		_size = src._size;
		_front = src._front;
		_rear = src._rear;
		_queue = src._queue;
		src._queue = nullptr;
		src._size = 0;
		src._rear = 0;
		src._front = 0;
	}
	
	
	return(*this);
}

template<class T>
inline void queue<T>::push(const T& item)
{
	assert(!full());
	if (empty())
	{
		_front = _rear = 0;

	}
	else
	{
		_rear = (_rear + 1) % _size;
	}
	_queue[_rear] = item;
	}



template<class T>
inline void queue<T>::pop()
{
	assert(!empty());
		if (_front == _rear)
		{
			_rear = _front = -1;
		}
		else
			_front = (_front + 1) % _size;


}

template<class T>
inline T& queue<T>::front()
{
	assert(!empty());

		return _queue[_front];
	
}

template<class T>
inline T& queue<T>::rear()
{
	assert(!full());

		return _queue[_rear];


}

template<class T>
inline bool queue<T>::empty()
{
	return (_front == -1 && _rear == -1);
}

template<class T>
inline bool queue<T>::full()
{
	if (_size == 0)
		return false;
	else return (_rear + 1) % _size == _front;
}

template<class T>
inline int queue<T>::size() const
{
	return _size;
}

template<class T>
inline void queue<T>::clear()
{
	
		while (!empty())
			pop();
	
}



