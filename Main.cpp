#include<iostream>
#include"List.h"
using namespace std;

int main()
{
	List<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);

	cout << endl;
	for (int i = 0; i < list.GetSize(); i++)
	{
		cout << list[i];
	}
	
	//cout << endl;
//	for (int i = list.GetSize(); i > 0; i--)
	//{
//			cout << "prev "<< list._tail->data << endl;
	//}
}