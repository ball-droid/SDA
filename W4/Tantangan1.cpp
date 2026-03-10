/*------------------------------------------------------------*/
/* File : PTR21_modular.cpp */
/* Deskripsi : Contoh linked list sederhana (versi modular)   */
/* Catatan : membuat node lalu insert di depan list           */
/*------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan makro agar mempermudah penulisan dan akses terhadap atribut struct
#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

// Mendefinisikan tipe data yang akan digunakan
typedef int infotype;
typedef struct tElmtlist *address; // address merupakan pointer ke struktur node

// Mendefinisikan struktur untuk node pada linked list
typedef struct tElmtlist {
    infotype info; // Berfungsi untuk menyimpan data atau nilainya
    address next;  // Pointer yang digunakan untuk menunjuk ke node selanjutnya
} ElmtList;


/*------------------------------------------------*/
// Fungsi yang bertugas untuk mengalokasikan memori bagi node baru          
/*------------------------------------------------*/
address Alokasi(infotype X){
    address P;

    // Memesan lokasi di memori menggunakan malloc dengan ukuran dari ElmtList
    P = (address) malloc(sizeof(ElmtList));

    // Memastikan bahwa memori berhasil dialokasikan (P tidak sama dengan NULL)
    if(P != Nil){
        info(P) = X;   // Memasukkan nilai X ke dalam node
        next(P) = Nil; // Pointer next diatur menjadi NULL karena node belum diposisikan
    }

    return P; // Mengembalikan pointer dari node yang sudah dibuat
}


/*------------------------------------------------*/
// Fungsi untuk menyisipkan node di posisi paling awal dari list
/*------------------------------------------------*/
void InsertFirst(address *First, address P){

    // Pointer next dari node baru dihubungkan ke awal list sebelumnya
    next(P) = *First;

    // Head (First) kemudian dipindahkan agar menunjuk ke node yang baru
    *First = P;
}


/*------------------------------------------------*/
// Fungsi ini bertujuan untuk mencetak elemen ke-3 pada list     
/*------------------------------------------------*/
void PrintElemenKetiga(address First){

    // Melangkah mundur menuju node ketiga dengan memanggil next sebanyak dua kali
    printf("%d\n", info(next(next(First))));
}


/*------------------------------------------------*/
// Bagian utama dari berjalannya program      
/*------------------------------------------------*/
int main(){

    address First;
    address P;

    // Memastikan list berada dalam keadaan kosong terlebih dahulu
    First = Nil;

    // Membuat node berisi angka 10, lalu menempatkannya di awal list
    P = Alokasi(10);
    InsertFirst(&First, P);

    // Membuat node berisi angka 20, lalu menempatkannya di awal list
    P = Alokasi(20);
    InsertFirst(&First, P);

    // Membuat node berisi angka 30, lalu menempatkannya di awal list
    P = Alokasi(30);
    InsertFirst(&First, P);

    // Melakukan pengecekan keluaran untuk elemen ke-3
    PrintElemenKetiga(First);

    return 0;
}