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
