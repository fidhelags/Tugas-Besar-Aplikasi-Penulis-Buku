#include "penulisbuku.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    listPenulis LP;
    createListP(LP);

    listBuku LB;
    createListB(LB);

    listRelasi LR;
    createListR(LR);

    dataPenulis dataP;
    adrPenulis P;

    dataBuku dataB;
    adrBuku B;

    // Data Penulis pertama: Raditya Dika
    dataP.idPenulis = "P001";
    dataP.nama = "Raditya Dika";
    dataP.kontak = "raditya@kambingjantan.com";
    dataP.tanggalLahir = "28/12/1984";
    dataP.totalBuku = 0;
    P = createElmP(dataP);
    insertLastP(LP, P);

    dataB.idBuku = "B001";
    dataB.judul = "Manusia Setengah Salmon";
    dataB.penerbit = "Gramedia";
    dataB.tahunTerbit = 2010;
    dataB.jumlahHalaman = 320;
    dataB.totalPenjualan = 1512200;
    B = createElmB(dataB);
    insertLastB(LB, B);
    connect(LB, LR, P, B);

    dataB.idBuku = "B003";
    dataB.judul = "Cinta Brontosaurus";
    dataB.penerbit = "Gramedia";
    dataB.tahunTerbit = 2012;
    dataB.jumlahHalaman = 288;
    dataB.totalPenjualan = 1287700;
    B = createElmB(dataB);
    insertLastB(LB, B);
    connect(LB, LR, P, B);

    // Data Penulis kedua: Pidi Baiq
    dataP.idPenulis = "P002";
    dataP.nama = "Pidi Baiq";
    dataP.kontak = "pidi@dilan1990.com";
    dataP.tanggalLahir = "08/08/1972";
    dataP.totalBuku = 0;
    P = createElmP(dataP);
    insertLastP(LP, P);

    dataB.idBuku = "B002";
    dataB.judul = "Dilan 1990";
    dataB.penerbit = "PastelBooks";
    dataB.tahunTerbit = 2014;
    dataB.jumlahHalaman = 290;
    dataB.totalPenjualan = 5987000;
    B = createElmB(dataB);
    insertLastB(LB, B);
    connect(LB, LR, P, B);

    dataB.idBuku = "B004";
    dataB.judul = "Milea: Suara dari Dilan";
    dataB.penerbit = "Pastel";
    dataB.tahunTerbit = 2016;
    dataB.jumlahHalaman = 200;
    dataB.totalPenjualan = 4019540;
    B = createElmB(dataB);
    insertLastB(LB, B);
    connect(LB, LR, P, B);

    dataB.idBuku = "B005";
    dataB.judul = "Misteri Langit Senja";  // Judul buku random
    dataB.penerbit = "AlmaMedia";  // Penerbit buku ini
    dataB.tahunTerbit = 2010;  // Tahun terbit buku ini
    dataB.jumlahHalaman = 250;  // Jumlah halaman buku ini
    dataB.totalPenjualan = 301120;  // Estimasi total penjualan sekitar 300.000 eksemplar
    B = createElmB(dataB);
    insertLastB(LB, B);
    connect(LB, LR, P, B);

    // Data Penulis ketiga: Tere Liye
    dataP.idPenulis = "P003";
    dataP.nama = "Tere Liye";
    dataP.kontak = "tere@novelislife.com";
    dataP.tanggalLahir = "21/05/1979";
    dataP.totalBuku = 0;
    P = createElmP(dataP);
    insertLastP(LP, P);

    connect(LB, LR, P, B);

    dataB.idBuku = "B006";
    dataB.judul = "Bumi";
    dataB.penerbit = "Gramedia";
    dataB.tahunTerbit = 2014;
    dataB.jumlahHalaman = 400;
    dataB.totalPenjualan = 4439000;
    B = createElmB(dataB);
    insertLastB(LB, B);
    connect(LB, LR, P, B);

    dataB.idBuku = "B007";
    dataB.judul = "Lautan Hati";  // Judul buku random
    dataB.penerbit = "PustakaMedia";  // Penerbit buku ini
    dataB.tahunTerbit = 2020;  // Tahun terbit buku ini
    dataB.jumlahHalaman = 210;  // Jumlah halaman buku ini
    dataB.totalPenjualan = 459800;
    B = createElmB(dataB);
    insertLastB(LB, B);
    connect(LB, LR, P, B);

    //////////////////////////////////////////////////////

    // Data Penulis keempat: Fiersa Besari
    dataP.idPenulis = "P004";
    dataP.nama = "Fiersa Besari";
    dataP.kontak = "fiersa@jejaklangkah.com";
    dataP.tanggalLahir = "03/03/1984";
    dataP.totalBuku = 0;
    P = createElmP(dataP);
    insertLastP(LP, P);

    connect(LB, LR, P, B);

    // Data Penulis kelima: Boy Candra
    dataP.idPenulis = "P005";
    dataP.nama = "Boy Candra";
    dataP.kontak = "boy@katapuitis.com";
    dataP.tanggalLahir = "21/11/1989";
    dataP.totalBuku = 0;
    P = createElmP(dataP);
    insertLastP(LP, P);

    connect(LB, LR, P, B);

    dataB.idBuku = "B008";
    dataB.judul = "Rasa Cinta di Tengah Hujan";
    dataB.penerbit = "GagasMedia";
    dataB.tahunTerbit = 2020;
    dataB.jumlahHalaman = 368;
    dataB.totalPenjualan = 1599010;
    B = createElmB(dataB);
    insertLastB(LB, B);
    connect(LB, LR, P, B);

    menuUtama(LP, LB, LR);

    return 0;
}
