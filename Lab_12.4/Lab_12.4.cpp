#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

Elem* L = NULL;

void Insert(Elem*& L, Info value);
void insertAfter(Elem*& L, int supposed);
void Print(Elem* L);
Info Remove(Elem*& L);

void main()
{
	int amount;
	cout << "\n Enter amount of the list elements: "; cin >> amount;

	int num;
	for (int i = 0; i < amount; i++)
	{
		cout << "Enter the number to include to list: ";
		cin >> num;
		Insert(L, num);
	}
	cout << "\n List: ";
	Print(L);
	int supposed;
	cout << "\n Enter the value of the element that supposed to be duplicated: "; cin >> supposed;
	insertAfter(L, supposed);
	Print(L);
	Remove(L);
}

void Insert(Elem*& L, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;

	if (L != NULL)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link;

		T->link = tmp;
	}
	else
	{
		L = tmp;
	}

	tmp->link = L;

}


void insertAfter(Elem*& L, int supposed)
{	
	if (L != 0)
	{
		Elem* first = L;
		do
		{
			if (L->info == supposed)
			{
				Elem* tmp = new Elem; // 1
				tmp->info = supposed; // 2

				tmp->link = L->link; // 3
				L->link = tmp; // 4
				L = tmp;
			}
			L = L->link;
		} while (L != first);
		
	}
}

void Print(Elem* L)
{
	if (L == NULL)
		return;

	Elem* first = L;
	cout << " " << L->info;

	while (L->link != first)
	{
		L = L->link;
		cout << " " << L->info;
	}
	cout << endl;
	L = L->link;
}


Info Remove(Elem*& L)
{
	Elem* T = L;
	while (T->link != L)
		T = T->link;
	Info value = L->info;
	if (T != L)
	{
		Elem* tmp = L->link;
		delete L;
		L = tmp;
		T->link = L;
	}
	else
	{
		delete L;
		L = NULL;
	}
	return value;
}

