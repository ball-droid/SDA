/* --------------------------------------------------------- */
/* File Program : PTR1.CPP */
/* Contoh pemakaian pointer */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */
#include <stdio.h> // Memanggil pustaka standar I/O untuk fungsi printf.
int main() // Titik awal eksekusi program.
{
    int x, y; // Mendeklarasikan dua variabel integer: x dan y.
    int *px; // Mendeklarasikan pointer ke integer bernama px.
    x = 87; // Mengisi variabel x dengan nilai 87.
    px = &x; // Menyimpan alamat memori x ke pointer px.
    y = *px; // Mengambil nilai yang ditunjuk px (nilai x) lalu simpan ke y.
    printf("Alamat x = %p\n", &x); // Menampilkan alamat memori variabel x.
    printf("Isi px = %d\n", x); // Menampilkan nilai x.
    printf("Nilai yang ditunjuk oleh px = %d\n", *px); // Menampilkan nilai pada alamat yang disimpan di px.
    printf("Nilai y = %d\n", y); // Menampilkan nilai y hasil salinan dari x lewat pointer.
    return 0; // Mengakhiri program dengan status sukses.
    /* STUDI KASUS : */
    /* - Eksekusi file program tersebut dan pahami maksud program ini */
    /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
    /* - Tambahkan pernyataan untuk menampilkan Alamat varabel y, eksekusi, dan perhatikan hasilnya */
    /* - Bila pernyataan px = &x; diganti dengan y = *px; ,apa yang terjadi? */
    /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
}
