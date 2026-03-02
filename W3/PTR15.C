/* ---------------------------------------------------------------------------------------------------------------- */
/* File Program : PTR15.C                                                                                           */
/* Deskripsi    : Array of string : Pendefinisian dan pengaksesan. Perhatikanlah permasalahannya                    */
/* ---------------------------------------------------------------------------------------------------------------- */

#include <stdlib.h> // Mengimpor pustaka standar C untuk fungsi alokasi memori seperti malloc
#include <stdio.h>  // Mengimpor pustaka input-output C untuk fungsi seperti printf dan scanf

int main() // Deklarasi blok fungsi utama program
{
    /* Kamus Data */
    /* Definisi array yang elemennya string, statik dan sekaligus mengisi */
    static char *s[3] = {"the", "time", "is"}; // Mendeklarasikan array statik berupa pointer ke char (string) sebanyak 3 elemen

    /* Definisi array yang elemennya string, dinamik */
    char **TabStr; // Mendeklarasikan pointer ke pointer (array of string dinamis)
    int i;         // Mendeklarasikan variabel i bertipe data integer untuk perulangan

    /* Program */
    for (i = 0; i < 3; i++) // Melakukan perulangan untuk mencetak isi array string s
    {
        printf("%s\n", s[i]); // Mencetak setiap elemen array statik s ke layar
    }

    /* Alokasi TabStr sebanyak 3 */
    TabStr = (char **) malloc(3 * sizeof(char *)); // Mengalokasikan memori untuk menampung 3 pointer ke char (array of string)

    for (i = 0; i < 3; i++) // Melakukan perulangan untuk proses alokasi dan input string setiap elemen
    {
        /* Alokasi string yang merupakan elemen tabel */
        *(TabStr + i) = (char *) malloc(5 * sizeof(char)); // Mengalokasikan memori memori sebesar 5 byte untuk string ke-i

        printf("\nInput Str[%d], maksimum 5 karakter : ", i); // Menampilkan prompt input untu meminta rangkaian karakter
        scanf("%5s", *(TabStr + i)); // Membaca input dari keyboard dengan maksimal 5 karakter dan menaruhnya ke memori yang dialokasi

        printf("\n Nilai Str[%d] : %5s\n ", i, *(TabStr + i)); // Menampilkan nilai string yang sudah didapatkan dari input
    }
    
    return 0; // Memberikan nilai kembalian tanda program selesai tanpa error
}