#include "header.h"             //berisi protipe dan fungsi yg diperlukan
#include <stdio.h>
#include <string.h>

int main() {
    Alat alat[100];
    Pinjaman pinjaman[100];
    int jumlahAlat = 0, jumlahPinjaman = 0;
    char username[50], password[50], role[10];

    printf("Masukkan username: ");
    scanf("%s", username);
    printf("Masukkan password: ");
    scanf("%s", password);

    // Melakukan login
    if (login(username, password, role) == 1) {         //jika pengguna memasukkan data yg benar maka program login akan dijalankan
        // Memuat data alat dari file setelah login berhasil
        MuatAlat(alat, &jumlahAlat); //Fungsi ini membaca file yang berisi informasi alat.
        
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
