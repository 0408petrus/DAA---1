#include <iostream>
using namespace std;


int main (){
    int data[8], n = 8;

    cout <<"Masukkan angka : \n";
    for (int i = 0; i < 8; i++) {
        cout << "Angka ke - " << i+1 <<" : ";
        cin >> data[i];
    }

    for(int i = 0; i<10; i++) {
        for(int j = i+1; j<10; j++) {
            if(data[j] > data[i]) {
                swap(data[j], data[i]);
            }
        }
    }

    cout << "Data yang telah disortir : \n";
    for (int i = 0; i < 8; i++){
        cout << data[i] <<" ";
    }
}