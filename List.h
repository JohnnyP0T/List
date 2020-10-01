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

	/// @brief Удаление с начала
	void PopFront();

	/// @brief удаление с конца
	void PopBack();

	/// @brief добавление элемента в конец
	/// @param data значение
	void PushBack(int data);

	/// @brief добавление элемента с начала
	/// @param data значение
	void PushFront(int data);
	
	/// @brief marge sort
	void Sort();

	/// @brief полная очистка
	void Clear();

	/// @brief линейный поиск
	/// @param data значение
	/// @return итератор указывающий на значение если такое есть
	ListIterator LinearSearch(int data);

	/// @brief получение размера списка
	/// @return размер списка
	int GetSize();

	/// @brief вставка элемента по индексу
	/// @param data значение
	/// @param index итератор
	void Insert(int data, ListIterator iter);

	/// @brief удаление по индексу
	/// @param index итератор
	void RemoveAt(ListIterator iter);

private:
		/// @brief метод для сортировки
		/// @param head1 
		/// @param head2 
		/// @return 
		Node* MergeSortedLists(Node* head1, Node* head2);
		
		/// @brief метод для сортировки
		/// @param src 
		/// @param fRef 
		/// @param bRef 
		void SplitList(Node* src, Node** fRef, Node** bRef);

		/// @brief метод для сортировки
		/// @param head 
		void MergeSort(Node** head);

public:
	
	/// @brief возврат указателя первого элемента
	/// @return 
	ListIterator begin();

	/// @brief возврат указателя последнего элемента
	/// @return 
	ListIterator end();

	/// @brief возврат указателя первого элемента
	/// @return 
	ListIterator begin() const;

	/// @brief возврат указателя последнего элемента
	/// @return 
	ListIterator end() const;

	typedef ListIterator iterator;
	typedef ListIterator const_iterator;
};


#endif