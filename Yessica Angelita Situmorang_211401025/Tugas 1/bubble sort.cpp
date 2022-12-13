
#include <iostream>
using namespace std;
int main()
{
cout << "Bubble sort\n\n";
int n = 8;
int data[8];
cout << "input data: \n\n";
for (int i = 0; i < 8; i++)
{
cout << "Data- " << i + 1 << " : ";
cin >> data[i];
}
// ---- bubble sort
for (int i = 1; i < n; i++)
{
for (int j = n - 1; j >= i; j--)
{
if (data[j] > data[j - 1]) // descending
swap(data[j], data[j - 1]);
}
}
//
cout << "\n sorted data\n";
for (int i = 0; i < n; i++)
{
cout << data[i] << " ";
}
cout << endl;
return 0;
}
