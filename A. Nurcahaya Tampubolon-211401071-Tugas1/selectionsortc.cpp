#include <iostream>
using namespace std;
int main()
{
    cout<<"Selection Sort\n";
    int data[8]={10,11,23,21,0,0,8,7};
    int pos;
    for(int i=0;i<7;i++)
    {
        pos=i;
        for(int j=i+1;j<8;j++)
        {
            if(data[j]>data[pos])//descending
                pos=j;
        }
        if(pos !=i)
            swap(data[pos],data[i]);
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