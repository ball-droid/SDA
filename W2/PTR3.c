/* --------------------------------------------------------- */
/* File Program : PTR3.CPP */
/* Contoh pengubahan isi suatu variabel melalui pointer */
/* Tujuan : Menggunakan type data pointer dan manipulasinya */
/* --------------------------------------------------------- */
#include <stdio.h> // Memanggil pustaka standar I/O untuk printf.
int main() // Titik awal eksekusi program.
{
    float d, *pd; // d adalah variabel float, pd adalah pointer yang menunjuk ke float.
    d = 54.5; // Mengisi d dengan nilai awal 54.5.
    printf("Isi d semula = %g\n", d); // Menampilkan nilai d sebelum diubah lewat pointer.
    pd = &d; // Menyimpan alamat d ke pd, sehingga pd menunjuk ke d.
    *pd = *pd + 10; // Menambah nilai yang ditunjuk pd sebesar 10 (berarti nilai d ikut berubah).
    printf("Isi d kini = %g\n", d); // Menampilkan nilai d setelah dimodifikasi.
    return 0; // Mengakhiri program dengan status sukses.
    /* STUDI KASUS : */
    /* - Eksekusi file program tersebut dan pahami maksud program ini */
    /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
    /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
}
