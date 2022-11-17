#include<iostream>
using namespace std;
int main(){
    cout<<"Soal: 10,11,23,21,0,0,8,7\n";
    cout<<"Insertion Short: ";
    int data[8]= {10,11,23,21,0,0,8,7};
    int temp,j;
    for (int i=1;i<8;i++){
        temp=data[i];
        j=i-1;
        while(data[j]<temp&&j>=0){
            data[j+1]=data[j];
            j--;
        }
        data[j+1]=temp;
    }
    for (int i=0;i<8;i++){
        cout<<data[i]<<" ";
    }

}