#pragma once

#include <iostream>
using namespace std;
template<typename T>
class List
{
public:
	List();
	~List();


	void PopFront();

	/// @brief добавление элемента в конец
	/// @param data значение
	void PushBack(T data);


	void Clear();

	/// @brief получение размера списка
	/// @return размер списка
	int GetSize();

	/// @brief перегрузка оператора индексирования 
	/// @param index индекс
	/// @return значение
	T& operator[](const int index);


	//void PushFront(T data);
	//void Insert(T data, int index);
	//void RemoveAt(int index);
	void PopBack();
	

private:
	template<typename T>
	class Node
	{
	public:
		Node* pointNext;
		Node* pointPrev;
		T data;
		Node(T data = T(),Node * pointPrev = nullptr, Node* pointNext = nullptr) :
			data(data), pointPrev(pointPrev), pointNext(pointNext) {}
	};


private:
	int _size;
	Node<T>* _head;
	Node<T>* _tail;
};



template<typename T>
inline List<T>::List()
{
	_size = 0;
	_head = nullptr;
	_tail = nullptr;
}


template<typename T>
inline List<T>::~List()
{
	Clear();
}


template<typename T>
inline void List<T>::PopFront()
{
	if (_size == 0)
	{
		return;
	}
	Node<T>* temp = _head;
	_head = _head->pointNext;
	if (_size != 1)
	{
		_head->pointPrev = nullptr;
	}
	else if (_size == 1)
	{
		_head = nullptr;
		_tail = nullptr;
	}
	delete temp;
	--_size;
}


template<typename T>
inline void List<T>::PushBack(T data)
{
	if (_head == nullptr)
	{
		_head = new Node<T>(data);
	}
	else if (_tail == nullptr)
	{
		_tail = new Node<T>(data, _head);
		_head->pointNext = _tail;
	}
	else
	{
		Node<T>* current = _tail;
		_tail = new Node<T>(data, current);
		current->pointNext = _tail;
	}
	++_size;
}


template<typename T>
inline void List<T>::Clear()
{
	for (_size; _size > 0;)
	{
		PopFront();
		PopBack();
	}
}


template<typename T>
inline int List<T>::GetSize()
{
	return _size;
}


template<typename T>
inline T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current;
	if (index <= (_size / 2))
	{
		current = this->_head;
		while (counter <= (_size / 2))
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pointNext;
			counter++;
		}
	}
	counter = _size - 1;
	current = this->_tail;
	while (counter > (_size / 2))
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pointPrev;
		counter--;
	}
	
}


template<typename T>
inline void List<T>::PopBack()
{
	if (_size == 0)
	{
		return;
	}
	Node<T>* temp = _tail;
	_tail = _tail->pointPrev;
	if (_size != 1)
	{
		_tail->pointNext = nullptr;
	}
	else if(_size == 1)
	{
		_head = nullptr;
		_tail = nullptr;
	}
	delete temp;
	--_size;
}


