#include <iostream>
using namespace std;

void menu(int pilih){
        cout << "-------------------\n";
        cout << "|  Playlist lagu   |\n";
        cout << "-------------------\n\n";
        cout << " 1. Tambah lagu"<<endl;
        cout << " 2. Cari lagu"<<endl;
        cout << " 3. Keluar"<<endl;
    }
void balikmenu(char balik){
    cout << "Kembali ke menu? (y/n) : ";
    cin >> balik;
    int pilih;
    while (balik == 'y'){
        menu(pilih);
    }
    
    
}
    struct lagu {
        string judul;
        string penyanyi;
        string genre;
        int tahun;
    } lagu[]

    
    
   
    

void tambah_lagu(string judul, string penyanyi, string genre, int tahun){
        int index_lagu;
        cout << "----Tambah Lagu----"<<endl;
        cout << "-------------------\n";
        cout << "Berapa lagu yang ingin ditambahkan? : ";
        cin >> index_lagu;

        for (int i = 0; i < index_lagu; i++){
            cout << "Masukan Judul Lagu\t: ";
            cin >> judul;
            cout << "Masuklan Penyanyi\t: ";
            cin >> penyanyi;
            cout << "Masukan Genre Lagu\t: ";
            cin >> genre;
            cout << "Masukan Tahun Lagu\t: ";
            cin >> tahun;

            lagu[i].judul = judul;
            lagu[i].penyanyi = penyanyi;
            lagu[i].genre = genre;
            lagu[i].tahun = tahun;
        }
        cout << "-------------------\n\n";
    }
    
void cari_lagu(string judul,string target){
    cout << "Masukan judul lagu yang dicari: ";
    cin >> target;
    for (int i = 0; i < index_lagu; i++){
        if (target == lagu[i].judul){
            cout << "Judul Lagu\t: " << lagu[i].judul << endl;
            cout << "Penyanyi\t: "  << lagu[i].penyanyi << endl;
            cout << "Genre\t: " << lagu[i].genre << endl;
            cout << "Tahun\t: " << lagu[i].tahun << endl;
            cout << "-------------------\n\n";
        }
    }
}
    
    

     

int main(){
    int pilih,pilihan;
    string judul, penyanyi, genre;
    int tahun;
    char balik;
    
    menu(pilih);
    cout << "pilih menu :";
    cin >> pilihan;
    cout<<endl;

    switch(pilihan){
        case 1:
            
            cout << "----Tambah Lagu----"<<endl;
            tambah_lagu(judul,penyanyi,genre,tahun);
            balikmenu(balik);
            break;
            
        case 2:
            cout << "Cari Lagu"<<endl;
            cari_lagu(judul);

            break;
        case 3:
            cout << "Keluar"<<endl;
            break;
        default:
            cout << "Menu tidak tersedia"<<endl;
            break;
    }
    // switch(pilihan){
    //     case 1:
    //         cout << "----Tambah Lagu----"<<endl;
    //         tambah_lagu();
    //         break;
    //     case 2:
    //         cout << "Cari Lagu"<<endl;
    //         break;
    //     case 3:
    //         cout << "Keluar"<<endl;
    //         break;
    //     default:
    //         cout << "Menu tidak tersedia"<<endl;
    //         break;
    // }

    // if (pilihan=1){
    //     tambah_lagu(judul,penyanyi,genre,tahun);
    // }
    // ifelse (pilihan=2){
    //     string judulcari;
    //     cout << "Masukan lagu yang ingin dicari : ";
    //     cin >> judulcari;
    // }
}

// case 1 
// MENU (playlist lagu)
// -pilihan menu (1. tambah lagu,2. cari lagu, 3. keluar)//disini pakai looping jadi input 1 lagu bisa input lagi jika mau... ada tanya ingin ke menu lagi nggak

// case 2
// jika pilihan 1 (tambah lagu)// masukan judul lagu, penyayi,genre,tahun
// jika pilihan 2 (cari lagu)// maka masukan judul lagu yang dicari (disini pakai searching bebas) bila tidak ditemukan maka munculkan "data tidak ada" ,tawaran balik ke menu,jangan lupa disorting dulu playlistnya.