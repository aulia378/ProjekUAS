#include "header.h"             // Berisi prototipe dan fungsi yang diperlukan
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    Alat alat[100];
    Pinjaman pinjaman[100];
    int jumlahAlat = 0, jumlahPinjaman = 0;
    char username[50], password[50], role[10];

    // Memeriksa jumlah argumen yang diberikan
    if (argc != 3) {
        printf("Penggunaan: %s <username> <password>\n", argv[0]);
        return 1; // Mengembalikan kode kesalahan
    }

    // Mengambil username dan password dari argumen command line
    strcpy(username, argv[1]);
    strcpy(password, argv[2]);

    // Melakukan login
    if (login(username, password, role) == 1) { // Jika pengguna memasukkan data yang benar
        // Memuat data alat dari file setelah login berhasil
        MuatAlat(alat, &jumlahAlat); // Fungsi ini membaca file yang berisi informasi alat.
        
        if (strcmp(role, "admin") == 0) {
            adminMenu(alat, &jumlahAlat);
        } else {
            userMenu(alat, jumlahAlat, pinjaman, &jumlahPinjaman, username);
        }
    } else {
        printf("Login gagal. Silakan coba lagi.\n");
    }

    return 0;
}
