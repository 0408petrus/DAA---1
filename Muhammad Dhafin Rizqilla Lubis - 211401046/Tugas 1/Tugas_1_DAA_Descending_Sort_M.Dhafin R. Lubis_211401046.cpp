#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main() {
    int n = 8, data[] = {10, 11, 23, 21, 0, 0, 8, 7}, pilihan, temp;
    while(true){
    a:  system("CLS");
        cout<<"Data sebelum sorting : 10 11 23 21 0 0 8 7"<<endl;
        cout<<"Menu Sorting : "<<endl;
        cout<<"1. Bubble Sort"<<endl;
        cout<<"2. Selection Sort"<<endl;
        cout<<"3. Insertion Sort"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"Pilihan : ";cin>>pilihan;

        switch(pilihan) {
        case 1:
            //BUBBLE SORT
            for(int i=1 ; i<n ; i++) {
                for(int j=n-1 ; j>=i ; j--) {
                    if(data[j]>data[j-1]) {
                        temp = data[j];
                        data[j] = data[j-1];
                        data[j-1] = temp;
                    }
                }
        }
        break;

        case 2:
            //SELECTION SORT
            int pos;
            for(int i=0 ; i<n-1 ; i++) {
                pos=i;
                for(int j=(i+1) ; j<n ; j++) {
                    if(data[j]>data[pos])
                    pos=j;
                }
                if(pos!=i) {
                    temp = data[pos];
                    data[pos] = data[i];
                    data[i] = temp;
                }
            }
        break;

        case 3:
            //INSERTION SORT
            int j;
            for(int i=1 ; i<n ; i++) {
                temp = data[i];
                j = i-1;
                while(data[j]<temp && j>=0) {
                    data[j+1] = data[j];
                    j--;
                }
                data[j+1] = temp;
            }
        break;

        default :
            cout<<"Menu tidak tersedia"<<endl;getch();
            goto a;

        case 4:
            return 0;

        }

        cout<<"Data setelah sorting : ";
        for(int i=0 ; i<n ; i++)
            cout<<data[i]<<" ";
        getch();
    }
}