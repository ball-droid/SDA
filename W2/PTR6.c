/* ----------------------------------------------------- */
/* File Program : PTR6.CPP */
/* Deskripsi : pointer yang menunjuk ke array */
/* ---------------------------------------------------- */

#include <stdio.h> // Memanggil pustaka standar I/O untuk printf.
int main() // Titik awal eksekusi program.
{
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    static int tgl_lahir[] = {18, 6, 1989}; // Membuat array statis berisi tanggal, bulan, dan tahun lahir.
    int *ptgl; // Mendeklarasikan pointer ke int bernama ptgl.
    ptgl = tgl_lahir; // Pointer ptgl diisi alamat elemen pertama array tgl_lahir.
    printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl); // Menampilkan nilai elemen pertama array lewat pointer.
    printf("Nilai dari tgl_lahir[0] = %d\n", tgl_lahir[0]); // Menampilkan elemen pertama array secara langsung.
    return 0; // Mengakhiri program dengan status sukses.
}
/* STUDI KASUS : */
/* Eksekusi dan pahami maksud program ini (tulis tujuan program ini) */
/* Modifikasi */
