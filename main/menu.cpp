#include "toko.h"
#include "barang.h"
#include "relasi.h"

int menu() {
    cout << "Menu" << endl;
    cout << "1.  Input Data Toko" << endl;
    cout << "2.  Input Data Barang" << endl;
    cout << "3.  Tampilkan Semua Data toko" << endl;
    cout << "4.  Hapus Data Toko" << endl;
    cout << "5.  Cari Data Toko" << endl;
    cout << "6.  Cari Data Barang" << endl;
    cout << "7.  Hubungkan Data Toko dan Data Barang" << endl;
    cout << "8.  Tampilkan Semua Toko dan Barang" << endl;
    cout << "9.  Cari Barang pada Toko" << endl;
    cout << "10. Hapus Data Barang dari Toko" << endl;
    cout << "11. Hitung Barang dari Toko" << endl; 
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

    X = inputBarang();
    P = createElemenBarang(X);

    if (isListBarangEmpty(Lb)) {
        insertFirstBarang(Lb, P);
    } else {
        insertLastBarang(Lb, P);
    }

    Y = inputToko();
    Q = createElemenToko(Y);

    if (isListTokoEmpty(Lt)) {
        insertFirstToko(Lt, Q); 
    } else {
        insertLastToko(Lt, Q); 
    }
}
