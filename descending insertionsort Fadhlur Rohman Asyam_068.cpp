#include<iostream>
#define n 8

using namespace std;

int main() {
int data[n]={10,11,23,21,0,0,8,7};
int temp,j;
	
	for(int i = 0;i<n;i++) {
		temp = data[i];
		j=i-1;
		while(data[j]<temp&&j>=0) {
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=temp;	
	}
	

	cout<<"\n sorted data\n";
	for(int i = 0;i<n;i++) 
	{
		cout<<data[i]<<" ";
	}	
	return 0;
}
