#ifndef BARANG_H_INCLUDED
#define BARANG_H_INCLUDED

#include <iostream>

using namespace std;

#define firstB(L) L.firstB
#define nextB(L) L->nextB
#define infoB(L) L->infoB

typedef struct barang *adrBarang;

struct barang {
    string IDbarang;
    string namaBarang;
    string deskripsi;
    string harga;
};

struct elmListBarang {
    infoBarang infoB;
    adrBarang nextB;
};

typedef barang infoBarang;
typedef struct elmListBarang *adrBarang;

struct listBarang {
    adrBarang firstB;
};

void createListBarang(listBarang &Lb);
adrBarang createElemenBarang(infoBarang X);
bool isListBarangEmpty(listBarang Lb);
void insertFirstBarang(listBarang &Lb, adrBarang P);
void insertLastBarang(listBarang &Lb, adrBarang P);
adrBarang findBarang(listBarang Lb, string x);
void printInfobarang(listBarang Lb, string x);
void printListBarang(listBarang Lb);
void deleteBarang(listBarang &Lb, string x);

#endif // BARANG_H_INCLUDED
