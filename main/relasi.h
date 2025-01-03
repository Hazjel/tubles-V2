#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "toko.h"
#include "barang.h"
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define prev(P) P->prev
#define toko(P) P->toko
#define barang(P) P->barang

typedef struct elm_r *adr_r;

struct elm_r {
    adrToko toko;
    adrBarang barang;
    adr_r next;
    adr_r prev;
};

struct list_r {
    adr_r first;
};

void createList(list_r &L);
adr_r allocate(adrBarang B, adrToko T);
void insertFirst(list_r &L, adr_r p);
void deleteElm(list_r &L, adr_r &p);
adr_r findElm(list_r L, adrBarang B, adrToko T);
adr_r findElmByInfo(list_r L, string T, string B);
void connect(list_r &L, listBarang lb, listToko lt, string B, string T);
void printRelasi(list_r L, listToko Lt);

#endif // RELASI_H_INCLUDED
