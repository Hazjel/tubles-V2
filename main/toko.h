#ifndef TOKO_H_INCLUDED
#define TOKO_H_INCLUDED

#include <iostream>
#define firstT(L) L.firstT
#define lastT(L) L.lastT
#define nextT(P) P->nextT
#define prevT(P) P->prevT
#define infoT(P) P->infoT
using namespace std;

typedef struct toko *adrToko;

struct toko {
    string IDtoko;
    string namaToko;
    string alamat;
    string kontak;

};

typedef toko infoToko;
typedef struct elmListToko *adrToko;

struct elmListToko {
    infoToko infoT;
    adrToko nextT;
    adrToko prevT;
};

struct listToko {
    adrToko firstT;
    adrToko lastT;
};

void createListToko(listToko &Lt);
adrToko createElemenToko(infoToko X);
void insertFirstToko(listToko &Lt, adrToko P);
void insertLastToko(listToko &Lt, adrToko P);
adrToko findToko(listToko Lt, string x);
void printInfoToko(listToko Lt, string x);
void printListToko(listToko Lt);
void deleteToko(listToko &Lt, string x);

#endif // TOKO_H_INCLUDED
