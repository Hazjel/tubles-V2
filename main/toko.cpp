#include <iostream>
#include"toko.h"
using namespace std;

void createListToko(listToko &Lt) {
    firstT(Lt) = NULL;
    lastT(Lt) = NULL;
}

adrToko createElemenToko(infoToko X) {
    adrToko p = new elmListToko;
    infoT(p).IDtoko = X.IDtoko;
    infoT(p).namaToko = X.namaToko;
    infoT(p).alamat = X.alamat;
    infoT(p).kontak = X.kontak;

    return p;
}

bool isListTokoEmpty(listToko Lt) {
    return firstT(Lt) == NULL;
}

void insertFirstToko(listToko &Lt, adrToko P) {
    if (firstT(Lt) == NULL) {
        firstT(Lt) = P;
        lastT(Lt) = P;
    } else {
        nextT(P) = firstT(Lt);
        prevT(firstT(Lt)) = P;
        firstT(Lt) = P;
    }
}

void insertLastToko(listToko &Lt, adrToko P) {
    if (firstT(Lt) == NULL) {
        firstT(Lt) = P;
        lastT(Lt) = P;
    } else if (firstT(Lt) == lastT(Lt)) {
        nextT(firstT(Lt)) = P;
        prevT(P) = lastT(Lt);
        lastT(Lt) = P;
    } else {
        nextT(lastT(Lt)) = P;
        prevT(P) = lastT(Lt);
        lastT(Lt) = P;
    }
}

adrToko findToko(listToko Lt, string x) {
    adrToko p = firstT(Lt);
    while (next(p) != NULL && infoT(p).namaToko != x) {
        p = nextT(p);
    }
    if (infoT(p).namaToko == x) {
        return p;
    } else {
        return NULL;
    }
}

void printInfoToko(listToko Lt, string x) {
    adrToko p;
    p = findToko(Lt, x);
    if (p != NULL) {
        cout << "Info Toko :" << endl;
        cout << "Nama Toko : " << infoT(p).namaToko << endl;
        cout << "ID Toko   : " << infoT(p).IDtoko << endl;
        cout << "Alamat    : " << infoT(p).alamat << endl;
        cout << "Kontak    : " << infoT(p).kontak << endl;
    } else {
        cout << "Toko Tidak Ditemukan" << endl;
    }
}

void printListToko(listToko Lt) {
    int i = 1;
    adrToko p = firstT(Lt);
    
    if (firstT(Lt) == NULL) {
        cout << "List Toko Kosong" << endl;
    } else {
        cout << "List Toko :" << endl;
        while (p != NULL) {
            cout << i << ". " << infoT(p).namaToko << endl;
            p = nextT(p);
            i++;
        }
    }
}

void deleteToko(listToko &Lt, string x) {
    adrToko p;
    p = findToko(Lt, x);
    if (p == NULL) {
        cout << "Toko Tidak Ditemukan" << endl;
    } else {
        if (p == firstT(Lt) && p == lastT(Lt)) {
            firstT(Lt) == NULL;
            lastT(Lt) == NULL;
        } else if (p == firstT(Lt)) {
            firstT(Lt) = nextT(p);
            prevT(firstT(Lt)) = NULL;
            nextT(p) = NULL;
        } else if (p == lastT(Lt)) {
            lastT(Lt) = prevT(p);
            prevT(p) = NULL;
            nextT(p) = NULL;
        } else {
            nextT(prevT(p)) = nextT(p);
            prevT(nextT(p)) = prevT(p);
            prevT(p) = NULL;
            nextT(p) = NULL;
        }
    }
}
