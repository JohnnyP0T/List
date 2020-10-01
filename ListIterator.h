#pragma once
#ifndef _LISTITERATOR_H_
#define _LISTITERATOR_H_

#include "Node.h"

/// @brief итератор для листа
class ListIterator
{
private:
	Node* value;
public:
	friend class Node;
	friend class List;
	/// @brief конструктор
	ListIterator() : value(nullptr) {}

	/// @brief конструктор
	ListIterator(Node* value) : value(value) {}

	/// @brief оператор сравниения
	/// @param it 
	/// @return 
	bool operator==(const ListIterator it) const;

	/// @brief оператор сравниения
	/// @param it 
	/// @return 
	bool operator!=(const ListIterator it) const;

	/// @brief инкремент
	/// @return 
	ListIterator& operator++();

	/// @brief оператор разыменования
	/// @return 
	int& operator*();

	/// @brief декремент
	/// @return 
	ListIterator& operator--();

	/// @brief инкремент
	/// @param  
	/// @return 
	ListIterator& operator++(int); 


	typedef ListIterator Iterator;
	typedef ListIterator ConstIterator;
};

#endif