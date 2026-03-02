/* -------------------------------------------------------------- */
/* File : PTR10.cpp */
/* Deskripsi : Pointer dan fungsi/prosedur */
/* -------------------------------------------------------------- */
#include <stdio.h> // Memanggil pustaka standar I/O untuk printf dan getchar.
/* Prototype */
void f1(void); // Deklarasi fungsi f1.
void f2(void); // Deklarasi fungsi f2.
void f3(void); // Deklarasi fungsi f3.
void f4(void); // Deklarasi fungsi f4.
/* kamus Global */
#define true 1 // Mendefinisikan konstanta true sebagai 1.
#define false 0 // Mendefinisikan konstanta false sebagai 0.
int quit = false; // Variabel kontrol loop menu, awalnya false.
int main() // Titik awal eksekusi program.
{
    /* kamus lokal */
    /* Definisi tabel yang elemennya adalah pointer ke fungsi */
    /* Elemen tabel yang ke - i akan mengakses fungsi ke - i */
    /* Pilihan menjadi indeks tabel, dan dipakai untuk mengaktifkan fungsi */
    /* yang sesuai */
    void (*tab[4]) () = {f1, f2, f3, f4}; /* Pointer ke procedure */
    /* program */
    printf("Pointer to function : \n"); // Menampilkan judul contoh pointer ke fungsi.
    /* Menu */
    do // Memulai loop menu yang berjalan selama quit masih false.
    {
        printf("Pilih salah satu : \n"); // Menampilkan instruksi pilihan.
        printf("1. Buka file hanya untuk baca \n"); // Menampilkan opsi 1.
        printf("2. Tutup file \n"); // Menampilkan opsi 2.
        printf("3. Edit file \n"); // Menampilkan opsi 3.
        printf("4. Quit \n"); // Menampilkan opsi 4.
        tab[getchar() - '1'] () ; // Menjalankan fungsi dari tabel berdasarkan input angka 1-4.
        getchar(); /* untuk membuang return karakter */
    } while (!quit); // Loop berhenti ketika quit bernilai true.
    return 0; // Mengakhiri program dengan status sukses.
}
/* Body Function */
void f1 () // Definisi fungsi f1.
{
    printf("Ini fungsi f1 \n"); // Menampilkan bahwa f1 dipanggil.
}

void f2 () // Definisi fungsi f2.
{
    printf("Ini fungsi f2 \n"); // Menampilkan bahwa f2 dipanggil.
}
void f3 () // Definisi fungsi f3.
{
    printf("Ini fungsi f3 \n"); // Menampilkan bahwa f3 dipanggil.
}
void f4 () // Definisi fungsi f4.
{
    quit = true; // Mengubah variabel quit agar loop menu berhenti.
    printf("Quit ... \n"); // Menampilkan pesan keluar program.
}
