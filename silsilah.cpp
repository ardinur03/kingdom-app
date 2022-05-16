#include "header.h"
#include "silsilah.h"
#include "display.h"

int tahun(){
	char buffer[100];
	time_t v__lewatan_waktu;
	struct tm *p__sekarang;
	int year;
		
	v__lewatan_waktu = time(NULL);
	p__sekarang = localtime(&v__lewatan_waktu);
	strftime(buffer, 100, "%Y \n", p__sekarang);
	year = atoi(buffer);
	
	return year;
}

int getUsia(int thLahir){
	int us;
	int thNow;
	
	thNow=tahun();
	us=thNow-thLahir;
	
	return us;
} 

void Create_Node_Tree (nbAddr *tr){
	
	*tr = (nbAddr)malloc(sizeof(nbTreeNode));
	if(*tr != Nil){
//		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
	}else{
		printf("Gagal Alokasi\n");
	}
}
void nbCreate(TreeSilsilah *x){
	(*x).root=NULL;
}
void CreateEmptyNode(nbAddr *tr){
	Create_Node_Tree(&(*tr));
}

int isTreeEmpty(nbAddr tr){
	return tr == NULL;
}

int isSilsilahEmpty(nbAddr tr){	
	return isTreeEmpty(tr);
}

void Isi_Node_Silsilah(nbAddr *tr, nbType nama,char jenis_kelamin, int usia, nbType religion){
	if(isSilsilahEmpty(*tr)) {
        printf("Node Belum di Alokasi\n");
    } else {
		fs(*tr) = NULL;
		strcpy(nama(*tr),nama);
		jenis_kelamin(*tr)=jenis_kelamin;
		usia(*tr) = usia;
        strcpy(religion(*tr),religion);
		nb(*tr) = NULL;
		parent(*tr) = NULL;

	}
}
// nbType name[], nbType gender, int age, nbType religion[]
nbAddr nbCNode(nbType nama, char jenis_kelamin, int usia, nbType religion_param){// Create New Node
	nbAddr newNode;
	newNode=(nbAddr) malloc(sizeof(nbTreeNode));
	if (newNode != NULL){
		strcpy(newNode->nama, nama);
		newNode->jenis_kelamin  = jenis_kelamin;
		newNode->usia	  = usia;
		strcpy(newNode->religion, religion_param);
		
		newNode->fs=NULL;
		newNode->nb=NULL;
		newNode->parent=NULL;
	}
	return newNode;
}

nbAddr nbSearch(nbAddr root, nbType nameParam)
{
	nbAddr nSrc;
	if (root!=NULL){
		if (strcmp(root->nama,nameParam)==0)
			return root;
		else{
			nSrc=nbSearch(root->fs,nameParam);
			if (nSrc==NULL)
				return nbSearch(root->nb,nameParam);
			else
				return nSrc;
		}
	}
	return NULL;
}

// nbType nama,char jenis_kelamin, int usia, nbType religion
void nbInsert(TreeSilsilah *tRoot, nbAddr parent, nbType nama_param, char jenis_kelamin_param, int usia_param, nbType religion_param){// Insert New Node baru dengan keadaan tertentu
	nbAddr newNode, temp;
	newNode=nbCNode(nama_param, jenis_kelamin_param, usia_param, religion_param);
	if (newNode !=NULL){ //Jika penciptaan node baru berhasil
		if (parent==NULL) //Jika belum terdapat root
			tRoot->root=newNode;
		else{
			temp=parent; 
			if (temp->fs != NULL){
				temp=temp->fs;
				while(temp->nb!=NULL)
					temp=temp->nb;
				temp->nb=newNode;
			}else
				temp->fs=newNode;
			newNode->parent=parent;
		}
	}
	
}

nbAddr Search(nbAddr tr,nbType SQ){
	boolean visit = true;
	if(isSilsilahEmpty(tr))
		return NULL;
	if(strcmp(nama(tr),SQ) == 0)
		return tr;
	else if(strcmp(nama(tr),SQ) != 0 && fs(tr) == NULL)	
		return NULL;
	else{
		while(parent(tr) != NULL || visit){	
			if(fs(tr) != NULL && visit){
				tr = fs(tr);
				if(strcmp(nama(tr),SQ) == 0)
					return tr;	
			}else{
				if(nb(tr) != NULL){	
					tr = nb(tr);
					if(strcmp(nama(tr),SQ) == 0)
						return tr;
					visit = true;
				}else{
					visit = false;	
					tr = parent(tr);
				}
			}
		}
		return NULL;
	}
}

void InsertSilsilah(nbAddr *tr){
	nbAddr TNode = NULL, temp = NULL;
	char jenis_kelamin;
	int thLahir, usia;
	nbType Nama,parent,Agama;
	address Queue;

	CreateEmptyNode(&TNode);

	if(isSilsilahEmpty(*tr)){
		gotoxy(100,20); 
		printf("Nama : "); 
		fflush(stdin);
		gets(Nama);
		gotoxy(100,21); printf("Jenis Kelamin : "); fflush(stdin);
		scanf("%c",&jenis_kelamin);
		gotoxy(100,22); printf("Tahun Lahir: "); fflush(stdin);
		scanf("%d",&thLahir);
        gotoxy(100,23); printf("Agama : "); fflush(stdin);
		gets(Agama);
		usia=getUsia(thLahir);
		gotoxy(100,24) ;printf("Usia: %d",usia);
		// insertion(Queue, Nama);
		if(usia >= 11){
			if(jenis_kelamin == 'L'||jenis_kelamin == 'l'){
				gotoxy(100,25); printf("Karena Kerajaan Baru saja dibangun maka, %s Menjadi Raja\n",Nama);
			}else if(jenis_kelamin == 'P'||jenis_kelamin == 'p'){
				gotoxy(100,25); printf("Karena Kerajaan Baru saja dibangun maka, %s Menjadi Ratu\n",Nama);
			}
			Isi_Node_Silsilah(&TNode,Nama,jenis_kelamin,usia, Agama);
			*tr = TNode;
		}else{
			gotoxy(100,25); printf("Karena Silsilah Kerajaan masih kosong\n");
			gotoxy(100,26); printf("dan Raja yang ditambahkan tersebut belum berumur 11 tahun\n");
			gotoxy(100,27); printf("maka tidak dapat ditambahkan ke dalam silsilah\n");
			gotoxy(100,28); printf("Yang menjadi raja harus berumur lebih dari 11 tahun\n");
		}
	}else{
		gotoxy(100,20); printf("Nama : "); fflush(stdin);
		gets(Nama);
		gotoxy(100,21); printf("Jenis Kelamin : ");	fflush(stdin);
		scanf("%c",&jenis_kelamin);
		gotoxy(100,22); printf("Tahun Lahir: "); fflush(stdin);
		scanf("%d",&thLahir);
		usia=getUsia(thLahir);
		gotoxy(100,23); printf("Usia: %d",usia);
        Isi_Node_Silsilah(&TNode,Nama,jenis_kelamin,usia, Agama);
		// insertion(Queue, Nama);
		do{	
			gotoxy(100,24); printf("Masukkan Parent dari Anak Tersebut : "); fflush(stdin);
			gets(parent);
		}while(Search(*tr,parent) == NULL);
		temp = Search(*tr,parent);
		if(fs(temp) != NULL){
			temp = fs(temp);
			while(nb(temp) != NULL) 
				temp = nb(temp);
			parent(TNode) = parent(temp);
			nb(temp) = TNode;	
		}else{
			parent(TNode) = temp;
			fs(temp) = TNode;
		}
		gotoxy(100,26); printf("Node dengan nama %s berhasil ditambahkan dengan parent %s",Nama,parent);
		//Enqueue(&Queue, TNode);		
	}
}

// pre-order
void cetakSilsilah(nbAddr tr, char tab[]){
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	if (tr!=NULL){
		// root node jangan di tampilkan
		if(strcmp(nama(tr), "root") != 0){
			printf("%s%s\n",tab,tr->nama);
		}
		cetakSilsilah(tr->fs,tempTab);
		cetakSilsilah(tr->nb,tab);
	}
}

int hitungAnak(nbAddr tree, nbType parent){
 TnbTreeNode *temp;

 int jumlah = 0;


 if(!isTreeEmpty(tree)){
	  temp = Search(tree, parent);
  	if (fs(temp) != NULL){
   		jumlah =jumlah +1;
   		temp = fs(temp);
  		}else{
   			return 0;
  		}
  		while (nb(temp) != NULL){
   			temp = nb(temp);
   			jumlah =jumlah +1;
  		}
  	return jumlah;

 }
  return 0;
}

void urutanPewaris(nbAddr tr){
	boolean visit = true;
	int i = 1;
	if(tr == NULL){
		gotoxy(100,20); printf("Silsilah Kosong");
	}else{
		//check apakah ada first son atau tidak
		if (fs(tr) != NULL){		
			while(parent(tr) != NULL || visit){
				if(fs(tr) != NULL && visit){
					tr = fs(tr);
					gotoxy(100,20+i); printf("%d. ",i);
					printf("%s",nama(tr));
					i++;
				}else{
					if(nb(tr) != NULL){
						tr = nb(tr);
						gotoxy(100,20+i); printf("%d. ",i);
						printf("%s",nama(tr));
						visit = true;
						i++;
					}else{
						tr = parent(tr);
						visit = false;
					}
				}
			}
		}else{
			gotoxy(100,21); printf("Belum ada pewaris\n");
		}
	} 
}

void nbUpgrade(nbAddr *root){
	nbAddr temp;
	
	temp=(*root)->nb;
	if ((*root)->fs==NULL)
		(*root)->fs=temp;
	while(temp!=NULL){
		temp->parent=*root;
		temp=temp->nb;
	}
}

TnbTreeNode* SearchNode(TreeSilsilah tree, nbType nama){
	TnbTreeNode *node = tree.root;
	while(node != NULL){
		if(strcmp(nama(node),nama)== 0){
			return node;
		}
		if(fs(node) != NULL){
			node = fs(node);
		}
		else{
			if(nb(node) != NULL){
				node = nb(node);
			}
			else{
				while(nb(node) == NULL && node != tree.root){
					node = parent(node);
				}
				node = nb(node);
			}
		}
	}
	return NULL;
}

void nbDelete(TreeSilsilah *tree, nbType pTree){
	TnbTreeNode *pSearch, *temp, *pDelete, *raja;
	pSearch = SearchNode(*tree, pTree);
	raja = tree->root;

	if(pSearch == NULL){
		gotoxy(100,20); printf("Nama tidak ditemukan");
	}else{
		if(fs(pSearch) == NULL && nb(pSearch) == NULL){
			if(pSearch == tree->root){
				tree->root = NULL;
			}else{
				if(parent(pSearch)->fs == pSearch){
					parent(pSearch)->fs = NULL;
				}else{
					parent(pSearch)->nb = NULL;
				}
			}
		}else{
			if(fs(pSearch) != NULL && nb(pSearch) == NULL){
				if(pSearch == tree->root){
					tree->root = fs(pSearch);
					fs(pSearch)->parent = NULL;
				}else{
					if(parent(pSearch)->fs == pSearch){
						parent(pSearch)->fs = fs(pSearch);
						fs(pSearch)->parent = parent(pSearch);
					}else{
						parent(pSearch)->nb = fs(pSearch);
						fs(pSearch)->parent = parent(pSearch);
					}
				}
			}else{
				if(fs(pSearch) == NULL && nb(pSearch) != NULL){
					if(pSearch == tree->root){
						tree->root = nb(pSearch);
						nb(pSearch)->parent = NULL;
					}else{
						if(parent(pSearch)->fs == pSearch){
							parent(pSearch)->fs = nb(pSearch);
							nb(pSearch)->parent = parent(pSearch);
						}else{
							parent(pSearch)
							->nb = nb(pSearch);
							nb(pSearch)->parent = parent(pSearch);
						}
					}
				}else{
					if(fs(pSearch) != NULL && nb(pSearch) != NULL){
						temp = fs(pSearch);
						while(nb(temp) != NULL){
							temp = nb(temp);
						}
						if(pSearch == tree->root){
							tree->root = temp;
							temp->parent = NULL;
						}else{
							if(parent(pSearch)->fs == pSearch){
								parent(pSearch)->fs = temp;
								temp->parent = parent(pSearch);
							}else{
								parent(pSearch)->nb = temp;
								temp->parent = parent(pSearch);
							}
						}
						pDelete = nb(temp);
						nb(temp) = NULL;
						nb(pDelete) = fs(pSearch);
						fs(pDelete)->parent = pDelete;
						fs(pSearch) = NULL;
					}
				}
			}
		}
	}
}

void nbPre2(nbAddr root, char tab[]){
	nbAddr px;
	char temptab[255];
	strcpy(temptab,tab);
	strcat(temptab,">");
	if (root!=NULL){
		printf("\n%sNama : %s || Umur : %d || Jenis Kelamin : %c || Religion : %s ||",tab,root->nama,root->usia,root->jenis_kelamin,root->religion);
		nbPre2(root->fs,temptab);
		nbPre2(root->nb,tab);
	}
}

//void LihatIdentitas(nbAddr tr,nbType data){
//	Tree src;
//	Queue Q;
//	
//	if ((src=Search(tr, data))!=NULL){
//		if (pr(src)!=NULL){
//			gotoxy(100,21); printf("Ditemukan!");
//			gotoxy(100,23); printf("Gelar Kebangsawanan: "); jabatan(src,Q);
//			gotoxy(100,24); printf("Nama Depan: %s", name(src));
//			if (JK(src)=='L'||JK(src)=='l'){
//				gotoxy(100,25); printf("Nama Belakang: %ssson", name(pr(src)));
//				gotoxy(100,26); printf("Jenis Kelamin: Laki - Laki");
//			}else if(JK(src)=='P'||JK(src)=='p'){
//				gotoxy(100,25); printf("Nama Belakang: %ssdottir", name(pr(src)));
//				gotoxy(100,26); printf("Jenis Kelamin: Perempuan");
//			}
//			gotoxy(100,27); printf("Usia: %d tahun", US(src));
//		}else{
//			gotoxy(100,21); printf("Ditemukan!");
//			gotoxy(100,23); printf("Gelar Kebangsawanan: "); jabatan(src,Q);
//			gotoxy(100,24); printf("Nama: %s", name(src));
//			if (JK(src)=='L'||JK(src)=='l'){
//				gotoxy(100,25); printf("Jenis Kelamin: Laki - Laki");
//			}else if(JK(src)=='P'||JK(src)=='p'){
//				gotoxy(100,25); printf("Jenis Kelamin: Perempuan");
//			}
//			gotoxy(100,26); printf("Usia: %d tahun", US(src));
//		}
//	}else{
//		gotoxy(100,21); printf("Nama tersebut tidak ada pada Silsilah Kerajaan LEGARDE\n");
//	}
//}
