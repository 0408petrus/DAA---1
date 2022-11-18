#include <iostream>
using namespace std;


int main(){
	int n;
	int temp;
	cout<<"Masukkan banyak data : "; cin>>n;
	int data[n];
	
	cout<<"========================== MASUKKAN DATA ANDA ===============================\n"<<endl;
	for(int i = 0; i<n; i++){
		cout<<"Inputkan data ke-"<<i+1<<" : " ;cin>>data[i];
	}
	cout<<"\n\n";
	
	//BUBBLE SORT	
	for (int a=1;a<n;a++){
		for(int b=0;b<n-a;b++){
			if (data[b+1]>data[b]){
				temp = data[b];
				data[b]= data[b+1];
				data[b+1] = temp;
			}
		}

	}
	
	cout<<"Sorting menggunakan bubble sort \t=> ";
	for(int i=0;i<n;i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
	
	
//	selection sort
	for (int i = 0; i < n - 1; i++){
        int pos = i;
        for (int j = i+1; j<n; j++){
            if (data[j] > data[pos]) 
                pos = j;
        }
        if (pos != i)
            swap(data[pos], data[i]);
    }

    cout << "Sorting menggunakan selection sort \t=> ";
    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
    cout<<endl;


// Insertion sort
	int j;
	for (int i = 1; i < n; i++){
        temp = data[i];
        j = i - 1;
        while (data[j] < temp && j >= 0){ 
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
 
    cout << "Sorting menggunakan Insertion sort \t=> ";
    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
}
