/* File    : bintree.h 	*/
/* Desk    : Deklarasi Binary Tree secara rekursif  	*/
/* Oleh    : ANI RAHMANI / 23501007  			*/
/* Tgl	   : 21 / 11 / 2001	     			*/

#ifndef BINTREE_H
#define BINTREE_H

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a-1); i >= (b); i--)

#endif

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define Nil NULL
#define Info(P) (P)->info
#define Left(P) (P)->left
#define Parent(P) (P)->parent
#define Right(P) (P)->right
#define Hur(P) (P)->hur
#define Next(P) (P)->next
#define Count(P) (P)->count

typedef int infotype;
typedef struct tElmtNode *address;
typedef struct tElmtNode
{
    infotype info;
    address left;
    address right;
    address parent;
    u int count;
} ElmtNode;

typedef address BinTree;

address Alokasi(infotype X);
/* Menghasilkan  address hasil alokasi sebuah  Node 	*/
/* Jika alokasi berhasil, maka  address tidak NIl   	*/
/* Info(P)=X, Left(P)=Nil,Right(P)=Nil, dan Count(P)=0 	*/
/* Jika alokasi gagal mengembalikan Nil  		*/

boolean IsEmpty(BinTree P);
/* Mengembalikan true jika pohon kosong */

infotype GetAkar(BinTree P);
/* Mengirimkan nilai Akar pohon biner P */

BinTree GetLeft(BinTree P);
/* Mengirimkan anak kiri pohon biner P  */

BinTree GetRight(BinTree P);
/* Mengirimkan anak kanan pohon biner P  */

/* ******** KONSTRUKTOR ************ */
BinTree Tree(infotype X, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon Biner dari A, L, dan R jika Alokasi berhasil */
/* Menghasilkan pohon kosong Nil, jika alokasi gagal 			  */

void MakeTree(infotype X, BinTree L, BinTree R, BinTree *P);
/* I.S   : Sembarang 	*/
/* F.S   : Menghasilkan sebuah pohon biner P dari A,L,dan R, jika alokasi */
/*         berhasil; Menghasilkan pohon P yang kosong jika alokasi gagal  */

/* ********* PREDIKAT PENTING  **************  */

boolean IsUnerLeft(BinTree P);
/* Mengirimkan True jika pohon biner tidak kosong; P adalah pohon  */
/* unerleft : hanya mempunyai subpohon kiri 			   */

boolean IsUnerRight(BinTree P);
/* Mengirimkan True jika pohon biner tidak kosong; P adalah pohon  */
/* unerright : hanya mempunyai subpohon kanan          		   */

boolean IsBiner(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong; P adalah pohon */
/* biner : mempunyai subpohon kiri dan subpohon kanan 		  */

/* ************* TRAVERSAL   ************* */

void Preorder(BinTree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Preorder; akar, kiri */
/*        kanan (dengan Proses (P)) 				    */

void Inorder(BinTree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Inorder; kiri, akar  */
/*        kanan (dengan Proses (P)) 				    */

void Postorder(BinTree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Postorder; kiri,     */
/* 	  kanan, akar (dengan Proses (P)) 			    */

void PrintTree(BinTree P);
/* I.S  : P terdefinisi, h adalah jarak indentasi	*/
/* F.S  : semua simpul P sudah ditulis 			*/

/* ************ SEARCH **************** */
address Search2(BinTree T, infotype X);

/* *********** MEMBENTUK BALANCE TREE ************* */
BinTree BuildBalanceTree(int n);
/* Menghasilkan sebuah balance tree dengan n node, nilai setiap node dibaca 							*/

/* ************** TERHADAP BINARY SEARCH TREE *************** */
void InsSearchTree(BinTree *P, infotype X);
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan X. Belum ada simpul P yang bernilai X 			  */

void DelBTree(BinTree *P, infotype X);
/* I.S  : Pohon P tidak kosong 					   */
/* F.S  : Nilai yang dihapus pasti ada, sebuah node dengan nilai X */
/*        dihapus 						   */

#endif