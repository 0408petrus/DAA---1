#include<iostream>
using namespace std;
int main()
{
    int input, way, i, j, pos, temp;
    int n=8;
    int data[n]={10,11,23,21,0,0,8,7};

    cout<<"Pilih metode sorting : \n";
    cout<<"1. Bubble Sort\n";
    cout<<"2. Selection Sort\n";
    cout<<"3. Insertion Sort\n";
    cout<<"Ans : ";
    cin>>input;
    cout<<"Pengurutan secara : \n";
    cout<<"1. Ascending\n";
    cout<<"2. Descending\n";
    cout<<"Ans : ";
    cin>>way;
    cout<<endl;

    if(input==1)
    {
        if(way==1)
        {
            for (i=1;i<n;i++)
            {
                for (j=n-1;j>=i;j--)
                {
                    if (data[j]<data[j-1])
                    swap(data[j],data[j-1]);
                }
            }
        }
        else if(way==2)
        {
           for (i=1;i<n;i++)
            {
                for (j=n-1;j>=i;j--)
                {
                    if (data[j]>data[j-1])
                    swap(data[j],data[j-1]);
                }
            }
        }
    }

    else if(input==2)
    {
        if(way==1)
        {
            for (i=0;i<n-1;i++)
            {
                pos = i;
                for (j=i+1;j<n;j++)
                {
                    if (data[j]<data[pos])
                    pos = j;
                }
                if (pos!=i)
                swap(data[pos],data[i]);
            }
        }
        else if(way==2)
        {
            for (i=0;i<n-1;i++)
            {
                pos = i;
                for (j=i+1;j<n;j++)
                {
                    if (data[j]>data[pos])
                    pos = j;
                }
                if (pos!=i)
                swap(data[pos],data[i]);
            }
        }
    }

    else if(input==3)
    {
        if(way==1)
        {
            for (i=1;i<n;i++)
            {
                temp=data[i];
                j = i - 1;
                while (data[j]>temp&&j>=0)
                {
                    data[j+1]=data[j];
                    j--;
                }
                data[j+1]=temp;
            }
        }
        else if(way==2)
        {
            for (i=1;i<n;i++)
            {
                temp=data[i];
                j = i - 1;
                while (data[j]<temp&&j>=0)
                {
                    data[j+1]=data[j];
                    j--;
                }
                data[j+1]=temp;
            }
        }
    }
    cout<<"Data        : 10 11 23 21 0 0 8 7\n";
    cout<<"Sorted Data : ";
    for(i=0;i<n;i++)
    {
        cout<<data[i]<<" ";
    }
    return 0;
}
