/* ------------------------------------------------------------------------------------------------------------------ */
/* File : PTR13.cpp */
/* Deskripsi : Pointer ke function (Procedure dengan parameter input/output sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ------------------------------------------------------------------------------------------------------------------ */
#include <stdio.h> // Memanggil pustaka standar I/O untuk printf.
#include <stdlib.h> // Memanggil pustaka untuk fungsi malloc.
/* Kamus Global */
int N; /* ukuran efektif */
enum MyType // Enum untuk menandai tipe data tabel yang akan dicetak.
{
    bulat, karakter // bulat untuk int, karakter untuk char.
};

/* Prototype, fungsi yang diberikan sebagai parameter aktual */
void succI (int *i); /* suksessor, berupa procedure by ref */
void predI (int *i); /* predesessor */
void succC (char *c); /* suksessor, berupa procedure by ref */
void predC (char *c); /* predesessor */
/* print tabel yang belum ketahuan typenya */
void printtab (void *T, enum MyType Ty); // Deklarasi prosedur cetak tabel generik berdasarkan enum tipe.
/* Prosedur dengan parameter sebuah fungsi */
void geser (int *TT, void (*f) (void *)); // Deklarasi prosedur geser dengan parameter pointer ke prosedur.
/* Program Utama */
int main() // Titik awal eksekusi program.
{
    /* kamus lokal */
    void *MyTabInt; // Pointer generik untuk menampung alamat array integer dinamis.
    void *MyTabC; // Pointer generik untuk menampung alamat array karakter dinamis.
    int i; // Variabel indeks perulangan.
    /* program */
    N = 10; // Menentukan ukuran efektif array.
    MyTabInt = (int *) malloc (N * sizeof(int)); // Mengalokasikan memori untuk N elemen integer.
    MyTabC = (char *) malloc (N * sizeof(char)); // Mengalokasikan memori untuk N elemen karakter.
    *MyTabInt = 1; // Mengisi elemen pertama data pada MyTabInt dengan nilai 1.
    for (i = 0; i < N; i++) // Loop untuk inisialisasi isi array integer dan karakter.
    {
        *(MyTabInt + i) = i; // Mengisi elemen integer ke-i dengan nilai i.
        *(MyTabC + i) = 'Z'; // Mengisi elemen karakter ke-i dengan huruf 'Z'.
    }
    printf("Isi tabel dalam main sebelum pemanggilan : \n"); // Menampilkan judul kondisi awal data.
    printf(" Tabel integer \n"); // Menandai output untuk tabel integer.
    printtab ((int *) MyTabInt, 0); // Mencetak tabel integer dengan tipe enum bulat.
    printf(" Tabel charakter \n"); // Menandai output untuk tabel karakter.
    printtab ((char *) MyTabC, 1); // Mencetak tabel karakter dengan tipe enum karakter.
    printf("\n"); // Pindah baris.

    /* Pakai geser dengan parameter succ */
    printf("Geser dengan succ \n"); // Menandai proses geser dengan fungsi suksesor.
    geser ((int *) MyTabInt, (int *) succI); // Menggeser tabel integer menggunakan succI.
    geser ((char *) MyTabC, (char *) succC); // Menggeser tabel karakter menggunakan succC.
    printf(" dalam main \n"); // Menampilkan keterangan kembali ke main.
    printf(" Tabel integer \n"); // Menandai output tabel integer setelah succ.
    printtab ((int *) MyTabInt, 0); // Mencetak tabel integer setelah proses succ.
    printf(" Tabel charakter \n"); // Menandai output tabel karakter setelah succ.
    printtab ((char *) MyTabC, 1); // Mencetak tabel karakter setelah proses succ.
    printf("\n"); // Pindah baris.
    /* Pakai geser dengan parameter pred */
    printf("Geser dengan pred \n"); // Menandai proses geser dengan fungsi predesesor.
    geser ((int *) MyTabInt, (int *) predI); // Menggeser tabel integer menggunakan predI.
    geser ((char *) MyTabC, (char *) predC); // Menggeser tabel karakter menggunakan predC.
    printf(" dalam main \n"); // Menampilkan keterangan kembali ke main.
    printf(" Tabel integer \n"); // Menandai output tabel integer setelah pred.
    printtab ((int *) MyTabInt, 0); // Mencetak tabel integer setelah proses pred.
    printf(" Tabel charakter \n"); // Menandai output tabel karakter setelah pred.
    printtab ((char *) MyTabC, 1); // Mencetak tabel karakter setelah proses pred.
    printf("\n"); // Pindah baris.
    return 0; // Mengakhiri program dengan status sukses.
}
/* Body Function */
void succI (int *i) // Prosedur suksesor untuk data integer.
{
    *i = *i+1; // Nilai integer yang ditunjuk pointer ditambah 1.
}
void predI (int *i) // Prosedur predesesor untuk data integer.
{
    *i = *i-1; // Nilai integer yang ditunjuk pointer dikurangi 1.
}
void succC (char *c) // Prosedur suksesor untuk data karakter.
{
    *c = *c+1; // Nilai karakter yang ditunjuk pointer dinaikkan satu kode ASCII.
}
void predC (char *c) // Prosedur predesesor untuk data karakter.
{
    *c = *c-1; // Nilai karakter yang ditunjuk pointer diturunkan satu kode ASCII.
}
void geser (int *TT, void (*f) (void *)) // Prosedur umum untuk menerapkan fungsi f pada setiap elemen.
{
    int i; // Variabel indeks perulangan lokal.
    printf(" dalam geser \n"); // Menampilkan bahwa proses berada dalam prosedur geser.
    for (i = 0; i < N; i++) // Loop untuk memproses seluruh elemen data.
    {
        f (&TT[i]); // Memanggil prosedur f dengan alamat elemen ke-i.
        printf(" %d ", TT[i]); // Menampilkan nilai elemen setelah diproses.
    }
    printf("\n"); // Pindah baris setelah semua elemen ditampilkan.
}

void printtab (void *T, enum MyType Ty) // Prosedur mencetak isi tabel berdasarkan tipe Ty.
{
    int i; // Variabel indeks perulangan lokal.
    for (i = 0; i < N; i ++) // Loop untuk menampilkan tiap elemen tabel.
    {
        switch (Ty) // Memilih format cetak berdasarkan tipe data.
        {
            case bulat : printf("%d ", (int *) *(T + i)); break; // Menampilkan elemen sebagai integer.
            case karakter : printf("%c ", (char *) *(T + i)); break; // Menampilkan elemen sebagai karakter.
        }
    }
}
