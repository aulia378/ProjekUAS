#ifndef HEADER_H        //utk mencari apakah HEADER_H sudah pernah terdefinisi apa blm
#define HEADER_H        //definisi HEADER_H jika blm terdefinisi

// Struct untuk data alat laboratorium
typedef struct {      //membuat nama alias untuk tipe data tersebut tanpa perlu menulis struct setiap kali.
    unsigned int id; // unsigned utk menyimpan variabel baru
    char nama[50];
    char merek[50];
    char model[50];
    unsigned int tahunProduksi;
    unsigned int jumlahUnit;
    unsigned int jumlahTersedia;
} Alat;

// Struct untuk data akun
typedef struct {
    char username[50];
    char password[50];
    char role[10]; // "admin" atau "user"
} Akun;

// Struct untuk data peminjaman
typedef struct {
    int idAlat;          // ID alat yang dipinjam
    char username[50];   // Nama pengguna yang meminjam alat
} Pinjaman;

// Fungsi untuk login Admin
int login(char *username, char *password, char *role);
void adminMenu(Alat *alat, int *jumlahAlat);
void tambahAlat(Alat *alat, int *jumlahAlat);
void SimpanAlat(Alat *alat, int jumlahAlat);
void hapusAlat(Alat *alat, int *jumlahAlat, int id);
void tambahAlat(Alat *alat, int *jumlahAlat);
void editAlat(Alat *alat, int jumlahAlat, int id);

//fungsi utk login user
void userMenu(Alat *alat, int jumlahAlat, Pinjaman *pinjaman, int *jumlahPinjaman, char *username);
void lihatPinjaman(Alat *alat, int jumlahAlat, Pinjaman *pinjaman, int jumlahPinjaman, char *username);
void LihatAlat(Alat *alat, int jumlahAlat);
void pinjamAlat(Alat *alat, int *jumlahAlat, Pinjaman *pinjaman, int *jumlahPinjaman, char *username, int id);
void kembalikanAlat(Pinjaman *pinjaman, int *jumlahPinjaman, char *username, int id);
void MuatAkun(Akun *akun, int *jumlahAkun);                                                                // Fungsi untuk memuat data dari file
void MuatAlat(Alat *alat, int *jumlahAlat);
void DataPinjaman(Pinjaman *pinjaman, int *jumlahPinjaman);
void SimpanPinjaman(Pinjaman *pinjaman, int jumlahPinjaman);                                              // Fungsi untuk menyimpan data ke file

#endif
    
