#include <iostream>
using namespace std;
int main()
{
  cout << "\n **Bubble sort** \n\n" << endl;
  int z;
  int data[8];
  cout << " Masukkan banyak data yang diinginkan : ";
  cin >> z; 
  for (int i = 0; i < z; i++)
{
        cout << " Data Ke- " << i + 1 << " : ";
        cin >> data[i];
}
for (int i = 1; i < z; i++)
{
  for (int j = z - 1; j >= i; j--)
{
    if (data[j] > data[j - 1]) 
        swap(data[j], data[j - 1]);
    }
}
cout << "\n\n Hasil Sortigan Adalah : \n";
for (int i = 0; i < z; i++)
{
        cout << " " << data[i] << " ";
}
    cout << endl;
    return 0;
}
