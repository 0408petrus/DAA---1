#include <iostream>
using namespace std;
int main()
{
	cout<<"Program Selection Sort"<<endl;
	int n, m;
	cout<<"Berapa kali input Data: ";
	cin >>n;
	int data[n];
	for (int i = 0; i < n; i++)
	{
		cout<<"Data ke-" << i + 1 << " : ";
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
	cout<<"Data Tersortir: ";
	for (int i = 0; i < n; i++)
	{
		cout<<data[i]<<" ";
	}
}