#include "silsilah.h"
#include "display.h"
int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	nbAddr root = NULL;
	nbAddr src;
	int pil;
	nbType SQ;
	Queue Q;
	char newName[50];
	char str[] = "\t";

	for (;;)
	{
		system("cls");
		gotoxy(100, 9);
		printf("============================ MENU KERAJAAN ============================");
		gotoxy(100, 12);
		printf("[1] Tambah Anggota Kerajaan");
		gotoxy(100, 13);
		printf("[2] Tampilkan Silsilah");
		// gotoxy(100, 14);
		// printf("[3] Lihat Identitas"); 
		// gotoxy(100, 15);
		// printf("[4] Urutan Pewaris");
		gotoxy(130, 12);
		printf("[0] Exit");
		gotoxy(100, 17);
		printf("Pilih: ");
		scanf("%d", &pil);
		switch (pil)
		{
		case 1:
			printf("\n\n");
			InsertSilsilah(&root);
			printf("\n\n");
			getch();
			break;
		case 2:
			if (isSilsilahEmpty(root))
			{
				gotoxy(100, 20);
				printf("Belum ada siapapun disini");
				getch();
				break;
			}
			cetakSilsilah(root, str);
			getch();
			break;
		//case 3:
		// 	if (isSilsilahEmpty(root))
		// 	{
		// 		gotoxy(100, 20);
		// 		printf("Belum ada siapapun disini");
		// 		getch();
		// 		break;
		// 	}
		// 	gotoxy(100, 20);
		// 	printf("Nama     : ");
		// 	fflush(stdin);
		// 	gets(newName);
		// 	LihatIdentitas(root, newName);
		// 	getch();
		// 	break;
		// case 4:
		// 	if (isSilsilahEmpty(root))
		// 	{
		// 		gotoxy(100, 20);
		// 		printf("Belum ada siapapun disini");
		// 		getch();
		// 		break;
		// 	}
		// 	urutanPewaris(root);
		// 	getch();
		// 	break;
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