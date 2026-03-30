/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */
/* Diupdate oleh : WW & AM, 8-3-2025, penyesuaian area body & main untuk latihan Diploma 3 */

#include "liststatis.h"
#include <stdio.h>

int main()
{
	/* Kamus Lokal */
		List MyList;
		infotype isi;
		address P, Prec;

	/* Program */
	CreateList (&MyList);	//List sudah terbentuk, digunakan untuk memanipulasi elemen
	
	//aksi mahasiswa untuk implementasi studi kasus
	

	/* Finishing */
	
	//Pastikan List di Dealokasi setelah manipulasi elemen selesai
	
	return 0;
}

