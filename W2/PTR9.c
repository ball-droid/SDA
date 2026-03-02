/* -------------------------------------------------- */
/* File Program : PTR9.CPP */
/* Deskripsi : pointer yang menunjuk pointer */
/* -------------------------------------------------- */
#include <stdio.h> // Memanggil pustaka standar I/O untuk printf.
int main() // Titik awal eksekusi program.
{
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    int var_x = 273; // Mendeklarasikan variabel integer var_x dengan nilai awal 273.
    int *ptr1; // ptr1 adalah pointer yang menunjuk ke data bertipe integer.
    int **ptr2; // ptr2 adalah pointer yang menunjuk ke pointer integer.
    ptr1 = &var_x; // ptr1 menyimpan alamat var_x.
    ptr2 = &ptr1; // ptr2 menyimpan alamat ptr1.
    /* Mengakses nilai var_x melalui ptr1 dan ptr2 */
    printf("Nilai var_x = %d\n", *ptr1); // Menampilkan nilai var_x melalui dereference ptr1.
    printf("Nilai var_x = %d\n", **ptr2); // Menampilkan nilai var_x melalui dereference bertingkat ptr2.
    return 0; // Mengakhiri program dengan status sukses.
}
/* STUDI KASUS : */
/* Eksekusi dan pahami maksud program ini dan */
/* komentari setiap baris programnya (mulai dari baris ptr1= &var_x; ) */
