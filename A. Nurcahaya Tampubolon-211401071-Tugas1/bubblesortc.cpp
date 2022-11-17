#include <iostream>
using namespace std;
int main()
{
    cout<<"Bubble Sort\n\n";

    int n=5;
    int data[5];
    cout<<"Input data : \n\n";
    for (int i=0;i<5;i++)
    {
        cout<<"Data-"<<i+1<<":";
        cin>>data[i];
    }
    //----bubble sort
    for (int i=0;i<n;i++)
    {
        for (int j=n-1;j>=i;j--)
    {
        if(data[j]>data[j-1]) //descending
            swap(data[j],data[j-1]);
    }
    cout<<data[i]<<" ";
    }
}