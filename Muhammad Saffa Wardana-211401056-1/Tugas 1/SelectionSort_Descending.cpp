#include <iostream>
using namespace std;
int main()
{
	cout << "Selection Sort\n\n";
	int n = 8, pos;
	int data[8];
	cout << "Input Data: \n\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Data - " << i + 1 << ":";
		cin >> data[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		pos = i;
		for (int j = i + 1; j < n; j++)
		{
			if (data[j] > data[pos])
				pos = j;
		}
		if (pos != i)
			swap(data[pos], data[i]);
	}

	cout << "\nSorted data\n";
	for (int i = 0; i < n; i++)
	{
		cout << data[i] << " ";
	}
	cout << "\n";
	return 0;
}
