#pragma once
#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <exception>

#include "ListIterator.h"
#include "Node.h"
/// @brief doubly linked list
class List
{
private:
	int _size;
	Node* _head;
	Node* _tail;

public:
	List();
	~List();

	/// @brief �������� � ������
	void PopFront();

	/// @brief �������� � �����
	void PopBack();

	/// @brief ���������� �������� � �����
	/// @param data ��������
	void PushBack(int data);

	/// @brief ���������� �������� � ������
	/// @param data ��������
	void PushFront(int data);
	
	/// @brief marge sort
	void Sort();

	/// @brief ������ �������
	void Clear();

	/// @brief �������� �����
	/// @param data ��������
	/// @return �������� ����������� �� �������� ���� ����� ����
	ListIterator LinearSearch(int data);

	/// @brief ��������� ������� ������
	/// @return ������ ������
	int GetSize();

	/// @brief ������� �������� �� �������
	/// @param data ��������
	/// @param index ��������
	void Insert(int data, ListIterator iter);

	/// @brief �������� �� �������
	/// @param index ��������
	void RemoveAt(ListIterator iter);

private:
		/// @brief ����� ��� ����������
		/// @param head1 
		/// @param head2 
		/// @return 
		Node* MergeSortedLists(Node* head1, Node* head2);
		
		/// @brief ����� ��� ����������
		/// @param src 
		/// @param fRef 
		/// @param bRef 
		void SplitList(Node* src, Node** fRef, Node** bRef);

		/// @brief ����� ��� ����������
		/// @param head 
		void MergeSort(Node** head);

public:
	
	/// @brief ������� ��������� ������� ��������
	/// @return 
	ListIterator begin();

	/// @brief ������� ��������� ���������� ��������
	/// @return 
	ListIterator end();

	/// @brief ������� ��������� ������� ��������
	/// @return 
	ListIterator begin() const;

	/// @brief ������� ��������� ���������� ��������
	/// @return 
	ListIterator end() const;

	typedef ListIterator iterator;
	typedef ListIterator const_iterator;
};


#endif