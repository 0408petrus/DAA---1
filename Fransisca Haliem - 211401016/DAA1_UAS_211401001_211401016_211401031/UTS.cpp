#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define nmax 5
using namespace std;

int n=0;
 struct data
 {
 	char nama_pegawai[30];
 	int id_pegawai;
 	char golongan_pegawai[8];
 };

 struct data pegawai[nmax];
 void tambah_data();
 void hapus_data();
 void tampilkan_data();

 struct node
 {
    struct data Data;
    struct node* next;
 };

 struct node *head = NULL;
 struct node *last = NULL;

 bool isEmpty(node *head)
 {
     return head == NULL;
 }

 char menu()
 {
     char choice;
     cout<<"1. Tambah data\n";
     cout<<"2. Hapus data\n";
     cout<<"3. Tampilkan data\n";
     cout<<"4. Mencari data\n";
     cout<<"5. Exit\n";
     cout<<"Pilihan : ";
     cin>>choice;
     return choice;
 }

  void insert(struct data Data){
    if(isEmpty(head)){
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        temp->Data = Data;
        temp->next = NULL;
        head = temp;
        last = temp;

    }else{
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        temp->Data = Data;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

}

void selectionSort(node* awal_ptr)
{
    node* temp = awal_ptr;

    while (temp) {
        node* min = temp;
        node* r = temp->next;

        while (r) {
            if (min->Data.id_pegawai > r->Data.id_pegawai)
                min = r;

            r = r->next;
        }

        int x = temp->Data.id_pegawai;
        temp->Data.id_pegawai = min->Data.id_pegawai;
        min->Data.id_pegawai = x;

        char nsort[20];
        strcpy(nsort, temp->Data.nama_pegawai);
        strcpy(temp->Data.nama_pegawai , min->Data.nama_pegawai);
        strcpy(min->Data.nama_pegawai, nsort);

        char m[10];
        strcpy(m, temp->Data.golongan_pegawai);
        strcpy(temp->Data.golongan_pegawai , min->Data.golongan_pegawai);
        strcpy(min->Data.golongan_pegawai, m);


        temp = temp->next;
    }
}

void TampilkanData()
{
    char so;
    node *temp;
    temp = head;
    if(isEmpty(head)){
    cout<<"Data Tidak Ada\n";
    }
    else{
        selectionSort(head);
        while(temp!=NULL){
        cout<<"\nId Pegawai           : "<<temp->Data.id_pegawai<<endl;
        cout<<"Nama Pegawai         : "<<temp->Data.nama_pegawai<<endl;
        cout<<"Golongan Pegawai     : "<<temp->Data.golongan_pegawai<<endl;
        temp = temp->next;
        }
    }
    system("pause");
}

void MencariData()
{
    int tempid;
    if(isEmpty(head)){
            cout<<"Data Kosong\n";
    }else{
        cout<<"\nId Pegawai yang dicari : ";
        cin>>tempid;
        struct node *temp = head;
        while(temp->next!=NULL){
            if(temp->Data.id_pegawai==tempid){
                    break;
            }
            temp = temp -> next;
        }
        if(temp->Data.id_pegawai==tempid){
            cout<<"Nama Pegawai : "<<temp->Data.nama_pegawai<<endl;
        }else{
            cout<<"Data id pegawai : "<<tempid<<"Tidak ada";
        }
    }
    system("pause");
}

void HapusData(node* head)
{
 	int dataa,ph,poshapus;
 	node *hapus, *bantu;
 	if(head != NULL)
 	{
 		cout<<"Data yang ingin kamu hapus : ";
 		cin>>ph;
 		dataa=1;
 		bantu=head;
 		while(bantu->next != NULL)
 		{
 			bantu=bantu->next;
 			dataa++;
 		}
 	if((ph<1)||(ph>dataa))
 	{
 		cout << "Tidak ada data disitu"<<endl;
 	}
 	else
 	{
 		bantu=head;
 		poshapus=1;
 		while(poshapus<(ph-1))
 		{
 			bantu=bantu->next;
 			poshapus++;
 		}
 		hapus=bantu->next;
 		bantu->next=hapus->next;
 		delete hapus;
        }
 	}
}
int main()
{

 int pilihan,pil;
 a:
 cout << "\t -------------------------------------"  << endl;
 cout << "\t|Selamat Datang Di Program Kelompok 1 |" << endl;
 cout << "\t -------------------------------------"  << endl;
 cout << endl;

 printf("\n Kami Menyediakan Beberapa Menu Untuk Anda : ");
 printf("\n 1. Struktur Data Statis ");
 printf("\n 2. Struktur Data Dinamis ");
 cout << endl;
 cout << " Silakan Pilih Menu Kamu : ";
 cin >> pilihan;
 system ("cls");

 switch(pilihan){
 	case 1:
 		b:
 		    system("cls");
 		cout << endl;
 		cout << "\t -------------------------------------"  << endl;
 		cout << "\t|Selamat Datang Di Program Kelompok 1 |" << endl;
 		cout << "\t -------------------------------------"  << endl;
		cout << endl;
 		cout << " Menu :\n";
 		cout << "1. Tambah Data\n";
 		cout << "2. Hapus Data\n";
 		cout << "3. Tampilkan Data\n";
 		cout << "4. Kembali\n";
 		cout << "Pilih Menu Yang Kamu Mau : ";
 		cin >> pil;
 		system ("cls");

 		if (pil == 1)
 			tambah_data();

 		else if (pil == 2)
 			hapus_data();

 		else if (pil == 3)
 			tampilkan_data();

 		else if (pil == 4)
 			goto a;

 		else {
 			cout << "Yahh Pilihan Kamu Tidak Ada, Silakan input lagi \n\n ";
		 }
		goto b;
 		break;
    case 2:
         char choice;
         struct data Data;
         do{
            system("cls");
            choice = menu();
            switch(choice){
            case '1':
                cout<<"\nId Pegawai : ";
                cin>>Data.id_pegawai;
                cout<<"Nama Pegawai : ";
                cin>>Data.nama_pegawai;
                cout<<"Golongan Pegawai : ";
                cin>>Data.golongan_pegawai;
                insert(Data);
                break;
            case '2':
                HapusData(head);
                break;
            case '3':
                TampilkanData();
                break;
            case '4':
                MencariData();
                break;
            case '5':
                cout<<"Exit";
            }
         }while(choice!='5');
     }
}

void tambah_data()
{
	if (n < nmax)
	{
		cout << "Nama Pegawai : ";
		cin  >> pegawai[n].nama_pegawai;
		cout << "ID Pegawai : ";
		cin  >> pegawai[n].id_pegawai;
		cout << "\nSilakan Input Golongan Pegawai (Swasta/Negeri) : ";
		cout << "\nGolongan Pegawai : ";
		cin  >> pegawai[n].golongan_pegawai;
		n++;
		system ("cls");
	}

	else
		cout << "Data Telah Melebihi\n Maksimal data = " <<nmax;
}

void hapus_data()
{
	int x;
	cout << "Pilih Data Yang Akan Dihapus (1 s/d 5) : ";
	cin >> x;
	system ("cls");
	if (x < n && x > 0)
	{
		for (int i = x; i < n; i++)
		{
			strcpy(pegawai[i-1].nama_pegawai,pegawai[x].nama_pegawai);
			pegawai[i-1].id_pegawai,pegawai[x].id_pegawai;
			pegawai[i-1].golongan_pegawai,pegawai[x].golongan_pegawai;
		}
		n--;

	}

	else if (x == n)
	n--;

	else
    {
        cout << "Data Yang Dihapus Tidak Ada\n";
    }
    getch();

}

void tampilkan_data()
{
	if (n == 0)
	cout << "Tidak Ada Data Yang Disimpan\n";

	else {
		for (int i = 1; i < n; i++)
		{
		  for (int j = n - 1; j >= i; j--)
		{
		    if (pegawai[j].id_pegawai < pegawai[j-1].id_pegawai) // Ascending
		        swap(pegawai[j], pegawai[j-1]);
		    }
		}
		for (int i = 0; i < n; i++)
		{
			cout << endl;
			cout << " Data Ke- " << i+1 << " : ";
			cout << "\n ID Pegawai : "<< pegawai[i].id_pegawai;
			cout << "\n Nama : " << pegawai[i].nama_pegawai;
			cout << "\n Golongan : "<< pegawai[i].golongan_pegawai;
			cout << endl;

		}
	}
	getch();
}
