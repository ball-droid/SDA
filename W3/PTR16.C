/* ---------------------------------------------------------------------------------------------------------------- */
/* File Program : PTR16.C                                                                                           */
/* Deskripsi    : Array of string : Pendefinisian dan pengaksesan. Perhatikanlah permasalahannya                    */
/* Jelaskan perbedaannya dengan program PTR15.cpp!                                                                 */
/* ---------------------------------------------------------------------------------------------------------------- */

#include <stdlib.h> // Mengimpor pustaka standar untuk perintah alokasi memori dinamis
#include <stdio.h>  // Mengimpor pustaka standar untuk operasi input (scanf) dan output (printf)

#define STRING char* // Mendefinisikan alias macro 'STRING' sebagai tipe data pointer ke char

int main() // Deklarasi fungsi utama yang menjadi titik awal eksekusi program
{
    /* Kamus Data */
    /* Definisi array yang elemennya string, statik dan sekaligus mengisi nilai string default */
    static STRING s[3] = {"the", "time", "is"}; // Mendeklarasikan dan mengisi array statis dari tipe 'STRING'

    /* Definisi array yang elemennya string, dinamik */
    STRING *TabStr; // Mendeklarasikan pointer ke elemen 'STRING' untuk array dinamis
    int i;          // Mendeklarasikan variabel perulangan berjenis integer

    /* Program Utama */
    for (i = 0; i < 3; i++) // Perulangan untuk mencetak isi dari array statis 's'
    {                       // Membuka blok blok perulangan cetak
        printf("%s\n", s[i]); // Mencetak elemen string ke-i dari array statis 's'
    }                       // Menutup blok perulangan cetak

    /* Alokasi TabStr sebanyak 3 elemen ke alokasi memori di heap */
    TabStr = (STRING *) malloc(3 * sizeof(STRING)); // Melakukan alokasi memori ukuran 3 'STRING' untuk array dinamis string utama

    for (i = 0; i < 3; i++) // Perulangan untuk alokasi karakter spesifik dan input nilai baru
    {                       // Membuka blok perulangan string dinamis
        /* Alokasi string yang merupakan per-elemen tabel (karakter stringnya) */
        *(TabStr + i) = (STRING) malloc(5 * sizeof(char)); // Memesan memori lima byte dalam setiap slot 'TabStr' untuk setiap teks

        printf("\nInput Str[%d], maksimum 5 karakter : ", i); // Menampilkan pemberitahuan dan batasan jumlah karakter maksimal
        scanf("%5s", *(TabStr + i));                   // Menerima masukan dari konsol dan menyimpannya di elemen 'TabStr' saat ini
        
        printf("\n Nilai Str[%d] : %5s\n ", i, *(TabStr + i)); // Menampilkan nilai yang sudah terekam di indeks 'TabStr' ke-i
    }                       // Akhir blok perulangan input string dinamis

    return 0;               // Memberitahu sistem kompilasi bahwa operasi berjalan dengan baik dan mengakhiri blok
}