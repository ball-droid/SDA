/* --------------------------------------------------------- */
/* File Program : PTR2.CPP */
/* Contoh pemakaian pointer yang salah */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */
#include <stdio.h> // Memanggil pustaka standar I/O untuk printf.
int main() // Titik awal eksekusi program.
{
    float *pu; // Pointer pu dideklarasikan sebagai pointer ke float.
    float nu; // Variabel nu bertipe float.
    int u = 1234; // Variabel u bertipe int dan diinisialisasi 1234.
    pu = &u; // Contoh yang salah: alamat int dimasukkan ke pointer float.
    nu = *pu; // Membaca data lewat pu (hasilnya tidak valid secara konsep tipe data).
    printf("u = %d\n", u); // Menampilkan nilai asli variabel u.
    printf("nu = %f\n", nu); // Menampilkan nilai nu hasil pembacaan pointer yang salah tipe.
    return 0; // Mengakhiri program dengan status sukses.
    /* STUDI KASUS : */
    /* - Eksekusi file program tersebut dan pahami maksud program ini */
    /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */

    /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
}
