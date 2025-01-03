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

void sumBarangFromToko(list_r L) {
    string x;
    cout << "Masukkan nama toko yang ingin dihitung : ";
    cin >> x;
    adrBarang B;
    adr_r P = first(L);
    int sum = 0;
    while (P != NULL) {
        if (infoT(toko(P)).namaToko == x) {
            B = P->barang;
            sum++;
        }
        P = next(P);
    }
    cout << "Jumlah barang pada toko " << x << " adalah " << sum << endl;
}

void printBarangFromToko(list_r L, string nama) {
    cout << "Nama barang: ";
    cin >> nama;
    adr_r P = first(L);
    if (P != NULL) {
        while (P != NULL) {
            if (infoB(barang(P)).namaBarang == nama) {
                cout << "Nama Toko: " << infoT(toko(P)).namaToko << endl;
            }
            P = next(P);
        }
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}

void deleteParent(listToko &Lt, list_r &L) {
    string namaToko;
    cout << "Nama Toko yang ingin dihapus: ";
    cin >> namaToko;
    adrToko P = findToko(Lt, namaToko);
    adr_r Q, K;
    Q = first(L);
    while (Q != first(L)) {
        if (toko(Q) == P) {
            deleteElm(L, K);
        } 
        Q = next(Q);
    }
}

void deleteChild(list_r &L) {
    string namaBarang, namaToko;
    cout << "Nama Toko: ";
    cin >> namaToko;
    printBarangFromToko(L, namaToko);
    cout << "Nama Barang yang mau dihapus: ";
    cin >> namaBarang;
    adr_r P = findElmByInfo(L, namaToko, namaBarang);
    if (P != NULL) {
        deleteElm(L, P);
        cout << "Data berhasil dihapus" << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}
