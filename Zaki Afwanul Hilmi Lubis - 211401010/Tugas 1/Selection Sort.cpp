#include <iostream>
using namespace std;
int main()
{
cout << " \n **Selection Sort** \n\n " << endl;
int z , zak;
int data[8];
cout << " Masukkan banyak data yang diinginkan : ";
cin >> z;
for (int i = 0; i < z; i++)
{
cout << " Data Ke-  " << i + 1 << " : ";
cin >> data[i];
}

for (int i = 0; i < z - 1; i++)
{
zak = i;
for (int j = i + 1; j < z; j++)
{
if (data[j] > data[zak])
zak = j;
}
if (zak != i)
swap(data[zak], data[i]);
}

cout << "\n\n Hasil Sortigan Adalah : ";
cout << endl;
for (int i = 0 ; i < z ; i++)
{
cout << " " << data[i] << "  ";
}
cout << endl;
return 0;
}
