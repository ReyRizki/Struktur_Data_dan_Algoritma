// Program          : linkedList.h
// Description      : file header untuk linked list
// Author           : Reynaldy Rizki Saputra
// Latest Update    : 27 Feb 2020
// Version          : v1.1

#ifndef linkedList_H_
#define linkedList_H_

// struct node yang digunakan untuk menyimpan 1 node dari linked list
struct Node
{
    int data;           // data yang dismpan
    struct Node *next;  // alamat node selanjutnya, jika tidak ada, maka menggunakan NULL
};

// PEMBUATAN NODE

// Description      : Digunakan untuk membuat 1 node baru yang masih kosong
// Input            : -
// Output           : Alamat node baru
struct Node *createNode();

// PENGISIAN NODE

// Description      : Mengisi data node baru dengan n
// Initial State    : Data node baru belum terisi
// Final State      : Data node baru sudah terisi
void assignNode(struct Node *list, int n);

// Description      : Melakukan inisialisasi terhadap linked list dengan 1 node
// Initial State    : List belum diinisialisasi
// Final State      : Lise belum diinisialisasi
void initializeList(struct Node **list, int n);

// Description      : Membuat node baru kemudian memasangnya di depan di depan linked list
// Initial State    : Node baru belum dibuat
// Final State      : Node baru sudah dibuat
void pushFront(struct Node **list, int n);

// Description      : Membuat node baru kemudian memasangnya di belakang linked list
// Initial State    : Node baru belum dibuat
// Final State      : Node baru sudah dibuat
void pushBack(struct Node *list, int n);

// Description      : Membuat node baru kemudian memasangnya di salah satu index
// Initial State    : Node baru belum dibuat
// Final State      : Node baru sudah dibuat
void pushAt(struct Node *list, int n, int index);

// PENCARI UKURAN LINKED LIST

// Description      : Mendapatkan banyak node yang terdapat pada linked list
// Input            : Linked list
// Output           : Banyak node
int size(struct Node *list);

// PENAMPIL LINKED LIST

// Description      : Menampilkan linked list
// Initial State    : Linked list belum ditampilkan
// Final State      : Linked list sudah ditampilkan
void printList(struct Node *n);

// PENCARI ALAMAT NODE

// Description      : Mendapatkan alamat node di salah satu index linked list
// Input            : Linked list, index
// Output           : Alamat index di linked list
struct Node *addressAt(struct Node *list, int index);

// Description      : Mendapatkan alamat index terakhir dari linked list
// Input            : Linked list, index
// Output           : Alamat index terakhir dari linked list
struct Node *tailAddress(struct Node *list);

// MEILHAT ISI DATA

// Description      : Mendapatkan data yang disimpan di index pertama dalam linked list
// Input            : Linked list
// Output           : Data yang disimpan di index pertama
int headData(struct Node *list);

// Description      : Mendapatkan data yang disimpan di index terakhir dalam linked list
// Input            : Linked list
// Output           : Data yang disimpan di index terakhir
int tailData(struct Node *list);

// Description      : Mendapatkan data yang disimpan di suatu index dalam linked list
// Input            : Linked list, index
// Output           : Data pada index
int dataAt(struct Node *list, int index);

// PENGHAPUS NODE

// Description      : Menghapus node yang ada di index pertama
// Initial State    : Node belum dihapus
// Final State      : Node sudah dihapus
void popFront(struct Node **list);

// Description      : Menghapus node yang ada di index terakhir
// Initial State    : Node belum dihapus
// Final State      : Node sudah dihapus
void popBack(struct Node *list);

// Description      : Menghapus node di suatu index tertentu
// Initial State    : Node belum dihapus
// Final State      : Node sudah dihapus
void popAt(struct Node *list, int index);

#include "linkedList.c"
#endif