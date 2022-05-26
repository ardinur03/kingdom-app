#ifndef silsilah_H
#define silsilah_H
#include "header.h"

int isSilsilahEmpty(nbAddr tr); //cek Tree apakah kosong atau tidak 
void CreateEmptyNode(nbAddr *tr); //membuat node kosong 
void InsertSilsilah(nbAddr *tr); //menambahkan node ke dalam tree
nbAddr Search(nbAddr tr,nbType SQ); //untuk mencari node tertentu
void cetakSilsilah(nbAddr tr, char tab[]); //untuk menampilkan silsilah
void urutanPewaris(nbAddr tr); //untuk menampilkan urutan pewaris
void LihatIdentitas(nbAddr tr,nbType data); //untuk menampilkan identitas lengkap dari nama yang dicari
void nbInsert(TreeSilsilah *tRoot, nbAddr parent, nbType nama_param, char jenis_kelamin_param, int usia_param, nbType religion_param); // untuk menambahkan node baru
nbAddr nbSearch(nbAddr root, nbType nameParam); //untuk mencari node yang dicari berdasarkan nama yang dicari 
void nbCreate(TreeSilsilah *x); // membuat create anggota kerajaan silsilah 
void nbDelete(nbAddr *pDel, TreeSilsilah *pTree);// Delete sebagai saudara dari raja
void nbDelete2(nbAddr *pDel, TreeSilsilah *pTree);//Delete Raja dan Upgrade ke Raja
void nbUpgrade(nbAddr *root); // mengupgrade node
void urutanTahtaPewaris(nbAddr tr); // untuk menampilkan urutan pewaris berdasarkan tahta pewaris
void nbLevelOrder(nbAddr root,int curLevel, int desLevel); // untuk menampilkan saudara dari raja dalam level tertentu
int nbDepth(nbAddr root);  // digunakan pada opsi delete untuk menghitung tinggi dari tree
void menuHitungAnak(nbAddr treeSilsilahTemp); // menu untuk menghitung anak dari root/first son/next son
int hitungAnak(nbAddr tree, nbType parent); //untuk menghitung jumlah anak 
void opsiDeleteAnggotaKerajaan(nbAddr treeSilsilahTemp, TreeSilsilah tree); // untuk menampilkan opsi dalam pendeletan anggota kerajaan dari raja ataupun saudara ataupu anak
void detailAnggota(nbAddr tr); // untuk menampilkan detail anggota kerajaan

#endif
