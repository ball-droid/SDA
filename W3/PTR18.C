/* ------------------------------------------------------------------------------------------------------------- */
/* File Program : PTR18.C                                                                                        */
/* Deskripsi    : Program array dinamis dan statis: mengisi dgn baca, menulis (Modular, program                  */
/*                passing parameter tabel/array)                                                                */
/* ------------------------------------------------------------------------------------------------------------- */

#include <stdio.h> // Header pustaka standar khusus fungsi output seperti cetak (printf) input (scanf)

/* Definisi tabel integer */
typedef struct {     // Memulai pendefinisian struktur data bentukan atau struct dengan alias 'tabint'
    int tab[10];     // Mendeklarasikan data bertipe array integernya sebagai komponen 'tab' kapasitas 10
    int N;           // Mendeklarasikan variabel sub-data int 'N' untuk menyimpan ukuran efektif data array
} tabint;            // Akhir dari blok tipe 'struct' dan deklarasi tipe tipe datanya sebagai alias 'tabint'

/* Prototype fungsi */
void incTab(tabint *T); // Deklarasi purwarupa fungsi prosedur penambah (increment) setiap elemen tabel secara referensi
void printTab(tabint T); // Deklarasi purwarupa fungsi pencetak traversal berdasar pengiriman copy / nilai biasa

int main() // Tempat awalan mengeksekusi urutan logika pemanggilan dalam aplikasi ini
{
    /* Kamus Data Lokal (Main) */
    tabint T; // Mendeklarasikan T sebagai instansiasi tipe data bentukan (variabel 'tabint')
    int i;    // Mendeklarasikan variabel index iterator (perulangan) i

    /* Program Utama */
    T.N = 3; // Menetapkan field ukuran array efektif yang akan digunakan, yaitu 3 elemen terpakai

    printf("Isi dan print tabel untuk indeks 1..5 \n"); // Menampilkan pesan pembuka cetak array ke layar console pengguna
    
    /* Isi dari pembacaan (pengguna menginput nilai-nilai untuk elemen spesifik) */
    for (i = 0; i < T.N; i++) // Menginisialisasi blok loop membaca array element sebanyak N iterasi
    {                         // Pembatas awal prosedur loop data dari pengguna
        printf("Input tabel ke -[%d] = ", i); // Menampilkan pemberitahuan yang menuntut untuk memberikan masukkan elemen
        scanf("%d", &(T.tab[i]));             // Mengambil inputan keyboard, men-set nilai integer dan menyimpannya ke memori tab
    };                        // Penutup dari perintah siklus loop

    /* Print: perhatikan passing parameter by value */
    printTab(T); // Memanggil modul (fungsi printTab) yang hanya membuat tabel sementara dalam ruang lingkupnya, tidak menimpa asli

    /* Increment: perhatikan passing parameter by reference (dengan tanda referensi '&')*/
    incTab(&T); // Memanggil modul yang menggunakan pengiriman argumen memori sehingga setiap elemen asli tabel (yang di-incremen) ikut terubah
    
    // Menge-print daftar akhir
    printTab(T); // Mencetak ulang keadaan 'T' untuk menguji apakah elemen 'T' berubah oleh fungsi 'incTab'
    
    return 0; // Memberitahukan penanda kembali operasi sistem sebagai kondisi sukses (tanpa cacat program)
}

/* Body / implementasi prototype */
void incTab(tabint *T) // Fungsi ber-argumen pointer untuk meng-increment setiap nilai pada instansiasi tabel
{
    /* Kamus lokal modul increment */
    int i; // Variabel angka loop per-elemen
    
    /* Program perulangan dan eksekusi pada penambahan */
    for (i = 0; i < (*T).N; i++) // Berjalan melakukan for i dari 0 sampai sejumlah *T target length 'N'
    {                            // Awal dari set increment penambahan nilai-nilai tersebut
        (*T).tab[i] = (*T).tab[i] + 1; // Meng-set index memori pada tab dengan menambah satu angkanya dari keadaan aslinya
    }                            // Akhir eksekusi
}

void printTab(tabint T) // Modul fungsi parameter "passing by value" untuk mengeksekusi format print ke layar terminal
{ 
    /* Kamus lokal pencetakan (hanya ada di lingkungan lingkup memori terpisah di fungsi ini saja) */
    int i; // Mendeklarasikan 'i' sebagai target penanda loop untuk output elemen print

    /* Program untuk traversal (pencetakan masing-masing data dari atas awal ke bawah) */
    for (i = 0; i < T.N; i++) // Mendeklarasikan pembatas iterasi print element yaitu nol sampainbatas 'N' minus 1
    {                         // Menghasilkan awal proses blok statement print looping
        printf("T[%d] = %d \n", i, T.tab[i]); // Mengeprint format angka i dan element yang didapatkan melalui iterasi nilai aslinya 'tabi'
    }                         // Mengakhiri proses cetak array element
}