#pragma once

#include <iostream>
#include <exception>


template<typename T>
class List
{

public:
	template<class T>
	class ListIterator;

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

	/// @brief линейный поиск
	/// @param data значение
	/// @return значение если такое есть
	ListIterator<T> LinearSearch(T data);

	/// @brief получение размера списка
	/// @return размер списка
	int GetSize();

	/// @brief вставка элемента по индексу
	/// @param data значение
	/// @param index итератор
	void Insert(T data, ListIterator<T> iter);

	/// @brief удаление по индексу
	/// @param index итератор
	void RemoveAt(ListIterator<T> iter);
	
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

	template<typename T>
	class ListIterator
	{
	private:
		Node<T>* value;
	public:
		friend class Node<T>;
		friend class List<T>;
		ListIterator() : value(nullptr) {}
		ListIterator(Node<T>* value) : value(value) {}


		bool operator == (const ListIterator it) const
		{
			return(value == it.value);
		}


		bool operator != (const ListIterator it) const
		{
			return (value != it.value);
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


		ListIterator& operator--()
		{
			if (value != nullptr)
			{
				value = value->pointPrev;
			}
			return *this;
		}


		ListIterator& operator++(int)
		{
			ListIterator it(*this);
			++(*this);
			return it;
		}
	};

private:
	int _size;
	Node<T>* _head;
	Node<T>* _tail;

private:
		Node<T>* MergeSortedLists(Node<T>* head1, Node<T>* head2)
		{
			Node<T>* result = NULL;
			if (head1 == NULL) 
			{
				return head2;
			}
			if (head2 == NULL) 
			{
				return head1;
			}
			if (head1->data < head2->data) 
			{
				head1->pointNext = MergeSortedLists(head1->pointNext, head2);
				head1->pointNext->pointPrev = head1;
				head1->pointPrev = NULL;
				return head1;
			}
			else 
			{
				head2->pointNext = MergeSortedLists(head1, head2->pointNext);
				head2->pointNext->pointPrev = head2;
				head2->pointPrev = NULL;
				return head2;
			}
		}


		void SplitList(Node<T>* src, Node<T>** fRef, Node<T>** bRef) 
		{
			Node<T>* fast;
			Node<T>* slow;
			slow = src;
			fast = src->pointNext;
			while (fast != NULL) 
			{
				fast = fast->pointNext;
				if (fast != NULL) 
				{
					slow = slow->pointNext;
					fast = fast->pointNext;
				}
			}
			*fRef = src;
			*bRef = slow->pointNext;
			slow->pointNext = NULL;
		}


		void MergeSort(Node<T>** head) 
		{
			Node<T>* p = *head;
			Node<T>* a = NULL;
			Node<T>* b = NULL;
			if (p == NULL || p->pointNext == NULL) 
			{
				return;
			}
			SplitList(p, &a, &b);
			MergeSort(&a);
			MergeSort(&b);
			*head = MergeSortedLists(a, b);
			//возврат головы на место
			while (_tail->pointNext)
				_tail = _tail->pointNext;
		}

public:
	
	ListIterator<T> begin()
	{
		return ListIterator<T>(_head);
	}

	ListIterator<T> end()
	{
		return ListIterator<T>();
	}

	ListIterator<const T> begin() const
	{
		return ListIterator<T>(_head);
	}

	ListIterator<const T> end() const
	{
		return ListIterator<T>();
	}

	typedef ListIterator<Node<T>> iterator;
	typedef ListIterator<const Node<T>> const_iterator;
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
		throw std::exception("List is empty");
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
	if (_size == 0)
	{
		throw std::exception("List is empty");
	}
	//удаляем с конца и с начала
	for (_size; _size > 0;)
	{
		PopFront();
		PopBack();
	}
}


template<typename T>
inline List<T>::ListIterator<T> List<T>::LinearSearch(T data)
{
	if (_size == 0)
	{
		throw std::exception("List is empty");
	}
	for (auto i = this->begin(); i != this->end(); ++i)
	{
		if ((*i) == data)
		{
			return i;
		}
	}
	
	return ListIterator<T>(nullptr);
}


template<typename T>
inline int List<T>::GetSize()
{
	return _size;
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
inline void List<T>::Insert(T data, ListIterator<T> iter)
{
	Node<T>* previous = iter.value;
	previous->pointNext = new Node<T>(data, previous, previous->pointNext);
	//у следующего элемента после нового надо установить предыдущий указатель
	previous = previous->pointNext;
	previous->pointNext->pointPrev = previous;
	_size++;
}


template<typename T>
inline void List<T>::RemoveAt(ListIterator<T> iter)
{
	Node<T>* toDelete = iter.value;
	Node<T>* previous = toDelete->pointPrev;
	previous->pointNext = toDelete->pointNext;
	toDelete->pointNext->pointPrev = previous;
	delete toDelete;
	--_size;
}


template<typename T>
inline void List<T>::PopBack()
{
	if (_size == 0)
	{
		throw std::exception("List is empty");
	}
	if (this->_tail == nullptr)
	{
		PopFront();
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




