#include "display.h"

void gotoxy(short x, short y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

void istanaDisplay(){
	// open file txt
	FILE *fp;
	char line;
	int i = 0;
	// open file in directory assets
	fp = fopen("assets/istana.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	// read file txt

	do 
	{
		line = fgetc(fp);
		printf("%c", line);
		i++;
	} while(line != EOF);
	fclose(fp);
}

void aturanDisplay(){
	// open file txt
	FILE *fp;
	char line;
	int i = 0;
	// open file in directory assets
	fp = fopen("assets/aturanKerajaan.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	// read file txt

	do 
	{
		line = fgetc(fp);
		printf("%c", line);
		i++;
	} while(line != EOF);
	fclose(fp);
	boxMenuOutput();
	printf("ketik enter untuk kembali ...");
	getch();
}

void kingDisplay(){
  // open file txt
  FILE *fp;
  char line;
  int i = 0;
  fp = fopen("assets/king.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening file!\n");
    exit(1);
  }
  // read file txt

  do 
  {
    line = fgetc(fp);
    printf("%c", line);
    i++;
  } while(line != EOF);
  fclose(fp);
}

void boxMenuOutput(){
	int x=2, y=2;
	gotoxy(99,0); printf("%c",201); // box atas ╔
	gotoxy(161,0); printf("%c",187); // box atas ╗
	gotoxy(100,0); 
	for(int i=0;i<61;i++){ // horizontal atas
		printf("%c",205);
	}
	gotoxy(99,4); printf("%c", 204);
	gotoxy(161,4); printf("%c", 185);
	for(int i=0;i<3;i++){ // vertikal atas kiri
		gotoxy(99,1+i);
		printf("%c",186);
	}
	for(int i=0;i<3;i++){
		gotoxy(161,1+i);
		printf("%c",186);
	}
	gotoxy(100,4);
	for(int i=0;i<61;i++){
		printf("%c",205);
	}
	for(int i=0;i<9;i++){ // vertikal kiri atas
		gotoxy(99,5+i);
		printf("%c",186);
	} 
	for(int i=0;i<9;i++){ // vertikal kanan atas
		gotoxy(161,5+i); 
		printf("%c",186);
	}
	gotoxy(99,13); printf("%c",200);
	gotoxy(161,13); printf("%c",188);
	gotoxy(100,13);
	for(int i=0;i<61;i++){
		printf("%c",205);
	}
	
	gotoxy(99,14); printf("%c",201);
	gotoxy(161,14); printf("%c",187);
	gotoxy(100,14);
	for(int i=0;i<61;i++){
		printf("%c",205);
	}
	for(int i=0;i<19;i++){
		gotoxy(99,15+i);
		printf("%c",186);
	}
	for(int i=0;i<19;i++){
		gotoxy(161,15+i);
		printf("%c",186);
	}
	gotoxy(99,34); printf("%c",200);
	gotoxy(161,34); printf("%c",188);
	gotoxy(100,34);
	for(int i=0;i<61;i++){
		printf("%c",205);
	}

	gotoxy(101, 2);
	printf("                        MENU KERAJAAN ");
	gotoxy(101, 5);
	printf("1. Tambah Anggota Kerajaan");
	gotoxy(101, 6);
	printf("2. Tampilkan Silsilah");
	gotoxy(101, 7);
	printf("3. Hitung Anak"); 
	gotoxy(101, 8);
    printf("4. Urutan Pewaris");
	gotoxy(101, 9);
    printf("5. Turunkan Tahta Raja");
	gotoxy(131, 5);
	printf("6. Peraturan");
	gotoxy(131, 6);
	printf("0. Exit");
	gotoxy(101, 12);
	printf("Pilih: ");
}

