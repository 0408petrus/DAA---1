#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;
#define MAX 50

int n = 0;
struct barang{
	char nama[20];
	int id;
	int harga;
	barang *next;
};

void tampilkan_menu(){
	cout<<"================== PILIHAN MENU DATA =====================\n"<<endl;
	cout<<"1. Tambah Pesanan"<<endl;
	cout<<"2. Hapus Pesanan"<<endl;
	cout<<"3. Tampilkan Pesanan"<<endl;
	cout<<"4. Update Pesanan"<<endl;
	cout<<"5. Keluar"<<endl;
}

// BAGIAN DATA STATIS
struct barang belanja[MAX];

sorting_statis(){
	for(int i = 1;i<n;i++){
		for(int j=n-1;j>=i;j--){
			if(belanja[j].harga < belanja[j-1].harga){
				swap(belanja[j], belanja[j-1]);
			}
		}
	}
}

tambah_data(){
	if(n<= MAX)	{
		cout<<"Nama Barang \t: "; cin>>belanja[n].nama;
		cout<<"ID Barang \t: "; cin>> belanja[n].id;
		cout<<"Harga Barang\t: "; cin>> belanja[n].harga;
		n++;
		
	} else {
		cout<<"Maaf... Anda telah mencapai batas maksimum"<<endl;
	}
	system("cls");
}

hapus_data(){
	int x;
	sorting_statis();
		
	for(int i =0;i<n;i++){
		cout<<i+1<<"   Nama Barang \t: "<<belanja[i].nama;
		cout<<"\n    ID Barang  \t: "<<belanja[i].id;
		cout<<"\n    Harga Barang \t: "<<belanja[i].harga;
		cout<<"\n\n";	
	}
	cout<<"Pilih nomor belanja yang dihapus : "; cin>>x;
	if(x<n && x>0){
		for(int i=x; i<n;i++){
			strcpy(belanja[i-1].nama, belanja[x].nama);
			belanja[i-1].id = belanja[x].id;
			belanja[i-1].harga = belanja[x].harga;
		}
		n--;
	}
	else if(x==n){
		n--;
	}	
	else {
		cout<<"\n data yang ingin dihapus tidak ada...!!!\n";
		getch();
	}
	system("cls");	
}


tampilkan_data(){
	int total = 0;
	if(n==0){
	   cout<<"tidak ada Pesanan yang disimpan...!!!!\n";
	} 
	else {	
		sorting_statis();	
		for(int i =0;i<n;i++){
			cout<<i+1<<".   Nama Barang \t: "<<belanja[i].nama;
			cout<<"\n     ID Barang  \t: "<<belanja[i].id;
			cout<<"\n     Harga Barang \t: "<<belanja[i].harga;
			total += belanja[i].harga;
			cout<<"\n\n";	
		}	
	}
	cout<<"\nTotal Pesanan Anda adalah Rp."<<total<<endl;
	getch();
	system("cls");

}

update_data(){
	int nomorUbah;
	cout<<"Nomor barang yang ingin diubah \t: ";
	cin>>nomorUbah;
	
	if(nomorUbah<=n && nomorUbah > 0){
		cout<<"Nama Barang \t: ";
		cin>>belanja[nomorUbah-1].nama;
		cout<<"ID Barang \t: ";
		cin>>belanja[nomorUbah-1].id;
		cout<<"Harga Barang \t: ";
		cin>>belanja[nomorUbah-1].harga;
	} else {
		cout<<"Data tidak ditemukan..."<<endl;
	}
}

//----------------------------

//untuk data dinamis
barang *head = NULL;
barang *tail = NULL;
barang *node;

TambahData(){
	barang *dataBaru;
	dataBaru = new barang;
	cout<<"ID Barang \t: "; cin>>dataBaru->id;
	cout<<"Nama Barang \t: "; cin>>dataBaru->nama;
	cout<<"Harga Barang \t: "; cin>> dataBaru -> harga;

	if(tail==NULL){
		head = dataBaru;
		tail = dataBaru;
	} else {
		tail->next = dataBaru;
		tail = dataBaru;
	}
	system("cls");
}

TampilkanData(){
	barang *temp;
	temp = head;
	
	if(temp == NULL){
		cout<<"Anda belum berbelanja!!!";
	} else {	
		while(temp != NULL){
			cout<<"Nama Barang \t: "<<temp->nama<<endl;
			cout<<"ID Barang \t: "<<temp->id<<endl;
			cout<<"Harga Barang \t: "<<temp->harga<<endl;
			temp = temp->next;
			cout<<endl;
		}
	}
	getch();
	system("cls");
}

HapusData(int y){
	barang *temp1 = head;

	if(head == NULL && tail == NULL){
		cout<<"Barang Tidak ada, silakan berbelanja ..."<<endl;
	}
	if(y==1){
		head = temp1->next;
	}
	for(int i = 0;i<n-2;i++){
		temp1 = temp1->next;
	}
	barang *temp2 = temp1->next;
	temp1->next = temp2->next;
	delete(temp2);
	cout<<"Barang sukses dihapus ..."<<endl;
	getch();
	system("cls");
	
	
}

UpdateData(int y){
	bool cari = false;
	barang *temp4;
	temp4 = head;
	
	while(temp4 != NULL){
		if(temp4->id==y){
			cari = true;
			cout<<"Nama Barang \t: "<<temp4->nama<<endl;
			cout<<"ID Barang \t: "<<temp4->id<<endl;
			cout<<"Harga Barang \t: "<<temp4->harga<<endl;
			
			cout<<"Proses Ubah=============="<<endl;
			cout<<"Nama Barang \t : "; cin>>temp4->nama;
			cout<<"ID Barang \t: "; cin>>temp4->id;
			cout<<"Harga Barang \t : "; cin>>temp4->harga;
			
			cout<<"\n\n Data Berhasil Diedit"<<endl;
			getch();
		}
		temp4 = temp4->next;
	}
	getch();
	system("cls");
}





int main() {
	int pilihan, pilihan_statis, pilihan_dinamis,y;
	cout<<"====================== MENU HOME =================================\n"<<endl;
	cout<<"1. Data Statis"<<endl;
	cout<<"2. Data Dinamis"<<endl;
	cout<<">> "; cin>>pilihan;
	system("cls");
	
	switch(pilihan){
		case 1:
			menustatis:
			tampilkan_menu();
			cout<<">> ";
			cin>>pilihan_statis;
			system("cls");
			
			switch(pilihan_statis){
				case 1 :
					tambah_data();
					break;
				case 2 :
					hapus_data();
					break;
				case 3 :
					tampilkan_data();
					break;
				case 4 :
					update_data();
					break;
				case 5 :
					exit(1);
					break;
				default :
					cout<<"Anda salah memasukkan angka....";				
			}
			goto menustatis;
		case 2 :
			menudinamis:
			tampilkan_menu();
			cout<<">> ";
			cin>>pilihan_dinamis;
			system("cls");
			switch(pilihan_dinamis){
				case 1 :
					TambahData();
					break;
				case 2 :
					cout<<"Posisi data yang dihapus \t:";
					cin>>y;
					HapusData(y);
					break;
				case 3 :
					TampilkanData();
					break;
				case 4 :
					cout<<"ID yang diedit : ";
					cin>>y;
					UpdateData(y);
					break;
				case 5 :
					exit(1);
					break;
				default :
					cout<<"Anda salah memasukkan angka....";
			}
			goto menudinamis;	
	}
}

