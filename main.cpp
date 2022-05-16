/**
 * @file main.cpp
 * @author 
 *  	- Irfan Khoirul 
 *      - Muhamad Ardi Nur Insan - 211511022
 * @brief 
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "silsilah.h"
#include "display.h"

int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	
	TreeSilsilah Tree;
	nbAddr src, deleteNode;
	int pil;
	nbType parentTempInput, namaNode;
	Queue Q;
	char str[] = "\t";

	Isi_Node_Silsilah(&Tree.root, "root", 'l', 21, "Protestan"); // root node
	nbInsert(&Tree, nbSearch(Tree.root,"root"), "raja" , 'P', 68, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root,"root"), "calon raja 1", 'P', 68, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root,"calon raja 1"), "Anak calon raja 1", 'P', 68, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root,"calon raja 1"), "Anak calon raja 1", 'P', 68, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root,"root"), "calon raja 2", 'P', 68, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root,"root"), "calon raja 3", 'P', 68, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root,"root"), "calon raja 4", 'P', 68, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root,"calon raja 4"), "Anak raja 4", 'P', 68, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root,"calon raja 4"), "Anak raja 4", 'P', 68, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root,"root"), "calon raja 5", 'P', 68, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root,"root"), "calon raja 6", 'P', 68, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root,"root"), "calon raja 7", 'P', 68, "Protestan");

	for (;;)
	{
		system("cls");
		gotoxy(1, 5);
		kingDisplay();
		
		gotoxy(100, 9);
		printf("====================== MENU KERAJAAN ======================");
		gotoxy(100, 12);
		printf("1. Tambah Anggota Kerajaan");
		gotoxy(100, 13);
		printf("2. Tampilkan Silsilah");
		gotoxy(100, 14);
		printf("3. Hitung Anak"); 
		gotoxy(100, 15);
	    printf("4. Urutan Pewaris");
		gotoxy(100, 16);
	    printf("5. Turunkan Tahta Raja");
		gotoxy(100, 17);
		printf("0. Exit");
		gotoxy(100, 18);
		printf("Pilih: ");
		scanf("%d", &pil);
		switch (pil)
		{
		case 1:	
			printf("\n\n");
			InsertSilsilah(&Tree.root);
			printf("\n\n");
			getch();
			break;
		case 2:
			if (isSilsilahEmpty(Tree.root))
			{
				gotoxy(100, 20);
				printf("Belum ada siapapun disini");
				getch();
				break;
			}
			cetakSilsilah(Tree.root, str);
			getch();
			break;
		case 3:
			int src;
			if (isSilsilahEmpty(Tree.root))
			{
				gotoxy(100, 20);
				printf("Belum ada siapapun disini");
				getch();
				break;
			}
			gotoxy(100, 20);
			printf("Masukkan nama parent : ");
			scanf("%s", parentTempInput);
			src = hitungAnak(Tree.root, parentTempInput);
			if (src == NULL)
			{
				gotoxy(100, 21);
				printf("Parent %s tidak memiliki anak", parentTempInput);
				getch();
				break;
			}
			gotoxy(100, 21);
			printf("Jumlah anak dari %s yaitu : %d", parentTempInput, src);
			getch();
			break;
		case 4:
			urutanPewaris(Tree.root);
			getch();
			break;
		case 5:
			// printf("Masukkan Anggota yang akan di Delete = ");
			// printf("Data : ");
			// gets(namaNode);
			// if (deleteNode!=NULL){
			// 	nbDelete(&Tree, namaNode);
			// }else{
			// 	printf("Data Tidak Ada!!!");
			// }
			getch();
			break;
		case 0:
			exit(0);
			break;
		default:
			gotoxy(100, 20);
			printf("!!Inputan tidak valid silahkan coba lagi!!");
			getch();
		}
	}

	return 0;
}