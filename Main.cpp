#include <iostream>
#include <list>
#include <time.h> 

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


void PrintList(List* list)
{
	for (auto i = list->begin(); i != list->end(); ++i)
	{
		cout << (*i) << ' ';
	}
}


int main()
{
	List* list = new List;
	int count = 0;
	bool valueForPrint = 0;
	int valueForMenu = 0;
	ListIterator it;
	for (;;) {
		if (valueForPrint)
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
		cout << "Enter operation: ";
		count = GetElementConsole();
		cout << endl;
		switch (count)
		{
		case 1:
		{
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
		}
		case 2:
		{
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
		}
		case 3: 
		{
			cout << "Enter integer value\n";
			valueForMenu = GetElementConsole();
			list->PushBack(valueForMenu);
			break;
		}
		case 4:
		{
			cout << "Enter integer value\n";
			valueForMenu = GetElementConsole();
			list->PushFront(valueForMenu);
			break;
		}
		case 5:
		{
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
				cout << "value " << *(it) << " exist\n";
			}
			else
			{
				cout << "Not found\n";
			}
			system("pause");
			break;
		}
		case 6:
		{
			list->Sort();
			break;
		}
		case 7:
		{
			valueForPrint = true;
			break;
		}
		case 8:
		{
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
			it = list->begin();
			for (int i = 0; i < valueForMenu; i++)
			{
				it++;
			}
			list->Insert(count, it);
			break;
		}
		case 9:
		{
			cout << "Enter index\n";
			valueForMenu = GetElementConsole();
			if (valueForMenu >= list->GetSize() || valueForMenu < 0)
			{
				cout << "Out of range\n";
				system("pause");
				break;
			}
			it = list->begin();
			for (int i = 0; i < valueForMenu; i++)
			{
				it++;
			}
			list->RemoveAt(it);
			break;
		}
		case 0:
		{
			return 0;
			break;
		}
		default:
		{
			cout << "Invalid value\n";
			system("pause");
			break;
		}
		}
		system("cls");
	}
}