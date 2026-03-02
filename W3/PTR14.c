/* ---------------------------------------------------------------------------------------------- */
/* File Program : PTR14.c                                                                         */
/* Deskripsi    : Array dinamis, dimana ukuran array ditentukan dari read keyboard                */
/* ---------------------------------------------------------------------------------------------- */

#include <stdlib.h> // Mengimpor pustaka standar untuk fungsi utilitas seperti malloc dan free
#include <stdio.h>  // Mengimpor pustaka standar untuk operasi input dan output

int main() // Deklarasi fungsi utama program
{
    /* Kamus Data (deklarasi, inisialisasi nilai variabel) */
    int *tab; // Deklarasi pointer ke integer yang akan digunakan sebagai array dinamis
    int N;    // Deklarasi variabel integer N untuk menampung ukuran array maksimal
    int i;    // Deklarasi variabel integer i untuk iterasi perulangan

    /* Program */
    printf("Contoh mengisi array dinamis berukuran 0..N : \n"); // Menampilkan teks pengantar ke layar
    printf("N = "); // Menampilkan prompt untuk meminta input nilai N
    scanf("%d", &N); // Membaca input nilai N dari pengguna melalui keyboard

    printf("Alokasi setelah mengetahui ukuran array \n"); // Menampilkan pesan informasi sebelum alokasi
    tab = (int *) malloc((N+1) * sizeof(int)); // Mengalokasikan memori dinamis untuk (N+1) elemen integer

    if (tab != NULL) // Mengecek apakah alokasi memori berhasil (tab tidak NULL)
    {
        for (i = 0; i <= N; i++) // Melakukan perulangan dari indeks 0 hingga N
        {
            printf("i=%d tab[i]=%d \n", i, *(tab + i)); // Menampilkan nilai dari memori yang dialokasikan (tanpa inisialisasi)
        };
        
        printf("Akhir program \n"); // Menampilkan pesan bahwa proses telah selesai
        
        /* Dealloc */
        free(tab); // Membebaskan kembali ruang memori yang telah dialokasikan secara dinamis
        return 0; // Mengembalikan nilai 0 sebagai tanda program berakhir normal
    }
    else // Blok kondisi jika alokasi memori gagal
    {
        printf("Alokasi gagal ... \n"); // Menampilkan pesan error alokasi gagal
        return 1; // Mengembalikan nilai 1 sebagai tanda program berakhir tidak normal
    }
    return 0; // Baris pengembalian tambahan (redudansi), mengembalikan nilai 0
}