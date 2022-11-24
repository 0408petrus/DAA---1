#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//struktur data yang dipakai
struct data_statis {
    string nama{};              //nama barang
    unsigned int id{};          //id barang
    unsigned int stok{};        //stok barang yang tersisa
    unsigned long int harga{};  //harga barang
    string satuan{};            //unit satuan barang
};

struct data_dinamis {
    string nama{};              //nama barang
    unsigned int id{};          //id barang
    unsigned int stok{};        //stok barang yang tersisa
    unsigned long int harga{};  //harga barang
    string satuan{};            //unit satuan barang

    data_dinamis* ptr{};        //pointer yang menunjuk ke struct berikutnya
};

//deklarasi global di sini



//fungsi-fungsi di sini
//fungsi ini buat struct data_dinamis kosong habis itu dikembalikan alamat structnya
data_dinamis* newNode() {
    data_dinamis* data = new data_dinamis;
    return data;
}

//buat copy dari elemen linked list yang dipass alamatnya
data_dinamis* createNodeCopy(data_dinamis* source) {
    data_dinamis* copy = new data_dinamis;

    //isi dari copy sama dengan data yang dicopy
    copy->harga = source->harga;
    copy->id = source->id;
    copy->nama = source->nama;
    copy->satuan = source->satuan;
    copy->stok = source->stok;
    //ptr tidak dicopy karena tidak boleh menunjuk ke alamat linked list asal
    copy->ptr = nullptr;

    //mengembalikan alamat copy
    return copy;
}

//buat copy linked list, yg dipass alamat kepala linked list
data_dinamis* createLinkedListCopy(data_dinamis* head) {
    //copy terakhir itu copy dari kepala
    data_dinamis* lastcopy = createNodeCopy(head);
    //data yg dicopy selanjutnya itu ditunjuk kepala
    data_dinamis* nextcopy = head->ptr;
    //kepala dari copy linked list itu copy kepala
    data_dinamis* origin = lastcopy;

    //selagi ada elemen dalam linked list
    while (nextcopy != nullptr) {
        //buat copy baru dari elemen selanjutnya
        data_dinamis* newcopy = createNodeCopy(nextcopy);
        //elemen sebelumnya menunjuk ke elemen baru
        lastcopy->ptr = newcopy;
        //elemen yang akan dicopy adalah elemen berikutnya
        nextcopy = nextcopy->ptr;
        //copy terakhir adalah hasil copy yang baru ini
        lastcopy = newcopy;
    }

    return origin;
}

//traverse the list until reaching the tail
data_dinamis* traversetoTail(data_dinamis* head) {
    //while node isn't the tail, keep traversing the list
    data_dinamis* current = head;
    while (current->ptr != nullptr) {
        current = current->ptr;
    }
    return current;
}

//count the number of nodes inside the list
int getlistLength(data_dinamis** head) {
    int count{ 0 };
    if (*head == nullptr) {
        return count;
    }
    //while node isn't the tail, keep traversing the list
    data_dinamis* data_todisplay = *head;
    while (data_todisplay != nullptr) {
        //iterate count by one, and move it forward
        count++;
        data_todisplay = (*data_todisplay).ptr;
    }

    return count;
}

//Input data dinamis
void inputDinamis(data_dinamis** head) {
    //if the list is empty, create a head
    if (*head == nullptr) {
        *head = newNode();
        cin.ignore();
        cout << "Nama barang  : "; getline(cin, (**head).nama);
        cout << "ID barang    : "; cin >> (**head).id;
        cout << "Stok barang  : "; cin >> (**head).stok;
        cout << "Harga barang : "; cin >> (**head).harga;
        cout << "Unit satuan  : "; cin >> (**head).satuan;
    }
    //if not, then traverse the list until the head and append a new node
    else {
        data_dinamis* current{};
        //traverse the list to its tail, append a new struct to the list and move the current pointer forward
        current = traversetoTail(*head);
        current->ptr = newNode();
        current = current->ptr;

        cin.ignore();
        cout << "Nama barang  : "; getline(cin, (*current).nama);
        cout << "ID barang    : "; cin >> (*current).id;
        cout << "Stok barang  : "; cin >> (*current).stok;
        cout << "Harga barang : "; cin >> (*current).harga;
        cout << "Unit satuan  : "; cin >> (*current).satuan;
        (*current).ptr = nullptr;
    }
}

//display node contents
void displayNode(data_dinamis node) {
    cout << "Nama barang  : " << node.nama << '\n'
        << "ID barang    : " << node.id << '\n'
        << "Stok barang  : " << node.stok << '\n'
        << "Harga barang : " << node.harga << '\n'
        << "Unit satuan  : " << node.satuan << "\n\n";
}


//update linked list
void updateList(data_dinamis** head) {
    if (*head == nullptr) {
        cout << "Tidak ada data yang terdeteksi dalam linked list! ";
    }
    else {
        cout << "Barang keberapa yang akan diupdate? ";
        int index{};
        cin >> index;

        if (index > getlistLength(head) || index < 1) {
            cout << "Index tidak terdapat dalam linked list! ";
            return;
        }

        int i{ 0 };
        data_dinamis* data_toupdate = *head;
        while (data_toupdate != nullptr) {
            i++;
            if (i == index) {
                cin.ignore();
                cout << "Nama barang  : "; getline(cin, (*data_toupdate).nama);
                cout << "ID barang    : "; cin >> (*data_toupdate).id;
                cout << "Stok barang  : "; cin >> (*data_toupdate).stok;
                cout << "Harga barang : "; cin >> (*data_toupdate).harga;
                cout << "Unit satuan  : "; cin >> (*data_toupdate).satuan;
                return;
            }
            data_toupdate = (*data_toupdate).ptr;
        }
    }

}

//menghapus node
void deleteNode(data_dinamis** head) {
    //if linked list is empty
    if (*head == nullptr) {
        cout << "Tidak ada data yang terdeteksi dalam linked list! ";
    }
    //if not then
    else {
        cout << "Barang keberapa yang akan dihapus? ";
        int index{};
        cin >> index;
        //check if index is within linked list range
        if (index > getlistLength(head) || index < 1) {
            cout << "Index tidak terdapat dalam linked list! ";
            return;
        }

        int i{ 0 };
        data_dinamis* data_todelete = *head;
        //if the data to be deleted is the head, delete it and make the next node the head
        if (index == 1) {
            *head = data_todelete->ptr;
            delete data_todelete;
            return;
        }
        //traverse the list until the node before the index
        while (data_todelete != nullptr) {
            i++;
            if (i == (index - 1)) {
                //determine the data to delete, previous data and upcoming data
                data_dinamis* data_prev = data_todelete;
                data_todelete = (*data_prev).ptr;
                data_dinamis* data_next = (*data_todelete).ptr;

                //delete the data and stitch the gap together
                delete data_todelete;
                (*data_prev).ptr = data_next;
                return;
            }
            data_todelete = (*data_todelete).ptr;
        }
    }
}

//mengembalikan alamat node pada index tertentu
data_dinamis* getNodeatIndex(data_dinamis** head, int index) {
    int i{ 0 };
    data_dinamis* current = *head;
    while (current != nullptr) {
        if (i == index) {
            return current;
        }
        i++;
        current = (*current).ptr;
    }
    return nullptr;
}

void copypasteNode(data_dinamis* copy, data_dinamis* paste) {
    (*paste).nama = (*copy).nama;
    (*paste).id = (*copy).id;
    (*paste).stok = (*copy).stok;
    (*paste).harga = (*copy).harga;
    (*paste).satuan = (*copy).satuan;
}

//swap node
void swapNode(data_dinamis* m, data_dinamis* n) {
    data_dinamis* temp = createNodeCopy(m);
    copypasteNode(n, m);
    copypasteNode(temp, n);

    delete temp;
}

//sorting linked list
void sortList(data_dinamis** head) {
    //selection sort by price
    for (int i = 0; i < (getlistLength(head) - 1); i++) {
        int max = i;
        for (int j = i + 1; j < (getlistLength(head)); j++) {
            if ((*getNodeatIndex(head, j)).harga > (*getNodeatIndex(head, max)).harga) {
                max = j;
            }
        }
        if (max != i) {
            swapNode(getNodeatIndex(head, i), getNodeatIndex(head, max));
        }
    }
}


//display linked list content
void displayList(data_dinamis** head) {
	sortList(head);
    //if list is empty
    if (*head == nullptr) {
        cout << "Tidak ada data yang tersedia! ";
    }
    //if not
    else {
        //start from head
        data_dinamis* data_todisplay = *head;
        int i{ 0 };
        while (data_todisplay != nullptr) {
            //iterate count by one, display current data and move it forward
            cout << "Data #" << ++i << '\n';
            displayNode(*data_todisplay);
            data_todisplay = (*data_todisplay).ptr;
        }
    }
}

/*============FUNGSI STATIS==============*/

//bubble sort statis
void sort_statis(data_statis sort[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (sort[j].harga > sort[j + 1].harga)
            {
                data_statis temp;

                temp.nama = sort[j + 1].nama;
                temp.id = sort[j + 1].id;
                temp.stok = sort[j + 1].stok;
                temp.harga = sort[j + 1].harga;
                temp.satuan = sort[j + 1].satuan;

                sort[j + 1].nama = sort[j].nama;
                sort[j + 1].id = sort[j].id;
                sort[j + 1].stok = sort[j].stok;
                sort[j + 1].harga = sort[j].harga;
                sort[j + 1].satuan = sort[j].satuan;

                sort[j].nama = temp.nama;
                sort[j].id = temp.id;
                sort[j].stok = temp.stok;
                sort[j].harga = temp.harga;
                sort[j].satuan = temp.satuan;
            }
        }
    }
}

//data statis
void statis() {
    int opsiStatis, a, n, jumlah = 0, data = 1;
    bool input{};
    data_statis barang[20];

    while (true) {
        system("cls");
        cout << "Menu Data Statis :";
        cout << "\n1. Input Data";
        cout << "\n2. Tampilkan Data";
        cout << "\n3. Update Data";
        cout << "\n4. Delete Data";
        cout << "\n5. Back\n>> ";
        cin >> opsiStatis;

        switch (opsiStatis) {
        case 1: {
            cout << "\nMasukkan jumlah data yang akan di-input : "; cin >> a;
            if (jumlah + a > 20) {
                cout << "Maksimum data sebanyak 20!\n";
                system("pause");
                break;
            }
            else {
                jumlah += a;
            }

            if (input == true) {
                for (int i = data; i < jumlah; i++)
                {
                    cin.ignore();
                    cout << "\nBARANG " << i + 1;
                    cout << "\nNama barang : "; getline(cin, barang[i].nama);
                    cout << "ID barang : "; cin >> barang[i].id;
                    cout << "Stok barang : "; cin >> barang[i].stok;
                    cout << "Harga barang : "; cin >> barang[i].harga;
                    cout << "Unit satuan : "; cin >> barang[i].satuan;
                    data += 1;
                }
            }

            else {
                for (int i = 0; i < jumlah; i++)
                {
                    cin.ignore();
                    cout << "\nBARANG " << i + 1;
                    cout << "\nNama barang : "; getline(cin, barang[i].nama);
                    cout << "ID barang : "; cin >> barang[i].id;
                    cout << "Stok barang : "; cin >> barang[i].stok;
                    cout << "Harga barang : "; cin >> barang[i].harga;
                    cout << "Unit satuan : "; cin >> barang[i].satuan;
                    if (i > 0) {
                        data += 1;
                    }
                }
                input = true;
            }
            system("pause");
            break;
        }

        case 2: {
            sort_statis(barang, jumlah);
            for (int i = 0; i < jumlah; i++)
            {
                cout << "\nBARANG " << i + 1;
                cout << "\nNama barang : " << barang[i].nama;
                cout << "\nID barang : " << barang[i].id;
                cout << "\nStok barang : " << barang[i].stok;
                cout << "\nHarga barang : " << barang[i].harga;
                cout << "\nUnit satuan : " << barang[i].satuan;
                cout << endl;
            }
            system("pause");
            break;
        }

        case 3: {
            cout << "\nPilih data keberapa yang akan di-update : "; cin >> n;
            cin.ignore();
            cout << "\nUPDATE BARANG " << n;
            cout << "\nNama barang : "; getline(cin, barang[n - 1].nama);
            cout << "ID barang : "; cin >> barang[n - 1].id;
            cout << "Stok barang : "; cin >> barang[n - 1].stok;
            cout << "Harga barang : "; cin >> barang[n - 1].harga;
            cout << "Unit satuan : "; cin >> barang[n - 1].satuan;
            system("pause");
            break;
        }

        case 4: {
            cout << "\nPilih data keberapa yang akan di-delete : "; cin >> n;
            for (int i = n - 1; i < jumlah; i++)
            {
                barang[i] = barang[i + 1];
            }
            data -= 1;
            jumlah -= 1;
            system("pause");
            break;
        }

        case 5: {
            goto restart_static;
            break;
        }

        default: {
            cout << "Opsi tidak ada! ";
            system("pause");
            break;
        }
        }
    }
restart_static:
    system("cls");
}

//data dinamis
void dinamis() {
    data_dinamis* head = nullptr;
    bool flag = true;

    while (flag) {
        system("cls");
        cout << "Panjang linked list sekarang: " << getlistLength(&head) << '\n'
            << "1. Input data\n"
            << "2. Tampilkan data\n"
            << "3. Update data\n"
            << "4. Delete data\n"
            << "5. Back\n"
            << ">> ";
        int select{};
        cin >> select;

        switch (select) {
        case 1: {
            cout << "Berapa banyak data yang ingin dimasukkan? "; int data_count{}; cin >> data_count;
            for (int i = 0; i < data_count; i++) {
                cout << "\nData #" << i + 1 << endl;
                inputDinamis(&head);
                cout << "\n\n";
            }
            break;
        }

        case 2: {
            displayList(&head);
            break;
        }

        case 3: {
        	displayList(&head);
            updateList(&head);
            break;
        }

        case 4: {
        	displayList(&head);
            deleteNode(&head);
            break;
        }

        case 5: {
            flag = false;
            break;
        }

        default: {
            cout << "Opsi tidak ada! ";
            break;
        }

        }
        system("pause");
    }
}

int main()
{
    while (true) {
        cout << "Selamat datang di Microhard Binbows Excelsior!\n"
            << "1. Data Statis\n"
            << "2. Data Dinamis\n"
            << "3. Exit\n>> ";
        int x;
        cin >> x;

        switch (x) {
        case 1: {
            statis();
            break;
        }

        case 2: {
            dinamis();
            break;
        }

        case 3: {
            exit(0);
            break;
        }

        default: {
            cout << "Opsi tidak ada! ";
            system("pause");
            break;
        }
        }
        system("CLS");
    }
}

