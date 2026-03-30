#ifndef liststatis_H
#define liststatis_H
#include "boolean.h"
#include <stdio.h>

#define MaxEl 100
#define Nil -1

#define Info(P) (L).A[P].info
#define Next(P) (L).A[P].next
#define First(L) (L).First

typedef int infotype;
typedef int address;

/* Elemen list */
typedef struct {
    infotype info;
    address next;
} ElmtList;

/* Representasi list statis dengan array */
typedef struct {
    ElmtList A[MaxEl];
    address First;
} List;

/*********** PROTOTYPE ****************/

/**** Predikat untuk test keadaan LIST ****/
boolean isListEmpty (List L);
/* Mengirim true jika List Kosong */

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List *L);
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */

/**** Manajemen Elemen (Simulasi Alokasi Array) ****/
address Alokasi (List *L, infotype X);
/* Mengirimkan indeks array yang kosong */
/* Jika berhasil maka info diisi X dan next = Nil */
/* Jika gagal mengirim Nil */

void DeAlokasi (List *L, address P);
/* Mengosongkan elemen array pada indeks P */

/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X);
/* Mencari apakah ada elemen dengan info = X */
/* Jika ada mengirimkan indeksnya */
/* Jika tidak mengirim Nil */

/**** PRIMITIF BERDASARKAN NILAI ****/

/**** Penambahan Elemen ****/
void InsVFirst (List *L, infotype X);
/* Menambahkan elemen pertama dengan nilai X */

void InsVLast (List *L, infotype X);
/* Menambahkan elemen terakhir dengan nilai X */

/**** Penghapusan Elemen ****/
void DelVFirst (List *L, infotype *X);
/* Menghapus elemen pertama */

void DelVLast (List *L, infotype *X);
/* Menghapus elemen terakhir */

/**** PRIMITIF BERDASARKAN ALAMAT (INDEX) ****/

/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List *L, address P);
/* Menambahkan elemen dengan indeks P sebagai elemen pertama */

void InsertAfter (List *L, address P, address Prec);
/* Menyisipkan elemen P setelah Prec */

void InsertLast (List *L, address P);
/* Menambahkan elemen P sebagai elemen terakhir */

/**** Penghapusan sebuah elemen ****/
void DelFirst (List *L, address *P);
/* Menghapus elemen pertama */

void DelP (List *L, infotype X);
/* Menghapus elemen dengan nilai X */

void DelLast (List *L, address *P);
/* Menghapus elemen terakhir */

void DelAfter (List *L, address *Pdel, address Prec);
/* Menghapus elemen setelah Prec */

/**** PROSES SEMUA ELEMEN LIST ****/
void PrintInfo (List L);
/* Menampilkan semua elemen list */

int NbElmt (List L);
/* Mengirimkan jumlah elemen list */

infotype Max (List L);
/* Mengirimkan nilai maksimum dalam list */

#endif