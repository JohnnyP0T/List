#include<iostream>
#include <list>
#include <time.h> 
#include <chrono>

#include "windows.h"
#include "List.h"

using namespace std;


int GetElementConsole()
{
	int taxableIncome;
	for (;;) {
		if (cin >> taxableIncome) 
		{
			return taxableIncome;
			break;
		}
		else 
		{
			cin.clear();
			cin.ignore(80, '\n');
		}
	}
}


void PrintList(List<int>* list)
{
	for (auto i = list->begin(); i != list->end(); ++i)
	{
		cout << (*i) << ' ';
	}
}


int main()
{
	List<int>* list = new List<int>;
	long double seconds;
	int count = 0;
	int valueForPrint = 0;
	int valueForMenu = 0;
	List<int>::ListIterator<int> it;
	for (;;) {
		if (valueForPrint == 7)
		{
			PrintList(list);
			cout << endl;
		}
		cout << "+=================== Linked list ===================+" << endl;
		cout << "Size = " << list->GetSize() << endl;
		cout << "1 - PopBack \n";
		cout << "2 - PopFront \n";
		cout << "3 - PushBack \n";
		cout << "4 - PushFront \n";
		cout << "5 - liner search \n";
		cout << "6 - Sort \n";
		cout << "7 - Show list \n";
		cout << "8 - Insert \n";
		cout << "9 - Remove \n";
		cout << " =++=  0 - Exit  =++=" << endl;
		count = GetElementConsole();
		switch (count)
		{
		case 1:
			try
			{
				list->PopBack();
			}
			catch (std::exception ex)
			{
				cout << ex.what() << endl;
				system("pause");
			}
			break;
		case 2:
			try
			{
				list->PopFront();
			}
			catch (std::exception ex)
			{
				cout << ex.what() << endl;
				system("pause");
			}
			break;
		case 3: 
			cout << "Enter integer value\n";
			valueForMenu = GetElementConsole();
			list->PushBack(valueForMenu);
			break;
		case 4:
			cout << "Enter integer value\n";
			valueForMenu = GetElementConsole();
			list->PushFront(valueForMenu);
			break;
		case 5:
			cout << "Enter integer value\n";
			valueForMenu = GetElementConsole();
			try
			{
				it = list->LinearSearch(valueForMenu);
			}
			catch (std::exception ex)
			{
				cout << ex.what() << endl;
				system("pause");
				break;
			}
			if (it != nullptr)
			{
				cout << "value " <<*(it) << " exist\n";
			}
			else
			{
				cout << "Not found\n";
			}
			system("pause");
			break;
		case 6:
			list->Sort();
			break;
		case 7:
			valueForPrint = 7;
			break;
		case 8:
			cout << "Enter index\n";
			valueForMenu = GetElementConsole();
			if (valueForMenu > list->GetSize() || valueForMenu < 0)
			{
				cout << "Out of range\n";
				system("pause");
				break;
			}
			cout << "Enter value\n";
			count = GetElementConsole();
			if (valueForMenu == 0)
			{
				list->PushFront(count);
				break;
			}
			if (valueForMenu == list->GetSize())
			{
				list->PushBack(count);
				break;
			}
			it = list->begin();
			for (int i = 1; i < valueForMenu; i++)
			{
				it++;
			}
			list->Insert(count, it);
			break;
		case 9:
			cout << "Enter index\n";
			valueForMenu = GetElementConsole();
			if (valueForMenu > list->GetSize() || valueForMenu < 0)
			{
				cout << "Out of range\n";
				system("pause");
				break;
			}
			if (valueForMenu == 0)
			{
				list->PopFront();
				break;
			}
			if (valueForMenu == list->GetSize())
			{
				list->PopBack();
				break;
			}
			it = list->begin();
			it++;
			for (int i = 2; i < valueForMenu; i++)
			{
				it++;
			}
			list->RemoveAt(it);
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "Invalid value\n";
			system("pause");
			break;
		}
		std::system("cls");
	}
}