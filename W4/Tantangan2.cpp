#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Nil NULL
// Mendefinisikan makro agar kita tidak perlu selalu menuliskan tanda panah (->)
#define info(P) (P)->info
#define next(P) (P)->next

// Menyiapkan tipe data terstruktur untuk menyimpan data mahasiswa
typedef struct {
    char nama[50];
    int nilai;
} infotype;

// Mendefinisikan tipe pointer dan skema dari elemen node untuk linked list
typedef struct tElmtlist *address;
typedef struct tElmtlist{
    infotype info; // Atribut ini berguna sebagai tempat menampung data mahasiswa dalam node
    address next;  // Pointer ini berperan untuk menghubungkan suatu node dengan node sesudahnya
} ElmtList;


// Fungsi Alokasi digunakan untuk menginisialisasi atau menciptakan node baru saat hendak bertambah elemen
address Alokasi(char nama[], int nilai){
    // Pemesanan blok memori secara dinamis untuk menampung satu buah node utuh
    address P = (address) malloc(sizeof(ElmtList));

    // Jika blok dari memori berhasil didapatkan, maka operasikan hal berikut
    if(P != Nil){ 
        strcpy(info(P).nama, nama); // Menyalin parameter nama menjadi isi komponen informasi bertipe string
        info(P).nilai = nilai;      // Mengisi parameter dari nilai yang sifatnya sudah sesuai dengan deklarasi (integer)
        next(P) = Nil;              // Karena referensi node belum mendapat posisi khusus pada susunan list, berikan nilai default berupa NULL
    }

    return P; // Mengembalikan identitas atau referensi letak dari node baru tersebut
}


// Fungsi tambahan untuk menangani tahap memasukkan struktur node menjadi posisi permulaan list (Insert First)
void InsertFirst(address *First, address P){
    next(P) = *First; // Pointer tujuan elemen diarahkan menuju komponen node pertama list sebelumnya
    *First = P;       // Merombak perwakilan head sehingga kembali menyasar letak posisi susunan Node P
}


// Fungsi spesifik untuk penambahan node baru tepat di belakang posisi nama komponen referensi  
void InsertAfter(address *First, char namaCari[], address P){
    address Q = *First;

    // Perulangan menelusuri isi dari elemen ke elemen lain pada list 
    while(Q != Nil){
        // Mengevaluasi hasil komparasi antara nama target dengan menggunakan fungsi dari library bawaan string, yakni strcmp
        if(strcmp(info(Q).nama, namaCari) == 0){ 
            next(P) = next(Q); // Merangkaikan pointer target dari node ke seberang letak penyisipan yang ditetapkan
            next(Q) = P;       // Referensi letak ujung bagian belakang dari target akan dipatok menjadi node P ini 
            return; // Proses operasional iterasi diberhentikan jika pencocokan membuahkan kelancaran penggabungan
        }
        Q = next(Q); // Operasi berlanjut kembali menjajaki struktur selanjutnya apabila target belum ditemukan
    }
}


// Subrutin prosedur untuk mendistribusikan node menuju titik paling terakhir dalam rantai berderet
void InsertLast(address *First, address P){
    address Q;

    // Mengoreksi apabila list mula-mula masih kosong, yang berarti fungsi bisa ditarik implementasinya seperti fungsi InsertFirst 
    if(*First == Nil){ 
        *First = P;
    }
    // Jika kondisinya sudah ada unsur pada list, tahapannya beralih menjadi skenario di bawah ini
    else{ 
        Q = *First;
        // Menyusuri barisan seluruh data struktur dengan batas penghujung NULL ditemukan
        while(next(Q) != Nil){
            Q = next(Q);
        }
        next(Q) = P; // Memposisikan susunan ujung node tersebut agar mengaitkan ujung akhirnya ke elemen P
    }
}


// Fungsi keluaran guna menerbitkan tampilan data dari struktur kepada pengguna dalam layar
void PrintList(address First){
    address P = First;

    printf("\nIsi Linked List:\n");

    while(P != Nil){
        // Mencetak entitas objek mahasiswa mencakup penamaan dan hasil nilainya pada terminal
        printf("%s - %d\n", info(P).nama, info(P).nilai);
        // Memastikan referensi untuk melakukan lompatan elemen senantiasa dijalankan agar perputaran instruksi tidak mengulangi terus sebuah indeks tiada akhirnya
        P = next(P); 
    }
}


// Rangkaian komputasi diatur dari prosedur eksekusi list utamanya di bagian main  
int main(){

    // Penerapan pendefinisian pertama kalinya dalam inisialisasi status pointer dengan berformatkan nilai kosong/NULL 
    address First = Nil; 
    address P;

    // 1. Eksekusi penambahan mahasiswa Nizar, beserta bobot skor 70 miliknya ke urutan list    
    P = Alokasi("Nizar",70);
    InsertFirst(&First,P);

    // 2. Memberikan delegasi kepada subjek data profil yaitu Lutfia guna berdiam di awal mula list memikul hak keutamaan dari posisi First   
    P = Alokasi("Lutfia",50);
    InsertFirst(&First,P);

    // 3. Merutekan penataan daftar letak komponen Reno agar ditugaskan penyisipannya setelah kedudukan asal profil Lutfia 
    P = Alokasi("Reno",80);
    InsertAfter(&First,"Lutfia",P);

    // 4. Menyempurnakan pendaftaran partisipasi sosok Zidan berada di rentetan terminal urutan yaitu penutupan akhir
    P = Alokasi("Zidan",60);
    InsertLast(&First,P);

    // 5. Operasi penyisipan khusus bagi saudara bernama Wulan ini akan diulas batas letaknya bertumpu menyusul saudara Reno di depannya
    P = Alokasi("Wulan",90);
    InsertAfter(&First,"Reno",P);

    // Rangkaian akhir ini difokuskan menjalankan pengecekan list agar keabsahan output penambahan telah tervalidasi siap dipaparkan 
    PrintList(First);

    return 0; 
}