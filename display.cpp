#include "display.h"

void gotoxy(short x, short y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

void kingDisplay(){
  // open file txt
  FILE *fp;
  char line;
  fp = fopen("king.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening file!\n");
    exit(1);
  }
  // read file txt
  do 
  {
    line = fgetc(fp);
    putchar(line);

  } while(line != EOF);
  fclose(fp);
}