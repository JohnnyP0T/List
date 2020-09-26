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
	void PopBack();

	/// @brief добавление элемента в конец
	/// @param data значение
	void PushBack(T data);
	/// @brief добавление элемента с начала
	/// @param data значение
	void PushFront(T data);

	void Sort();

	void Clear();

	/// @brief получение размера списка
	/// @return размер списка
	int GetSize();

	/// @brief перегрузка оператора индексирования 
	/// @param index индекс
	/// @return значение
	T& operator[](const int index);

	/// @brief вставка элемента по индексу
	/// @param data значение
	/// @param index индекс
	void Insert(T data, int index);

	/// @brief удаление по индексу
	/// @param index индекс
	void RemoveAt(int index);
	
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

	template<typename Node, typename T>
	class ListIterator
	{
	private:
		Node* value;
	public:
		ListIterator() : value(nullptr) {}
		ListIterator(Node* value) : value(value) {}


		bool operator != (const Node* _value) const
		{
			return (value != _value);
		}


		ListIterator& operator++()
		{
			if (value != nullptr)
			{
				value = value->pointNext;
			}
			return *this;
		}


		T& operator*()
		{
			return value->data;
		}


		ListIterator& operator++(int)
		{
			ListIterator it(*this);
			++* this;
			return it;
		}
	};

private:
	int _size;
	Node<T>* _head;
	Node<T>* _tail;

public:
	typedef ListIterator<Node<T>, T> iterator;
	typedef ListIterator<const Node<T>, const T> const_iterator;


	Node<T>* begin()
	{
		return _head;
	}


	Node<T>* end()
	{
		return nullptr;
	}


	Node<T>* begin() const
	{
		return _head;
	}


	Node<T>* end() const
	{
		return nullptr;
	}

private:
	Node<T>* MergeSortedLists(Node<T>* head1, Node<T>* head2)
	{
		Node<T>* result = NULL;
		if (head1 == NULL) {
			return head2;
		}
		if (head2 == NULL) {
			return head1;
		}
		if (head1->data < head2->data) {
			head1->pointNext = MergeSortedLists(head1->pointNext, head2);
			head1->pointNext->pointPrev = head1;
			head1->pointPrev = NULL;
			return head1;
		}
		else {
			head2->pointNext = MergeSortedLists(head1, head2->pointNext);
			head2->pointNext->pointPrev = head2;
			head2->pointPrev = NULL;
			return head2;
		}
	}


	void SplitList(Node<T>* src, Node<T>** fRef, Node<T>** bRef) {
		Node<T>* fast;
		Node<T>* slow;
		slow = src;
		fast = src->pointNext;
		while (fast != NULL) {
			fast = fast->pointNext;
			if (fast != NULL) {
				slow = slow->pointNext;
				fast = fast->pointNext;
			}
		}
		*fRef = src;
		*bRef = slow->pointNext;
		slow->pointNext = NULL;
	}


	void MergeSort(Node<T>** head) {
		Node<T>* p = *head;
		Node<T>* a = NULL;
		Node<T>* b = NULL;
		if (p == NULL || p->pointNext == NULL) {
			return;
		}
		SplitList(p, &a, &b);
		MergeSort(&a);
		MergeSort(&b);
		*head = MergeSortedLists(a, b);
		while (_tail->pointNext)
			_tail = _tail->pointNext;
	}

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
	//удаляем с конца и с начала
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
	//проверяем от куда быстрее найти нужный элемент
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
inline void List<T>::PushFront(T data)
{
	if (_head == nullptr)
	{
		_head = new Node<T>(data);
	}
	else if (_tail == nullptr)
	{
		_tail = new Node<T>(_head->data, _head);
		_head->pointNext = _tail;
		_head->data = data;
	}
	else
	{
		Node<T>* current = _head;
		_head = new Node<T>(data, nullptr, current);
		current->pointPrev = _head;
	}
	++_size;
}


template<typename T>
inline void List<T>::Sort()
{
	MergeSort(&_head);
}


template<typename T>
inline void List<T>::Insert(T data, int index)
{
	if (index == 0)
	{
		PushFront(data);
	}
	else if (index == _size)
	{
		PushBack(data);
	}
	else
	{
		Node<T>* previous;
		if (index <= (_size / 2))
		{
			previous = this->_head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pointNext;
			}
			previous->pointNext = new Node<T>(data, previous, previous->pointNext);
			//у следующего элемента после нового надо установить пердыдущий указатель
			previous = previous->pointNext;
			previous->pointNext->pointPrev = previous;
		}
		else
		{
			previous = this->_tail;
			for (int i = _size; i > index + 1; i--)
			{
				previous = previous->pointPrev;
			}
			previous->pointPrev = new Node<T>(data, previous->pointPrev, previous);
			previous = previous->pointPrev;
			previous->pointPrev->pointNext = previous;
		}
		++_size;
	}
}


template<typename T>
inline void List<T>::RemoveAt(int index)
{
	if (index == 0)
	{
		PopFront();
	}
	else if (index == _size)
	{
		PopBack();
	}
	else
	{
		Node<T>* previous;
		if (index <= (_size / 2))
		{
			previous = this->_head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pointNext;
			}
			Node<T>* toDelete = previous->pointNext;
			previous->pointNext = toDelete->pointNext;
			toDelete->pointNext->pointPrev = previous;
			delete toDelete;
		}
		else
		{
			previous = this->_tail;
			for (int i = _size; i > index + 1; i--)
			{
				previous = previous->pointPrev;
			}
			Node<T>* toDelete = previous->pointPrev;
			previous->pointPrev = toDelete->pointPrev;
			toDelete->pointPrev->pointNext = previous;
			delete toDelete;
		}
		--_size;
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




