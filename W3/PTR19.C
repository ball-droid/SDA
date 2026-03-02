/* --------------------------------------------------------------------------------------------------------- */
/* File Program : PTR19.C                                                                                    */
/* Deskripsi    : Maksud program sama dengan PTR18.cpp. Cari perbedaannnya!                                  */
/* --------------------------------------------------------------------------------------------------------- */

#include <stdlib.h> // Library input C standar file pemanfaatan alokasi array 'malloc' dan memori dasar (built-in function stdlib)
#include <stdio.h>  // Tambahan library file karena scanf dan printf dipakai (C standar Input and output library functions)

/* Definisi tabel integer menggunakan struktur bentukan */
typedef struct { // Memulai formasi tipe variabel gabungan baru alias 'tabint' yang berbeda dari array statis pada type lama
    int *tab;    // Mendeklarasikan komponen member pointer integer ('tab') pengakses daftar tipe integer dalam struct
    int N;       // Mengalokasikan tempat data struct berupa ukuran maksimum variabel integer N pada batas efektivitas tabel
} tabint;        // Penutupan tanda tipe struct yang nantinya dipanggil menggunakan variabel label 'tabint'

/* Prototype prosedur modular*/
void incTab(tabint *T);  // Prosedur increment tabel menggunakan mode operasional 'Passing Parameter by Reference' (Alamat asli diubah)
void printTab(tabint T); // Prosedur print tabel menggunakan 'Passing Parameter by Value' (Nilai tabel diduplikat secara lokal ke fungsi ini)

int main() // Deklarasi area fungsi paling pertama yang akan dikerjakan di sistem (Fungsi main)
{ 
    /* Kamus Data area */
    tabint T; // Inisialisasi alias data bentukan variabel penunjuk (objek utama lokal pada program), menggunakan struct T
    int i;    // Deklarasi index elemen-elemen variabel lokal array dengan pengenal i 

    /* Program Utama berjalan di urutan sebagai berikut */
    T.tab = (int *) malloc(3 * sizeof(int)); // Menyiapkan array secara pointer dan jumlah ukuran dinamis alokasi heap dikali ukuran bit integer
    T.N = 3; // Menetapkan properti isi struct yakni panjang limit daftar yang diefektifkan sejumlah angka 3

    printf("Isi dan print tabel untuk indeks 1..3 \n"); // Menampilkan petunjuk atau prompt info indeks pertama output

    for (i = 0; i < T.N; i++) // Memberikan loop siklus dari nol sampai dengan target indeks maksimum T array size dikurang 1
    {                         /* Isi dari pembacaan blok ini meminta input secara sistematis dengan for */
        printf("Input tabel ke -[%d] = ", i); // Mengisyaratkan perintah teks sebagai permintaan value yang wajib dieksuksi inputnya
        scanf("%d", &(T.tab[i]));             // Mengutip hasil dari input keyboard numerik dan merekam isinya pada field indeks array struktur pointer dinamis
    };                        // Akhir pengisian alur membaca program (akhir scope loop input)
    
    printTab(T); /* Print awal elemen: Modul ini menerima satu parameter lewat 'value', dan mencetak angka array sesuai input awal kita*/
    
    incTab(&T); /* Increment: Parameter alamat referensi dialihkan sehingga memicu efek manipulasi secara langsung tiap nilai memori array-nya bertambah */
    
    printTab(T); // Memanggil kembali rutin fungsi print (mencetak kembali apa yang ada memori untuk memverifikasi kenaikan)

    return 0; // Return function dari program tanpa tanda error (mengembalikan 0 kepada environment operasi)
}

/* Bagian pendefinisian nyata fungsi / Body prototype */
void incTab(tabint *T) // Menuntun penambahan (increment). Menerima nilai berupa parameter referensi asli
/* Increment setiap elemen tabel ke alamat pointer parameternya */
{ 
    /* Kamus lokal subprogram modul */
    int i; // inisialisasi counter-loop dalam variabel lokal blok operasi scope yang ada disini
    
    /* Program perulangan utama */
    for (i = 0; i < (*T).N; i++) // Mensiklus i sama dengan nol menuju bilangan maksimum yang sama secara parameter aktual struct 'N'
    {                            // Memulai scope program per-increment 
        (*T).tab[i] = (*T).tab[i] + 1; // Memuat field nilai isi pada parameter indeks list saat ini, bertambah (add) konstan sebanyak 1 angka 
    }                            // Titik akhiran scope program nilai pada pointer indeks yang ditujukan per-looping-nya
}

void printTab(tabint T) // Output setiap isi indeks elemen data array yang dikirim
/* Fungsi mencetak (Print) setiap elemen tabel parameter value lokal */
{ 
    /* Kamus lokal variabel sub-fungsi 'printTab' */
    int i; // Variabel looping iterasi array data index
    
    /* Program blok khusus untuk siklus travers output nilai print-loop perulangan */
    for (i = 0; i < T.N; i++) // Looping dari elemen index daftar struct mulai bernilai i=0 di list array ukuran ke-i menuju size iterasi N 'T'-list
    {                         // Pembuka eksekusi list data display console iteratif i-loop
        printf("T[%d] = %d \n", i, T.tab[i]); // Melacak lalu menampilkan data indeks integer yang diiterasi 'i' maupun indeks value hasil isi pointer 
    }                         // Mengakhiri operasional loop dan berhenti jika batasan loop habis (tidak ada yg dicetak lagi)
}