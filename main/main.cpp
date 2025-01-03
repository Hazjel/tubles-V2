#include "relasi.h"
#include "barang.h"
#include "toko.h"
#include "menu.h"

int main() {
    listToko Lt;
    createListToko(Lt);
    adrToko p;
    infoToko Toko;
    int nomor;
    string x;

    listBarang Lb;
    createListBarang(Lb);
    adrBarang q;
    infoBarang Barang;

    list_r Lr;
    createList(Lr);

    Toko.IDtoko = "1";
    Toko.namaToko = "SumberJaya";
    Toko.alamat = "Jl.Sukajadi";
    Toko.kontak = "103921";
    p = createElemenToko(Toko);
    insertFirstToko(Lt, p);

    Toko.IDtoko = "2";
    Toko.namaToko = "SumberMakmur";
    Toko.alamat = "Jl.Hamjel";
    Toko.kontak = "109843";
    p = createElemenToko(Toko);
    insertFirstToko(Lt, p);

    Toko.IDtoko = "3";
    Toko.namaToko = "SumberAdil";
    Toko.alamat = "Jl.Mimkel";
    Toko.kontak = "107856";
    p = createElemenToko(Toko);
    insertFirstToko(Lt, p);

    Barang.IDbarang = "01";
    Barang.namaBarang = "HelloPandi";
    Barang.deskripsi = "Cemilan";
    Barang.harga = "10500";
    q = createElemenBarang(Barang);
    insertFirstBarang(Lb, q);

    Barang.IDbarang = "02";
    Barang.namaBarang = "BoarBrand";
    Barang.deskripsi = "Susu";
    Barang.harga = "13000";
    q = createElemenBarang(Barang);
    insertFirstBarang(Lb, q);

    Barang.IDbarang = "03";
    Barang.namaBarang = "KapalKaram";
    Barang.deskripsi = "Kopi";
    Barang.harga = "5500";
    q = createElemenBarang(Barang);
    insertFirstBarang(Lb, q);

    Barang.IDbarang = "04";
    Barang.namaBarang = "AquYa";
    Barang.deskripsi = "Air";
    Barang.harga = "3000";
    q = createElemenBarang(Barang);
    insertFirstBarang(Lb, q);

    Barang.IDbarang = "05";
    Barang.namaBarang = "Moonlight";
    Barang.deskripsi = "Sabun";
    Barang.harga = "8500";
    q = createElemenBarang(Barang);
    insertFirstBarang(Lb, q);

    Barang.IDbarang = "06";
    Barang.namaBarang = "KecapSoang";
    Barang.deskripsi = "Kecap";
    Barang.harga = "7500";
    q = createElemenBarang(Barang);
    insertFirstBarang(Lb, q);

    Barang.IDbarang = "07";
    Barang.namaBarang = "Jandomie";
    Barang.deskripsi = "Mie";
    Barang.harga = "3500";
    q = createElemenBarang(Barang);
    insertFirstBarang(Lb, q);

    Barang.IDbarang = "08";
    Barang.namaBarang = "Deadbuoy";
    Barang.deskripsi = "Sabun";
    Barang.harga = "20500";
    q = createElemenBarang(Barang);
    insertFirstBarang(Lb, q);

    Barang.IDbarang = "09";
    Barang.namaBarang = "Popsodent";
    Barang.deskripsi = "PastaGigi";
    Barang.harga = "8000";
    q = createElemenBarang(Barang);
    insertFirstBarang(Lb, q);

    Barang.IDbarang = "10";
    Barang.namaBarang = "Komodo";
    Barang.deskripsi = "Sabun";
    Barang.harga = "12000";
    q = createElemenBarang(Barang);
    insertFirstBarang(Lb, q);

    do {
        menu();
        cout << "Masukkan nomor menu: ";
        cin >> nomor;
        switch (nomor) {
            case 1:
                inputData(Lb, Lt);
                break;
            case 2:
                printListToko(Lt);
                break;
            case 3:
                deleteParent(Lt, Lr);
                break;
            case 4:
                searchToko(Lt);
                break;
            case 5:
                searchBarang(Lb);
                break;
            case 6:
                connectData(Lb, Lt, Lr);
                break;
            case 7:
               printRelasi(Lr, Lt);
                break;
            case 8:
                printBarangFromToko(Lr, x);
                break;
            case 9:
                deleteChild(Lr);
                break;
            case 10:
                cout << "Masukkan nama toko yang ingin dihitung : ";
                cin >> x;
                sumBarangFromToko(Lr);
                break;
            case 0:
                cout << "Terima kasih" << endl;
                break;
        }
    } while (nomor != 0);
}
