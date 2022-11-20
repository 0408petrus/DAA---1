#include <iostream>
using namespace std;
int main()
{
  cout << "-----------" << endl;
  cout << "Bubble sort" << endl;
  cout << "-----------" << endl;
  int n;
  int data[8];
  cout << "input Banyak Data Yang Kamu Mau : ";
  cin >> n; 
  for (int i = 0; i < n; i++)
{
        cout << "Data- " << i + 1 << " : ";
        cin >> data[i];
}
// bubble sort
for (int i = 1; i < n; i++)
{
  for (int j = n - 1; j >= i; j--)
{
    if (data[j] > data[j - 1]) // descending
        swap(data[j], data[j - 1]);
    }
}
//
cout << "sorted data Kamu : \n";
for (int i = 0; i < n; i++)
{
        cout << data[i] << " ";
}
    cout << endl;
    return 0;
}
