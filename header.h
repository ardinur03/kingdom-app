#ifndef header_H
#define header_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include <windows.h>
#include <time.h>

// Tree => nbAddr
// info => nama
#define nama(P) (P)->nama
#define fs(P) (P)->fs
#define nb(P) (P)->nb
#define parent(P) (P)->parent
#define jenis_kelamin(P) (P)->jenis_kelamin
#define usia(P) (P)->usia
#define religion(p) (p)->religion


#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

typedef char nbType[50];
typedef struct TnbTreeNode *nbAddr;
typedef struct TnbTreeNode{
	nbType nama;
	char jenis_kelamin;
    nbType religion;
	int usia;
	nbAddr fs;
	nbAddr nb;
	nbAddr parent;
}nbTreeNode;

struct TreeSilsilah{
	nbAddr root;
};
#endif
