#include<iostream>
using namespace std;

int main()
{
    cout<<"Insertion Sort\n\n";
    int n=8;
    int data[8] = {10,11,23,21,0,0,8,7};

    //----------Insertion sort
    int temp, j;
    for(int i=1;i<n;i++)
    {
        temp=data[i];
        j = i-1;
        while (data[j]< temp && j>=0)
        {
            //descending
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1]= temp;
    }
//--------------------------------------------
    cout<<"Data yang telah di sortir\n\n";
    for(int i=0;i<n;i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
