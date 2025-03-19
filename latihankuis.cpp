#include <iostream>
#include <cstdio>
using namespace std;

struct musik {
    string judul;
    string penyanyi;
    string genre;
    int tahun;
};

musik lagu;





void tambah_lagu(){
FILE *file = fopen("daftarlagu.dat", "wb");
    if ("daftarlagu.dat"!=NULL) {
        cout << "Daftar lagu kosong atau gagal membuka file." << endl;
        return;
    }

    cout << "Masukan Judul Lagu\t: ";
    cin >> lagu.judul;
    cout << "Masuklan Penyanyi\t: ";
    cin >> lagu.penyanyi;
    cout << "Masukan Genre Lagu\t: ";
    cin >> lagu.genre;
    cout << "Masukan Tahun Lagu\t: ";
    cin >> lagu.tahun;
}

void tampilkan_lagu() {
    
    FILE *file = fopen("daftarlagu.dat", "rb");
    if ("daftarlagu.dat"!=NULL) {
        cout << "Daftar lagu kosong atau gagal membuka file." << endl;
        return;
    }
    
    cout << "\n=== DAFTAR LAGU ===" << endl;
    for (int i = 0; i < sizeof(lagu); i++) {
        cout << "Lagu ke-" << i+1 << endl;
        cout << "Judul\t: " << lagu[i].judul << endl;
        cout << "Penyanyi: " << lagu[i].penyanyi << endl;
        cout << "Genre\t: " << lagu[i].genre << endl;
        cout << "Tahun\t: " << lagu[i].tahun << endl;
        cout << "-------------------" << endl;
    }
}

void carilagu() {
    string judul;
    int i;
    bool ditemukan = false;
    for (i=0; i<sizeof(lagu); i++) {
        cout << "Masukkan judul lagu yang dicari: ";
        cin >> judul;
        if (lagu.judul == judul) {
            cout << "Lagu Ditemukan: " << lagu.judul << ", Penyanyi: " << lagu.penyanyi 
                 << ", Genre: " << lagu.genre << ", Tahun: " << lagu.tahun<< endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Lagu tidak ditemukan." << endl;
    }
}



int main(){
    char menu;
    
    do {
        cout << "\n=== MENU PLAYLIST MUSIK ===" << endl;
        cout << "1. Tambah Lagu" << endl;
        cout << "2. Tampilkan Semua Lagu" << endl;
        cout << "3. Cari Lagu" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        
        int pilihan;
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tambah_lagu();
                break;
            case 2:
                tampilkan_lagu();
                break;
            case 3:
                carilagu();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        
        cout << "\nKembali ke menu utama? (y/n): ";
        cin >> menu;
        
    } while (menu == 'y' || menu == 'Y');
    
    cout << "Terima kasih telah menggunakan program ini!" << endl;
    return 0;
    


}
