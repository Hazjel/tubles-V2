#include <iostream>
#include "relasi.h"
using namespace std;

void createList(list_r &L) {
    first(L) = NULL;
}

adr_r allocate(adrBarang B, adrToko T) {
    adr_r p = new elm_r;
    barang(p) = B;
    toko(p) = T;
    next(p) = NULL;
    prev(p) = NULL;

    return p;
}

void connect(list_r &L, listBarang Lb, listToko Lt, string B, string T) {
    adrBarang P = findBarang(Lb, B);
    adrToko Q = findToko(Lt, T);

    if (P != NULL && Q != NULL) {
        adr_r R = allocate(P, Q);
        insertFirst(L, R);
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}

void insertFirst(list_r &L, adr_r p) {
    if (first(L) == NULL) {
        first(L) = p;
    } else {
        next(p) = first(L);
        first(L) = p;
    }
}
void deleteElm(list_r &L, adr_r &P) {
    adr_r Q;
    
    if (first(L) == P) {
        if (next(P) == P) {
            first(L) = NULL;
        } else {
            first(L) = next(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
    } else if (P != NULL) {
        Q = first(L);
        while (next(Q) != P) {
            Q = next(Q);
        }
        next(Q) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}
adr_r findElm(list_r L, adrBarang B, adrToko T) {
    adr_r P = first(L);
    if (P != NULL) {
        while (next(P) != NULL && (barang(P) != B || toko(P) != T)) {
            P = next(P);
        }

        if (barang(P) == B && toko(P) == T) {
            return P;
        } 
    }
}

adr_r findElmByInfo(list_r L, string T, string B) {
    adr_r P = first(L);
    int i = 1;
    if (P != NULL) {
        while (P != NULL) {
            if (infoT(toko(P)).namaToko == T && infoB(barang(P)).namaBarang == B) {
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}

void printRelasi(list_r L, listToko Lt) {
    adrToko P = firstT(Lt);
    
    cout << "Print Relasi" << endl;
    while (P != NULL) {
        cout << "Toko: " << infoT(P).namaToko << "->";
        adr_r Q = first(L);
        if (Q != NULL) {
            while (Q != first(L)) {
                if (infoT(toko(Q)).namaToko == infoT(P).namaToko) {
                    cout << infoB(barang(Q)).namaBarang << " ";
                }
                Q = next(Q);
            }
        }
        cout << endl;
        P = nextT(P);
    }
    cout << endl;
}