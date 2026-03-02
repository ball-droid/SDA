/* --------------------------------------------------------- */
/* File Program : PTR4.CPP */
/* Contoh pemakaian pointer */
/* --------------------------------------------------------- */
#include <stdio.h> // Memanggil pustaka standar I/O untuk printf.
int main() // Titik awal eksekusi program.
{
    int z, s, *pz, *ps; // z dan s bertipe int, pz dan ps adalah pointer ke int.
    z = 20; // Mengisi z dengan nilai 20.
    s = 30; // Mengisi s dengan nilai 30.
    pz = &z; // Menyimpan alamat z ke pointer pz.
    ps = &s; // Menyimpan alamat s ke pointer ps.
    *pz = *pz + *ps; // Menjumlahkan nilai z dan s lewat pointer, hasilnya disimpan ke z.

    printf("z = %d, s = %d\n", z , s); // Menampilkan nilai akhir z dan s.
    return 0; // Mengakhiri program dengan status sukses.
}
/* STUDI KASUS : */
/* - Eksekusi file program tersebut dan pahami maksud program ini */
/* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
/* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
