/* --------------------------------------------------------------------------------------------- */
/* File Program : PTR5.CPP */
/* Deskripsi : pointer ke type dasar, mendeklarasikan & alokasi variabel dinamik */
/* --------------------------------------------------------------------------------------------- */
#include <stdlib.h> // Memanggil pustaka untuk fungsi malloc.
#include <stdio.h> // Memanggil pustaka standar I/O untuk printf.
int main() // Titik awal eksekusi program.
{
    /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    int i = 5, j; // Mendeklarasikan i dengan nilai awal 5 dan j tanpa inisialisasi.
    char c = 'X'; // Mendeklarasikan karakter c dengan nilai 'X'.
    int *Ptri = (int *) malloc(4); // Mengalokasikan 4 byte memori dinamis lalu disimpan ke pointer int Ptri.
    int *Ptrj = (int *) malloc(sizeof(int)); // Mengalokasikan memori sebesar ukuran int untuk Ptrj.
    float *fx = (float *) malloc(sizeof(float)); // Mengalokasikan memori sebesar ukuran float untuk fx.
    int A[5]; // Mendeklarasikan array int A berukuran 5 elemen.
    float f = 7.23; // Mendeklarasikan float f dengan nilai 7.23.
    /* program */
    *Ptri = 8; // Mengisi nilai pada memori yang ditunjuk Ptri dengan 8.
    *Ptrj = 0; // Mengisi nilai pada memori yang ditunjuk Ptrj dengan 0.
    *fx = 3; // Mengisi nilai pada memori yang ditunjuk fx dengan 3.
    printf("Alamat i = %x \n", &i); // Menampilkan alamat memori variabel i.
    printf("Nilai i = %d \n", i); // Menampilkan nilai i.
    printf("Ukuran int = %d byte\n\n", sizeof(int)); // Menampilkan ukuran tipe int.
    printf("Alamat j = %x \n", &j); // Menampilkan alamat memori variabel j.
    printf("Nilai j = %d \n", j); // Menampilkan nilai j.
    printf("Alamat c = %x \n", &c); // Menampilkan alamat memori variabel c.
    printf("Nilai c = %c \n", c); // Menampilkan nilai karakter c.
    printf("Ukuran char = %d byte\n\n", sizeof(char)); // Menampilkan ukuran tipe char.
    printf("Alamat Ptri = %x \n", &Ptri); // Menampilkan alamat variabel pointer Ptri.
    printf("Isi var Ptri = %x \n", Ptri); // Menampilkan isi Ptri (alamat memori yang ditunjuk).
    printf("Nilai yang ditunjuk oleh Ptri = %d \n", *Ptri); // Menampilkan nilai pada alamat yang ditunjuk Ptri.
    printf("Ukuran pointer int = %d byte\n\n", sizeof(int *)); // Menampilkan ukuran tipe pointer int.
    printf("Alamat Ptrj = %x \n", &Ptrj); // Menampilkan alamat variabel pointer Ptrj.
    printf("Isi var Ptrj = %x \n", Ptrj); // Menampilkan isi Ptrj (alamat memori yang ditunjuk).
    printf("Nilai yang ditunjuk oleh Ptrj = %d \n", *Ptrj); // Menampilkan nilai pada alamat yang ditunjuk Ptrj.
    Ptrj = Ptri; // Membuat Ptrj menunjuk ke alamat yang sama seperti Ptri.
    printf("Isi var Ptrj sekarang = %x \n", Ptrj); // Menampilkan isi Ptrj setelah reassignment.
    printf("Nilai yang ditunjuk oleh Ptrj sekarang = %d \n", *Ptrj); // Menampilkan nilai yang kini ditunjuk Ptrj.
    printf("Alamat A = %x \n", &A); // Menampilkan alamat dasar array A.
    printf("Isi var A = %x \n", A[0]); // Menampilkan nilai elemen pertama array A.
    printf("Ukuran array A = %d byte\n\n", sizeof(A)); // Menampilkan total ukuran array A.
    printf("Alamat f = %x \n", &f); // Menampilkan alamat memori variabel f.
    printf("Nilai f = %f \n", f); // Menampilkan nilai f.
    printf("Ukuran float = %d byte\n\n", sizeof(float)); // Menampilkan ukuran tipe float.
    return 0; // Mengakhiri program dengan status sukses.
}
