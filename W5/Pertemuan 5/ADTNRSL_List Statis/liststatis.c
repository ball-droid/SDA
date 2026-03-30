#include "liststatis.h"

/* Modul ADT List Statis (array + indeks next) */

/* fungsi bantu: cek apakah index i sedang dipakai di rantai list */
static boolean IsIndexUsed(List L, address i){
    address P = First(L);

    while(P != Nil){
        if(P == i){
            return true;
        }
        P = L.A[P].next;
    }

    return false;
}

/**** Predikat keadaan list ****/
boolean isListEmpty(List L){
    /* true jika first menunjuk Nil */
    return (First(L) == Nil);
}

/**** Konstruktor List Kosong ****/
void CreateList(List *L){
    int i;

    /* list kosong ditandai first = Nil */
    First(*L) = Nil;

    /* inisialisasi isi array supaya aman */
    for(i = 0; i < MaxEl; i++){
        L->A[i].info = 0;
        L->A[i].next = Nil;
    }
}

/**** Manajemen Elemen (Alokasi dari array kosong) ****/
address Alokasi(List *L, infotype X){
    address i;

    /* cari indeks pertama yang belum dipakai */
    for(i = 0; i < MaxEl; i++){
        if(!IsIndexUsed(*L, i)){
            L->A[i].info = X;
            L->A[i].next = Nil;
            return i;
        }
    }

    /* jika penuh, gagal alokasi */
    return Nil;
}

void DeAlokasi(List *L, address P){
    /* isi dibuat default lagi */
    if(P != Nil){
        L->A[P].info = 0;
        L->A[P].next = Nil;
    }
}

/**** Search ****/
address Search(List L, infotype X){
    address P = First(L);

    /* telusuri list sampai ketemu atau habis */
    while(P != Nil){
        if(L.A[P].info == X){
            return P;
        }
        P = L.A[P].next;
    }

    return Nil;
}

/**** INSERT BERDASARKAN NILAI ****/
void InsVFirst(List *L, infotype X){
    address P = Alokasi(L, X);

    /* jika alokasi berhasil, masukkan di depan */
    if(P != Nil){
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotype X){
    address P = Alokasi(L, X);

    /* jika alokasi berhasil, masukkan di belakang */
    if(P != Nil){
        InsertLast(L, P);
    }
}

/**** DELETE BERDASARKAN NILAI ****/
void DelVFirst(List *L, infotype *X){
    address P;

    if(!isListEmpty(*L)){
        DelFirst(L, &P);
        *X = L->A[P].info;
        DeAlokasi(L, P);
    }
}

void DelVLast(List *L, infotype *X){
    address P;

    if(!isListEmpty(*L)){
        DelLast(L, &P);
        *X = L->A[P].info;
        DeAlokasi(L, P);
    }
}

/**** INSERT BERDASARKAN ADDRESS ****/
void InsertFirst(List *L, address P){
    /* next dari elemen baru menunjuk first lama */
    L->A[P].next = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec){
    /* sisipkan P setelah Prec */
    L->A[P].next = L->A[Prec].next;
    L->A[Prec].next = P;
}

void InsertLast(List *L, address P){
    address Last;

    /* kalau kosong, elemen baru jadi first */
    if(isListEmpty(*L)){
        First(*L) = P;
    }else{
        Last = First(*L);

        while(L->A[Last].next != Nil){
            Last = L->A[Last].next;
        }

        L->A[Last].next = P;
    }

    L->A[P].next = Nil;
}

/**** DELETE BERDASARKAN ADDRESS ****/
void DelFirst(List *L, address *P){
    /* ambil first lama lalu geser first */
    *P = First(*L);
    First(*L) = L->A[*P].next;
    L->A[*P].next = Nil;
}

void DelP(List *L, infotype X){
    address P, Prec;

    P = First(*L);
    Prec = Nil;

    /* cari elemen bernilai X */
    while(P != Nil && L->A[P].info != X){
        Prec = P;
        P = L->A[P].next;
    }

    if(P != Nil){
        if(Prec == Nil){
            /* yang dihapus elemen pertama */
            First(*L) = L->A[P].next;
        }else{
            /* lewati P dari rantai list */
            L->A[Prec].next = L->A[P].next;
        }

        DeAlokasi(L, P);
    }
}

void DelLast(List *L, address *P){
    address Prec;

    /* jika hanya 1 elemen */
    if(L->A[First(*L)].next == Nil){
        *P = First(*L);
        First(*L) = Nil;
    }else{
        Prec = First(*L);

        while(L->A[L->A[Prec].next].next != Nil){
            Prec = L->A[Prec].next;
        }

        *P = L->A[Prec].next;
        L->A[Prec].next = Nil;
    }

    L->A[*P].next = Nil;
}

void DelAfter(List *L, address *Pdel, address Prec){
    /* hapus elemen tepat setelah Prec */
    *Pdel = L->A[Prec].next;
    L->A[Prec].next = L->A[*Pdel].next;
    L->A[*Pdel].next = Nil;
}

/**** PROSES SEMUA ELEMEN LIST ****/
void PrintInfo(List L){
    address P;

    /* tampilkan elemen dari first sampai Nil */
    printf("[");
    P = First(L);

    while(P != Nil){
        printf("%d", L.A[P].info);
        P = L.A[P].next;

        if(P != Nil){
            printf(", ");
        }
    }

    printf("]\n");
}

int NbElmt(List L){
    int count = 0;
    address P = First(L);

    /* hitung jumlah node yang tersambung */
    while(P != Nil){
        count++;
        P = L.A[P].next;
    }

    return count;
}

infotype Max(List L){
    address P;
    infotype maxVal;

    /* jika kosong, kembalikan Nil sebagai tanda */
    if(isListEmpty(L)){
        return Nil;
    }

    P = First(L);
    maxVal = L.A[P].info;
    P = L.A[P].next;

    while(P != Nil){
        if(L.A[P].info > maxVal){
            maxVal = L.A[P].info;
        }
        P = L.A[P].next;
    }

    return maxVal;
}
