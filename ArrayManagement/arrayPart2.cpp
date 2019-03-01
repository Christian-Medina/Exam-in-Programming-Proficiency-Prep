#include <iostream>
using namespace std;
int main()
{
	bool insert(int value, int intArray[], int & numberOfValidEntries, int size);
	bool del(int value, int intArray[], int & numberOfValidEntries);
	void print(int intArray[], int & numberOfValidEntries);
	int find(int valueToSearchFor, int intArray[], int numberOfValidEntries);
	void menu();

	int array[10];
	int choice = 0;
	int index = 0;
	menu();
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int input;
			cout << "Please enter an integer to be inserted ";
			cin >> input;
			if (insert(input, array, index, 10))
			{
				cout << "Value inserted" << endl;
			}
			else
			{
				cout << "Array full" << endl;
			}
			menu();
			break;
		}
		case 2:
		{
			int remove;
			cout << "Please  enter an integer to be deleted ";
			cin >> remove;
			if (del(remove, array, index))
			{
				cout << "Value deleted";
			}
			else
			{
				cout << "Value not found ";
			}
			menu();
			break;
			}
		case 3:
		{
			print(array, index);
			menu();
			break;
		}
		default:
		{
			break;
		}
		}
	} while (choice != 4);
	return 0;
}
void menu()
{
	cout << "1: Insert an integer" << endl;
	cout << "2: Delete an integer" << endl;
	cout << "3: Print array" << endl;
	cout << "4: Quit" << endl;
}
bool insert(int value, int intArray[], int & numberOfValidEntries, int size)
{
	if (numberOfValidEntries == size)
	{
		return false;
	}
	intArray[numberOfValidEntries] = value;
	numberOfValidEntries++;
	return true;
}
int find(int valueToSearchFor, int intArray[], int numberOfValidEntries)
{
	int y;
	for (y = 0; y <= numberOfValidEntries; y++)
	{
		if (intArray[y] == valueToSearchFor)
		{
			return y;
		}
	}
	return 0;
}
bool del(int value, int intArray[], int & numberOfValidEntries)
{
	if (find(value, intArray, numberOfValidEntries)!=NULL)
	{
		for (int i = find(value, intArray, numberOfValidEntries); i >= 0; i--)
		{
			intArray[i] = intArray[i - 1];
		}
		intArray[0] = 0;
		return true;
	}
	else
	{
		return false;
	}
}
void print(int intArray[], int & numberOfValidEntries)
{
	cout << endl;
	for (int i = 0; i < numberOfValidEntries; i++)
	{
		cout << intArray[i] << endl;
	}
	cout << endl;
}
