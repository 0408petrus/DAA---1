#include <iostream>
using namespace std;
int main()
{
cout << "--------------" << endl;
cout << "Selection Sort " << endl;
cout << "--------------" << endl;
int n , pos;
int data[8];
cout << "Input banyak data yang kamu mau : ";
cin >> n;
for (int i = 0; i < n; i++)
{
cout << "Data-" << i + 1 << " : ";
cin >> data[i];
}

for (int i = 0; i < n - 1; i++)
{
pos = i;
for (int j = i + 1; j < n; j++)
{
if (data[j] > data[pos]) // Descending
pos = j;
}
if (pos != i)
swap(data[pos], data[i]);
}
//
cout << "Sorted Data kamu : ";
cout << endl;
for (int i = 0; i < n; i++)
{
cout << data[i] << " ";
}
cout << endl;
return 0;
}
