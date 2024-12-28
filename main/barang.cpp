#include <iostream>
#include "barang.h"
using namespace std;

void createListBarang(listBarang &Lb) {
    firstB(Lb) = NULL;
}

adrBarang createElemenBarang(infoBarang X) {
    adrBarang p = new elmListBarang;
    infoB(p).namaBarang = X.namaBarang;
    infoB(p).IDbarang = X.IDbarang;
    infoB(p).deskripsi = X.deskripsi;
    infoB(p).harga = X.harga;
    infoB(p).jumlah = X.jumlah;
    infoB(p).stok = X.stok;

    return p;
}

void insertFirstBarang(listBarang &Lb, adrBarang P) {
    if (firstB(Lb) == NULL) {
        firstB(Lb) = P;
    } else {
        nextB(P) = firstB(Lb);
        firstB(Lb) = P;
    }
}

void insertLastBarang(listBarang &Lb, adrBarang P) {
    if (firstB(Lb) == NULL) {
        firstB(Lb) = P;
    } else {
        adrBarang Q = firstB(Lb);
        while (nextB(Q) != NULL) {
            Q = nextB(Q);
        }
        nextB(Q) = P;
    }
}

adrBarang findBarang(listBarang Lb, string x) {
    adrBarang p = firstB(Lb);
    while (nextB(p) != NULL && infoB(p).namaBarang != x) {
        p = nextB(p);
    }
    if (infoB(p).namaBarang == x) {
        return p;
    } else {
        return NULL;
    }
}

void printInfobarang(listBarang Lb, string x) {
    adrBarang p = findBarang(Lb, x);

    if (p != NULL) {
        cout << infoB(p).IDbarang << endl;
        cout << infoB(p).namaBarang << endl;
        cout << infoB(p).deskripsi << endl;
        cout << infoB(p).harga << endl;
        cout << infoB(p).stok << endl;
        cout << infoB(p).jumlah << endl;
    } else {
        cout << "Barang tidak tersedia" << endl;
    }
    cout << endl;
}

void printListBarang(listBarang Lb) {
    adrBarang P = firstB(Lb);
    int i = 1;
    if (firstB(Lb) != NULL) {
        while (P != NULL) {
            if (i < 10) {
                cout << i << ". Nama: " << infoB(P).namaBarang << endl;
            } else {
                cout << i << ".Nama: " << infoB(P).namaBarang << endl;
            }
            i++;
            P = nextB(P);
        }
    } else {
        cout << "kosong" << endl;
    }
    cout << endl;
}
void deleteBarang(listBarang &Lb, string x) {
    adrBarang P = firstB(Lb);

    if (nextB(firstB(Lb)) == NULL) {
        firstB(Lb) = NULL;
    } else if (infoB(P).namaBarang == x) {
        firstB(Lb) = nextB(firstB(Lb));
        nextB(P) = NULL;
    } else {
        adrBarang Q = NULL;

        while (P != NULL && infoB(nextB(P)).namaBarang == x) {
            P = nextB(P);
        }
        Q = P;
        nextB(P) = nextB(Q);
        nextB(Q) = NULL;
        if (P == NULL){
            cout << "Barang tidak ada" << endl;
    }
}
}

