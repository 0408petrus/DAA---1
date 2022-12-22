#include <iostream>
using namespace std;
int main()
{
	cout<<"Program Bubble sort"<<endl;
	int n;
	cout<<"Berapa kali input Data: ";
	cin >>n;
	int data[n];
	for (int i = 0; i < n; i++)
	{
        cout<<"Data ke-" << i + 1 << " : ";
        cin	>>data[i];
	}
	for (int i = 1; i < n; i++)
	{
  		for (int j = n - 1; j >= i; j--)
		{
    		if (data[j] > data[j - 1])
        	swap(data[j], data[j - 1]);
    	}
	}
	cout<<"Data Tersortir: ";
	for (int i = 0; i < n; i++)
	{
        cout<<data[i]<<" ";
	}
}