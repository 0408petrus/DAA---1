#include<iostream>
using namespace std;

int main()
{
    cout<<"Bubble Sort\n\n";
    int n=8;
    int data[8] = {10,11,23,21,0,0,8,7},temp;

    //----Bubble Sort
    for(int i=1;i<n;i++)
    {
        for(int j=n-1;j>=i;j--)
        {
            if(data[j] > data[j - 1])
            {  
                //descending
                temp = data[j]; 
                data[j] = data[j - 1];
                data[j - 1] = temp;
            }
        }
    }
//------------------------------------------
    cout<<"Data yang telah di sortir\n\n";
    for(int i=0;i<n;i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
    return 0;
}
