#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;
const int MAKSIMAL= 50;
int jumlah=0;

struct node
{
	char nama_resto [100];
    int  id_resto;
    char lokasi_resto [100];
    char hari_buka [100];
    char jam_buka [100];
    node *next;
};

node *awal_ptr = NULL;
node *posisi;
int option = 0;


void buat()
{
    int banyak, sisa;
    if (jumlah<MAKSIMAL)
    {
        cout << "+=================================+"<<endl;
        cout << "|             Welcome             |"<<endl;
        cout << "+=================================+"<<endl;
        cout << "How many restaurant do you have: ";
        cin >> banyak;
        system ("CLS");
        sisa= MAKSIMAL-jumlah-banyak;
        if (sisa>=banyak)
        {
            for (int i=0; i<banyak;i++)
            {
                node *temp, *temp2;
                temp = new node;
                cout <<"======================================================="<<endl;
                cout << "Restaurant Name\t\t: ";
                cin >> temp -> nama_resto;
                cout << "Restaurant ID\t\t: ";
                cin >> temp -> id_resto;
                cout << "Restaurant Location\t: ";
                cin >> temp -> lokasi_resto;
                cout << "Opening Days Schedule\t: ";
                cin >> temp -> hari_buka;
                cout << "Business Hours\t\t: ";
                cin >> temp -> jam_buka;
                cout <<"======================================================="<<endl;
                cout <<endl;
                jumlah++;
                temp->next = NULL;
                if (awal_ptr == NULL)
                {
                    awal_ptr = temp;
                    posisi = awal_ptr;
                }
                else
                {
                    temp2 = awal_ptr;
                    while (temp2->next != NULL)
                    {
                        temp2 = temp2->next;
                    }
                    temp2->next = temp;
                }
            }
        }
         else
        {
            cout <<"========================================================"<<endl;
            cout <<"         Sorry! The remaining free space is: " <<sisa<<endl;
            cout <<"========================================================"<<endl;
        }
    }
    else
    {
        cout <<"========================================================"<<endl;
        cout <<"      Sorry! Our community database has already full"<<endl;
        cout <<"========================================================"<<endl;
    }

}

void hapus()
{
 	int banyakdata,posisi_hapus,poshapus;
 	node *hapus, *bantu;
 	if(awal_ptr != NULL)
 	{
 		cout<<"Enter your restaurant position number: ";
 		cin>>posisi_hapus;
 		banyakdata=1;
 		bantu=awal_ptr;
 		while(bantu->next != NULL)
 		{
 			bantu=bantu->next;
 			banyakdata++;
 		}
 	if((posisi_hapus<1)||(posisi_hapus>banyakdata))
 	{
 		cout <<"============================================="<<endl;
        cout <<"         Oh no! There is no restaurant"<<endl;
        cout <<"============================================="<<endl;
 	}
 	else
 	{
 		bantu=awal_ptr;
 		poshapus=1;
 		while(poshapus<(posisi_hapus-1))
 		{
 			bantu=bantu->next;
 			poshapus++;
 		}
 		hapus=bantu->next;
 		bantu->next=hapus->next;
 		delete hapus;
 	}
 	system ("CLS");
    cout <<"===================================="<<endl;
    cout <<"      We will miss you so much!"<<endl;
    cout <<"===================================="<<endl;
    jumlah--;
 	}
 	else
    {
        cout <<"============================================="<<endl;
        cout <<"      Oh no! There is no restaurant left"<<endl;
        cout <<"============================================="<<endl;
    }
}
void baca()
{
 	node *temp;
 	temp = awal_ptr;
 	cout << endl;
 	if (temp == NULL)
 	{
 	    cout <<"======================================================================"<<endl;
        cout <<"      OH NO! There are no restaurants that have registered yet"<<endl;
        cout <<"                                BE THE FIRST"<<endl;
        cout <<"======================================================================"<<endl;
 	}
 	else
 	{
        cout << "=========================================================="<<endl;
        cout << "                   All Restaurant Information "<<endl;
        cout << "=========================================================="<<endl<<endl;
		while (temp != NULL)
 		{
 		    cout <<"======================================================="<<endl;
            cout << "Restaurant Name\t\t: "<<temp -> nama_resto<<endl;
            cout << "Restaurant ID\t\t: "<<temp -> id_resto<<endl;
            cout << "Restaurant Location\t: "<<temp -> lokasi_resto<<endl;
            cout << "Opening Days Schedule\t: "<<temp -> hari_buka<<endl;
            cout << "Business Hours\t\t: "<<temp -> jam_buka<<endl;
            cout <<"======================================================="<<endl;
 			cout << endl;
 			temp = temp->next;
 		}
 	}
}

void swapnode(node *left, node *right)
{
    node *temp;
    temp = new node;
    *temp->nama_resto = *left->nama_resto;
    temp -> id_resto = left -> id_resto;
    *temp -> lokasi_resto = *left -> lokasi_resto;
    *temp -> hari_buka = *left -> hari_buka;
    *temp -> jam_buka = *left -> jam_buka;

    *left -> nama_resto = *right -> nama_resto;
    left -> id_resto = right -> id_resto;
    *left -> lokasi_resto = *right -> lokasi_resto;
    *left -> hari_buka = *right -> hari_buka;
    *left -> jam_buka = *right -> jam_buka;

    *right -> nama_resto = *temp -> nama_resto;
    right -> id_resto = temp -> id_resto;
    *right -> lokasi_resto = *temp -> lokasi_resto;
    *right -> hari_buka = *temp -> hari_buka;
    *right -> jam_buka = *temp -> jam_buka;
}

node* carilist(node* awal_ptr, int urutan)
{
    node* temp = awal_ptr;
    for (int i = 0; i < urutan; i++){
        temp = temp->next;
    }
    return temp;
}

void selectionSort(node* awal, int size)
{
    int i, j, imin;
    for (i = 0; i < size - 1; i++) {
        imin = i;   //get index of minimum data
        for (j = i + 1; j < size; j++) {
            if (carilist(awal, j)->id_resto < carilist(awal, imin)->id_resto) {
                imin = j;
            }
        }
        //placing in correct position
        swapnode(carilist(awal, i), carilist(awal, imin));
    }
}


void perbaru(int y){
	bool cari = false;
	node *temp;
	temp = awal_ptr;

	while(temp != NULL)
	{
		if(temp->id_resto==y)
            {
			cari = true;

                cout <<"======================================================="<<endl;
                cout << "Restaurant Name\t\t: ";
                cin >> temp -> nama_resto;
                cout << "Restaurant ID\t\t: ";
                cin >> temp -> id_resto;
                cout << "Restaurant Location\t: ";
                cin >> temp -> lokasi_resto;
                cout << "Opening Days Schedule\t: ";
                cin >> temp -> hari_buka;
                cout << "Business Hours\t\t: ";
                cin >> temp -> jam_buka;
                cout <<"======================================================="<<endl;
                cout <<endl;
                system ("CLS");
                cout <<"============================================="<<endl;
                cout <<"           Data has been updated"<<endl;
                cout <<"============================================="<<endl;

			getch();
		}
		temp = temp->next;
	}
}

struct data_resto{
    char nama_resto [100];
    int  id_resto;
    char lokasi_resto [100];
    char hari_buka [100];
    char jam_buka [100];
};

struct data_resto restoran [MAKSIMAL];

void create()
{
    int banyak, sisa;
    if (jumlah<MAKSIMAL)
    {
        cout << "+=================================+"<<endl;
        cout << "|             Welcome             |"<<endl;
        cout << "+=================================+"<<endl;
        cout << "How many restaurant you have: ";
        cin >> banyak;
        system ("CLS");
        sisa= MAKSIMAL-jumlah-banyak;
        if (sisa>=banyak)
        {
            for (int i=0; i<banyak;i++)
            {
                cout <<"======================================================="<<endl;
                cout << "Restaurant Name\t\t: ";
                cin >> restoran[jumlah].nama_resto;
                cout << "Restaurant ID\t\t: ";
                cin >> restoran[jumlah].id_resto;
                cout << "Restaurant Location\t: ";
                cin >> restoran[jumlah].lokasi_resto;
                cout << "Opening Days Schedule\t: ";
                cin >> restoran[jumlah].hari_buka;
                cout << "Business Hours\t\t: ";
                cin >> restoran[jumlah].jam_buka;
                cout <<"======================================================="<<endl;
                jumlah++;
                cout <<endl<<endl;
            }
        }
        else
        {
            cout <<"========================================================"<<endl;
            cout <<"          Sorry! The remaining free space is: " <<sisa<<endl;
            cout <<"========================================================"<<endl;
        }
    }
    else
    {
        cout <<"========================================================"<<endl;
        cout <<"      Sorry our community database has already full"<<endl;
        cout <<"========================================================"<<endl;
    }
}

void read ()
{
    if (jumlah==0){
        cout <<"======================================================================"<<endl;
        cout <<"      OH NO! There are no restaurants that have registered yet"<<endl;
        cout <<"                              BE THE FIRST"<<endl;
        cout <<"======================================================================"<<endl;
    }
    else
    {
        for (int i=1;i<jumlah;i++)
        {
            for (int j= jumlah-1;j>=i;j--)
            {
                if(restoran[j].id_resto<restoran[j-1].id_resto)
                {
                    swap(restoran[j],restoran[j-1]);
                }
            }
        }
    }
        cout << "=========================================================="<<endl;
        cout << "                   All Restaurant Information "<<endl;
        cout << "=========================================================="<<endl<<endl;
        for (int i=0; i<jumlah;i++)
        {   cout <<"======================================================="<<endl;
            cout <<"Restaurant Name\t\t: "<<restoran[i].nama_resto<<endl;
            cout <<"Restaurant ID\t\t: "<<restoran[i].id_resto<<endl;
            cout <<"Restaurant Location\t: "<<restoran[i].lokasi_resto<<endl;
            cout <<"Opening Days Schedule\t: "<<restoran[i].hari_buka<<endl;
            cout <<"Business Hours\t\t: "<<restoran[i].jam_buka<<endl;
            cout <<"======================================================="<<endl<<endl;
        }
}


void del ()
{
    int pilih;
    cout <<"Enter your restaurant position number: ";
    cin >> pilih;
    if (pilih<jumlah && pilih>0)
    {
        for (int i =pilih; i<jumlah;i++)
        {
            strcpy(restoran[i-1].nama_resto,restoran[i].nama_resto);
            restoran[i-1].id_resto=restoran[i].id_resto;
            strcpy(restoran[i-1].lokasi_resto,restoran[i].lokasi_resto);
            strcpy(restoran[i-1].hari_buka,restoran[i].hari_buka);
            strcpy(restoran[i-1].jam_buka,restoran[i].jam_buka);
        }
        system ("CLS");
        cout <<"===================================="<<endl;
        cout <<"      We will miss you so much!"<<endl;
        cout <<"===================================="<<endl;
        jumlah--;
    }
    else if (pilih==jumlah)
        {jumlah--;}
    else
    {
        cout <<"============================================="<<endl;
        cout <<"        Oh no! There is no restaurant"<<endl;
        cout <<"============================================="<<endl;
    }
}

void update ()
{
    int pilih;
    cout << "Enter your restaurant position number: ";
    cin >> pilih;
    if (pilih<=jumlah && pilih>0)
    {
        cout << "Restaurant Name\t\t: ";
        cin >> restoran[pilih-1].nama_resto;
        cout << "Restaurant ID\t\t: ";
        cin >> restoran[pilih-1].id_resto;
        cout << "Restaurant Location\t: ";
        cin >> restoran[pilih-1].lokasi_resto;
        cout << "Opening Days Schedule\t: ";
        cin >> restoran[pilih-1].hari_buka;
        cout << "Business Hours\t\t: ";
        cin >> restoran[pilih-1].jam_buka;
        system("CLS");
        cout <<"============================================="<<endl;
        cout <<"           Data has been updated"<<endl;
        cout <<"============================================="<<endl;
    }
    else
    {   cout <<"========================================================="<<endl;
        cout <<"       Hmm! We do not have any data for that number"<<endl;
        cout <<"========================================================="<<endl;
    }
}





int main () {
    int pilihan, identify, owner, option, linked;
    iden:
    cout <<"+===========================================+"<<endl;
    cout <<"|      Welcome To Restaurant Community      |"<<endl;
    cout <<"+===========================================+"<<endl;
    cout <<"|        How would we identify you?         |"<<endl;
    cout <<"+===========================================+"<<endl;
    cout <<"|                                           |"<<endl;
    cout <<"| 1. I'm looking for some restaurant        |"<<endl;
    cout <<"| 2. I'm an restaurant owner                |"<<endl;
    cout <<"| 3. Exit                                   |"<<endl;
    cout <<"|                                           |"<<endl;
    cout <<"+===========================================+"<<endl;
    cout << "I am: ";
    cin >> identify;
    system ("CLS");

    switch (identify){
        case 1:
            system ("CLS");
            read();
            system ("pause");
            system ("CLS");
            goto iden;

        case 2:
            opsi:
            cout << "+======================+"<<endl;
            cout << "|  Please choose one!  |"<<endl;
            cout << "+======================+"<<endl;
            cout << "|                      |"<<endl;
            cout << "| 1. Static            |"<<endl;
            cout << "| 2. Dynamic           |"<<endl;
            cout << "| 3. Back              |"<<endl;
            cout << "| 4. Exit              |"<<endl;
            cout << "|                      |"<<endl;
            cout << "+======================+"<<endl;
            cout << "Your Option: ";
            cin >> option;
            system("CLS");

            switch (option){
                case 1:
                    menu:
                    cout <<"+===========================================================+"<<endl;
                    cout <<"|                  Hi Owner, what do you want               |"<<endl;
                    cout <<"+===========================================================+"<<endl;
                    cout <<"|                                                           |"<<endl;
                    cout <<"| 1. I want to add my restaurant to the community           |"<<endl;
                    cout <<"| 2. I'm looking for some restaurant information            |"<<endl;
                    cout <<"| 3. I want to update my restaurant information             |"<<endl;
                    cout <<"| 4. I want to remove my restaurant from the community      |"<<endl;
                    cout <<"| 5. Back                                                   |"<<endl;
                    cout <<"| 6. Exit                                                   |"<<endl;
                    cout <<"|                                                           |"<<endl;
                    cout <<"+===========================================================+"<<endl;
                    cout <<" I want: ";
                    cin >> owner;
                    system ("CLS");

                    switch (owner) {
                        case 1:
                            create ();
                            system ("pause");
                            system ("CLS");
                            goto menu;

                        case 2:
                            read ();
                            system ("pause");
                            system ("CLS");
                            goto menu;

                        case 3:
                            update ();
                            system ("pause");
                            system ("CLS");
                            goto menu;

                        case 4:
                            del ();
                            system ("pause");
                            system ("CLS");
                            goto menu;

                        case 5:
                            system("CLS");
                            goto opsi;
                        case 6:
                            return (0);
                        default:
                            cout <<"======================================="<<endl;
                            cout <<"    We do not know what do you want"<<endl;
                            cout <<"======================================="<<endl;
                            system("pause");
                            system("CLS");
                            goto menu;
                    }
                case 2:
                    menul:
                    cout <<"+===========================================================+"<<endl;
                    cout <<"|                  Hi Owner, what do you want               |"<<endl;
                    cout <<"+===========================================================+"<<endl;
                    cout <<"|                                                           |"<<endl;
                    cout <<"| 1. I want to add my restaurant to the community           |"<<endl;
                    cout <<"| 2. I'm looking for some restaurant information            |"<<endl;
                    cout <<"| 3. I want to update my restaurant information             |"<<endl;
                    cout <<"| 4. I want to remove my restaurant from the community      |"<<endl;
                    cout <<"| 5. Back                                                   |"<<endl;
                    cout <<"| 6. Exit                                                   |"<<endl;
                    cout <<"|                                                           |"<<endl;
                    cout <<"+===========================================================+"<<endl;
                    cout <<" I want: ";
                    cin >> owner;
                    system ("CLS");

                    switch (owner) {
                        case 1:
                            buat ();
                            system ("pause");
                            system ("CLS");
                            goto menul;

                        case 2:
                            selectionSort(awal_ptr, jumlah);
                            baca ();
                            system ("pause");
                            system ("CLS");
                            goto menul;

                        case 3:
                            cout <<"Enter your restaurant position number: ";
                            cin >> linked;
                            perbaru (linked);
                            system ("pause");
                            system ("CLS");
                            goto menul;

                        case 4:
                            hapus ();
                            system ("pause");
                            system ("CLS");
                            goto menul;

                        case 5:
                            system("CLS");
                            goto opsi;
                        case 6:
                            return (0);
                        default:
                            cout <<"======================================="<<endl;
                            cout <<"    We do not know what do you want"<<endl;
                            cout <<"======================================="<<endl;
                            system("pause");
                            system("CLS");
                            goto menul;
                    }
        case 3:
            goto iden;
        case 4:
            return (0);
        default:
            cout <<"============================================"<<endl;
            cout <<"     Please choose the option correctly"<<endl;
            cout <<"============================================"<<endl;
            system("pause");
            system ("CLS");
            goto opsi;
    }
    case 3:
        return (0);
    default:
       cout <<"============================================"<<endl;
       cout <<"     Please identify yourself correctly"<<endl;
       cout <<"============================================"<<endl;
            system("pause");
            system ("CLS");
            goto iden;
}
}

