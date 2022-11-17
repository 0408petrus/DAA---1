#include<iostream>
#define n 8

using namespace std;

int main() {
int data[n]={10,11,23,21,0,0,8,7};
	
	for(int i = n;i>=0;i--) 
	{
		for(int j = n;j>n-i;j--) 
		{
			if(data[j]>data[j-1]) 
			{		
					swap(data[j-1],data[j]);
			}
		}
	}
	cout<<"\n sorted data\n";
	for(int i = 0;i<n;i++) 
	{
		cout<<data[i]<<" ";
	}	
	return 0;
}
