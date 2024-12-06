#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000    // Menentukan jumlah maksimum kata
#define MAX_WORD_LENGTH 100    // Menentukan jumlah maksimum panjang sebuah kata

// Fungsi untuk mengubah string menjadi huruf kecil
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Fungsi untuk menghapus tanda baca dari kata
void cleanWord(char *word) {
    int j = 0;
    for (int i = 0; word[i]; i++) {
        // Memeriksa apakah karakter adalah huruf
        if (isalpha(word[i])) {
            word[j++] = word[i];
        } 
         // Memeriksa tanda penghubung yang valid
        else if (word[i] == '-' && word[i + 1] != '\0' && isalpha(word[i + 1])) {
            word[j++] = word[i];
        } 
        // Memeriksa apostrof yang valid
        else if (word[i] == '\'') {
            // Menyimpan apostrof jika ada huruf di sebelahnya
            if ((isalpha(word[j - 1]) || (i < strlen(word) - 1 && isalpha(word[i + 1])))) {
                word[j++] = word[i];
            }
        }
        // Memeriksa titik yang valid
        else if (word[i] == '.') {
            // Menyimpan titik jika ada huruf di sebelahnya
            if ((isalpha(word[j - 1]) || (i < strlen(word) - 1 && isalpha(word[i + 1])))) {
                word[j++] = word[i];
            }
        }
    }
    word[j] = '\0'; // Menambahkan null terminator
}

int main() {
    FILE *inputFile, *outputFile;
    char line[1024];
    char *words[MAX_WORDS];
    int wordCount = 0;

    // Membuka file lirik.txt untuk dibaca
    inputFile = fopen("lirik.txt", "r");
    if (inputFile == NULL) {    // Jika file tidak ada maka program akan mencetak pesan kesalahan ke stderr 
        fprintf(stderr, "Error: Cannot open lirik.txt\n");
        return 1;
    }

    // Membaca judul dari file
    if (fgets(line, sizeof(line), inputFile) != NULL) {
        // Membuka file kosa-kata.word untuk ditulis
        outputFile = fopen("kosa-kata.word", "w");
        if (outputFile == NULL) {       // Jika file tidak ditemukan maka akan error 
            fprintf(stderr, "Error: Cannot create kosa-kata.word\n");
            fclose(inputFile);
            return 1;
        }
        fprintf(outputFile, "%s", line); // Menulis judul ke file output
    }

    // Membaca setiap baris lirik
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        char *kata = strtok(line, " \n");      // strtok digunakan untuk memecah kalimat menjadi kata
        while (kata != NULL) {
            char cleanedWord[MAX_WORD_LENGTH];
            strcpy(cleanedWord, kata);
            cleanWord(cleanedWord);
            toLowerCase(cleanedWord);

            // Memeriksa apakah kata sudah ada dalam daftar
            int exists = 0;
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(words[i], cleanedWord) == 0) {
                    exists = 1;
                    break;
                }       // Jika kata didalam words sama dengan yg didalam cleanedword maka if selanjutnya ga dieksekusi
            }

            // Jika kata belum ada, tambahkan ke daftar
            if (!exists && strlen(cleanedWord) > 0) {       // jika tidak exists dan string cleanedword bukan string kosong
                words[wordCount] = malloc(strlen(cleanedWord) + 1);  // Mengalokasikan memori yang cukup untuk menyimpan (cleanedWord)
                strcpy(words[wordCount], cleanedWord);
                wordCount++;
            }
            kata = strtok(NULL, " \n");   // Melanjutkan pemecahan string 
        }
    }

    // Menulis kosa-kata ke file output
    for (int i = 0; i < wordCount; i++) {
        fprintf(outputFile, "%s=\n", words[i]);
        free(words[i]);    // Menghapus memori yang dialokasikan
    }

    // Menutup file
    fclose(inputFile);
    fclose(outputFile);

    printf("Kosa-kata telah berhasil ditulis ke kosa-kata.word\n");
    return 0;
}
