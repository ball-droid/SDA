/* ----------------------------------------------------------- */
/* File Program : PTR7.CPP */
/* (Pointer dan String bagian ke-1) */
/* Deskripsi : pointer yang menunjuk ke data string */
/* ---------------------------------------------------------- */
#include <stdio.h> // Memanggil pustaka standar I/O untuk puts.
int main() // Titik awal eksekusi program.
{
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    char *pkota = "BANDUNG"; // Pointer char pkota menunjuk ke string literal "BANDUNG".
    puts(pkota); // Menampilkan string yang ditunjuk pkota ke layar.
    return 0; // Mengakhiri program dengan status sukses.
}
/* STUDI KASUS : */
/* Apa perbedaan deklarasi variabel char *pkota='BANDUNG'; dengan char kota[]='BANDUNG' ?
*/
