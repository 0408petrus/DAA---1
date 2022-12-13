#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define nmax 10 // maksimal teman pet
#include<stack>
using namespace std;
int n = 0;

struct tgl_lahir {
  int Tanggal;
  int Bulan;
  int Tahun;
};

struct data{
    char nama[30];
    char umur[5]; //umur pet dalam hari
    char namapet[20];
    char zodiak[10];
    tgl_lahir lahir;
};

struct data pet[nmax];
struct data temp;
void tambah_data();
void hapus_data();
void tampilkan_data();
void ubah_data();
void sorting_data();

void statis()
{
    int pil;
    do{
            cout <<" \t\t SELAMAT DATANG DI SHOPEE PETS\n";
            cout <<" \t\t      MENU  SHOPEE PET\n";
            cout <<"1. Tambah teman pet \n";
            cout <<"2. Tampilkan teman pet\n";
            cout <<"3. Ubah teman pet\n";
            cout <<"4. Hapus teman pet\n";
            cout <<"5. Urutkan teman pet \n";
            cout <<"6. Keluar\n";
            cout <<">> ";cin>>pil;
    switch(pil){
        case 1:
            tambah_data();
            break;
        case 2:
            tampilkan_data();
            break;
        case 3:
            ubah_data();
            break;
        case 4:
            hapus_data();
            break;
        case 5:
            sorting_data();
        case 6:
            break;

        default : cout << "maaf pilihanmu tidak ada,silahkan pilih menu lain!\n";
    }
    } while (pil != 6);
}

void tambah_data(){
    if (n < nmax){
        cout << "Nama pemilik pet : "; cin >> pet[n].nama;
        cout << "Nama pet         : "; cin >> pet[n].namapet;
        cout<<"Tanggal lahir pet  :\n";
        cout<<"\tTanggal  : "; cin>>pet[n].lahir.Tanggal;
        cout<<"\tBulan    : "; cin>>pet[n].lahir.Bulan;
        cout<<"\tTahun    : "; cin>>pet[n].lahir.Tahun;
        cout << "Umur pet         : "; cin >> pet[n].umur;
        cout << "Zodiak pet       : "; cin >> pet[n].zodiak;
    n++;
}
    else
    cout << "\n Maaf pet-mu tidak dapat menambahkan teman lagi.\n maksimal teman pet = " << nmax;
}

void tampilkan_data(){
    if (n == 0)
        cout << " Pet-mu sendirian,tolong tambah teman!\n";
    else{
        for (int i = 0; i < n; i++){
            cout << "\nData teman di Shopee Pet ke-" << i + 1 << " : ";
            cout << "\nNama Pemilik Pet : " << pet[i].nama;
            cout << "\nNama Pet : " << pet[i].namapet;
            cout <<"\nTanggal Lahir  : "<<pet[i].lahir.Tanggal<<"-";cout<<pet[i].lahir.Bulan<<"-"<<pet[i].lahir.Tahun;
            cout << "\nUmur Pet : " << pet[i].umur<<" hari";
            cout << "\nZodiak Pet : " << pet[i].zodiak;
            cout << "\n_________________________________________________ "<<endl;
            cout << endl;
        }
    }
    getch();
}

void ubah_data(){
    int ub;
    cout<<"Pilih teman pet yang ingin diubah : ";cin>>ub;
    if(ub<=n && ub>=0) {
        for(int i=ub-1;i<ub;i++){
            cout << "Nama pemilik pet : "; cin >> pet[n].nama;
            cout << "Nama pet         : "; cin >> pet[n].namapet;
            cout<<"Tanggal lahir pet  :\n";
            cout<<"\tTanggal  : "; cin>>pet[n].lahir.Tanggal;
            cout<<"\tBulan    : "; cin>>pet[n].lahir.Bulan;
            cout<<"\tTahun    : "; cin>>pet[n].lahir.Tahun;
            cout << "Umur pet         : "; cin >> pet[n].umur;
            cout << "Zodiak pet       : "; cin >> pet[n].zodiak;
        }
    } else
        cout<<"\nTeman pet-mu tidak ada\n";
}

void hapus_data(){
    int x;
    cout << "pilih teman pet yang ingin kamu hapus (1 s.d. 10) : ";
    cin >> x;
    if (x < n && x > 0){
        for (int i = x; i < n; i++){
            strcpy(pet[i - 1].nama, pet[x].nama);
            pet[i - 1].namapet == pet[x].namapet;
            pet[i - 1].umur == pet[x].umur;
            pet[i - 1].zodiak == pet[x].zodiak;
            pet[i - 1].lahir.Tanggal = pet[x].lahir.Tanggal;
            pet[i - 1].lahir.Bulan = pet[x].lahir.Bulan;
            pet[i - 1].lahir.Tahun = pet[x].lahir.Tahun;
        }
    n--;
    }
    else if (x == n)
    n--;
    else
        cout << "\n Teman pet-mu tidak ada :/ \n";
}

void sorting_data(){
    if(n == 0)
        cout<<"\nPet-mu tidak punya teman.";
    else {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(pet[i].umur<pet[j].umur)
            {
                temp=pet[i];
                pet[i]=pet[j];
                pet[j]=temp;
            }
        }
        cout<<"\nTeman pet ke-"<<i+1<<":"<<endl;
        cout<<"Nama   pet        : "<<pet[i].nama<<endl;
        cout<<"Umur   pet        : "<<pet[i].umur<<"  hari"<<endl;
        cout<<"Zodiak pet        : "<<pet[i].zodiak<<endl;
        cout<<"Tanggal lahir pet : "<<pet[i].lahir.Tanggal<<"-";cout<<pet[i].lahir.Bulan<<"-"<<pet[i].lahir.Tahun;
    }
    }
    getch();
}

void dinamis()
{
    stack<int> s;
    stack<string> st;
    int i, j, n, pos, tugas[100], uts[100], uas[100], total[100];
    string nama[100];
    cout<<"Masukkan jumlah data mahasiswa : ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"Masukkan data mahasiswa ke "<<i<<" : \n";
        cout<<"Nama : ";
        cin>>nama[i-1];
        cout<<"Nilai Tugas : ";
        cin>>tugas[i-1];
        cout<<"Nilai UTS : ";
        cin>>uts[i-1];
        cout<<"Nilai UAS : ";
        cin>>uas[i-1];
    }

    for(i=1;i<=n;i++)
    {
        total[i-1]=tugas[i-1]+uts[i-1]+uas[i-1];
    }
    for (i=0;i<n-1;i++)
    {
        pos = i;
        for (j=i+1;j<n;j++)
        {
            if (total[j]<total[pos])
            pos = j;
        }
        if (pos!=i)
        swap(total[pos], total[i]);
        swap(nama[pos], nama[i]);
    }

    for(i=1;i<=n;i++)
    {
        st.push(nama[i-1]);
        s.push(total[i-1]);
    }

    cout<<"\nRanking : \n";
    cout<<"Nama"<<"   "<<"Total\n";
    do
    {
        cout<<st.top()<<"    ";
        cout<<s.top()<<endl;
        st.pop();
        s.pop();
    } while (s.size() != 0);
    cout<<endl;
}

int main()
{
    int ans;
    menu:
    system("cls");
    cout<<"Data Structure : \n";
    cout<<"1. Statis\n";
    cout<<"2. Dinamis\n";
    cout<<"3. Keluar\n";
    cout<<"Ans : ";
    cin>>ans;
    if(ans==1)
    {
        statis();
    }
    else if(ans==2)
    {
        dinamis();
    }
    else if(ans==3)
    {
        return 0;
    }
    else
    {
        cout<<"Wrong Command";
    }
    getch();
    goto menu;
}
