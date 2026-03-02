/* ----------------------------------------------------------------------------- */
/* File : PTR11.cpp */
/* Deskripsi : Pointer ke function (Function sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ----------------------------------------------------------------------------- */
#include <stdio.h> // Memanggil pustaka standar I/O untuk printf.
/* Kamus Global */
int N; /* ukuran efektif */
/* Prototype, fungsi yang diberikan sebagai parameter aktual */
int succ (int i); /* succ -> singkatan dari suksessor */
int pred (int i); /* pred -> singkatan dari predesessor */
/* Prosedur dengan parameter sebuah fungsi */
void geser (int *TT, int (*f) (int)); // Deklarasi prosedur geser dengan parameter pointer fungsi.
/* Program Utama */
int main() // Titik awal eksekusi program.
{
    /* kamus lokal */
    int MyTab[10]; // Mendeklarasikan array integer berukuran 10.
    int i; // Variabel indeks perulangan.
    /* program */
    N = 10; // Menentukan ukuran efektif data yang diproses.
    for (i = 0; i < N; i++) // Loop untuk mengisi array awal.
    {
        MyTab[i] = i; // Mengisi setiap elemen array dengan nilai indeksnya.
    }
    printf("Isi tabel dalam main sebelum pemanggilan : \n"); // Menampilkan judul isi array awal.
    for (i = 0; i < N; i++) // Loop untuk menampilkan isi array awal.
    {
        printf(" %d ", MyTab[i]); // Mencetak tiap elemen array.
    }
    printf("\n"); // Pindah baris.
    /* Pakai geser dengan parameter succ */
    printf("Geser dengan succ \n"); // Menandai proses geser menggunakan fungsi succ.
    geser (MyTab, succ); // Memanggil geser dengan fungsi succ (nilai ditambah 1).
    printf(" dalam main \n"); // Menampilkan keterangan konteks di main.
    for (i = 0; i < N; i++) // Loop untuk menampilkan hasil setelah succ.
    {
        printf(" %d ", MyTab[i]); // Mencetak tiap elemen array setelah proses succ.
    }
    printf("\n"); // Pindah baris.
    /* Pakai geser dengan parameter pred */
    printf("Geser dengan pred \n"); // Menandai proses geser menggunakan fungsi pred.
    geser (MyTab, pred); // Memanggil geser dengan fungsi pred (nilai dikurang 1).
    printf(" dalam main setelah aplikasi pred \n"); // Menampilkan keterangan hasil setelah pred.
    for (i = 0; i < N; i++) // Loop untuk menampilkan hasil setelah pred.
    {
        printf(" %d ", MyTab[i]); // Mencetak tiap elemen array setelah proses pred.
    }
    printf("\n"); // Pindah baris.
    return 0; // Mengakhiri program dengan status sukses.
}
/* Body Function */
int succ (int i) // Fungsi succ mengembalikan nilai suksesor dari i.
{
    return (i+1); // Mengembalikan i ditambah 1.
}
int pred (int i) // Fungsi pred mengembalikan nilai predesesor dari i.
{
    return (i-1); // Mengembalikan i dikurangi 1.
}
void geser (int *TT, int (*f) (int)) // Prosedur untuk mengubah isi array memakai fungsi f.
{
    int i; // Variabel indeks perulangan lokal.
    printf(" dalam geser \n"); // Menampilkan bahwa proses sedang berjalan di prosedur geser.
    for (i = 0; i < N; i++) // Loop untuk memproses semua elemen array.
    {
        TT[i] = f (TT[i]); // Mengubah elemen ke-i dengan menerapkan fungsi f.
        printf(" %d ", TT[i]); // Menampilkan elemen setelah diubah.
    }
    printf("\n"); // Pindah baris setelah semua elemen dicetak.
}
