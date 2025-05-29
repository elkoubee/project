#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk menyimpan data buku
struct Buku {
    string judul;
    string penulis;
    Buku* sebelumnya;
    Buku* selanjutnya;
};

// Pointer awal dan akhir linked list
Buku* kepala = nullptr;
Buku* ekor = nullptr;

// Fungsi untuk menambahkan buku dari depan
void tambahDariDepan(string judul_baru, string penulis_baru) {
    Buku* buku_baru = new Buku();
    buku_baru->judul = judul_baru;
    buku_baru->penulis = penulis_baru;
    buku_baru->sebelumnya = nullptr;
    buku_baru->selanjutnya = kepala;

    if (kepala != nullptr) {
        kepala->sebelumnya = buku_baru;
    } else {
        ekor = buku_baru;
    }

    kepala = buku_baru;
    cout << "Buku berhasil ditambahkan di depan.\n";
}

// Fungsi untuk menambahkan buku dari belakang
void tambahDariBelakang(string judul_baru, string penulis_baru) {
    Buku* buku_baru = new Buku();
    buku_baru->judul = judul_baru;
    buku_baru->penulis = penulis_baru;
    buku_baru->selanjutnya = nullptr;
    buku_baru->sebelumnya = ekor;

    if (ekor != nullptr) {
        ekor->selanjutnya = buku_baru;
    } else {
        kepala = buku_baru;
    }

    ekor = buku_baru;
    cout << "Buku berhasil ditambahkan di belakang.\n";
}

// Fungsi untuk menampilkan daftar buku
void tampilkanBuku() {
    if (kepala == nullptr) {
        cout << "Daftar buku kosong.\n";
        return;
    }

    Buku* sekarang = kepala;
    cout << "\n=== Daftar Buku ===\n";
    while (sekarang != nullptr) {
        cout << "Judul  : " << sekarang->judul << endl;
        cout << "Penulis: " << sekarang->penulis << endl;
        cout << "----------------------\n";
        sekarang = sekarang->selanjutnya;
    }
}

// Fungsi untuk menghapus buku berdasarkan judul
void hapusBuku(string judul_dicari) {
    if (kepala == nullptr) {
        cout << "Daftar buku kosong.\n";
        return;
    }

    Buku* sekarang = kepala;
    while (sekarang != nullptr) {
        if (sekarang->judul == judul_dicari) {
            if (sekarang->sebelumnya != nullptr) {
                sekarang->sebelumnya->selanjutnya = sekarang->selanjutnya;
            } else {
                kepala = sekarang->selanjutnya;
            }

            if (sekarang->selanjutnya != nullptr) {
                sekarang->selanjutnya->sebelumnya = sekarang->sebelumnya;
            } else {
                ekor = sekarang->sebelumnya;
            }

            delete sekarang;
            cout << "Buku dengan judul '" << judul_dicari << "' berhasil dihapus.\n";
            return;
        }
        sekarang = sekarang->selanjutnya;
    }

    cout << "Buku dengan judul '" << judul_dicari << "' tidak ditemukan.\n";
}

// Fungsi utama program
int main() {
    int pilihan;
    string judul, penulis;

    do {
        cout << "\n=== Menu Aplikasi Daftar Buku ===\n";
        cout << "1. Tambah Buku dari Depan\n";
        cout << "2. Tambah Buku dari Belakang\n";
        cout << "3. Hapus Buku berdasarkan Judul\n";
        cout << "4. Tampilkan Daftar Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        cin.ignore(); // Menghindari masalah input getline

        switch (pilihan) {
            case 1:
                cout << "Masukkan judul buku   : ";
                getline(cin, judul);
                cout << "Masukkan nama penulis : ";
                getline(cin, penulis);
                tambahDariDepan(judul, penulis);
                break;
            case 2:
                cout << "Masukkan judul buku   : ";
                getline(cin, judul);
                cout << "Masukkan nama penulis : ";
                getline(cin, penulis);
                tambahDariBelakang(judul, penulis);
                break;
            case 3:
                cout << "Masukkan judul buku yang ingin dihapus: ";
                getline(cin, judul);
                hapusBuku(judul);
                break;
            case 4:
                tampilkanBuku();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan aplikasi ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (pilihan != 5);

    return 0;
}
