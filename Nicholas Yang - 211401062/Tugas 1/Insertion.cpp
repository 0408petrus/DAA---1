#include <iostream>
using namespace std;


int main (){
    int data[8], n = 8;

    cout <<"Masukkan angka : \n";
    for (int i = 0; i < 8; i++) {
        cout << "Data ke - " << i+1 <<" : ";
        cin >> data[i];
    }

   for (int i = 1; i < n; i++) {
        int temp = data[i];
        int j = i - 1;
        while (data[j] < temp && j >= 0) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    cout << "Data yang telah disortir : \n";
    for (int i = 0; i < 8; i++){
        cout << data[i] <<" ";
    }
}