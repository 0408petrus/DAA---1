#include <iostream>
using namespace std;
int main()
{
	cout<<" ------------------\n";
	cout<<"|  Selection sort  |";
	cout<<"\n ------------------\n";
	int n, m;
	cout<<"Input banyak data: ";
	cin >>n;
	int data[n];
	cout<<"Input Data\n";
	for (int i = 0; i < n; i++)
	{
		cout<<"Data-" << i + 1 << " : ";
		cin >> data[i];
	}
		for (int i = 0; i < n - 1; i++)
		{
			m = i;
			for (int j = i + 1; j < n; j++)
			{
				if (data[j] > data[m])
				m = j;
			}
			if (m != i)
			swap(data[m], data[i]);
		}

	cout<<"Sorted Data: ";
	for (int i = 0; i < n; i++)
	{
		cout<<data[i] << " ";
	}
	cout << "\n";
	return 0;
}
