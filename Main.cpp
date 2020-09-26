#include<iostream>
#include"List.h"
using namespace std;

int main()
{
	List<int> list;
	list.PushFront(1);
	list.PushFront(2);
	list.PushFront(3);
	list.PushFront(4);
	list.PushFront(1023);
	list.PushBack(8); 
	list.PushBack(7);
	list.Insert(9, 3);
	cout << endl;
	cout << list.GetSize();
	cout << endl;

	List<int>::iterator io = list.begin();
	while (io != list.end()) {
		cout << *io << ' ';
		++io;
	}

	list.Sort();
	cout << endl;
	io = list.begin();
	while (io != list.end()) {
		cout << *io << ' ';
		++io;
	}
	//for (int i = 0; i < list.GetSize(); i++)
	//{
	//	cout << list[i];
	//}
	list.RemoveAt(3);
	cout << endl;
//	for (int i = 0; i < list.GetSize(); i++)
//	{
	//	cout << list[i];
	//}
	

}