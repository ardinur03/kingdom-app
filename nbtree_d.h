/*
Code Sumber : di ambil dari praktikum SDA
File	: nbtree_d.h
Deskripsi : spesifikasi program ADT Non Binary Tree Dinamis
Author	: SN
Created : 25-5-2011
Last Update : 25-4-2020

*/

#ifndef nbtree_d_H
#define nbtree_d_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// typedef int nbType;		//boleh diganti char
// typedef struct TnbTreeNode *nbAddr;

// typedef struct TnbTreeNode{
// 	nbAddr fs; //First child
// 	nbType info; 
// 	nbAddr nb; //Next brother
// 	nbAddr parent;
// }nbTreeNode;

// struct nbTree{
// 	nbAddr root;
// };

/* ---------------- Konstruktor Tree ---------------- */
void nbCreate(nbTree *x);
//Membuat tree kosong (X.root=NULL)

/* ---------------- Alokasi node baru Tree ---------------- */
nbAddr nbCNode(nbType X);
//Alokasi untuk membuat node baru

/* ---------------- Operasi-operasi Tree ---------------- */
void nbInsert(nbTree *tRoot, nbAddr parent, nbType X);
// Menambah element pada node parent

nbAddr nbSearch(nbAddr root, nbType src);
// Mencari node dengan info ttn dan mengembalikan addressnya

void nbUpgrade(nbAddr *root);
// Mengupgrade parent dari beberapa node. (digunakan pada proses penghapusan)

void nbDelete(nbAddr *pDel, nbTree *pTree);
// Menghapus node tertentu dan jika node tersebut memiliki child, maka posisinya digantikan oleh fs dari node tsb

int nbDepth(nbAddr root);
// Mengukur kedalaman suatu node dari root


/* ---------------- TRAVERSAL Tree ---------------- */
void nbPost(nbAddr root); // Postorder traversing
void nbPre(nbAddr root); // Preorder traversing
void nbIn(nbAddr root); // Inorder traversing
void nbLevelOrder(nbAddr root,int curLevel, int desLevel); // Levelorder traversing

/* ---------------- PRINT TREE ---------------- */
void nbPrint(nbAddr node, char tab[]);
//boleh diganti dengan : void nbPrint(nbAddr node, char *tab);

#endif
