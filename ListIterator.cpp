#include "ListIterator.h"

bool ListIterator::operator==(const ListIterator it) const
{
	return(value == it.value);
}


bool ListIterator::operator!=(const ListIterator it) const
{
	return (value != it.value);
}


ListIterator& ListIterator::operator++()
{
	if (value != nullptr)
	{
		value = value->pointNext;
	}
	return *this;
}


int& ListIterator::operator*()
{
	return value->data;
}


ListIterator& ListIterator::operator--()
{
	if (value != nullptr)
	{
		value = value->pointPrev;
	}
	return *this;
}

ListIterator& ListIterator::operator++(int)
{
	ListIterator it(*this);
	++(*this);
	return it;
}
