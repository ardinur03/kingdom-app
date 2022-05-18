#ifndef silsilah_H
#define silsilah_H
#include "header.h"

int tahun(); //mengambil data tahun saat ini
int getUsia(int thLahir); //untuk menghitung usia 
int isSilsilahEmpty(nbAddr tr); //cek Tree apakah kosong atau tidak
void CreateEmptyNode(nbAddr *tr); //membuat node kosong
void Isi_Node_Silsilah(nbAddr *tr, nbType name, char JK, int US, nbType religion); //mengisi node
void InsertSilsilah(nbAddr *tr); //menambahkan node ke dalam tree
nbAddr Search(nbAddr tr,nbType SQ); //untuk mencari node tertentu
void cetakSilsilah(nbAddr tr, char tab[]); //untuk menampilkan silsilah
void urutanPewaris(nbAddr tr); //untuk menampilkan urutan pewaris
void LihatIdentitas(nbAddr tr,nbType data); //untuk menampilkan identitas lengkap dari nama yang dicari
void nbInsert(TreeSilsilah *tRoot, nbAddr parent, nbType nama_param, char jenis_kelamin_param, int usia_param, nbType religion_param);
nbAddr nbSearch(nbAddr root, nbType nameParam);
void nbCreate(TreeSilsilah *x);
void nbPre2(nbAddr root, char tab[]);
void delete_node(TreeSilsilah *pTree);
void nbDelete(nbAddr *pDel, TreeSilsilah *pTree);//Tengah
void nbDelete2(nbAddr *pDel, TreeSilsilah *pTree);//Delete Raja and Upgrade
void nbUpgrade(nbAddr *root);
void urutanTahtaPewaris(nbAddr tr);
void nbLevelOrder(nbAddr root,int curLevel, int desLevel);
int nbDepth(nbAddr root);

void insertKeturuan ();

void menuHitungAnak(nbAddr treeSilsilahTemp); // menu untuk menghitung anak
int hitungAnak(nbAddr tree, nbType parent); //untuk menghitung jumlah anak

void opsiDeleteAnggotaKerajaan(nbAddr treeSilsilahTemp, TreeSilsilah tree);


#endif
