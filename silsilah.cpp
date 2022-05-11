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
	nbAddr TNode = NULL,temp = NULL;
	CreateEmptyNode(&TNode);
	char jenis_kelamin;
	int thLahir, usia;
	nbType Nama,parent,Agama;
	address Queue;
	
	if(isSilsilahEmpty(*tr)){
		gotoxy(100,20); printf("Nama : "); fflush(stdin);
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
				gotoxy(100,25); printf("Karena Kosong, %s Menjadi Raja\n",Nama);
			}else if(jenis_kelamin == 'P'||jenis_kelamin == 'p'){
				gotoxy(100,25); printf("Karena Kosong, %s Menjadi Ratu\n",Nama);
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


void cetakSilsilah(nbAddr tr, char tab[]){
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	if (tr!=NULL){
		printf("%s%s\n",tab,tr->nama);
		cetakSilsilah(tr->fs,tempTab);
		cetakSilsilah(tr->nb,tab);
	}
}
