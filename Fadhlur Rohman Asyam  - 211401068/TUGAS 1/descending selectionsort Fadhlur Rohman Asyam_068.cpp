#include<iostream>
#define n 8

using namespace std;

int main() {
int data[n]={10,11,23,21,0,0,8,7};
int pos;
	
	for(int i = 0;i<n-1;i++) 
	{
		pos = i;
		
		for(int j = i+1;j<n;j++) {
			if(data[j]>data[pos]) 
			pos=j;		
	}
	if(pos!=i) 
	swap(data[i],data[pos]);
	}
	
	cout<<"\n sorted data\n";
	for(int i = 0;i<n;i++) 
	{
		cout<<data[i]<<" ";
	}	
	return 0;
}
