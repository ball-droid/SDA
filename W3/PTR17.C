/* --------------------------------------------------------------------------------------------------------- */
/* File Program : PTR17.C                                                                                    */
/* Deskripsi    : Array dengan def type:mengisi dg assignment, menulis                                       */
/* --------------------------------------------------------------------------------------------------------- */

#include <stdlib.h> // Header pustaka standar utilitas fungsi memori dinamis seperti fungsi tipe malloc
#include <stdio.h>  // Header pustaka standar program I/O seperti fungsi penggunaan prinf dan scanf

int main() // Berfungsi sebagai tubuh aplikasi (pusat eksekusi awal)
{
    /* Kamus Data Definisi tabel integer */
    typedef struct {  // Mendefinisikan tipe data bentukan (struct) yang baru dengan alias 'tabint'
        int *T;       // Mendeklarasikan field berupa sub-pointer ke int yang akan menyimpan elemen array utamanya
        int N;        // Mendeklarasikan field integer untuk menyimpan jumlah total elemen dari alokasi array
    } tabint;         // Penutup blok struktur struct dan penamaan alias struct 'tabint'

    tabint MyTab;     // Mendeklarasikan variabel struct bernama 'MyTab' bertipe data 'tabint'
    int i;            // Mendeklarasikan variabel i berjenis numerik untuk perulangan (iterasi)

    /* Program Utama */
    printf("Tentukan ukuran tabel, maks 10 = "); // Menampilkan instruksi ukuran jumlah elemen masukan array
    scanf("%d", &(MyTab.N)); // Membaca input pengguna angka skalar untuk mendefinisikan batas ukuran list 'MyTab.N'

    MyTab.T = (int *) malloc(MyTab.N * sizeof(int)); // Mengalokasikan array 'T' melalui batas 'N' ukuran size dasar integer
    
    /* Proses pengisian list dengan assignment terprogram */
    for (i = 0; i < MyTab.N; i++) // Menginisialisasi perulangan nilai indeks 'i' dari awal hingga batas atas elemennya
    {                             // Memulai blok siklus iterasi pemberian nilai element-to-element
        *(MyTab.T + i) = i;       // Meng-assign (memberi) poin data indeks list 'T' saat ini sesuai nilai 'i' itu sendiri
        
        printf("i = %d MyTab.T = %d \n", i, *(MyTab.T + i)); // Meng-print data parameter iterator dan item memori terekam
    };                            // Penutup blok perulangan instruksi array
    
    return 0;                     // Menyatakan fungsi program seleseai dieksekusi normal/lancar ke sistem operasi
}