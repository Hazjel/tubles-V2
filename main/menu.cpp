#include "toko.h"
#include "barang.h"
#include "relasi.h"

int menu() {
    cout << "Menu" << endl;
    cout << "1.  Input Data" << endl;
    cout << "2.  Tampilkan Semua Data toko" << endl;
    cout << "3.  Hapus Data Toko" << endl;
    cout << "4.  Cari Data Toko" << endl;
    cout << "5.  Cari Data Barang" << endl;
    cout << "6.  Hubungkan Data Toko dan Data Barang" << endl;
    cout << "7.  Tampilkan Semua Toko dan Barang" << endl;
    cout << "8.  Cari Barang pada Toko" << endl;
    cout << "9.  Hapus Data Barang dari Toko" << endl;
    cout << "10. Hitung Barang dari Toko" << endl; 
    cout << "0.  Keluar" << endl;
}

infoBarang inputBarang() {
    infoBarang X;
    cout << "ID Barang : ";
    cin >> X.IDbarang;
    cout << "Nama Barang : ";
    cin >> X.namaBarang;
    cout << "Deskripsi : ";
    cin >> X.deskripsi;
    cout << "Harga : ";
    cin >> X.harga;
    cout << "Stok : ";
    cin >> X.stok;
    cout << "Jumlah : ";
    cin >> X.jumlah;

    return X;
}

infoToko inputToko() {
    infoToko X;
    cout << "ID Toko : ";
    cin >> X.IDtoko;
    cout << "Nama Toko : ";
    cin >> X.namaToko;
    cout << "Alamat : ";
    cin >> X.alamat;
    cout << "Kontak : ";
    cin >> X.kontak;

    return X;
}

void inputData(listBarang &Lb, listToko &Lt) {
    infoBarang X;
    infoToko Y;
    adrBarang P;
    adrToko Q;
    string data;

    cout << "Data apa yang ingin dimasukkan? (barang/toko)" << endl;
    cin >> data;

    X = inputBarang();
    P = createElemenBarang(X);
    Y = inputToko();
    Q = createElemenToko(Y);

    if (data == "barang") {
        if (isListBarangEmpty(Lb)) {
            insertFirstBarang(Lb, P);
        } else {
            insertLastBarang(Lb, P);
        }
    } else if (data == "toko") {
        if (isListTokoEmpty(Lt)) {
            insertFirstToko(Lt, Q);
        } else {
            insertLastToko(Lt, Q);
        }
    }
}

void searchToko(listToko Lt) {
    string x;
    cout << "Masukkan nama toko yang ingin dicari : ";
    cin >> x;
    printInfoToko(Lt, x);
}

void searchBarang(listBarang Lb) {
    string x;
    cout << "Masukkan nama barang yang ingin dicari : ";
    cin >> x;
    printInfobarang(Lb, x);
}

void connectData(listBarang Lb, listToko Lt, list_r &L) {
    string B, T;
    cout << "Masukkan nama barang : ";
    cin >> B;
    cout << "Masukkan nama toko : ";
    cin >> T;

    connect(L, Lb, Lt, B, T);
}
