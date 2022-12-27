//program cm (untuk tinggi)
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
 
 int n= 0, d=1;
 struct data { //struktur data mahasiswa yang akan di input 
 	char nama[40];
 	int umur;
 	int nim;
 	int tinggi;
 	int berat;
 	
 };
 
 	struct data Mahasiswa[140];
 	
 	void input (){
 		
 	   for (int i=n; i<d;i++){
 		cout <<" \n Nama Mahasiswa    : ";
 		cin>>Mahasiswa[n].nama;
 		cout <<" NIM	           : ";
 		cin>> Mahasiswa[n].nim;
 		cout <<" Umur              : ";
 		cin>> Mahasiswa[n].umur;
 		cout <<" Tinggi Badan(cm)  : ";
 		cin>> Mahasiswa[n].tinggi;
 		cout <<" Berat Badan(kg)   : ";
 		cin>> Mahasiswa[n].berat;
 		float bmi = Mahasiswa[n].berat/((Mahasiswa[n].tinggi/100)*(Mahasiswa[n].tinggi/100));
		   	 		if(bmi <= 18)
                		cout<<"\n BERAT BADAN KURANG";
            		else if(bmi > 18 && bmi<=24)
                		cout<<"\n BERAT BADAN IDEAL";
            		else if(bmi > 30)
                		cout<<"\n OBESITAS";
		   	 		cout<<"\n\n";
	 }
 	 n++;
 	 d++;
 };
		void hapus_data(){
		int x;
			cout << endl;
			cout <<" \t ````````````````````````````````"<<endl;
			cout <<"\t | Pilih Data Yang Ingin Dihapus | " <<endl;
			cout <<"\t ````````````````````````````````"<<endl;
			cout <<endl;
 			 cout<<" PILIH NOMOR DATA YANG INGIN DIHAPUS  : "; cin>>x;
					if(x<n && x>0){
					for (int i=x; i<n; i++){
					strcpy(Mahasiswa[i-1].nama,Mahasiswa[x].nama);
					 Mahasiswa[i-1].nim= Mahasiswa[x].nim;
					 Mahasiswa[i-1].tinggi=Mahasiswa[x].tinggi;
				}
				n--;
			}
			 else if (x==n){
   			 n--;}
   			 else{
   			 	cout << endl;
   			 	cout<<" DATA YANG INGIN DIHAPUS TIDAK ADA !!!\n";
   				 }
   	};
   			
	   void tampilkan_data() { /
	   	 	if (n==0)
	   			cout <<" BELUM DATA YANG SIMPAN...!!!\n ";
	   		else
	   	 		for (int i =1;i<n;i++){ //buble sort
	   	 			for (int j=n-1; j>=i; j--){
					if(Mahasiswa[j].tinggi < Mahasiswa[j-1].tinggi)	
				{
					swap (Mahasiswa[j],Mahasiswa[j-1]);
					}
				}
				}
				for (int i=0; i<n;i++){
		   	 		cout <<" \n Data ke- "<<i+1<<" ";
		   	 		cout <<"\n Nama             : "<<Mahasiswa[i].nama;
		   	 	    cout <<"\n NIM              : "<<Mahasiswa[i].nim;
		   	 		cout <<"\n Tinggi Badan(cm) : "<<Mahasiswa[i].tinggi;
		   	 		float bmi = Mahasiswa[i].berat/((Mahasiswa[i].tinggi/100)*(Mahasiswa[i].tinggi/100));
		   	 		if(bmi <= 18)
                		cout<<"\n BERAT BADAN KURANG";
            		else if(bmi > 18 && bmi<=24)
                		cout<<"\n BERAT BADAN IDEAL";
            		else if(bmi > 30)
                		cout<<"\n OBESITAS";
		   	 		cout<<"\n\n";
				}
			}
	   }
int main(){
	
	int pilihan, pilihan_statis;
	system("cls");
	cout <<endl;
	cout <<"\t  Selamat Datang Di Program Kelompok 3  " <<endl;
	cout <<"\t ```````````````````````````````````````"<<endl;
	cout << endl;
		cout <<"  -------------------"<<endl;
 		cout <<"  | MENU PILIHAN    | "<<endl;
 		cout <<"  |                 | "<<endl;
		cout <<"  | 1. Data Statis  | "<<endl;
		cout <<"  | 2. Data Dinamis | "<<endl;
		cout <<"  -------------------"<<endl;
		cout<<"   >> "; cin>>pilihan;
		system("cls");

	
	switch(pilihan) {
		case 1 :
			menu:
			cout<<"\n ================== PILIHAN MENU DATA STATIS =====================\n"<<endl;
			cout<<" 1. Input Data "<<endl;
			cout<<" 2. Tampilkan "<<endl;
			cout<<" 3. Hapus "<<endl;
			cout<<" 4. Keluar "<<endl;
			cout<<" >> ";cin>>pilihan_statis;
			system("cls");
			switch(pilihan_statis){
				case 1 :
					
					input();
				
					break;
				case 2 :
				
					tampilkan_data();
					break;
				case 3 :
					hapus_data();
					break;
				case 4 :
					exit(1);
					break;
				default :
					cout<<"PILIHAN TIDAK TERSEDIA...";
			}
			goto menu;
	}
}
