#include <iostream>
using namespace std;

int temp, i, j;

void BubbleSort(int jumlahData, int a[])
{

    for(int i=0;i<jumlahData;i++)
    {
       for(int j=i+1;j<jumlahData;j++)
       {
          if(a[j]>a[i])
          {
             temp = a[i];
             a[i] = a[j];
             a[j] = temp;
          }
       }
    }

    cout<<"\nBubble Sort Sorted Data\n";
    for (int i=0;i<jumlahData;i++)
    {
        cout<<"Data ke-"<<i+1<<" : "<<a[i]<<"\n";
    }
}

void SelectionSort (int jumlahData, int a[])
{
    for (int i=0;i<jumlahData-1;i++)
    {
        int pos=i;
        for(int j=i+1;j<jumlahData;j++)
        {
            if(a[j]>a[pos])
                pos=j;
        }

        if (pos!=i)
        {
            temp = a[i];
             a[i] = a[j];
             a[j] = temp;
        }
    }

    cout<<"\nSelection Sort Sorted Data\n";
    for (int i=0;i<jumlahData;i++)
    {
        cout<<"Data ke-"<<i+1<<" : "<<a[i]<<"\n";
    }
}

void InsertionSort (int jumlahData, int a[])
{
    for (int i = 1; i < jumlahData; i++)
    {
        temp = a[i];
        j = i - 1;
        while (a[j] < temp && j >= 0)
        {
            a[j + 1] = a[j];
            j++;
        }
        a[j + 1] = temp;
    }

    cout<<"\nInsertion Sort Sorted Data\n";
    for (int i=0;i<jumlahData;i++)
    {
        cout<<"Data ke-"<<i+1<<" : "<<a[i]<<"\n";
    }
}

int main()
{
    int n=8;
    int data[8]={10,11,23,21,0,0,8,7};

    for (int i=0;i<8;i++)
    {
        cout<<"Data ke-"<<i+1<<" : "<<data[i]<<"\n";
    }

   BubbleSort(n,data);
   SelectionSort(n,data);
   InsertionSort(n,data);
}
