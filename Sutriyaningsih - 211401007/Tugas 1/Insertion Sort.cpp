#include <iostream>
using namespace std;
int main()
{
	cout<<" ------------------\n";
	cout<<"|  Insertion sort  |";
	cout<<"\n ------------------\n";
	int n, m;
	cout<<"Input banyak data: ";
	cin >>n;
	int data[n];
	cout<<"Input Data\n";
	for (int i = 0; i < n; i++)
	{
    	cout<<"Data-" << i + 1 << " : ";
    	cin >>data[i];
	}
	
	int temp, j;
	for (int i = 1; i < n; i++)
	{
    	temp = data[i];
    	j = i - 1;
    	while (data[j] < temp && j >= 0)
    	{
        	data[j + 1] = data[j];
        	j--;
    	}
    data[j + 1] = temp;
	}

	cout<<"Sorted Data: ";
	for (int i = 0; i < n; i++)
	{
    	cout<<data[i] << " ";
	}
	cout << "\n";
	return 0;
}
