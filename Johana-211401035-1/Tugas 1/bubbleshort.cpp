#include<iostream>
using namespace std;
int main(){
    cout<<"Soal: 10,11,23,21,0,0,8,7\n";
    cout<<"Buble Short: ";
    int data[10]={10,11,23,21,0,0,8,7};
    for (int i=1;i<8;i++){
        for(int j=7;j>=i;j--){
            if (data[j]>data[j-1])
            swap(data[j],data[j-1]);
        }
    }
    for (int i=0;i<8;i++){
        cout<<data[i]<<" ";
    }

}
