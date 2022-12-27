#include <iostream>
#include <conio.h>
#include <cstring>
#include <windows.h>
using namespace std;

void gotoxy (int x, int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x,y};
    SetConsoleCursorPosition(h,c);
}

struct node //bertujuan untuk mendeklarasikan pointer dan simpul
{
    int nim;
    char nama[30];
    int umur;
    int tinggi;
    int berat;
    node *next;
};

node* head = NULL; //node awal_ptr=NULL;
node *posisi;
int pilih;

void CariData(int nmr) //untuk mencari data pada linked list, mengacu pada nim yang diterima oleh var nmr
{
	bool cari=false;
    node* temp = head;
    while(temp != NULL)
    {
        if((temp->nim)==nmr)
        {
            system("cls");
            cari=true;
            cout<<"DATA BERHASIL DITEMUKAN"<<endl;
            cout<<"NAMA   :"<<temp->nama<<" ";
            cout<<"NIM    :"<<temp->nim<<" ";
            cout<<"UMUR   :"<<temp->umur<<" ";
            cout<<"TINGGI :"<<temp->tinggi<<" ";
            cout<<"BERAT  :"<<temp->berat<<" ";
            cout<<"\nTEKAN ENTER UNTUK MELANJUTKAN PROSES";
            getch();
        }
    temp=temp->next;
    }
    if(cari==false)
    {
        system("cls");
        cout<<"MAAF DATA DENGAN NIM "<<nmr<<" TIDAK DITEMUKAN\nTEKAN ENTER UNTUK MELANJUTKAN PROSES";
        getch();
    }
}

int getlistLength(node** head) {
    int count{ 0 };
    if (*head == NULL) {
        return count;
    }
    node* data_todisplay = *head;
    while (data_todisplay != NULL) {
        count++;
        data_todisplay = (*data_todisplay).next;
    }

    return count;
}

node* getNodeatIndex(node** head, int index) {
    int i{ 0 };
    node* current = *head;
    while (current != NULL) {
        if (i == index) {
            return current;
        }
        i++;
        current = (*current).next;
    }
    return NULL;
}

node* createNodeCopy(node* source) {
    node* copy = new node;
    copy->tinggi = source->tinggi;
    copy->nim = source->nim;
    strcpy(source->nama, copy->nama);
    copy->berat = source->berat;
    copy->umur = source->umur;
    copy->next = NULL;
    return copy;
}

void copypasteNode(node* copy, node* paste) {
	strcpy((*paste).nama,(*copy).nama);
    (*paste).nim = (*copy).nim;
    (*paste).umur = (*copy).umur;
    (*paste).tinggi = (*copy).tinggi;
    (*paste).berat = (*copy).berat;
}

void swapNode(node* m, node* n) {
    node* temp = createNodeCopy(m);
    copypasteNode(n, m);
    copypasteNode(temp, n);

    delete temp;
}

void sortList(node** head) { //disorting berdasarkan tinggi badan menggunakan selection sort
    for (int i = 0; i < (getlistLength(head) - 1); i++) {
        int max = i;
        for (int j = i + 1; j < (getlistLength(head)); j++) {
            if ((*getNodeatIndex(head, j)).tinggi > (*getNodeatIndex(head, max)).tinggi) {
                max = j;
            }
        }
        if (max != i) {
            swapNode(getNodeatIndex(head, i), getNodeatIndex(head, max));
        }
    }
}

void tambah(int nmr);

node* inputDataMhs(int nmr) //berfungsi untuk mengisi simpul data yang telah dideklarasikan sebelumnya
{
    node* temp = new node;
    cout<<"Input nama   : ";
    cin >> temp->nama;
    cout<<"Input umur   : ";
    cin >>temp->umur;
    cout<<"Input tinggi : ";
    cin >>temp->tinggi;
    cout<<"Input berat  : ";
    cin >>temp->berat;
    temp->nim=nmr;
    return temp;
}
void cetak_tengah(int brs, char *teks)
{
    gotoxy(40-strlen(teks) /2,brs);
    cout<<teks;
}

int count()
{
    struct node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
        n=n->next;
        c++;
    }
    return c;
}

bool cekData(int nmr)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->nim==nmr)
            return false;
        else
            return true;
    temp=temp->next;
    }
    return true;
}

void tambah(int nmr) //untuk menambah data dalam linked list, pengolahannya dilakukan oleh fungsi input data
{
    node *temp = inputDataMhs(nmr);
    if(head==NULL)
    {
        head=temp;
        head->next=NULL;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}
void tambah_tengah_list(int nmr, int posisi_sisip)
{
    struct node *temp, *bantu;
    bantu=head;
    temp=new node;
    for(int i=1;i<posisi_sisip-1;i++)
    {
        if(bantu->next!=NULL)
            bantu=bantu->next;
        else
            break;
    }
    cout<<"Input nim    : ";
    cin >>temp->nim;
    cout<<"Input nama   : ";
    cin >>temp->nama;
    cout<<"Input umur   : ";
    cin >>temp->umur;
    cout<<"Input tinggi : ";
    cin >>temp->tinggi;
    cout<<"Input berat  : ";
    cin >>temp->berat;
    temp->nim=nmr;
    temp->next=bantu->next;
    bantu->next=temp;
}
void tambah_simpul_awal(int nmr)
{
    node *temp;
    temp=new node;
    inputDataMhs(nmr);
    temp->next=NULL;
    temp->next=head;
    head=temp;
}
void tambah_simpul_akhir(int nmr)
{
    node *temp, *temp2;
    temp=new node;
    inputDataMhs(nmr);
    temp->next=NULL;
    temp2=head;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp;
}
void InputData(int nmr) //untuk menyelesaikan fungsu tambah dan mana yang akan digunakan
{
    int c=0;
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        tambah(nmr);
        system("cls");
        cout<<"DATA BERHASIL DISIMPAN.\nTEKAN ENTER UNTUK MELANJUTKAN";
        getch();
    }
    else
    {
        if(cekData(nmr)==false)
        {
            system("cls");
            cout<<"NIM sudah pernah diinputkan";
            getch();
        }
        else
        {
            while(temp!=NULL)
            {
                if(temp->nim<nmr)
                    c++;
                temp=temp->next;
            }
            if(c==0)
                tambah_simpul_awal(nmr);
            else if(c<count())
            {
                tambah_tengah_list(nmr, ++c);
            }
            else
            {
                tambah_simpul_akhir(nmr);
            }
            system("cls");
            cout<<"DATA BERHASIL DISIMPAN.\nTEKAN ENTER UNTUK MELANJUTKAN";
            getch();
        }
    }
}

int hapus(int nim) //fungsi hapus data 
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->nim==nim)
        {
            if(temp==head)
            {
                head=temp->next;
                return 1;
            }
        }
        else
        {
            prev=temp;
            temp=temp->next;
        }
    }
    return 0;
}

void tampil_senarai() //fungsi tampil data
{

    struct node *temp;
    temp=head;
    if(temp==NULL)
        cout<<"List Kosong"<<endl;
    else
    {
        int i=1;
        cout<<endl;
        cetak_tengah(1, "DATA BERAT BADAN MAHASISWA MENURUT RUMUS BODY MASS INDEX");
        cout<<"\n---------------------------------------------------------------------------";
        gotoxy(2,4);cout<<"No.";
        gotoxy(7,4);cout<<"NIM";
        gotoxy(11,4);cout<<"NAMA";
        gotoxy(25,4);cout<<"UMUR";
        gotoxy(31,4);cout<<"TB"<<endl;
        gotoxy(35,4);cout<<"BB"<<endl;
        gotoxy(38,4);cout<<"BMI"<<endl;
        gotoxy(42,4);cout<<"KETERANGAN"<<endl;
        cout<<"----------------------------------------------------------------------------"<<endl;
        while(temp!=NULL)
        {
            gotoxy(2, i+5);cout<<i;
            gotoxy(7, i+5);cout<<temp->nim;
            gotoxy(11, i+5);cout<<temp->nama;
            gotoxy(25, i+5);cout<<temp->umur;
            gotoxy(31, i+5);cout<<temp->tinggi;
            gotoxy(35, i+5);cout<<temp->berat;
            //menghitung BMI
            int bmi=temp->berat/((temp->tinggi/100)*(temp->tinggi/100));
            gotoxy(38,i+5);cout<<bmi;
            //memberi keterangan
            char *ket;
            if(bmi <= 18)
                ket="BERAT BADAN KURANG";
            else if(bmi > 18 && bmi<=24)
                ket="BERAT BADAN IDEAL";
            else if(bmi > 30)
                ket="OBESITAS";
            gotoxy(42, i+5);cout<<ket;
            temp=temp->next;
            i++;
        }
        cout<<"\n\n-------------------------------------------------------------------------"<<endl;
        cout<<"KETERANGAN: "<<endl;
        cout<<"-BMI < 18 = BERAT BADAN KURANG"<<endl;
        cout<<"-BMI 18-24= BERAT BADAN IDEAL"<<endl;
        cout<<"-BMI > 30 = OBESITAS"<<endl;
    }
}
void EditData(int nmr)
{
    bool cari=false;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->nim==nmr)
        {
            system("cls");
            cari=true;
            cout<<"EDIT DATA BERIKUT INI"<<endl;
            cout<<"NIM   : "<<temp->nim<<" "<<endl;
            cout<<"NAMA   : "<<temp->nama<<" "<<endl;
            cout<<"UMUR   : "<<temp->umur<<" "<<endl;
            cout<<"TINGGI   : "<<temp->tinggi<<" "<<endl;
            cout<<"BERAT   : "<<temp->berat<<" "<<endl<<endl;
            cout<<"PROSES EDIT DATA"<<endl;
            cout<<"NIM   : ";
            cin >>temp->nim;
            cout<<"NAMA   : ";
            cin >>temp->nama;
            cout<<"UMUR   : ";
            cin >>temp->umur;
            cout<<"TINGGI   : ";
            cin >>temp->tinggi;
            cout<<"BERAT   : ";
            cin >>temp->berat;
            cout<<"DATA BERHASIL DIEDIT.\nTEKAN ENTER UNTUK MELANJUTKAN";
            getch();
        }
    temp=temp->next;
    }
    if(cari==false)
    {
        system("cls");
        cout<<"MAAF DATA DENGAN NIM "<<nmr<<" TIDAK DITEMUKAN\nTEKAN ENTER UNTUK MELANJUTKAN"<<endl;
        getch();
    }
}

int main()
{
    int nmr;
    head=NULL;
    node** kepala = &head;
    do
    {
        system("cls");
        sortList(kepala);
        tampil_senarai();
        cout<<"---------------------------------------------------------------------------"<<endl;
        cout<<"Menu Pilihan"<<endl;
        cout<<"1. Input Data"<<endl;
        cout<<"2. Cari Data"<<endl;
        cout<<"3. Hapus Data"<<endl;
        cout<<"4. Edit Data"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Pilihan: ";
        cin >>pilih;
        switch(pilih)
        {
            case 1: cout<<"Masukkan NIM: ";
            		cin>>nmr;
					tambah(nmr);
                    break;
            case 2: cout<<"Masukkan NIM: ";
                    cin >>nmr;
                    CariData(nmr);
                    break;
            case 3: cout<<"Input NIM: ";
                    cin >>nmr;
                    if(hapus(nmr))
                    {
                        system("cls");
                        cout<<"DATA BERHASIL DIHAPUS.\nTEKAN ENTER UNTUK MELANJUTKAN PROSES";
                        getch();
                    }
                    else
                    {
                        system("cls");
                        cout<<"DATA GAGAL DIHAPUS.\nTEKAN ENTER UNTUK MELANJUTKAN PROSES";
                        getch();
                    }
                    break;
            case 4: cout<<"Input NIM: ";
                    cin >>nmr;
                    EditData(nmr);
                    break;
        default:
            cout<<"Pilihan yang anda masukkan salah, \ntekan enter untuk melanjutkan";
        }
    }
    while(pilih!=5);
}
