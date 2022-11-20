#include <iostream>
using namespace std;
int main()
{
cout << "\n ** Insertion Sort ** \n\n" << endl;
int z ;
int data[8];
cout << " Masukkan banyak data yang diinginkan : ";
cin >> z;
for (int i = 0; i < z; i++)
{
    cout << " Data Ke- " << i + 1 << " : ";
    cin >> data[i];
}
int temp, j;
for (int i = 1; i < z; i++)
{
    temp = data[i];
    j = i - 1;
    while (data[j] < temp && j >= 0)
    {
        data[j + 1] = data[j];
        j--;
    }
    data[j + 1] = temp;
}

cout << " \n\n Hasil Sortigan Adalah : \n ";
for (int i = 0; i < z; i++)
{
    cout << " " << data[i] << " ";
}
cout << "\n";
return 0;
}
