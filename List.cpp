#include "List.h"


List::List()
{
	_size = 0;
	_head = nullptr;
	_tail = nullptr;
}


List::~List()
{
	Clear();
}


void List::PopFront()
{
	if (_size == 0)
	{
		throw std::exception("List is empty");
	}
	Node* temp = _head;
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


void List::PushBack(int data)
{
	if (_head == nullptr)
	{
		_head = new Node(data);
	}
	else if (_tail == nullptr)
	{
		_tail = new Node(data, _head);
		_head->pointNext = _tail;
	}
	else
	{
		Node* current = _tail;
		_tail = new Node(data, current);
		current->pointNext = _tail;
	}
	++_size;
}


void List::Clear()
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


ListIterator List::LinearSearch(int data)
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

	return ListIterator(nullptr);
}


int List::GetSize()
{
	return _size;
}


void List::PushFront(int data)
{
	if (_head == nullptr)
	{
		_head = new Node(data);
	}
	else if (_tail == nullptr)
	{
		_tail = new Node(_head->data, _head);
		_head->pointNext = _tail;
		_head->data = data;
	}
	else
	{
		Node* current = _head;
		_head = new Node(data, nullptr, current);
		current->pointPrev = _head;
	}
	++_size;
}


void List::Sort()
{
	MergeSort(&_head);
}


void List::Insert(int data, ListIterator iter)
{
	if (_head == nullptr && iter == nullptr)
	{
		_head = new Node(data);
	}
	else if (_tail == nullptr)
	{
		_tail = new Node(data, _head);
		_head->pointNext = _tail;
	}
	else if (iter == begin())
	{
		_head = new Node(data);
		iter.value->pointPrev = _head;
		_head->pointNext = iter.value;
	}
	else if (iter == nullptr)
	{
		Node* current = _tail;
		_tail = new Node(data, current);
		current->pointNext = _tail;
	}
	else
	{
		Node* previous = iter.value;
		previous->pointPrev = new Node(data, previous->pointPrev, previous);
		previous = previous->pointPrev;
		previous->pointPrev->pointNext = previous;
	}
	++_size;
}


void List::RemoveAt(ListIterator iter)
{
	if (_size == 0)
	{
		throw std::exception("List is empty");
	}
	if (iter == nullptr)
	{
		Node* temp = _tail;
		_tail = _tail->pointPrev;
		_tail->pointNext = nullptr;
		delete temp;
	}
	else if (iter == begin())
	{
		Node* temp = _head;
		_head = _head->pointNext;
		delete temp;
	}
	else if (iter.value->pointNext == nullptr)
	{
		Node* temp = _tail;
		_tail = _tail->pointPrev;
		_tail->pointNext = nullptr;
		delete temp;
	}
	else
	{
		Node* toDelete = iter.value;
		Node* previous = toDelete->pointPrev;
		previous->pointNext = toDelete->pointNext;
		toDelete->pointNext->pointPrev = previous;
		delete toDelete;
	}
	--_size;
}


Node* List::MergeSortedLists(Node* headOne, Node* headTwo)
{
	Node* result = nullptr;
	if (headOne == nullptr)
	{
		return headTwo;
	}
	if (headTwo == nullptr)
	{
		return headOne;
	}
	if (headOne->data < headTwo->data)
	{
		headOne->pointNext = MergeSortedLists(headOne->pointNext, headTwo);
		headOne->pointNext->pointPrev = headOne;
		headOne->pointPrev = nullptr;
		return headOne;
	}
	else
	{
		headTwo->pointNext = MergeSortedLists(headOne, headTwo->pointNext);
		headTwo->pointNext->pointPrev = headTwo;
		headTwo->pointPrev = nullptr;
		return headTwo;
	}
}

void List::SplitList(Node* source, Node** fReference, Node** bReference)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->pointNext;
	while (fast != nullptr)
	{
		fast = fast->pointNext;
		if (fast != nullptr)
		{
			slow = slow->pointNext;
			fast = fast->pointNext;
		}
	}
	*fReference = source;
	*bReference = slow->pointNext;
	slow->pointNext = nullptr;
}


void List::MergeSort(Node** head)
{
	Node* p = *head;
	Node* a = nullptr;
	Node* b = nullptr;
	if (p == nullptr || p->pointNext == nullptr)
	{
		return;
	}
	SplitList(p, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*head = MergeSortedLists(a, b);
	//возврат хвоста на место
	while (_tail->pointNext)
	{
		_tail = _tail->pointNext;
	}
}


ListIterator List::begin()
{
	return ListIterator(_head);
}


ListIterator List::end()
{
	return ListIterator();
}


ListIterator List::begin() const
{
	return ListIterator(_head);
}


ListIterator List::end() const
{
	return ListIterator();
}


void List::PopBack()
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
	Node* temp = _tail;
	_tail = _tail->pointPrev;
	if (_size != 1)
	{
		_tail->pointNext = nullptr;
	}
	else if (_size == 1)
	{
		_head = nullptr;
		_tail = nullptr;
	}
	delete temp;
	--_size;
}


