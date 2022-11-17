#include <iostream>
using namespace std;
int main()
{
cout << "Insertion Sort \n\n";
cout << "Input banyak data : ";
int n = 8, pos;
int data[8];
cout << "Input Data : \n\n";
for (int i = 0; i < n; i++)
{
    cout << "Data-" << i + 1 << " : ";
    cin >> data[i];
}
//--------------------Insertion Sort
int temp, j;
for (int i = 1; i < n; i++)
{
    temp = data[i];
    j = i - 1;
    while (data[j] > temp && j >= 0)
    { // Descending
        data[j + 1] = data[j];
        j--;
    }
    data[j + 1] = temp;
}
//-------------------------------
cout << "\nSorted Data\n";
for (int i = 0; i < n; i++)
{
    cout << data[i] << " ";
}
cout << "\n";
return 0;
}

