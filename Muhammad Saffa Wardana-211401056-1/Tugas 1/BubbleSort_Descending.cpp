#include<iostream>
using namespace std;
int main()
{
	int n = 8;
	int data[8];
	cout<<"Input Data \n\n";
	
	for (int i=0; i<8; i++)
	{
		cout<<"data - "<<i+1<<":";
		cin>>data[i];
	}
	
	for (int i=1; i<n; i++){
		for (int j=n-1; j>=i; j--)
		{
			if(data[j] < data[j-1]){
				swap(data[j], data[j-1]);
			}
				
		}
	}
	
	cout<<"\nsorted data\n";
	for (int i=n-1; i>=0; i--){
		cout<<data[i]<<" ";
	}
	
	cout<<endl;
	return 0;
}
