#include "penulisbuku.h"
#include <iostream>
#include <string>
#include "stdlib.h"
using namespace std;

//function and procedure (sesuai ketentuan)
void createListP(listPenulis &LP){
    //I.S. Struktur listPenulis belum diinisialisasi atau berisi data sebelumnya.
    //F.S. Pointer first(LP) dan last(LP) pada listPenulis diinisialisasi menjadi NULL, menandakan list kosong.
    first(LP) = NULL;
    last(LP) = NULL;
}

adrPenulis createElmP(infotypePenulis data){
    //I.S. Tidak ada elemen penulis (adrPenulis) yang dibuat.
    //F.S. Sebuah elemen penulis baru dibuat, diisi dengan data infotypePenulis, dan pointer next serta prev diinisialisasi menjadi NULL.
    adrPenulis P;
    P = new elmPenulis;
    info(P) = data;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void createListB(listBuku &LB){
    //I.S. Struktur listBuku belum diinisialisasi atau berisi data sebelumnya.
    //F.S. Pointer first(LB) pada listBuku diinisialisasi menjadi NULL, menandakan list kosong.
    first(LB) = NULL;
}

adrBuku createElmB(infotypeBuku data){
    //I.S. Tidak ada elemen buku (adrBuku) yang dibuat.
    //F.S. Sebuah elemen buku baru dibuat, diisi dengan data infotypeBuku, dan pointer next diinisialisasi menjadi NULL.
    adrBuku B;
    B = new elmBuku;
    info(B) = data;
    next(B) = NULL;

    return B;
}

void createListR(listRelasi &LR){
    //I.S. Struktur listRelasi belum diinisialisasi atau berisi data sebelumnya.
    //F.S. Pointer first(LR) pada listRelasi diinisialisasi menjadi NULL, menandakan list kosong.
    first(LR) = NULL;
}

adrRelasi createElmR(adrPenulis P, adrBuku B) {
    //I.S. Tidak ada elemen relasi (adrRelasi) yang dibuat.
    //F.S. Sebuah elemen relasi baru dibuat, diisi dengan referensi ke elemen penulis (adrPenulis P) dan buku (adrBuku B), dan pointer next diinisialisasi menjadi NULL.
    adrRelasi R = new elmRelasi;
    next(R) = NULL;
    infoRP(R) = P;
    infoRB(R) = B;

    return R;
}

adrBuku cariDataBukuID(listBuku LB, string ID){
    adrBuku B;
    B = first(LB);
    while (B != NULL) {
        if (info(B).idBuku == ID) {
            return B;
        }
        B = next(B);
    }
    return NULL;
}

adrBuku cariDataBukuJudul(listBuku LB, string judul){
    adrBuku B;
    B = first(LB);
    while (B != NULL) {
        if (info(B).judul == judul) {
            return B;
        }
        B = next(B);
    }
    return NULL;
}

adrPenulis cariDataPenulisID(listPenulis LP, string ID){
    adrPenulis P;
    P = first(LP);
    while (P != NULL) {
        if (info(P).idPenulis == ID) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

adrPenulis cariDataPenulisNama(listPenulis LP, string nama){
    adrPenulis P;
    P = first(LP);
    while (P != NULL) {
        if (info(P).nama == nama) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

//MENU UTAMA//
void menuUtama(listPenulis &LP, listBuku &LB, listRelasi &LR){
    string opsi;
    system("CLS");
    cout << "Welcome!~" << endl;
    cout << "======================================================" << endl;
    cout << "                      Menu Utama                      " << endl;
    cout << "======================================================" << endl;
    cout << " 1. Tambahkan Data Penulis" << endl;
    cout << " 2. Tampilkan Seluruh Data Penulis" << endl;
    cout << " 3. Hapus Data Penulis dan Bukunya" << endl;
    cout << " 4. Cari Data Penulis" << endl;
    cout << " 5. Tambahkan Data Buku" << endl;
    cout << " 6. Ubah Data Penulis atau Data Buku" << endl;
    cout << " 7. Tampilkan Seluruh Data Penulis beserta Bukunya" << endl;
    cout << " 8. Cari Data Buku pada Penulis Tertentu" << endl;
    cout << " 9. Hapus Data Buku pada Penulis Tertentu" << endl;
    cout << "10. Hitung Total Penjualan Buku pada Tahun Tertentu" << endl;
    cout << " 0. Keluar" << endl;
    cout << "======================================================" << endl;

    //loop supaya hanya menerima inputan sesuai dengan menu yang ada, jika tidak sesuai maka tidak valid.
    do {
        cout << "Pilihan Anda[0-11]: ";
        cin >> opsi;
        if (opsi == "1") {
            menuTambahPenulis(LP, LB, LR);
        } else if (opsi == "2") {
            showAllP(LP, LB, LR);
        } else if(opsi == "3") {
            hapusParentDanChild(LP, LB, LR);
        } else if(opsi == "4") {
            menuCariDataPenulis(LP, LB, LR);
        } else if(opsi == "5") {
            insertChild(LP, LB, LR);
        } else if (opsi == "6") {
            menuUbahData(LP, LB, LR);
        } else if(opsi == "7") {
            tampilkanParentDanChild(LP, LB, LR);
        } else if (opsi == "8") {
            menuCariDataBukuPenulis(LP, LB, LR);
        } else if(opsi == "9") {
            menuHapusDataBuku(LP, LB, LR);
        } else if(opsi == "10") {
            totalPenjualanTahun(LP, LB, LR);
        } else if (opsi == "0"){
            exit();
        } else {
            cout << "Pilihan Tidak Valid." << endl;
            cin.ignore();
            cin.get();
            menuUtama(LP, LB, LR);
        }
    } while (opsi != "0" && opsi != "1" && opsi != "2" && opsi != "3" && opsi != "4" && opsi != "5" && opsi != "6" && opsi != "7" && opsi != "8" && opsi != "9" && opsi != "10");
}

//KELUAR//
void exit(){
    system("CLS");
    cout << "  /\\_/\\\n";
    cout << "=( o.o )= Goodbye!~" << endl;
    cout << "  > ^ <" << endl;
    exit(0);
}

//KONFIRMASI AKSI//
bool konfirmasi(){
    char opsi;
    while (true) {
        cout << "Apakah Anda Yakin?(Y/T): ";
        cin >> opsi;

        opsi = toupper(opsi);

        if (opsi == 'Y') {
            return true;
        } else if (opsi == 'T') {
            return false;
        } else {
            cout << "Pilihan Tidak Valid." << endl;
        }
    }
}

//Insert data parent dari depan
void insertFirstP(listPenulis &LP, adrPenulis P){
    //I.S. Linked list parent mungkin kosong atau berisi beberapa data.
    //F.S. Data parent baru berhasil ditambahkan di awal linked list.
    if (first(LP) != NULL && last(LP) != NULL){
        next(P) = first(LP);
        prev(first(LP)) = P;
        first(LP) = P;
    } else {
        first(LP) = P;
        last(LP) = P;
    }
}

//Insert data parent dari belakang
void insertLastP(listPenulis &LP, adrPenulis P){
    //I.S. Linked list parent mungkin kosong atau berisi beberapa data.
    //F.S. Data parent baru berhasil ditambahkan di akhir linked list.
    if (first(LP) != NULL && last(LP) != NULL){
        next(last(LP)) = P;
        prev(P) = last(LP);
        last(LP) = P;
    } else {
        first(LP) = P;
        last(LP) = P;
    }
}

//MENU 1 Tambahkan Data Penulis
void menuTambahPenulis(listPenulis &LP, listBuku &LB, listRelasi &LR){
    string opsi;
    system("CLS");
    cout << "================================" << endl;
    cout << "       Tambah Data Penulis      " << endl;
    cout << "================================" << endl;
    cout << " 1. Insert First" << endl;
    cout << " 2. Insert Last" << endl;
    cout << " 0. Kembali" << endl;
    cout << "================================" << endl;
    do {
        cout << "Pilihan Anda[0-2]: ";
        cin >> opsi;
        if (opsi == "1" || opsi == "2") {
            tambahPenulis(LP, LB, LR, opsi);
        } else if (opsi == "0") {
            menuUtama(LP, LB, LR);
        } else {
            cout << "Pilihan Tidak Valid." << endl;
            cin.ignore();
            cin.get();
            menuTambahPenulis(LP, LB, LR);
        }
    } while (opsi != "0" && opsi != "1" && opsi != "2");
}

void tambahPenulis(listPenulis &LP, listBuku &LB,listRelasi &LR, string opsi){
    string lanjut;
    adrPenulis P, cek;
    dataPenulis data;
    bool confirm;
    system("CLS");
    cout << "Masukkan '0' pada ID untuk Kembali" << endl;
    cout << "Masukkan 'null' untuk Mengosongkan Inputan" << endl;
    cout << "===============================================" << endl;
    cout << "              Tambah Data Penulis              " << endl;
    cout << "===============================================" << endl;
    cout << "ID Penulis: ";
    cin >> data.idPenulis;
    if (data.idPenulis == "0") {
        menuTambahPenulis(LP, LB, LR);
    } else if (data.idPenulis == "null" || data.idPenulis == "-"){
        cout << "Input Tidak Valid." << endl;
        cout << "===============================================" << endl;
        cout << "Tekan Enter untuk Kembali.";
        cin.ignore();
        cin.get();
        tambahPenulis(LP, LB, LR, opsi);
    }

    cek = cariDataPenulisID(LP, data.idPenulis);

    if (cek == NULL) {
        cin.ignore();
        cout << "Nama: ";
        getline(cin, data.nama);
        if (data.nama == "null" || data.nama == "-"){
            cout << "Input Tidak Valid." << endl;
            cout << "===============================================" << endl;
            cout << "Tekan Enter untuk Kembali.";
            cin.get();
            tambahPenulis(LP, LB, LR, opsi);
        }
        cout << "Kontak: ";
        cin >> data.kontak;
        cout << "Tangal Lahir (DD/MM/YYYY): ";
        cin >> data.tanggalLahir;
        data.totalBuku = 0;
        cout << "-----------------------------------------------" << endl;

        confirm = konfirmasi();
        if (confirm) {
            P = createElmP(data);
            if (opsi == "1"){
                insertFirstP(LP, P);
            }else {
                insertLastP(LP, P);
            }
            cout << "Data Penulis Berhasil Ditambahkan." << endl;
            cout << "===============================================" << endl;
            cout << "Tekan Enter untuk Kembali.";
            cin.ignore();
            cin.get();
        } else {
            cout << "Data Penulis Tidak Ditambahkan." << endl;
            cout << "===============================================" << endl;
            cout << "Tekan Enter untuk Kembali.";
            cin.ignore();
            cin.get();
        }
        menuTambahPenulis(LP, LB, LR);
    } else {
        cout << "Penulis dengan ID " << data.idPenulis << " Sudah Ada." << endl;
        cout << "===============================================" << endl;
        cout << "Tekan Enter untuk Kembali.";
        cin.ignore();
        cin.get();
        menuTambahPenulis(LP, LB, LR);
    }
}

//Show all data parent
//MENU 2 Tambahkan Data Penulis Tampilkan Seluruh Data Penulis
void showAllP(listPenulis &LP, listBuku &LB, listRelasi &LR){
    //I.S. Linked list parent mungkin kosong atau berisi beberapa data.
    //F.S. Seluruh data parent ditampilkan ke layar.
    adrPenulis P;
    P = first(LP);
    system("CLS");
    cout << "==============================================" << endl;
    cout << "                 Data Penulis                 " << endl;
    cout << "==============================================" << endl;
    if (P != NULL){
        while (P != NULL) {
            cout << "ID Penulis   : ";
            cout << info(P).idPenulis << endl;
            cout << "Nama         : ";
            cout << info(P).nama << endl;
            cout << "Kontak       : ";
            if (info(P).kontak == "null"){
                cout << "-" << endl;
            } else {
                cout << info(P).kontak << endl;
            }
            cout << "Tanggal Lahir: ";
            if (info(P).tanggalLahir == "null"){
                cout << "-" << endl;
            } else {
                cout << info(P).tanggalLahir << endl;
            }
            cout << "Total Buku   : ";
            cout << info(P).totalBuku << endl;
            if (next(P) != NULL) {
                cout << "----------------------------------------------" << endl;
            }
            P = next(P);
        }
    } else {
        cout << "Tidak Ada." <<endl;
    }
    cout << "==============================================" << endl;
    cout << "Tekan Enter untuk Kembali.";
    cin.ignore();
    cin.get();
    menuUtama(LP, LB, LR);
}

//Menghapus data parent dan childnya
//MENU 3 Hapus Data Penulis dan Bukunya
void hapusParentDanChild(listPenulis &LP, listBuku &LB, listRelasi &LR) {
    system("CLS");
    string idPenulis;
    bool confirm;
     cout << "Masukkan '0' untuk Kembali" << endl;
    cout << "======================================================" << endl;
    cout << "            Hapus Data Penulis dan Bukunya            " << endl;
    cout << "======================================================" << endl;
    cout << "ID Penulis yang Ingin Dihapus: ";
    cin >> idPenulis;
    if (idPenulis == "0"){
        menuUtama(LP, LB, LR);
    } else if (idPenulis == "-"){
        cout << "Input Tidak Valid." << endl;
        cout << "===============================================" << endl;
        cout << "Tekan Enter untuk Kembali.";
        cin.ignore();
        cin.get();
        hapusParentDanChild(LP, LB, LR);
    }

    adrPenulis P = cariDataPenulisID(LP, idPenulis);
    if (P != NULL) {
        // Hapus semua relasi dan buku yang terkait dengan penulis
        cout << "------------------------------------------------------" << endl;
        cout << "ID Penulis   : " << info(P).idPenulis << endl;
        cout << "Nama         : " << info(P).nama << endl;
        cout << "Kontak       : ";
        if (info(P).kontak == "null"){
            cout << "-" << endl;
        } else {
            cout << info(P).kontak << endl;
        }
        cout << "Tanggal Lahir: ";
        if (info(P).tanggalLahir == "null"){
            cout << "-" << endl;
        } else {
            cout << info(P).tanggalLahir << endl;
        }
        cout << "Total Buku   : " << info(P).totalBuku << endl;

        // Menampilkan buku terkait penulis ini
        adrRelasi R = first(LR);
        while (R != NULL) {
            if (infoRP(R) == P) {
                cout << "  -> ID Buku : " << info(infoRB(R)).idBuku << endl;
                cout << "     Judul   : " << info(infoRB(R)).judul << endl;
            }
            R = next(R);
        }

        cout << "------------------------------------------------------" << endl;
        confirm = konfirmasi();

        if (confirm) {
            adrRelasi R = first(LR), prevR = NULL;
            while (R != NULL) {
                if (infoRP(R) == P) {
                    adrRelasi tempR = R;
                    adrBuku B = infoRB(R);

                    // Hapus buku dari list LB
                    if (banyakPenulis(LR, B) == 1){
                        adrBuku currentB = first(LB), prevB = NULL;
                        while (currentB != NULL) {
                            if (currentB == B) {
                                if (prevB == NULL) {
                                    first(LB) = next(currentB);
                                } else {
                                    next(prevB) = next(currentB);
                                }
                                delete currentB;
                            }
                            prevB = currentB;
                            currentB = next(currentB);
                        }
                    }

                    // Hapus relasi
                    if (prevR != NULL) {
                        next(prevR) = next(R);
                    } else {
                        first(LR) = next(R);
                    }
                    R = next(R);
                    delete tempR;
                } else {
                    prevR = R;
                    R = next(R);
                }
            }


            // Hapus penulis dari list LP
            if (prev(P) != NULL) {
                next(prev(P)) = next(P);
            } else {
                first(LP) = next(P);
            }
            if (next(P) != NULL) {
                prev(next(P)) = prev(P);
            } else {
                last(LP) = prev(P);
            }
            delete P;
            cout << "Data Penulis dan Semua Data Buku Berhasil Dihapus." << endl;
        } else {
            cout << "Data Penulis dan Semua Data Buku Tidak Dihapus." << endl;
        }
    } else {
        cout << "Penulis dengan ID " << idPenulis << " Tidak Ditemukan." << endl;
    }
    cout << "======================================================" << endl;
    cout << "Tekan Enter untuk kembali." << endl;
    cin.ignore();
    cin.get();
    menuUtama(LP, LB, LR);
}

int banyakPenulis(listRelasi &LR, adrBuku B){
    adrRelasi R;
    R = first(LR);
    int hitung = 0;
    while (R != NULL){
        if (info(infoRB(R)).idBuku == info(B).idBuku){
            hitung++;
        }
        R = next(R);
    }

    return hitung;
}

//Mencari data parent
// MENU 4 Cari Data Penulis
void menuCariDataPenulis(listPenulis LP, listBuku LB, listRelasi &LR) {
    string opsi;
    system("CLS");
    cout << "================================" << endl;
    cout << "       Cari Data Penulis        " << endl;
    cout << "================================" << endl;
    cout << " 1. Berdasarkan ID Penulis" << endl;
    cout << " 2. Berdasarkan Nama Penulis" << endl;
    cout << " 0. Kembali" << endl;
    cout << "================================" << endl;
    do {
        cout << "Pilihan Anda[0-2]: ";
        cin >> opsi;
        if (opsi == "1" || opsi == "2") {
            cariDataPenulis(LP, LB, LR, opsi);
        } else if (opsi == "0") {
            menuUtama(LP, LB, LR); // Kembali ke menu utama
        } else {
            cout << "Pilihan Tidak Valid." << endl;
            cin.ignore();
            cin.get();
            menuCariDataPenulis(LP, LB, LR); // Panggil ulang jika input tidak valid
        }
    } while (opsi != "0" && opsi != "1" && opsi != "2");
}

void cariDataPenulis(listPenulis LP, listBuku LB, listRelasi &LR, string opsi) {
    system("CLS");
    adrPenulis P;
    string ID, nama;
    if (opsi == "1") {
        cout << "Masukkan '0' untuk Kembali" << endl;
        cout << "=========================================" << endl;
        cout << "              Data Penulis               " << endl;
        cout << "=========================================" << endl;
        cout << "Cari Penulis dengan ID Penulis: ";
        cin >> ID;
        if (ID == "0") {
            menuCariDataPenulis(LP, LB, LR); // Kembali ke menu sebelumnya
        } else if (ID == "-"){
            cout << "Input Tidak Valid." << endl;
            cout << "=========================================" << endl;
            cout << "Tekan Enter untuk Kembali.";
            cin.ignore();
            cin.get();
            cariDataPenulis(LP, LB, LR, opsi);
        }
        P = cariDataPenulisID(LP, ID);
        if (P == NULL) {
            cout << "Penulis dengan ID " << ID << " Tidak Ditemukan." << endl;
            cout << "=========================================" << endl;
            cout << "Tekan Enter untuk kembali.";
            cin.ignore();
            cin.get();
            menuCariDataPenulis(LP, LB, LR); // Kembali ke menu pencarian
        } else {
            tampilkanDataPenulis(P);
            cin.ignore();
        }
    } else if (opsi == "2") {
        cin.ignore();
        cout << "Masukkan '-' untuk Kembali" << endl;
        cout << "=========================================" << endl;
        cout << "              Data Penulis               " << endl;
        cout << "=========================================" << endl;
        cout << "Cari Penulis dengan Nama: ";
        getline(cin, nama);
        if (nama == "-") {
            menuCariDataPenulis(LP, LB, LR); // Kembali ke menu utama
        }
        P = cariDataPenulisNama(LP, nama);
        if (P == NULL) {
            cout << "Penulis dengan Nama " << nama << " Tidak Ditemukan." << endl;
            cout << "=========================================" << endl;
            cout << "Tekan Enter untuk kembali.";
            cin.get();
            menuCariDataPenulis(LP, LB, LR); // Kembali ke menu pencarian
        } else {
            tampilkanDataPenulis(P);
        }
    }
    cin.get();
    menuCariDataPenulis(LP, LB, LR); // Kembali ke menu pencarian setelah selesai
}

void tampilkanDataPenulis(adrPenulis P) {
    system("CLS");
    cout << "=========================================" << endl;
    cout << "              Data Penulis               " << endl;
    cout << "=========================================" << endl;
    cout << "ID Penulis   : " << info(P).idPenulis << endl;
    cout << "Nama         : " << info(P).nama << endl;
    cout << "Kontak       : ";
    if (info(P).kontak == "null"){
        cout << "-" << endl;
    } else {
        cout << info(P).kontak << endl;
    }
    cout << "Tanggal Lahir: ";
    if (info(P).tanggalLahir == "null"){
        cout << "-" << endl;
    } else {
        cout << info(P).tanggalLahir << endl;
    }
    cout << "Total Buku   : " << info(P).totalBuku << endl;
    cout << "=========================================" << endl;
    cout << "Tekan Enter untuk Kembali.";
}

//Insert data child
// MENU 5 Tambahkan Data Buku
void insertChild(listPenulis &LP, listBuku &LB, listRelasi &LR) {
    system("CLS");
    string idPenulis;
    bool confirm;
    infotypeBuku dataBuku;
    adrBuku cek;
    cout << "Masukkan '0' pada ID untuk Kembali" << endl;
    cout << "Masukkan 'null' atau '0' untuk Mengosongkan Inputan" << endl;
    cout << "======================================================" << endl;
    cout << "                   Tambah Data Buku                   " << endl;
    cout << "======================================================" << endl;
    cout << "ID Penulis untuk Buku Ini: ";
    cin >> idPenulis;
    if (idPenulis == "0") {
        menuUtama(LP, LB, LR);
    } else if (idPenulis == "-") {
        cout << "Input Tidak Valid." << endl;
        cout << "======================================================" << endl;
        cout << "Tekan Enter untuk Kembali.";
        cin.ignore();
        cin.get();
        insertChild(LP, LB, LR);
    }

    adrPenulis P = cariDataPenulisID(LP, idPenulis);
    if (P == NULL) {
        cout << "Penulis dengan ID " << idPenulis << " Tidak Ditemukan." << endl;
        cout << "======================================================" << endl;
        cout << "Tekan Enter untuk Kembali.";
        cin.ignore();
        cin.get();
        menuUtama(LP, LB, LR);
    }

    // Input data buku
    cout << "------------------------------------------------------" << endl;
    cout << "ID Buku: ";
    cin >> dataBuku.idBuku;
    if (dataBuku.idBuku == "0") {
        menuUtama(LP, LB, LR);
    } else if (dataBuku.idBuku == "null" || dataBuku.idBuku == "-"){
        cout << "Input Tidak Valid." << endl;
        cout << "======================================================" << endl;
        cout << "Tekan Enter untuk Kembali.";
        cin.ignore();
        cin.get();
        insertChild(LP, LB, LR);
    }

    cek = cariDataBukuID(LB, dataBuku.idBuku);

    if (cek == NULL) {
        cin.ignore();
        cout << "Judul: ";
        getline(cin, dataBuku.judul);
        if (dataBuku.judul == "null" || dataBuku.judul == "-"){
            cout << "Input Tidak Valid." << endl;
            cout << "======================================================" << endl;
            cout << "Tekan Enter untuk Kembali.";
            cin.get();
            insertChild(LP, LB, LR);
        }
        cout << "Penerbit: ";
        cin >> dataBuku.penerbit;
        cout << "Tahun Terbit: ";
        cin >> dataBuku.tahunTerbit;
        cout << "Jumlah Halaman: ";
        cin >> dataBuku.jumlahHalaman;
        cout << "Total Penjualan: ";
        cin >> dataBuku.totalPenjualan;
        cout << "------------------------------------------------------" << endl;

        confirm = konfirmasi();

        if (confirm) {
            adrBuku B = createElmB(dataBuku);
            insertLastB(LB, B);

            // Tambahkan relasi antara Penulis dan Buku
            connect(LB, LR, P, B);

            // Tambahkan Penulis Lain
            penulisLain(LP, LB, LR, B);
            cout << "------------------------------------------------------" << endl;
            cout << "Data Buku Berhasil Ditambahkan." << endl;
            cout << "======================================================" << endl;
            cout << "Tekan Enter untuk Kembali.";
        } else {
            cout << "Data Buku Tidak Ditambahkan." << endl;
            cout << "======================================================" << endl;
            cout << "Tekan Enter untuk Kembali.";
        }
        cin.ignore();
        cin.get();
        menuUtama(LP, LB, LR);
    } else {
        cout << "Buku dengan ID " << dataBuku.idBuku << " Sudah Ada." << endl;
        cout << "======================================================" << endl;
        cout << "Tekan Enter untuk Kembali.";
        cin.ignore();
        cin.get();
        menuUtama(LP, LB, LR);
    }
}

void insertLastB(listBuku &LB, adrBuku B){
    if (first(LB) == NULL) {
        first(LB) = B;
    } else {
        adrBuku last = first(LB);
        while (next(last) != NULL) {
            last = next(last);
        }
        next(last) = B;
    }
}

void connect(listBuku &LB, listRelasi &LR, adrPenulis P, adrBuku B){
    adrRelasi R = createElmR(P, B);
    if (first(LR) == NULL) {
        first(LR) = R;
    } else {
        adrRelasi lastRel = first(LR);
        while (next(lastRel) != NULL) {
            lastRel = next(lastRel);
        }
        next(lastRel) = R;
    }
    // Tambahkan ke total buku penulis
    info(P).totalBuku += 1;
}

void penulisLain(listPenulis &LP, listBuku &LB, listRelasi &LR, adrBuku B){
    adrPenulis pL;
    string idLain;
    adrRelasi cekP;
    bool addPenulis = true;
    bool addData = true;
    while (addPenulis) {
        char opsi;
        cout << "------------------------------------------------------" << endl;
        cout << "Tambah Penulis Lain?(Y/T): ";
        cin >> opsi;

        opsi = toupper(opsi);

        if (opsi == 'Y') {
            while (addData){
                cout << "------------------------------------------------------" << endl;
                cout << "(Masukkan '0' atau '-' untuk Berhenti Menambahkan)" << endl;
                cout << "ID Penulis Lain: ";
                cin >> idLain;

                if (idLain == "0" || idLain == "-"){
                    addData = false;
                    addPenulis = false;
                }

                pL = cariDataPenulisID(LP, idLain);

                if (pL == NULL && (idLain != "0" && idLain != "-")){
                    cout << "Penulis dengan ID " << idLain << " Tidak Ditemukan." << endl;
                } else if (pL != NULL && (idLain != "0" || idLain != "-")) {
                    cekP = cariRelasi(LR, pL, B);
                    if (cekP == NULL){
                        connect(LB, LR, pL, B);
                        cout << "Penulis dengan ID " << idLain << " Berhasil Ditambahkan." << endl;
                    } else {
                        cout << "Penulis dengan ID " << idLain << " Sudah Pernah Ditambahkan." << endl;
                    }
                }
            }
        } else if (opsi == 'T') {
            addPenulis = false;
        } else {
            cout << "Pilihan Tidak Valid." << endl;
            cout << "------------------------------------------------------" << endl;
        }
    }
}

//Mengubah data parent / data child
//MENU 6 Ubah Data Penulis atau Data Buku
void menuUbahData(listPenulis &LP, listBuku &LB, listRelasi &LR){
    string opsi;
    system("CLS");
    cout << "================================" << endl;
    cout << "            Ubah Data           " << endl;
    cout << "================================" << endl;
    cout << " 1. Ubah Data Penulis" << endl;
    cout << " 2. Ubah Data Buku" << endl;
    cout << " 0. Kembali" << endl;
    cout << "================================" << endl;
    do {
        cout << "Pilihan Anda[0-2]: ";
        cin >> opsi;
        if (opsi == "1") {
            ubahDataPenulis(LP, LB, LR);
        } else if (opsi == "2") {
            ubahDataBuku(LP, LB, LR);
        } else if (opsi == "0") {
            menuUtama(LP, LB, LR);
        } else {
            cout << "Pilihan Tidak Valid." << endl;
            cin.ignore();
            cin.get();
            menuUbahData(LP, LB, LR);
        }
    } while (opsi != "0" && opsi != "1" && opsi != "2");
}

void ubahDataPenulis(listPenulis &LP, listBuku &LB, listRelasi &LR) {
    dataPenulis dataP;
    adrPenulis P;
    string ubah;
    bool confirm;
    system("CLS");
    cout << "===================================" << endl;
    cout << "         Ubah Data Penulis         " << endl;
    cout << "===================================" << endl;
    cout << " 1. Berdasarkan ID Penulis" << endl;
    cout << " 2. Berdasarkan Nama Penulis" << endl;
    cout << " 0. Kembali" << endl;
    cout << "===================================" << endl;
    cout << "Pilihan Anda[0-2]: ";
    cin >> ubah;

    if (ubah == "1") {
        system("CLS");
        cout << "Masukkan '0' untuk kembali" << endl;
        cout << "===================================" << endl;
        cout << "         Ubah Data Penulis         " << endl;
        cout << "===================================" << endl;
        cout << "ID Penulis: ";
        cin >> dataP.idPenulis;
        if (dataP.idPenulis == "0") {
            menuUbahData(LP, LB, LR);
        }
        dataP.nama = "-";
    } else if (ubah == "2") {
        system("CLS");
        cin.ignore();
        cout << "Masukkan '-' untuk kembali" << endl;
        cout << "===================================" << endl;
        cout << "         Ubah Data Penulis         " << endl;
        cout << "===================================" << endl;
        cout << "Nama Penulis: ";
        getline(cin, dataP.nama);
        if (dataP.nama == "-") {
            menuUbahData(LP, LB, LR);
        }
        dataP.idPenulis = "-";
    } else if (ubah == "0") {
        menuUbahData(LP, LB, LR);
    } else {
        cout << "Pilihan Tidak Valid." << endl;
        cin.ignore();
        cin.get();
        menuUbahData(LP, LB, LR);
    }


    if (dataP.idPenulis != "-" || dataP.nama != "-") {
        if (dataP.idPenulis != "-") {
            P = cariDataPenulisID(LP, dataP.idPenulis);
        } else if (dataP.nama != "-") {
            P = cariDataPenulisNama(LP, dataP.nama);
        }

        if (P != NULL) {
            system("CLS");
            cout << "Masukkan '0' pada ID untuk kembali" << endl;
            cout << "Masukkan '-' untuk Tidak Memperbarui Data" << endl;
            cout << "Masukkan 'null' untuk Mengosongkan Data" << endl;
            cout << "===============================================" << endl;
            cout << "           Masukkan Data Penulis Baru          " << endl;
            cout << "===============================================" << endl;
            cout << "ID Penulis: ";
            cin >> dataP.idPenulis;
            if (dataP.idPenulis == "0") {
                menuUbahData(LP, LB, LR);
            } else if (dataP.idPenulis == "null") {
                cout << "Input Tidak Valid." << endl;
                cout << "===============================================" << endl;
                cout << "Tekan Enter untuk Kembali.";
                cin.ignore();
                cin.get();
                menuUbahData(LP, LB, LR);
            }

            adrPenulis cek = cariDataPenulisID(LP, dataP.idPenulis);

            if (cek != NULL){
                cout << "Penulis dengan ID " << dataP.idPenulis << " Sudah Ada." << endl;
                cout << "===============================================" << endl;
                cout << "Tekan Enter untuk Kembali.";
                cin.ignore();
                cin.get();
                menuUbahData(LP, LB, LR);
            }

            cin.ignore();
            cout << "Nama Penulis: ";
            getline(cin, dataP.nama);
            if (dataP.nama == "null") {
                cout << "Input Tidak Valid." << endl;
                cout << "===============================================" << endl;
                cout << "Tekan Enter untuk Kembali.";
                cin.get();
                menuUbahData(LP, LB, LR);
            }
            cout << "Kontak: ";
            cin >> dataP.kontak;
            cout << "Tanggal Lahir: ";
            cin >> dataP.tanggalLahir;
            cout << "-----------------------------------------------" << endl;

            if (dataP.idPenulis == "-" && dataP.nama == "-" && dataP.kontak == "-" && dataP.tanggalLahir == "-") {
                cout << "Data Penulis Tidak Diperbarui." << endl;
                cout << "===============================================" << endl;
                cout << "Tekan Enter untuk Kembali.";
                cin.ignore();
                cin.get();
                menuUbahData(LP, LB, LR);
            }

            confirm = konfirmasi();
            if (confirm) {
                if (dataP.idPenulis != "-") {
                    info(P).idPenulis = dataP.idPenulis;
                }
                if (dataP.nama != "-") {
                    info(P).nama = dataP.nama;
                }
                if (dataP.kontak != "-") {
                    info(P).kontak = dataP.kontak;
                }
                if (dataP.tanggalLahir != "-") {
                    info(P).tanggalLahir = dataP.tanggalLahir;
                }
                cout << "-----------------------------------------------" << endl;
                cout << "Data Penulis Berhasil Diperbarui." << endl;

            } else {
                cout << "Data Penulis Tidak Diperbarui." << endl;
            }
            cout << "===============================================" << endl;
            cout << "Tekan Enter untuk Kembali.";
            cin.ignore();
            cin.get();
            menuUbahData(LP, LB, LR);
        } else {
            cout << "Penulis Tidak Ditemukan." << endl;
            if (dataP.nama == "-") {
                cin.ignore();
            }
            cout << "===================================" << endl;
            cout << "Tekan Enter untuk Kembali.";
            cin.get();
            menuUbahData(LP, LB, LR);
        }
    }
}

void ubahDataBuku(listPenulis &LP, listBuku &LB, listRelasi &LR) {
    dataBuku dataB;
    adrBuku B;
    string ubah;
    bool confirm;
    system("CLS");
    cout << "===================================" << endl;
    cout << "           Ubah Data Buku          " << endl;
    cout << "===================================" << endl;
    cout << " 1. Berdasarkan ID Buku" << endl;
    cout << " 2. Berdasarkan Judul Buku" << endl;
    cout << " 0. Kembali" << endl;
    cout << "===================================" << endl;
    cout << "Pilihan Anda[0-2]: ";
    cin >> ubah;

    if (ubah == "1") {
        system("CLS");
        cout << "Masukkan '0' untuk kembali" << endl;
        cout << "===================================" << endl;
        cout << "           Ubah Data Buku          " << endl;
        cout << "===================================" << endl;
        cout << "ID Buku: ";
        cin >> dataB.idBuku;
        if (dataB.idBuku == "0"){
            menuUbahData(LP, LB, LR);
        }
        dataB.judul = "-";
    } else if (ubah == "2") {
        system("CLS");
        cin.ignore();
        cout << "Masukkan '-' untuk kembali" << endl;
        cout << "===================================" << endl;
        cout << "           Ubah Data Buku          " << endl;
        cout << "===================================" << endl;
        cout << "Judul Buku: ";
        getline(cin, dataB.judul);
        if (dataB.judul == "-"){
            menuUbahData(LP, LB, LR);
        }
        dataB.idBuku = "-";
    } else if (ubah == "0") {
         menuUbahData(LP, LB, LR);
    } else {
        cout << "Pilihan Tidak Valid." << endl;
        cin.ignore();
        cin.get();
        menuUbahData(LP, LB, LR);
    }

     if (dataB.idBuku != "-" || dataB.judul != "-") {
        if (dataB.idBuku != "-") {
            B = cariDataBukuID(LB, dataB.idBuku);
        } else if (dataB.judul != "-") {
            B = cariDataBukuJudul(LB, dataB.judul);
        }

        if (B != NULL) {
            system("CLS");
            cout << "Masukkan '0' pada ID untuk kembali" << endl;
            cout << "Masukkan '-' atau '-1' untuk Tidak Memperbarui Data" << endl;
            cout << "Masukkan 'null' atau '0' untuk Mengosongkan Data" << endl;
            cout << "====================================================" << endl;
            cout << "               Masukkan Data Buku Baru              " << endl;
            cout << "====================================================" << endl;
            cout << "ID Buku: ";
            cin >> dataB.idBuku;
            if (dataB.idBuku == "0"){
                menuUbahData(LP, LB, LR);
            } else if (dataB.idBuku == "null"){
                cout << "Input Tidak Valid." << endl;
                cout << "====================================================" << endl;
                cout << "Tekan Enter untuk Kembali.";
                cin.ignore();
                cin.get();
               menuUbahData(LP, LB, LR);
            }

            adrBuku cek = cariDataBukuID(LB, dataB.idBuku);

            if (cek != NULL){
                cout << "Buku dengan ID " << dataB.idBuku << " Sudah Ada." << endl;
                cout << "====================================================" << endl;
                cout << "Tekan Enter untuk Kembali.";
                cin.ignore();
                cin.get();
                menuUbahData(LP, LB, LR);
            }

            cin.ignore();
            cout << "Judul Buku: ";
            getline(cin, dataB.judul);
            if (dataB.judul == "null"){
                cout << "Input Tidak Valid." << endl;
                cout << "====================================================" << endl;
                cout << "Tekan Enter untuk Kembali.";
                cin.ignore();
                cin.get();
                menuUbahData(LP, LB, LR);
            }
            cout << "Penerbit: ";
            cin >> dataB.penerbit;
            cout << "Tahun Terbit: ";
            cin >> dataB.tahunTerbit;
            cout << "Jumlah Halaman: ";
            cin >> dataB.jumlahHalaman;
            cout << "Total Penjualan: ";
            cin >> dataB.totalPenjualan;
            cout << "----------------------------------------------------" << endl;

            if (dataB.idBuku == "-" && dataB.judul == "-" && dataB.penerbit == "-" && dataB.tahunTerbit == 0 && dataB.jumlahHalaman == 0 && dataB.totalPenjualan == 0) {
                cout << "Data Buku Tidak Diperbarui." << endl;
                cout << "====================================================" << endl;
                cout << "Tekan Enter untuk Kembali.";
                cin.ignore();
                cin.get();
                menuUbahData(LP, LB, LR);
            }

            confirm = konfirmasi();
            if (confirm) {
                if (dataB.idBuku != "-") {
                    info(B).idBuku = dataB.idBuku;
                }
                if (dataB.judul != "-") {
                    info(B).judul = dataB.judul;
                }
                if (dataB.penerbit != "-") {
                    info(B).penerbit = dataB.penerbit;
                }
                if (dataB.tahunTerbit != -1) {
                    info(B).tahunTerbit = dataB.tahunTerbit;
                }
                if (dataB.jumlahHalaman != -1) {
                    info(B).jumlahHalaman = dataB.jumlahHalaman;
                }
                if (dataB.totalPenjualan != -1) {
                    info(B).totalPenjualan = dataB.totalPenjualan;
                }

                cout << "----------------------------------------------------" << endl;
                cout << "Data Buku Berhasil Diperbarui." << endl;
                cout << "====================================================" << endl;
                cout << "Tekan Enter untuk Kembali.";
                cin.ignore();
                cin.get();
            } else {
                cout << "Data Buku Tidak Diperbarui." << endl;
               cout << "====================================================" << endl;
                cout << "Tekan Enter untuk Kembali.";
                cin.ignore();
                cin.get();
            }
            menuUbahData(LP, LB, LR);
        } else {
            cout << "Buku Tidak Ditemukan." << endl;
            cout << "===================================" << endl;
            cout << "Tekan Enter untuk Kembali.";
            if (dataB.judul == "-"){
                cin.ignore();
            }
            cin.get();
            menuUbahData(LP, LB, LR);
        }
    }
}

//Menampilkan seluruh data parent beserta childnya
//MENU 7 Tampilkan Seluruh Data Penulis beserta Bukunya
void tampilkanParentDanChild(listPenulis &LP, listBuku &LB, listRelasi &LR) {
    adrPenulis P = first(LP);
    system("CLS");
    cout << "==============================================" << endl;
    cout << "                 Data Penulis                 " << endl;
    cout << "==============================================" << endl;
    if (P != NULL) {
        while (P != NULL) {
            cout << "ID Penulis   : " << info(P).idPenulis << endl;
            cout << "Nama         : " << info(P).nama << endl;
            cout << "Kontak       : " << info(P).kontak << endl;
            cout << "Tanggal Lahir: " << info(P).tanggalLahir << endl;
            cout << "Total Buku   : " << info(P).totalBuku << endl;
            if (info(P).totalBuku != 0){
                cout << "----------------------------------------------" << endl;
            }

            // Menampilkan buku terkait penulis ini
            adrRelasi R = first(LR);
            while (R != NULL) {
                if (infoRP(R) == P) {
                    cout << "  -> ID Buku : " << info(infoRB(R)).idBuku << endl;
                    cout << "     Judul   : " << info(infoRB(R)).judul << endl;
                }
                R = next(R);
            }

            if (next(P) != NULL) {
                cout << "==============================================" << endl;
            }
            P = next(P);
        }
    } else {
        cout << "Tidak Ada." << endl;
    }
    cout << "==============================================" << endl;
    cout << "Tekan Enter untuk Kembali.";
    cin.ignore();
    cin.get();
    menuUtama(LP, LB, LR);
}

//Mencari data child pada parent tertentu
//MENU 8 Cari Data Buku pada Penulis Tertentu
void menuCariDataBukuPenulis(listPenulis LP, listBuku LB, listRelasi &LR){
    string opsi;
    system("CLS");
    cout << "================================" << endl;
    cout << "         Cari Data Buku         " << endl;
    cout << "================================" << endl;
    cout << " 1. Berdasarkan ID Penulis" << endl;
    cout << " 2. Berdasarkan Nama Penulis" << endl;
    cout << " 0. Kembali" << endl;
    cout << "================================" << endl;
    do {
        cout << "Pilihan Anda[0-2]: ";
        cin >> opsi;
        if (opsi == "1" || opsi == "2") {
            cariDataBukuPenulis(LP, LB, LR, opsi);
        } else if (opsi == "0"){
            menuUtama(LP, LB, LR);
        } else {
            cout << "Pilihan Tidak Valid." << endl;
            cin.ignore();
            cin.get();
            menuCariDataBukuPenulis(LP, LB, LR);
        }
    } while (opsi != "0" && opsi != "1" && opsi != "2");
}

void cariDataBukuPenulis(listPenulis &LP, listBuku &LB, listRelasi &LR, string opsi){
    system("CLS");
    adrPenulis P;
    string  ID, nama;
    cout << "Masukkan '0' atau '-' untuk Kembali" << endl;
    cout << "=============================================" << endl;
    cout << "                Data Penulis                 " << endl;
    cout << "=============================================" << endl;
    if (opsi == "1"){
        cout << "Data Buku dengan ID Penulis: ";
        cin >>  ID;
        if (ID == "0" || ID == "-") {
            menuCariDataBukuPenulis(LP, LB, LR);
        }
        P = cariDataPenulisID(LP, ID);
        if (P == NULL) {
            cout << "Penulis dengan ID " << ID << " Tidak Ditemukan." << endl;
            cout << "=============================================" << endl;
            cout << "Tekan Enter untuk kembali.";
            cin.ignore();
            cin.get();
            menuCariDataBukuPenulis(LP, LB, LR);
        }
        showPB(LP, LB, LR, P);
        cin.ignore();
    } else {
        cin.ignore();
        cout << "Data Buku dengan Nama: ";
        getline(cin, nama);
        if (nama == "-" || nama == "0") {
            menuCariDataBukuPenulis(LP, LB, LR);
        }
        P = cariDataPenulisNama(LP, nama);
        if (P == NULL) {
            cout << "Penulis dengan Nama " << nama << " Tidak Ditemukan." << endl;
            cout << "=============================================" << endl;
            cout << "Tekan Enter untuk kembali.";
            cin.get();
            menuCariDataBukuPenulis(LP, LB, LR);
        }
        showPB(LP, LB, LR, P);
    }
    cout << "Tekan Enter untuk kembali.";
    cin.get();
    menuCariDataBukuPenulis(LP, LB, LR);
}

void showPB(listPenulis LP, listBuku LB, listRelasi LR, adrPenulis P){
    system("CLS");
    adrRelasi R;
    adrBuku B;
    cout << "=============================================" << endl;
    cout << "        Data Buku Berserta Penulisnya        " << endl;
    cout << "=============================================" << endl;
    cout << "ID Penulis     : ";
    cout << info(P).idPenulis << endl;
    cout << "Nama           : ";
    cout << info(P).nama << endl;
    if (info(P).totalBuku == 0){
        cout << "---------------------------------------------" << endl;
        cout << "Tidak Ada." << endl;
    }
    R = first(LR);
    if (R != NULL){
        while (R != NULL){
            if (infoRP(R) == P) {
                B = infoRB(R);
                cout << "---------------------------------------------" << endl;
                cout << "ID Buku        : " << info(B).idBuku << endl;
                cout << "Judul Buku     : " << info(B).judul << endl;
                cout << "Penerbit       : ";
                if (info(B).penerbit == "null"){
                    cout << "-" << endl;
                } else {
                    cout << info(B).penerbit << endl;
                }
                cout << "Tahun Terbit   : " << info(B).tahunTerbit << endl;
                cout << "Jumlah Halaman : " << info(B).jumlahHalaman << endl;
                cout << "Total Penjualan: " << info(B).totalPenjualan << endl;
            }
            R = next(R);
        }
    }
    cout << "=============================================" << endl;
}

//Menghapus data child pada parent tertentu
//MENU 9 Hapus Data Buku pada Penulis Tertentu
void menuHapusDataBuku(listPenulis &LP, listBuku &LB, listRelasi &LR){
    string opsi;
    system("CLS");
    cout << "================================" << endl;
    cout << "         Hapus Data Buku        " << endl;
    cout << "================================" << endl;
    cout << " 1. Berdasarkan ID Penulis" << endl;
    cout << " 2. Berdasarkan Nama Penulis" << endl;
    cout << " 0. Kembali" << endl;
    cout << "================================" << endl;
    do {
        cout << "Pilihan Anda[0-2]: ";
        cin >> opsi;
        if (opsi == "1" || opsi == "2") {
            hapusDataBuku(LP, LB, LR, opsi);
        } else if (opsi == "0"){
            menuUtama(LP, LB, LR);
        } else {
            cout << "Pilihan Tidak Valid." << endl;
            cin.ignore();
            cin.get();
            menuCariDataBukuPenulis(LP, LB, LR);
        }
    } while (opsi != "0" && opsi != "1" && opsi != "2");
}

void hapusDataBuku(listPenulis &LP, listBuku &LB, listRelasi &LR, string opsi){
    system("CLS");
    adrPenulis P;
    adrBuku B;
    adrRelasi R;
    bool confirm;
    string  ID, nama, idHapus;
    cout << "Masukkan '0' untuk Kembali" << endl;
    cout << "=============================================" << endl;
    cout << "                Data Penulis                 " << endl;
    cout << "=============================================" << endl;
    if (opsi == "1"){
        cout << "Data Buku dengan ID Penulis: ";
        cin >>  ID;
        if (ID == "0" || ID == "-") {
            menuHapusDataBuku(LP, LB, LR);
        }
        P = cariDataPenulisID(LP, ID);
        if (P == NULL) {
            cout << "Penulis dengan ID " << ID << " Tidak Ditemukan." << endl;
            cout << "=============================================" << endl;
            cout << "Tekan Enter untuk kembali.";
            cin.ignore();
            cin.get();
            hapusDataBuku(LP, LB, LR, opsi);
        }
    } else {
        cin.ignore();
        cout << "Data Buku dengan Nama: ";
        getline(cin, nama);
        if (nama == "-" || nama == "0") {
          menuHapusDataBuku(LP, LB, LR);
        }
        P = cariDataPenulisNama(LP, nama);
        if (P == NULL) {
            cout << "Penulis dengan Nama " << nama << " Tidak Ditemukan." << endl;
            cout << "==================================================================" << endl;
            cout << "Tekan Enter untuk kembali.";
            cin.get();
            hapusDataBuku(LP, LB, LR, opsi);
        }
    }
    showPBHapus(LP, LB, LR, P);
    cout << "ID Buku yang Ingin Dihapus: ";
    cin >> idHapus;
    if (idHapus == "-" || idHapus == "0") {
        menuHapusDataBuku(LP, LB, LR);
    }
    B = cariDataBukuID(LB, idHapus);
    R = cariRelasi(LR, P, B);

    if (R != NULL) {
        cout << "------------------------------------------------------------------" << endl;
        confirm = konfirmasi();
        if (confirm) {
            //hapus relasi
            if (R == first(LR)){
                deleteFirstRelasi(LR, R);
            } else if (next(R) == NULL) {
                deleteLastRelasi(LR, R);
            } else {
                adrRelasi precR = first(LR);
                while (next(precR) != R) {
                    precR = next(precR);
                }
                deleteAfterRelasi(LR, precR, R);
            }

            //hapus buku
            if (banyakPenulis(LR, B) == 0){
                if (B == first(LB)) {
                    deleteFirstB(LB, B);
                } else if (next(B) == NULL) {
                    deleteLastB(LB, B);
                } else {
                    adrBuku precB = first(LB);
                    while (next(precB) != B) {
                        precB = next(precB);
                    }
                    deleteAfterB(LB, precB, B);
                }
            }


            //mengurangi total buku yang ditulis oleh penulis
            info(P).totalBuku -= 1;
            cout << "Data Buku Berhasil Dihapus." << endl;
            cout << "==================================================================" << endl;
        } else {
            cout << "Data Buku Tidak Dihapus." << endl;
            cout << "==================================================================" << endl;
        }
        cout << "Tekan Enter untuk kembali.";
        cin.ignore();
        cin.get();
        menuHapusDataBuku(LP, LB, LR);
    } else {
        if (opsi == "1"){
            cout << "Buku Tidak Ditemukan pada Penulis dengan ID " << ID << "." << endl;
        } else {
            cout << "Buku Tidak Ditemukan pada Penulis dengan Nama " << nama << endl;
        }
        cout << "==================================================================" << endl;
        cout << "Tekan Enter untuk kembali.";
        cin.ignore();
        cin.get();
        menuHapusDataBuku(LP, LB, LR);
    }
}

void showPBHapus(listPenulis LP, listBuku LB, listRelasi LR, adrPenulis P){
    system("CLS");
    adrRelasi R;
    adrBuku B;
    cout << "Masukkan '0' untuk Kembali" << endl;
    cout << "==================================================================" << endl;
    cout << "                  Data Buku Berserta Penulisnya                   " << endl;
    cout << "==================================================================" << endl;
    cout << "ID Penulis     : ";
    cout << info(P).idPenulis << endl;
    cout << "Nama           : ";
    cout << info(P).nama << endl;

    R = first(LR);
    if (R != NULL){
        while (R != NULL){
            if (infoRP(R) == P) {
                B = infoRB(R);
                cout << "------------------------------------------------------------------" << endl;
                cout << "ID Buku        : " << info(B).idBuku << endl;
                cout << "Judul Buku     : " << info(B).judul << endl;
                cout << "Penerbit       : ";
                if (info(B).penerbit == "null"){
                    cout << "-" << endl;
                } else {
                    cout << info(B).penerbit << endl;
                }
                cout << "Tahun Terbit   : " << info(B).tahunTerbit << endl;
                cout << "Jumlah Halaman : " << info(B).jumlahHalaman << endl;
                cout << "Total Penjualan: " << info(B).totalPenjualan << endl;
            }
            R = next(R);
        }
    } else {
        cout << "------------------------------------------------------------------" << endl;
        cout << "Tidak Ada." << endl;
    }
    cout << "==================================================================" << endl;
}

void deleteFirstRelasi(listRelasi &LR, adrRelasi &R){
    if (first(LR) != NULL) {
        R = first(LR);
        first(LR) = next(R);
        next(R) = NULL;
        infoRP(R) = NULL;
        infoRB(R) = NULL;
        delete R;
        R = NULL;
    } else {
        R = NULL;
    }
}

void deleteLastRelasi(listRelasi &LR, adrRelasi &R){
    adrRelasi Q;
    if (first(LR) != NULL) {
        if (next(first(LR)) != NULL){
            Q = first(LR);
            while (next(next(Q)) != NULL) {
                Q = next(Q);
            }
            R = next(Q);
            next(Q) = NULL;

            infoRP(R) = NULL;
            infoRB(R) = NULL;
            delete R;
            R = NULL;
        } else {
            R = first(LR);
            first(LR) = NULL;
        }
    } else {
        R = NULL;
    }
}

void deleteAfterRelasi(listRelasi &LR, adrRelasi prec, adrRelasi &R){
    if (next(prec) != NULL) {
        R = next(prec);
        next(prec) = next(R);
        infoRP(R) = NULL;
        infoRB(R) = NULL;
        next(R) = NULL;
        delete R;
        R = NULL;
    } else {
        R = NULL;
    }
}

void deleteFirstB(listBuku &LB, adrBuku &B){
    if (first(LB) != NULL) {
        B = first(LB);
        first(LB) = next(B);
        next(B) = NULL;
        delete B;
        B = NULL;
    } else {
        B = NULL;
    }
}

void deleteLastB(listBuku &LB, adrBuku &B){
    adrBuku Q;
    if (first(LB) != NULL) {
        if (next(first(LB)) != NULL){
            Q = first(LB);
            while (next(next(Q)) != NULL){
                Q = next(Q);
            }
            B = next(Q);
            next(Q) = NULL;
            delete B;
            B = NULL;
        } else {
            B = first(LB);
            first(LB) = NULL;
        }
    } else {
        B = NULL;
    }
}

void deleteAfterB(listBuku &LB, adrBuku prec, adrBuku &B){
    if (next(prec) != NULL) {
        B = next(prec);
        next(prec) = next(B);
        next(B) = NULL;
        delete B;
        B = NULL;
    } else {
        B = NULL;
    }
}

adrRelasi cariRelasi(listRelasi LR, adrPenulis P, adrBuku B){
    adrRelasi R;
    R = first(LR);
    while (R != NULL){
        if (infoRB(R) == B && infoRP(R) == P){
            return R;
        }
        R = next(R);
    }
    return NULL;
}

//Menghitung total penjualan/ banyak buku pada tahun x
//MENU 10 Hitung Total Penjualan Buku pada Tahun Tertentu
void totalPenjualanTahun(listPenulis &LP, listBuku &LB, listRelasi &LR) {
    system("CLS");
    int tahun;
    cout << "================================================" << endl;
    cout << "          Hitung Total Penjualan Buku           " << endl;
    cout << "================================================" << endl;
    cout << "Tahun: ";
    cin >> tahun;
    cout << "------------------------------------------------" << endl;

    int total = 0;
    adrRelasi R = first(LR);

    while (R != NULL) {
        // Ambil informasi buku saat ini
        string idBuku = info(infoRB(R)).idBuku;
        adrRelasi temp = first(LR);
        bool duplicate = false;

        // Cek apakah ada relasi sebelumnya yang memiliki ID buku yang sama
        while (temp != R) {
            if (info(infoRB(temp)).idBuku == idBuku) {
                duplicate = true;
            }
            temp = next(temp);
        }

        // Jika bukan duplikat dan tahun sesuai, proses
        if (!duplicate && info(infoRB(R)).tahunTerbit == tahun) {
            cout << "  -> ID Buku        : " << idBuku << endl;
            cout << "     Judul          : " << info(infoRB(R)).judul << endl;
            cout << "     Total Penjualan: " << info(infoRB(R)).totalPenjualan << endl;
            total += info(infoRB(R)).totalPenjualan;
        }
        R = next(R);
    }
    cout << "------------------------------------------------" << endl;
    cout << "Total Penjualan Buku pada Tahun " << tahun << ": " << total << endl;
    cout << "================================================" << endl;
    cout << "Tekan Enter untuk Kembali.";
    cin.ignore();
    cin.get();
    menuUtama(LP, LB, LR);
}

