#include<iostream>
using namespace std;

int main()
{
    cout<<"Selection sort\n\n";
    int n=8,pos;
    int data[8] = {10,11,23,21,0,0,8,7};

//---------------Selection sort
for(int i=0;i<n-1;i++)
{

    pos = i;
    for(int j=i+1;j<n;j++)
    { 
        //Descneding
        if(data[j]>data[pos])
            pos = j;
    }
    if(pos != i)
        swap(data[pos],data[i]);
}

//---------------------------------------

cout<<"Data yang telah di sortir\n\n";
for(int i=0;i<n;i++)
{
    cout<<data[i]<<" ";
}
cout<<"\n";
return 0;
}
