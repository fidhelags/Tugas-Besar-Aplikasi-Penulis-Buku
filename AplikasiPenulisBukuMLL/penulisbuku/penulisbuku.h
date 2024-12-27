#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED

#include <iostream>
#include <string>
#include <limits>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define infoRP(P) P->infoRP
#define infoRB(P) P->infoRB
#define next(P) P->next
#define prev(P) P->prev

//PARENT (Penulis)
struct dataPenulis {
    string idPenulis;
    string nama;
    string kontak;
    string tanggalLahir;
    int totalBuku;
};

typedef struct dataPenulis infotypePenulis;
typedef struct elmPenulis *adrPenulis;

struct elmPenulis {
    infotypePenulis info;
    adrPenulis next;
    adrPenulis prev;
};

struct listPenulis {
    adrPenulis first;
    adrPenulis last;
};

//CHILD (Buku)
struct dataBuku {
    string idBuku;
    string judul;
    string penerbit;
    int tahunTerbit;
    int jumlahHalaman;
    int totalPenjualan;
};

typedef struct dataBuku infotypeBuku;
typedef struct elmBuku *adrBuku;

struct elmBuku {
    infotypeBuku info;
    adrBuku next;
};

struct listBuku {
    adrBuku first;
};

//RELASI
typedef string infotypeRelasi;
typedef struct elmRelasi *adrRelasi;

struct elmRelasi {
    adrRelasi next;
    adrPenulis infoRP;
    adrBuku infoRB;
};

struct listRelasi {
    adrRelasi first;
};

//default
void createListP(listPenulis &LP);
adrPenulis createElmP(infotypePenulis data);
void createListB(listBuku &LB);
adrBuku createElmB(infotypeBuku data);
void createListR(listRelasi &LR);
adrRelasi createElmR(adrPenulis P, adrBuku B);

/*function and procedure (sesuai ketentuan)*/

//Insert data parent dari depan/belakang
void insertFirstP(listPenulis &LP, adrPenulis P);
void insertLastP(listPenulis &LP, adrPenulis P);
void menuTambahPenulis(listPenulis &LP, listBuku &LB, listRelasi &LR);
void tambahPenulis(listPenulis &LP, listBuku &LB, listRelasi &LR, string opsi);

//Show all data parent
void showAllP(listPenulis &LP, listBuku &LB, listRelasi &LR);

//Menghapus data parent dan childnya
void hapusParentDanChild(listPenulis &LP, listBuku &LB, listRelasi &LR);
int banyakPenulis(listRelasi &LR, adrBuku B);

//Mencari data parent
void menuCariDataPenulis(listPenulis LP, listBuku LB, listRelasi &LR);
void cariDataPenulis(listPenulis LP, listBuku LB, listRelasi &LR, string opsi);
void tampilkanDataPenulis(adrPenulis P);

//Insert data child
void insertChild(listPenulis &LP, listBuku &LB, listRelasi &LR);
void insertLastB(listBuku &LB, adrBuku B);
void connect(listBuku &LB, listRelasi &LR, adrPenulis P, adrBuku B);
void penulisLain(listPenulis &LP, listBuku &LB, listRelasi &LR, adrBuku B);

//Mengubah data parent / data child
void menuUbahData(listPenulis &LP, listBuku &LB, listRelasi &LR);
void ubahData(listPenulis &LP, listBuku &LB, listRelasi &LR, string opsi);
void ubahDataPenulis(listPenulis &LP, listBuku &LB, listRelasi &LR);
void ubahDataBuku(listPenulis &LP, listBuku &LB, listRelasi &LR);

//Menampilkan seluruh data parent beserta childnya
void tampilkanParentDanChild(listPenulis &LP, listBuku &LB, listRelasi &LR);

//Mencari data child pada parent tertentu
void menuCariDataBukuPenulis(listPenulis LP, listBuku LB, listRelasi &LR);
void cariDataBukuPenulis(listPenulis &LP, listBuku &LB, listRelasi &LR, string opsi);
void showPB(listPenulis LP, listBuku LB, listRelasi LR, adrPenulis P);

//Menghapus data child pada parent tertentu
void menuHapusDataBuku(listPenulis &LP, listBuku &LB, listRelasi &LR);
void hapusDataBuku(listPenulis &LP, listBuku &LB, listRelasi &LR, string opsi);
void showPBHapus(listPenulis LP, listBuku LB, listRelasi LR, adrPenulis P);

//Menghitung total penjualan/ banyak buku pada tahun x
void totalPenjualanTahun(listPenulis &LP, listBuku &LB, listRelasi &LR);
bool cekDuplikatR(listRelasi LR, adrRelasi R);

//function and procedure (tambahan)
void exit();
bool konfirmasi();
void menuUtama(listPenulis &LP, listBuku &LB, listRelasi &LR);

//
void deleteFirstRelasi(listRelasi &LR, adrRelasi &R);
void deleteLastRelasi(listRelasi &LR, adrRelasi &R);
void deleteAfterRelasi(listRelasi &LR, adrRelasi prec, adrRelasi &R);
//
void deleteFirstB(listBuku &LB, adrBuku &B);
void deleteLastB(listBuku &LB, adrBuku &B);
void deleteAfterB(listBuku &LB, adrBuku prec, adrBuku &B);

adrRelasi cariRelasi(listRelasi LR, adrPenulis P, adrBuku B);
adrBuku cariDataBukuID(listBuku LB, string ID);
adrBuku cariDataBukuJudul(listBuku LB, string judul);
adrPenulis cariDataPenulisID(listPenulis LP, string ID);
adrPenulis cariDataPenulisNama(listPenulis LP, string nama);
#endif // BUKU_H_INCLUDED
