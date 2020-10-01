#pragma once
#ifndef _NODE_H_
#define _NODE_H_

using namespace std;

/// @brief узел листа
class Node
{
public:
	Node* pointNext;
	Node* pointPrev;
	int data;
	
	/// @brief конструктор
	/// @param data значение
	/// @param pointPrev укахатель на предыдущий узел
	/// @param pointNext укахатель на слудующий узел
	Node(int data = int(), Node* pointPrev = nullptr, Node* pointNext = nullptr) :
		data(data), pointPrev(pointPrev), pointNext(pointNext) {}
};

#endif