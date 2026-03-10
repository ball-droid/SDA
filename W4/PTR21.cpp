/*----------------------------------------------------------------------------*/
/* File : PTR21.cpp */
/* Deskripsi : contoh deklarasi list dan pemakaian makro */
/* Dibuat oleh : Tim Dosen SDP */
/* Tanggal : 13-09-2001 */
/*----------------------------------------------------------------------------*/
#include<stdlib.h>
#include<stdio.h>
// Mendefinisikan makro untuk mempermudah akses atribut tanpa harus menuliskan fungsi penunjuk struktur secara eksplisit
#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

// Mendefinisikan tipe data global untuk struktur elemen linked list
typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info; // Variabel ini berfungsi untuk menyimpan data
    address next; // Pointer ini berfungsi sebagai referensi untuk menunjuk ke node selanjutnya
} ElmtList;

// Program utama
int main()
{
    // Menyiapkan variabel pointer yang akan digunakan
    address First;
    address P, Q;

    // Tahap langkah awal program
    // Membuat sebuah list kosong dengan mengatur pointer First menjadi bernilai NULL (Nil)
    First = Nil;

    // Melakukan proses alokasi memori pada node yang baru, kemudian menyisipkannya pada letak pertama (InsertFirst)
    P = (address) malloc(sizeof (ElmtList));
    info(P) = 10; // Memberikan data node dengan nilai 10
    next(P) = Nil; // Karena hal ini adalah node perintis tunggal, referensi berikutnya dipastikan menunjuk ke baris penempatan Nil
    First = P; // Memperbarui pointer dari First agar merujuk ke elemen node P

    // Melakukan persiapan alokasi alur memori untuk menata struktur node Q, ditambah penempatan menuju posisi pertama
    Q = (address) malloc(sizeof (ElmtList));
    info(Q) = 20; // Mengeksekusi penugasan nilai angka 20 kepada pointer Q
    next(Q) = Nil;
    next(Q) = First; // Memanipulasi ikatan pada elemen dari node Q yang disambungkan ke letak keberadaan dari node P lalu First
    First = Q; // Proses sinkronisasi menggeser head list agar kembali menuju tahapan pointer letak susunan node Q

    // Menjalankan tahapan alokasi data memori ulang dari peranan subjek variabel P dalam alur posisi pertama
    P = (address) malloc(sizeof (ElmtList));
    info(P) = 30; // Melanjutkan pemrosesan nilai bernilai 30 
    next(P) = Nil;
    next(P) = First; // Perekatan sambungan koneksi susunan arah yang bermuara menuju susunan list terdahulu Q
    First = P; // Memperbarui peran kembali kedudukan head untuk menjadwalkan sasaran elemen ke posisi dari P

    // Menampilkan komponen informasi dari node di posisi nomor urutan ketiga (First->next->next) dengan output nilai 10   
    printf("%d \n", info(next(next(First))));

    return 0;
}