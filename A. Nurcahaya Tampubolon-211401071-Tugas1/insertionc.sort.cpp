#include <iostream>
using namespace std;
int main()
{
    cout<<"Insertion Sort\n";
    int data[8]={10,11,23,21,0,0,8,7};

    //-------Insertion Sort
    int temp,j,pos;
    for(int i=1;i<8;i++)
    {
        temp=data[i];
        j=i-1;
        while(data[j]<temp && j>=0)
        {
            //Descending
            data[j+1]=data[j];
            j--;
        }
        data[j+1]=temp;
    }
    //------------------
    cout<<"\nSorted Data\n";
    for(int i=0;i<8;i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<"\n";
    return 0;
}