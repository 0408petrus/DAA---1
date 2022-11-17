#include <iostream>
using namespace std;


int main (){
    int data[8], n = 8;

    cout <<"Masukkan angka : \n";
    for (int i = 0; i < 8; i++) {
        cout << "Angka ke - " << i+1 <<" : ";
        cin >> data[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] > data[pos])
                pos = j;
        }
        if (pos != i)
            swap(data[pos], data[i]);
    }

    cout << "Data yang telah disortir : \n";
    for (int i = 0; i < 8; i++){
        cout << data[i] <<" ";
    }
}