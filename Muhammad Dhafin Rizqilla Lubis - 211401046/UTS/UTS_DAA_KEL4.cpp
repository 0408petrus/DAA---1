#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int n = 0, d = 0;

struct data{
    char nama[20];
    int nilai;
    char kom;
};

struct data maba[5];
struct data temp;

void menustatic();
void input();
void tampil();
void update();
void hapus();
void staticsort();

struct node{
    char nama[20],kom;
    int nilai;
node *next;
};

node *awal_ptr = NULL;

void menudinamis();
void inputd();
void tampild();
void updated();
void hapusd();


int main(){
        int pilihan;
        do {
            system("CLS");
            cout<<"Silahkan pilih menu.\n";
            cout<<"1. Struktur Data Statis\n";
            cout<<"2. Struktur Data Dinamis\n";
            cout<<"3. Keluar\n";
            cout<<"Opsi: ";cin>>pilihan;

            switch(pilihan){
                case 1:
                    menustatic();
                    break;
                case 2:
                    menudinamis();
                    break;
                case 3: break;
                default:
                    cout<<"Menu tidak tersedia";getch();
            }
        }while (pilihan != 3);
}

void menustatic() {
    int opsi;

    do{
        system("CLS");
        cout<<"Silahkan pilih masukan: \n";
        cout<<"1. Input Data\n";
        cout<<"2. Tampilkan Data\n";
        cout<<"3. Update Data\n";
        cout<<"4. Delete Data\n";
        cout<<"5. Kembali\n";
        cout<<"Opsi : ";cin>>opsi;
        switch(opsi){
            case 1:
                input();
                break;
            case 2:
                tampil();
                break;
            case 3:
                update();
                break;
            case 4:
                hapus();
                break;
            case 5:
                break;
            default:
                cout<<"Menu tidak tersedia";
        }
    } while (opsi != 5);
}

void input(){
    if (n==5){
        cout<<"Kapasitas data sudah penuh";
        getch();
    } else {
        for(int i=n;i<n+1;i++){
            cout<<"Nama : ";
            cin>>maba[n].nama;
            cout<<"Nilai : ";
            cin>>maba[n].nilai;
            cout<<"KOM : ";
            cin>>maba[n].kom;
        }
        n++;
    }
}

void tampil(){
    char so;
    if(n == 0)
        cout<<"\nData tidak tersedia.";
    else {
        cout<<"\nApakah data ingin disorting berdasarkan nilai? (Y/T) : ";
        cin>>so;
        if ((so == 'Y') or (so == 'y')){
            staticsort();
        }
        for (int i=0;i<n;i++){
        cout<<"\nData ke-"<<i+1<<":"<<endl;
        cout<<"Nama : "<<maba[i].nama<<endl;
        cout<<"Nilai : "<<maba[i].nilai<<endl;
        cout<<"KOM : "<<maba[i].kom<<endl;
        }
    }
    getch();
}

void update(){
    int upd;
    cout<<"Pilih data yang ingin diupdate : ";cin>>upd;
    if(upd<=n && upd>=0) {
        for(int i=upd-1;i<upd;i++){
            cout<<"Nama : ";
            cin>>maba[i].nama;
            cout<<"Nilai : ";
            cin>>maba[i].nilai;
            cout<<"KOM : ";
            cin>>maba[i].kom;
        }
    } else
        cout<<"\nData tidak tersedia\n";
}

void hapus(){
    int h;
    cout<<"Pilih data yang ingin dihapus : ";cin>>h;
    if(h<n && h>0) {
        for(int i=h ; i<n ; i++) {
            strcpy(maba[i-1].nama, maba[h].nama);
            maba[i-1].nilai=maba[h].nilai;
            maba[i-1].kom=maba[h].kom;
        }
        n--;
    } else if (h==n)
        n--;
    else
        cout<<"\nData tidak tersedia\n";
}

void staticsort(){
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(maba[i].nilai<maba[j].nilai)
            {
                temp=maba[i];
                maba[i]=maba[j];
                maba[j]=temp;
            }
        }
    }
}

void menudinamis(){
    int opsi;

    do{
        system("CLS");
        cout<<"Silahkan pilih masukan: \n";
        cout<<"1. Input Data\n";
        cout<<"2. Tampilkan Data\n";
        cout<<"3. Update Data\n";
        cout<<"4. Delete Data\n";
        cout<<"5. Kembali\n";
        cout<<"Opsi : ";cin>>opsi;
        switch(opsi){
            case 1:
                inputd();
                break;
            case 2:
                tampild();
                break;
            case 3:
                updated();
                break;
            case 4:
                hapusd();
                break;
            case 5:
                break;
            default:
                cout<<"Menu tidak tersedia";
        }
    } while (opsi != 5);
}

void inputd() {
    node *temp, *temp2;
    temp = new node;
    cout << "Nama : ";
    cin >> temp->nama;
    cout << "Nilai : ";
    cin>>temp->nilai;
    cout << "KOM : ";
    cin >> temp->kom;
    temp->next=NULL;

    if (awal_ptr == NULL){
        awal_ptr = temp;
        }
    else{
        temp2 = awal_ptr;
        while (temp2->next != NULL){
            temp2 = temp2->next;
        }
            temp2->next = temp;
    }
    d++;
}

void selectionSort(node* awal_ptr)
{
    node* temp = awal_ptr;

    while (temp) {
        node* min = temp;
        node* r = temp->next;

        while (r) {
            if (min->nilai > r->nilai)
                min = r;

            r = r->next;
        }

        int x = temp->nilai;
        temp->nilai = min->nilai;
        min->nilai = x;

        char nsort[20];
        strcpy(nsort, temp->nama);
        strcpy(temp->nama , min->nama);
        strcpy(min->nama, nsort);

        char m;
        m = temp->kom;
        temp->kom = min->kom;
        min->kom = m;

        temp = temp->next;
    }
}

void tampild() {
    char so;
    node *temp;
    temp = awal_ptr;
    cout << endl;
    if (temp == NULL)
    cout << "List kosong!" << endl;
    else{
        cout<<"\nApakah data ingin disorting berdasarkan nilai? (Y/T) : ";
        cin>>so;
        if ((so == 'Y')  or (so == 'y')){
            selectionSort(awal_ptr);
        }
        while (temp != NULL){
            cout << "\nNama: "<<temp->nama <<endl;
            cout << "Nilai: " << temp->nilai<<endl;
            cout << "KOM: " <<temp->kom<<endl;

            temp = temp->next;
        }
    }
    getch();
}

void updated() {
    node *temp;
    temp = new node;
    temp = awal_ptr;
    int u;
    if(temp == NULL) {
        cout<<"List Kosong!";
        getch();
        return;
    } else {
        cout<<"Data yang ingin diganti : ";
        cin>>u;

        if ((u>d) or (u<=0)) {
            cout<<"Data tidak tersedia";
            getch();
            return;
        }


        cout << endl;
        for(int i=0 ; i<=u ; i++){
            if(i == u-1) {
                cout << "Nama : ";
                cin >> temp->nama;
                cout << "Nilai : ";
                cin >> temp->nilai;
                cout << "KOM : ";
                cin >> temp->kom;
                return;
            }
            temp = temp->next;
        }
    }
}

void hapusd() {
    node *temp1, *temp2;
    if (awal_ptr == NULL)
    cout << "List kosong!" << endl;
    else{
        temp1 = awal_ptr;
        if (temp1->next == NULL){
            delete temp1;
            awal_ptr = NULL;
        } else{
            int phapus;
            cout<<"1. Head\n2. Tail\n";
            cout<<"Pilih data yang ingin dihapus : ";cin>>phapus;
            switch (phapus) {
                case 1 :
                    awal_ptr= awal_ptr->next;
                    delete temp1;
                    break;
                case 2 :
                    while (temp1->next != NULL){
                        temp2 = temp1;
                        temp1 = temp1->next;
                    }
                    delete temp1;
                    temp2->next = NULL;
                    break;
                default :
                    cout<<"Pilihan tidak tersedia.";
                    getch();
            }
        }
    }
}
