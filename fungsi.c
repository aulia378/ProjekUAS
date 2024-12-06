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

void tambahAlat(Alat *alat, int *jumlahAlat) {          
    printf("\nMasukkan data alat baru:\n");

    alat[*jumlahAlat].id = *jumlahAlat + 1; // karena utk menandakan bahwa id bertambah.

    printf("Nama alat: ");
    scanf("%s", alat[*jumlahAlat].nama);

    printf("Merek alat: ");
    scanf("%s", alat[*jumlahAlat].merek);

    printf("Model alat: ");
    scanf("%s", alat[*jumlahAlat].model);

    printf("Tahun produksi: ");
    scanf("%u", &alat[*jumlahAlat].tahunProduksi);

    printf("Jumlah unit: ");
    scanf("%u", &alat[*jumlahAlat].jumlahUnit);

    alat[*jumlahAlat].jumlahTersedia = alat[*jumlahAlat].jumlahUnit;      // jumlahTersedia diatur sama dengan jumlahUnit, karena pada saat awal semua unit diasumsikan tersedia.  

    (*jumlahAlat)++;            // menandakan bahwa satu alat baru telah ditambahkan ke array 
    SimpanAlat(alat, *jumlahAlat);  // fungsi savealat untuk memperbahrui file alat.txt
    printf("Alat berhasil ditambahkan.\n");
}

// Simpan alat ke file
void SimpanAlat(Alat *alat, int jumlahAlat) {
    FILE *file = fopen("alat.txt", "w");
    for (int i = 0; i < jumlahAlat; i++) {             
        fprintf(file, "%u %s %s %s %u %u %u\n",
                alat[i].id, alat[i].nama, alat[i].merek, alat[i].model,
                alat[i].tahunProduksi, alat[i].jumlahUnit, alat[i].jumlahTersedia);
    }
    fclose(file);
}

// Fungsi untuk menghapus alat
void hapusAlat(Alat *alat, int *jumlahAlat, int id) {
    int found = 0; //menandakan alat belum ditemukan

    // Mencari alat berdasarkan ID
    for (int i = 0; i < *jumlahAlat; i++) {
        if (alat[i].id == id) {
            found = 1;

             // Untuk menghapus alat tersebut, elemen array setelah alat yang dihapus digeser satu posisi ke kiri menggunakan loop
            for (int j = i; j < *jumlahAlat - 1; j++) {
                alat[j] = alat[j + 1];
            }

            // Variabel *jumlahAlat dikurangi 1 untuk mencerminkan bahwa jumlah alat telah berkurang.
            (*jumlahAlat)--;

            printf("Alat dengan ID %d berhasil dihapus.\n",id); // Jika setelah iterasi alat dengan ID yang dimaksud tidak ditemukan (found tetap 0), maka fungsi mencetak pesan bahwa alat tidak ditemukan.
            break;
        }
    }
                                        
    if (!found) {
        printf("Alat dengan ID %d tidak ditemukan.\n", id);
    }
}

// Fungsi untuk mengedit alat
void editAlat(Alat *alat, int jumlahAlat, int id) {
    int found = 0;

    // Mencari alat berdasarkan ID
    for (int i = 0; i < jumlahAlat; i++) {
        if (alat[i].id == id) {
            found = 1; // Id alat yang ingin diedit ditemukan

            printf("Alat ditemukan: \n");
            //Menampilkan informasi alat yang akan diedit
            printf("ID: %u, Nama: %s, Merek: %s, Model: %s, Tahun: %u, Tersedia: %u\n",
                   alat[i].id, alat[i].nama, alat[i].merek, alat[i].model,
                   alat[i].tahunProduksi, alat[i].jumlahTersedia);

            int choice; // Menyimpan pilihan dari admin
            //Menampilkan menu pilihan kepada admin
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
    if (!found) { // Id alat yang ingin diedit tidak ditemukan
        printf("Alat dengan ID %d tidak ditemukan.\n", id);
    }
    
}
//Fungsi untuk menampilkan pilihan menu untuk user
void userMenu(Alat *alat, int jumlahAlat, Pinjaman *pinjaman, int *jumlahPinjaman, char *username) {
    int choice, id;
    
    do { // Tampilkan menu user
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
                //Menampilkan daftar pinjaman
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
    } while (choice != 5); // Loop berhenti ketika choise = 5 
}
// Fungsi untuk menampilkan riwayat pinjaman dari user
void lihatPinjaman(Alat *alat, int jumlahAlat, Pinjaman *pinjaman, int jumlahPinjaman, char *username) {
    printf("\nDaftar Pinjaman untuk pengguna %s:\n", username);
    int found = 0;      //Variabel found digunakan untuk melacak apakah pinjaman ditemukan untuk pengguna.

    for (int i = 0; i < jumlahPinjaman; i++) {              //Memeriksa data pinjaman
        if (strcmp(pinjaman[i].username, username) == 0) {   //membandingkan 2 string, jika cocok berarti pinjaman milik si user
            found = 1; //Data pinjaman utk user ditemukan

            // Mencari alat berdasarkan ID
            for (int j = 0; j < jumlahAlat; j++) { 
                if (alat[j].id == pinjaman[i].idAlat) { // Jika id alat yang diperiksa sama dengan id alat yg dicari
                    // Mencetak informasi tentang detail alat yang dipinjam
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
}
void MuatAkun(Akun *akun, int *jumlahAkun) {            //membaca data akun dari sebuah file, kemudian disimpan dalam array struct Akun.
    FILE *file = fopen("akun.txt", "r");        
    if (!file) {
        printf("File akun.txt tidak ditemukan.\n");
        exit(1);
    }
    *jumlahAkun = 0;            //jumlah akun utk menghitung jumlah akun yg berhasil dibaca
    while (fscanf(file, "%s %s %s", akun[*jumlahAkun].username, akun[*jumlahAkun].password, akun[*jumlahAkun].role) != EOF) { //Loop akan terus berjalan hingga fscanf mengembalikan nilai EOF
        (*jumlahAkun)++;          //Setiap kali satu baris data berhasil dibaca, nilai *jumlahAlat akan ditambah 1.        
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
    while (fscanf(file, "%u %s %s %s %u %u %u", //fscanf untuk membaca data dari file
                   &alat[*jumlahAlat].id, 
                   alat[*jumlahAlat].nama, 
                   alat[*jumlahAlat].merek, 
                   alat[*jumlahAlat].model,
                   &alat[*jumlahAlat].tahunProduksi, 
                   &alat[*jumlahAlat].jumlahUnit, 
                   &alat[*jumlahAlat].jumlahTersedia) != EOF) { //loop akan trs berjalan smpai EOF
        (*jumlahAlat)++;        //Setiap kali satu baris data berhasil dibaca, nilai *jumlahAlat akan ditambah 1.
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
        for (int i = 0; i < jumlahAlat; i++) {                  //jika tersedia,maka perulangan dijalankan
            printf("ID: %u, Nama: %s, Merek: %s, Model: %s, Tahun: %u, Tersedia: %u\n",
                   alat[i].id, alat[i].nama, alat[i].merek, alat[i].model,
                   alat[i].tahunProduksi, alat[i].jumlahTersedia);
        }
    }
}

// Fungsi untuk pinjam alat
void pinjamAlat(Alat *alat, int *jumlahAlat, Pinjaman *pinjaman, int *jumlahPinjaman, char *username, int id) {
    // Periksa apakah alat dengan ID tersebut tersedia
    for (int i = 0; i < *jumlahAlat; i++) {             
        if (alat[i].id == id) {    // Memeriksa apakah ID alat yang ada pada array alat sesuai dengan ID yang diberikan (parameter id)             
            if (alat[i].jumlahTersedia > 0) {   
                
                // Kurangi jumlah tersedia
                alat[i].jumlahTersedia--;   // Karena dipinjam maka jumlahtersedia akan dikurangi

                // Tambahkan ke daftar pinjaman
                pinjaman[*jumlahPinjaman].idAlat = id;
                strcpy(pinjaman[*jumlahPinjaman].username, username);
                (*jumlahPinjaman)++;        // Maka pinjaman akan bertambah

                printf("Peminjaman berhasil.\n");
                SimpanPinjaman(pinjaman, *jumlahPinjaman);  // Simpan data pinjaman
                return;
            } else {                 // Jika jumlahtersedia tidak sama dengan jumlahunit maka else akan berjalan
                printf("Alat tidak tersedia untuk dipinjam.\n");
                return;
            }
        }
    }
    printf("Alat dengan ID %d tidak ditemukan.\n", id);
}

//  Fungsi yang memuat data pinjaman
void DataPinjaman(Pinjaman *pinjaman, int *jumlahPinjaman) {
    FILE *file = fopen("pinjaman.txt", "r");        // Membuka file pinjaman.txt dengan mode 'r'
    if (file == NULL) {
        printf("Gagal membuka file untuk membaca.\n");
        return;
    }

    while (fscanf(file, "%d %s", &pinjaman[*jumlahPinjaman].idAlat, pinjaman[*jumlahPinjaman].username) != EOF) {
        (*jumlahPinjaman)++;         // Jika ada akan di tambahkan
    }

    fclose(file);
}

// Fungsi untuk menyimpan alat yg dipinjam ke dalam file pinjaman.txt
void SimpanPinjaman(Pinjaman *pinjaman, int jumlahPinjaman) {             
    FILE *file = fopen("pinjaman.txt", "w");   // Membuka file pinjaman.txt dengan mode 'w'
    if (file == NULL) {
        printf("Gagal membuka file untuk menulis.\n");
        return;
    }

    for (int i = 0; i < jumlahPinjaman; i++) {          // Jumlah Pinjaman akan bertambah di dalam file   
        fprintf(file, "%d %s\n", pinjaman[i].idAlat, pinjaman[i].username);
    }

    fclose(file);
}

// Fungsi untuk mengembalikan alat
void kembalikanAlat(Pinjaman *pinjaman, int *jumlahPinjaman, char *username, int id) {      
    for (int i = 0; i < *jumlahPinjaman; i++) {
        if (pinjaman[i].idAlat == id && strcmp(pinjaman[i].username, username) == 0) {
            // Kembalikan alat
            for (int j = i; j < *jumlahPinjaman - 1; j++) {
                pinjaman[j] = pinjaman[j + 1];
            }
            (*jumlahPinjaman)--;
            printf("Pengembalian alat berhasil.\n");
            return;
        }
    }
    printf("Peminjaman tidak ditemukan atau ID tidak cocok.\n");
}
