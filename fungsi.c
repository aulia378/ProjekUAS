#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"       //memanggil kembali protipe dan fungsi yg diperlukan

// Fungsi untuk login
int login(char *username, char *password, char *role) {
    FILE *file = fopen("akun.txt", "r");
    if (!file) {
        printf("File akun.txt tidak ditemukan.\n");
        return 1;
    }
    Akun akun;
    while (fscanf(file, "%s %s %s", akun.username, akun.password, akun.role) != EOF) {      //utk membaca apakah ada di dlm file
        if (strcmp(username, akun.username) == 0 && strcmp(password, akun.password) == 0) { //membadingkan dgn data di dlm file 
            strcpy(role, akun.role);        //jika cocok, maka strcpy akun.role di salin ke role
            fclose(file);
            return 1;   //close dan return 1 utk menunjukkan login berhasil.
        }
    }
    fclose(file);   //jika tdk ada cocok, file di tutup
    return 0;
}
void adminMenu(Alat *alat, int *jumlahAlat) {
    int choice, id;
    do {
        printf("\nMenu Admin:\n");
        printf("1. Tambah Alat\n");
        printf("2. Hapus Alat\n");
        printf("3. Edit Alat\n");   
        printf("4. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tambahAlat(alat, jumlahAlat);
                break;
            case 2:
                printf("Masukkan ID alat yang ingin dihapus: ");
                scanf("%d", &id);
                hapusAlat(alat, jumlahAlat, id);
                SimpanAlat(alat, *jumlahAlat);  // Simpan perubahan alat ke file
                break;
            case 3:
                printf("Masukkan ID alat yang ingin diedit: ");
                scanf("%d", &id);
                editAlat(alat, *jumlahAlat, id);
                SimpanAlat(alat, *jumlahAlat);  // Simpan perubahan alat ke file
                break;
            case 4:
                printf("Keluar dari menu admin.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");   //jika tdk valid disuruh pilih kembali
        }
    } while (choice != 4);
}

// Fungsi untuk mengedit alat
void editAlat(Alat *alat, int jumlahAlat, int id) {
    int found = 0;

    // Mencari alat berdasarkan ID
    for (int i = 0; i < jumlahAlat; i++) {
        if (alat[i].id == id) {
            found = 1;

            // Menampilkan informasi alat yang akan diedit
            printf("Alat ditemukan: \n");
            printf("ID: %u, Nama: %s, Merek: %s, Model: %s, Tahun: %u, Tersedia: %u\n",
                   alat[i].id, alat[i].nama, alat[i].merek, alat[i].model,
                   alat[i].tahunProduksi, alat[i].jumlahTersedia);

            // Memberikan pilihan untuk mengedit nama, merek, model, atau jumlah
            int choice;
            printf("Pilih data yang ingin diedit:\n");
            printf("1. Nama Alat\n");
            printf("2. Merek Alat\n");
            printf("3. Model Alat\n");
            printf("4. Tahun Produksi\n");
            printf("5. Jumlah Unit\n");
            printf("6. Jumlah Tersedia\n");
            printf("Pilihan: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Masukkan nama baru: ");
                    scanf("%s", alat[i].nama);
                    break;
                case 2:
                    printf("Masukkan merek baru: ");
                    scanf("%s", alat[i].merek);
                    break;
                case 3:
                    printf("Masukkan model baru: ");
                    scanf("%s", alat[i].model);
                    break;
                case 4:
                    printf("Masukkan tahun produksi baru: ");
                    scanf("%u", &alat[i].tahunProduksi);
                    break;
                case 5:
                    printf("Masukkan jumlah unit baru: ");
                    scanf("%u", &alat[i].jumlahUnit);
                    alat[i].jumlahTersedia = alat[i].jumlahUnit;  // Update jumlah tersedia
                    break;
                case 6:
                    printf("Masukkan jumlah tersedia baru: ");
                    scanf("%u", &alat[i].jumlahTersedia);
                    break;
                default:
                    printf("Pilihan tidak valid.\n");
                    break;
            }   
            printf("Alat berhasil diperbarui.\n");
            break;
        }
    }
    if (!found) {
        printf("Alat dengan ID %d tidak ditemukan.\n", id);
    }
    
}
void userMenu(Alat *alat, int jumlahAlat, Pinjaman *pinjaman, int *jumlahPinjaman, char *username) {
    int choice, id;
    
    do {
        printf("\nMenu User:\n");
        printf("1. Lihat Alat\n");
        printf("2. Pinjam Alat\n");
        printf("3. Lihat Pinjaman\n");
        printf("4. Kembalikan Alat\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Menampilkan daftar alat
                LihatAlat(alat, jumlahAlat);
                break;

            case 2:
                printf("Masukkan ID alat yang ingin dipinjam: ");
                scanf("%d", &id);
                pinjamAlat(alat, &jumlahAlat, pinjaman, jumlahPinjaman, username, id);
                break;

            case 3:
                lihatPinjaman(alat, jumlahAlat, pinjaman, *jumlahPinjaman, username);
                break;

            case 4:
                printf("Masukkan ID alat yang ingin dikembalikan: ");
                scanf("%d", &id);
                kembalikanAlat(pinjaman, jumlahPinjaman, username, id);
                break;

            case 5:
                printf("Keluar dari menu user.\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 5);          //jika bukan user 1-5 maka user akan disuruh memilih ulang. 
}

void lihatPinjaman(Alat *alat, int jumlahAlat, Pinjaman *pinjaman, int jumlahPinjaman, char *username) {
    printf("\nDaftar Pinjaman untuk pengguna %s:\n", username);
    int found = 0;      //Variabel found digunakan untuk melacak apakah pinjaman ditemukan untuk pengguna.

    for (int i = 0; i < jumlahPinjaman; i++) {              //Loop ini digunakan untuk memeriksa setiap entri dalam array pinjaman.
        if (strcmp(pinjaman[i].username, username) == 0) {   //membandingkan 2 string, jika cocok berarti pinjaman milik si user
            found = 1;

            // Mencari alat berdasarkan ID
            for (int j = 0; j < jumlahAlat; j++) {      //Loop ini mencari alat di array alat dengan ID yang sama seperti idAlat dalam data pinjaman.
                if (alat[j].id == pinjaman[i].idAlat) {
                    printf("ID: %u, Nama: %s, Merek: %s, Model: %s, Tahun: %u, Tersedia: %u\n",
                           alat[j].id, alat[j].nama, alat[j].merek, alat[j].model,
                           alat[j].tahunProduksi, alat[j].jumlahTersedia);
                    break; // Keluar dari loop setelah menemukan alat
                }
            }
        }
    }

    if (!found) {
        printf("Tidak ada pinjaman yang ditemukan untuk pengguna %s.\n", username);
    }
void MuatAkun(Akun *akun, int *jumlahAkun) {            //membaca data akun dari sebuah file, kemudian disimpan dalam array struct Akun.
    FILE *file = fopen("akun.txt", "r");        
    if (!file) {
        printf("File akun.txt tidak ditemukan.\n");
        exit(1);
    }
    *jumlahAkun = 0;            //jumlah akun utk menghitung jumlah akun yg berhasil dibaca
    while (fscanf(file, "%s %s %s", akun[*jumlahAkun].username, akun[*jumlahAkun].password, akun[*jumlahAkun].role) != EOF) {
        (*jumlahAkun)++;                    
    }
    fclose(file);
}

void MuatAlat(Alat *alat, int *jumlahAlat) {        //utk membaca data ttg alat dari file alat.txt kemudian disimpan dlm array struck Alat.
    FILE *file = fopen("alat.txt", "r");
    if (!file) {
        printf("File alat.txt tidak ditemukan.\n");
        exit(1);
    }
    *jumlahAlat = 0;            //nilai ini utk dihitung jumlah alat yg berhasil dari alat.txt.
    
    // Membaca setiap baris alat dari file
    while (fscanf(file, "%u %s %s %s %u %u %u", 
                   &alat[*jumlahAlat].id, 
                   alat[*jumlahAlat].nama, 
                   alat[*jumlahAlat].merek, 
                   alat[*jumlahAlat].model,
                   &alat[*jumlahAlat].tahunProduksi, 
                   &alat[*jumlahAlat].jumlahUnit, 
                   &alat[*jumlahAlat].jumlahTersedia) != EOF) {
        (*jumlahAlat)++;        //setiap berhasil dibaca 1 baris nilai 1 alat disimpan 1 data ke dlm array JumlahAlat.
    }
    fclose(file);
    if (*jumlahAlat == 0) {         
        printf("Tidak ada alat yang ditemukan dalam file alat.txt.\n");
    }
}
void LihatAlat(Alat *alat, int jumlahAlat) {         //fungsi ini utk menampilkan alat yg telah dibaca dari file dan disimpan dlm array struct Alat.
    printf("\nDaftar Alat Laboratorium:\n");
    if (jumlahAlat == 0) {
        printf("Tidak ada alat yang tersedia.\n");
    } else {
        for (int i = 0; i < jumlahAlat; i++) {                  //Menampilkan daftar alat
            printf("ID: %u, Nama: %s, Merek: %s, Model: %s, Tahun: %u, Tersedia: %u\n",
                   alat[i].id, alat[i].nama, alat[i].merek, alat[i].model,
                   alat[i].tahunProduksi, alat[i].jumlahTersedia);
        }
    }
}

void pinjamAlat(Alat *alat, int *jumlahAlat, Pinjaman *pinjaman, int *jumlahPinjaman, char *username, int id) {
    // Periksa apakah alat dengan ID tersebut tersedia
    for (int i = 0; i < *jumlahAlat; i++) {             //
        if (alat[i].id == id) {                 //
            if (alat[i].jumlahTersedia > 0) {           //Memeriksa apakah ID alat yang ada pada array alat sesuai dengan ID yang diberikan (parameter id).
                // Kurangi jumlah tersedia
                alat[i].jumlahTersedia--; //karena dipinjam maka jumlahtersedia akan dikurangi

                // Tambahkan ke daftar pinjaman
                pinjaman[*jumlahPinjaman].idAlat = id;
                strcpy(pinjaman[*jumlahPinjaman].username, username);
                (*jumlahPinjaman)++;        //maka pinjaman akan bertambah

                printf("Peminjaman berhasil.\n");
                SimpanPinjaman(pinjaman, *jumlahPinjaman); // Simpan data pinjaman
                return;
            } else {                    //jika jumlahtersedia != jumlahunit maka else akan berjalan
                printf("Alat tidak tersedia untuk dipinjam.\n");
                return;
            }
        }
    }
    printf("Alat dengan ID %d tidak ditemukan.\n", id);
}
// Memuat data pinjaman
void DataPinjaman(Pinjaman *pinjaman, int *jumlahPinjaman) {
    FILE *file = fopen("pinjaman.txt", "r");        //membuka file pinjaman.txt
    if (file == NULL) {
        printf("Gagal membuka file untuk membaca.\n");
        return;
    }

    while (fscanf(file, "%d %s", &pinjaman[*jumlahPinjaman].idAlat, pinjaman[*jumlahPinjaman].username) != EOF) {
        (*jumlahPinjaman)++;         //kalo ada akan di tambahkan
    }

    fclose(file);
}
void SimpanPinjaman(Pinjaman *pinjaman, int jumlahPinjaman) {             //utk menyimpan alat yg dipinjam ke dlm file pinjaman.txt
    FILE *file = fopen("pinjaman.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menulis.\n");
        return;
    }

    for (int i = 0; i < jumlahPinjaman; i++) {                           //Jumlah Pinjaman akan bertambah di dalam file   
        fprintf(file, "%d %s\n", pinjaman[i].idAlat, pinjaman[i].username);
    }

    fclose(file);
}
