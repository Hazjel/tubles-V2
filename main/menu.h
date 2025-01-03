#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include "relasi.h"
#include "barang.h"
#include "toko.h"

using namespace std;

int menu();
void inputData(listBarang &Lb, listToko &Lt);
infoBarang inputBarang();
infoToko inputToko();
void deleteParent(listToko &Lt, list_r &L);
void deleteChild(list_r &L);
void connectData(listBarang Lb, listToko Lt, list_r &L);
void searchBarang(listBarang Lb);
void searchToko(listToko Lt);
void sumBarangFromToko(list_r L);
void printBarangFromToko(list_r L);
void printRelasi(list_r L, listToko Lt);

#endif // MENU_H_INCLUDED

