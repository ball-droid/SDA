
/*---------------------------------------------------------------------------*/
/* File : PTR20.cpp */
/* Deskripsi : contoh pendefinisian struct dan pointer ke struct */
/* Dibuat oleh : Tim Dosen SDP */
/* Tanggal : 13-09-2001 */
/*---------------------------------------------------------------------------*/
#include<stdlib.h>
#include<stdio.h>
int main()
{
    // Bagian deklarasi variabel
    // Cara 3: Mendefinisikan tipe data baru (struct)
    typedef struct {
        float x;
        float y;
    } Point; // Menamai tipe data menjadi Point

    Point *P2; // Mendeklarasikan pointer P2 yang akan menunjuk ke tipe Point
    Point *P3 = (Point *) malloc (sizeof (Point)); // Melakukan alokasi memori untuk P3 menggunakan malloc

    // Memulai program utama
    // Cara 1: Mengakses elemen struct menggunakan pointer beserta tanda panah (->)
    printf("Titik P2, dengan P2->x dan P2->y : \n");
    P2 = (Point *) malloc (sizeof(Point)); // Mengalokasikan memori untuk P2 sebelum mengisikan nilainya
    P2->x = 9.12; // Mengisi nilai komponen x
    P2->y = 2.567; // Mengisi nilai komponen y
    printf("P2.x = %f \nP2.y = %f \n", P2->x, P2->y);

    // Cara 2: Menggunakan tanda kurung dan titik (.), serta memperhatikan prioritas operator
    (*P3).x = 0.5; // Mengisi nilai x untuk P3, yang mana hasilnya sama seperti P3->x
    (*P3).y = 10.5; // Mengisi nilai y untuk P3
    printf("P3.x = %f \nP3.y = %f \n", (*P3).x, (*P3).y);

    return 0;
}