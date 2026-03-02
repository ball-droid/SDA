/* ------------------------------------------------------------------------------------------------- */
/* File Program : PTR8b.CPP */
/* (Pointer dan String bagian ke-2) */
/* Deskripsi : menukar isi dua buah string yang ditunjuk oleh pointer */
/* PERHATIKAN! Bila dibandingkan dengan program PTR8A.cpp, maka dengan */
/* pointer, penyalinan isi array tidak perlu dilakukan. Sehingga bisa menghemat waktu eksekusi. */
/* ---------------------------------------------------------------------------------------------- */
#include <stdio.h> // Memanggil pustaka standar I/O untuk puts dan printf.
int main() // Titik awal eksekusi program.
{
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    char *nama1 = "DEWI SARTIKA"; // Pointer nama1 menunjuk ke string literal pertama.
    char *nama2 = "SULTAN HASANUDDIN"; // Pointer nama2 menunjuk ke string literal kedua.
    char *namaX; // Pointer bantu untuk menukar alamat string.
    puts("Nama semula : "); // Menampilkan judul kondisi awal.
    printf("Nama 1 --> %s\n", nama1); // Menampilkan string yang ditunjuk nama1 sebelum ditukar.
    printf("Nama 2 --> %s\n", nama2); // Menampilkan string yang ditunjuk nama2 sebelum ditukar.
    /* Penukaran string yang ditunjuk oleh pointer nama1 dan nama2 */
    namaX = nama1; // Menyimpan alamat string pada nama1 ke pointer bantu namaX.
    nama1 = nama2; // Memindahkan alamat string pada nama2 ke nama1.
    nama2 = namaX; // Memindahkan alamat string lama nama1 (di namaX) ke nama2.
    puts("Nama sekarang : "); // Menampilkan judul kondisi setelah pertukaran.
    printf("Nama 1 --> %s\n", nama1); // Menampilkan string yang ditunjuk nama1 setelah ditukar.
    printf("Nama 2 --> %s\n", nama2); // Menampilkan string yang ditunjuk nama2 setelah ditukar.
    return 0; // Mengakhiri program dengan status sukses.
}
