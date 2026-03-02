/* -------------------------------------------------------------------------------- */
/* File Program : PTR8a.CPP */
/* (Pointer dan String bagian ke-2) */
/* Deskripsi : menukar isi dua buah string TANPA pemakaian pointer */
/* ------------------------------------------------------------------------------- */
#include <stdio.h> // Memanggil pustaka standar I/O untuk puts dan printf.
#include <string.h> // Memanggil pustaka string untuk fungsi strcpy.
#define PANJANG 20 // Mendefinisikan panjang maksimum array karakter.
int main() // Titik awal eksekusi program.
{
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    char nama1[PANJANG] = "DEWI SARTIKA"; // Menyimpan string pertama dalam array karakter.
    char nama2[PANJANG] = "SULTAN HASANUDDIN"; // Menyimpan string kedua dalam array karakter.
    char namaX[PANJANG]; // Menyediakan variabel bantu untuk pertukaran isi string.
    puts("Nama semula : "); // Menampilkan judul kondisi awal.
    printf("Nama 1 --> %s\n", nama1); // Menampilkan isi nama1 sebelum ditukar.
    printf("Nama 2 --> %s\n", nama2); // Menampilkan isi nama2 sebelum ditukar.
    /* Pertukaran string */
    strcpy(namaX, nama1); // Menyalin isi nama1 ke variabel bantu namaX.
    strcpy(nama1, nama2); // Menyalin isi nama2 ke nama1.
    strcpy(nama2, namaX); // Menyalin isi namaX (nilai lama nama1) ke nama2.
    puts("Nama sekarang : "); // Menampilkan judul kondisi setelah pertukaran.
    printf("Nama 1 --> %s\n", nama1); // Menampilkan isi nama1 setelah ditukar.
    printf("Nama 2 --> %s\n", nama2); // Menampilkan isi nama2 setelah ditukar.
    return 0; // Mengakhiri program dengan status sukses.
}
