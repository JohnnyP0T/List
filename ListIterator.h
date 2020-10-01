#pragma once
#ifndef _LISTITERATOR_H_
#define _LISTITERATOR_H_

#include "Node.h"

/// @brief �������� ��� �����
class ListIterator
{
private:
	Node* value;
public:
	friend class Node;
	friend class List;
	/// @brief �����������
	ListIterator() : value(nullptr) {}

	/// @brief �����������
	ListIterator(Node* value) : value(value) {}

	/// @brief �������� ����������
	/// @param it 
	/// @return 
	bool operator==(const ListIterator it) const;

	/// @brief �������� ����������
	/// @param it 
	/// @return 
	bool operator!=(const ListIterator it) const;

	/// @brief ���������
	/// @return 
	ListIterator& operator++();

	/// @brief �������� �������������
	/// @return 
	int& operator*();

	/// @brief ���������
	/// @return 
	ListIterator& operator--();

	/// @brief ���������
	/// @param  
	/// @return 
	ListIterator& operator++(int); 


	typedef ListIterator Iterator;
	typedef ListIterator ConstIterator;
};

#endif