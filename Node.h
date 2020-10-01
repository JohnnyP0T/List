#pragma once
#ifndef _NODE_H_
#define _NODE_H_

using namespace std;

/// @brief ���� �����
class Node
{
public:
	Node* pointNext;
	Node* pointPrev;
	int data;
	
	/// @brief �����������
	/// @param data ��������
	/// @param pointPrev ��������� �� ���������� ����
	/// @param pointNext ��������� �� ��������� ����
	Node(int data = int(), Node* pointPrev = nullptr, Node* pointNext = nullptr) :
		data(data), pointPrev(pointPrev), pointNext(pointNext) {}
};

#endif