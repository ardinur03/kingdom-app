/*
File	: nbtree.cpp
Deskripsi : spesifikasi program ADT Non Binary Tree Dinamis
Author	: SN
Created : 25-5-2011
Last Update : 25-4-2020
*/
#include "nbtree_d.h"

// void nbCreate(nbTree *x){// Create New Root
// 	(*x).root=NULL;
// }

// nb ref

// nbAddr nbCNode(nbType X){// Create New Node
// 	nbAddr newNode;
// 	newNode=(nbAddr) malloc(sizeof(nbTreeNode));
// 	if (newNode != NULL){
// 		newNode->fs=NULL;
// 		newNode->info=X;
// 		newNode->nb=NULL;
// 		newNode->parent=NULL;
// 	}
// 	return newNode;
// }

// void nbInsert(nbTree *tRoot, nbAddr parent, nbType X){// Insert New Node baru dengan keadaan tertentu
// 	nbAddr newNode, temp;
// 	newNode=nbCNode(X);
// 	if (newNode !=NULL){ //Jika penciptaan node baru berhasil
// 		if (parent==NULL) //JIka belum terdapat root
// 			tRoot->root=newNode;
// 		else{
// 			temp=parent;
// 			if (temp->fs != NULL){
// 				temp=temp->fs;
// 				while(temp->nb!=NULL)
// 					temp=temp->nb;
// 				temp->nb=newNode;
// 			}else
// 				temp->fs=newNode;
// 			newNode->parent=parent;
// 		}
// 	}
// }

// nbAddr nbSearch(nbAddr root, nbType src){
// 	nbAddr nSrc;
// 	if (root!=NULL){
// 		if (root->info==src)
// 			return root;
// 		else{
// 			nSrc=nbSearch(root->fs,src);
// 			if (nSrc==NULL)
// 				return nbSearch(root->nb,src);
// 			else
// 				return nSrc;
// 		}
// 	}
// 	return NULL;
// }

// void nbUpgrade(nbAddr *root){
// 	nbAddr temp;
// 	temp=(*root)->nb;
// 	if ((*root)->fs==NULL)
// 		(*root)->fs=temp;
// 	while(temp!=NULL){
// 		temp->parent=*root;
// 		temp=temp->nb;
// 	}
// }

// void nbDelete(nbAddr *pDel, nbTree *pTree){
// 	nbAddr pCur;
// 	pCur=*pDel;

// 	if (pCur==pTree->root && pCur->fs==NULL){
// 		pTree->root=NULL;
// 		return;
// 	}

// 	while(pCur->fs!=NULL)
// 		pCur=pCur->fs;

// 	while (pCur!=*pDel){
// 		nbUpgrade(&pCur);
// 		if (pCur->parent!=NULL)
// 			pCur->nb=pCur->parent->nb;
// 		else
// 			pCur->nb=NULL;
// 		pCur=pCur->parent;
// 	}

// 	if (pCur->parent!=NULL)
// 		pCur->parent->fs=pCur->fs;
// 	if (pCur->fs!=NULL)
// 		pCur->fs->parent=pCur->parent;
// 	if (pCur->parent==NULL)
// 		pTree->root=pCur;
// }


/* ---------------- TRAVERSAL Tree ---------------- */
// void nbPost(nbAddr root){
// 	if (root!=NULL){
// 		nbPost(root->fs);
// 		printf("%d ", root->info);
// 		nbPost(root->nb);
// 	}
/*
// Post Order Non Rekursif -> selesai
nbAddr pCur;
	boolean arah;
	arah=0;

	pCur=pTree.root;
	do{
		if(pCur->fs!=NULL && arah==0)
			pCur=pCur->fs;
		else{
			printf("%d ", pCur->info);
			arah=0;
			if (pCur->nb!= NULL)
				pCur=pCur->nb;
			else{
				pCur=pCur->parent;
				arah=1;
			}
		}
	}while(pCur!=NULL);
*/
// }

// void nbPre(nbAddr root){
// 	if (root!=NULL){
// 		printf("%d ", root->info);
// 		nbPre(root->fs);
// 		nbPre(root->nb);
// 	}

// Pre order Non Rekursif -> Selesai
// nbAddr pCur;
// 	boolean arah;
// 	arah=0;

// 	pCur=pTree.root;
// 	printf("%d ", pCur->info);
// 	do{
// 		if(pCur->fs!=NULL && arah==0){
// 			pCur=pCur->fs;
// 			printf("%d ", pCur->info);
// 		}else{
// 			arah=0;
// 			if (pCur->nb!= NULL){
// 				pCur=pCur->nb;
// 				printf("%d ", pCur->info);
// 			}else{
// 				pCur=pCur->parent;
// 				arah=1;
// 			}
// 		}
// 	}while(pCur!=NULL);*/

// }

// void nbIn(nbAddr root){
// 	if (root!=NULL){
// 		nbIn(root->fs);
// 		if (root->fs==NULL) printf("%d ", root->info);
// 		if (root->parent !=NULL)
// 			if (root->parent->fs==root)
// 				printf("%d ", root->parent->info);
// 		nbIn(root->nb);
// 	}

/*
// Inorder non rekursif -> belum selesai
	nbAddr pCur;
	int arah;
	arah=0;

	pCur=pTree.root;
	do{
		if(pCur->fs!=NULL && arah==0){
			pCur=pCur->fs;
		}else{
			if (pCur->nb!= NULL){
				printf("%d ", pCur->info);
				pCur=pCur->nb;
			}else{
					printf("%d ", pCur->info);
					arah=1;
				pCur=pCur->parent;
			}
			if (arah==0 && pCur->parent!=NULL)
				printf("%d ", pCur->parent->info);
			if (arah==0) arah=1;
		}
	}while(pCur!=NULL);
*/
// }



// void nbLevelOrder(nbAddr root,int curLevel, int desLevel)
// {
// 	if(root!=NULL)
// 	{
// 		if(curLevel==desLevel)
// 			printf("%d  ",root->info);
// 		nbLevelOrder(root->fs,curLevel+1,desLevel);
// 		nbLevelOrder(root->nb,curLevel,desLevel);
// 	}
// }

// int nbDepth(nbAddr root)
// {
// 	int y,z;

// 	if(root==NULL)
// 		return -1;
// 	y=nbDepth(root->fs);
// 	z=nbDepth(root->nb);
// 	if (y > z)
// 		return (y+1);
// 	else
// 		return (z+1);
// }

// void nbPrint(nbAddr node, char tab[]){
// 	char tempTab[255];
// 	strcpy(tempTab, tab);
// 	strcat(tempTab, "-");
// 	if (node!=NULL){
// 		printf("%s%d\n",tab,node->info);
// 		nbPrint(node->fs,tempTab);
// 		nbPrint(node->nb,tab);
// 	}
// }
/*
void nbPrint(nbAddr node, char *tab){
	char *tempTab;
	tempTab = tab;
	strcat(tempTab, "-");
	if (node!=NULL){
		printf("%s%d\n",tab,node->info);
		nbPrint(node->fs,tempTab);
		nbPrint(node->nb,tab);
	}
}
*/
