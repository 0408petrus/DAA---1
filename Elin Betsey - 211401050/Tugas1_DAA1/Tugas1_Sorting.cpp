#include <iostream>
using namespace std;

int main()
{   int i, j, jumlah, pos, temp, data[1000];

    cout <<"Jumlah Data: "
    ;
    cin >> jumlah;
    cout << "Masukkan data: " <<endl;
        for (i=0; i<jumlah; i++)
        {
            cout <<"Data- "<<i + 1<<": ";
            cin>>data[i];
        }

        //bubble sort
        for (i=1;i<jumlah;i++)
        {
            for (j= jumlah-1;j>=i;j--)
            {
                if(data[j]>data[j-1])
                    swap(data[j], data[j-1]);
            }
        }
        cout << "Bubble Sorted Data\t: ";
        for (i=0; i<jumlah;i++)
        {
            cout << data[i]<<" ";
        }

        //selection sort
        for (i=0; i<jumlah-1; i++)
        {
            pos=i;
            for(int j=i+1; j<jumlah;j++)
            {
                if(data[j]<data[pos])
                    pos=j;
            }
            if (pos=i)
                swap(data[pos], data[i]);
        }
        cout << endl <<"Selection Sorted Data\t: ";
        for (i=0; i<jumlah;i++)
        {
            cout << data[i]<<" ";
        }


        //insertion sort
        for (i=1;  i<jumlah; i++)
        {
            temp=data[i];
            j=i-1;
            while (data[j]<temp && j>=0)
            {
                data[j+1]=data[j];
                j--;
            }
            data[j+1]=temp;
        }
        cout << endl <<"Insertion Sorted Data\t: ";
        for (i=0; i<jumlah;i++)
        {
            cout << data[i]<<" ";
        }
        return 0;
}

