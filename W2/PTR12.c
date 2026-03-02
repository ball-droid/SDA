/* ------------------------------------------------------------------------------------------------------------------ */
/* File : PTR12.cpp */
/* Deskripsi : Pointer ke function (Procedure dengan parameter input/output sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ------------------------------------------------------------------------------------------------------------------ */
#include <stdio.h> // Memanggil pustaka standar I/O untuk printf.
/* Kamus Global */
int N; /* ukuran efektif */
/* Prototype, fungsi yang diberikan sebagai parameter aktual */
void succ (int *i); /* suksessor, berupa procedure by ref */
void pred (int *i); /* predesessor */
/* Prosedur dengan parameter sebuah fungsi */
void geser (int *TT, void (*f) (int *)); // Deklarasi prosedur geser dengan pointer ke prosedur.
/* Program Utama */

int main() // Titik awal eksekusi program.
{
    /* kamus lokal */
    int MyTab[10]; // Mendeklarasikan array integer berukuran 10.
    int i; // Variabel indeks perulangan.
    /* program */
    N = 10; // Menetapkan ukuran efektif data.
    for (i = 0; i < N; i++) // Loop untuk mengisi nilai awal array.
    {
        MyTab[i] = i; // Mengisi elemen array dengan nilai indeksnya.
    }
    printf("Isi tabel dalam main sebelum pemanggilan : \n"); // Menampilkan judul isi array awal.
    for (i = 0; i < N; i++) // Loop untuk mencetak isi awal array.
    {
        printf(" %d ", MyTab[i]); // Mencetak tiap elemen array.
    }
    printf("\n"); // Pindah baris.
    /* Pakai geser dengan parameter succ */
    printf("Geser dengan succ \n"); // Menandai proses geser menggunakan prosedur succ.
    geser (MyTab, succ); // Memanggil geser dengan prosedur succ.
    printf(" dalam main \n"); // Menampilkan keterangan hasil di main.
    for (i = 0; i < N; i++) // Loop untuk menampilkan hasil setelah succ.
    {
        printf(" %d ", MyTab[i]); // Mencetak elemen array setelah dimodifikasi.
    }
    printf("\n"); // Pindah baris.
    /* Pakai geser dengan parameter pred */
    printf("Geser dengan pred \n"); // Menandai proses geser menggunakan prosedur pred.
    geser (MyTab, pred); // Memanggil geser dengan prosedur pred.
    printf(" dalam main setelah aplikasi pred \n"); // Menampilkan keterangan hasil setelah pred.
    for (i = 0; i < N; i++) // Loop untuk menampilkan hasil setelah pred.
    {
        printf(" %d ", MyTab[i]); // Mencetak elemen array setelah proses pred.
    }
    printf("\n"); // Pindah baris.
    return 0; // Mengakhiri program dengan status sukses.
}
/* Body Function */
void succ (int *i) // Prosedur succ menerima alamat integer lalu menambah nilainya.
{
    *i = *i+1; // Nilai yang ditunjuk pointer i ditambah 1.
}
void pred (int *i) // Prosedur pred menerima alamat integer lalu mengurangi nilainya.
{
    *i = *i-1; // Nilai yang ditunjuk pointer i dikurangi 1.
}
void geser (int *TT, void (*f) (int *)) // Prosedur untuk memproses setiap elemen array dengan prosedur f.
{
    int i; // Variabel indeks perulangan lokal.
    printf(" dalam geser \n"); // Menampilkan bahwa proses berada di prosedur geser.
    for (i = 0; i < N; i++) // Loop untuk memproses semua elemen array.
    {
        f (&TT[i]); // Memanggil prosedur f dengan alamat elemen ke-i.
        printf(" %d ", TT[i]); // Menampilkan nilai elemen setelah diproses.
    }
    printf("\n"); // Pindah baris setelah semua elemen dicetak.
}
