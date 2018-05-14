#include "crosscircle.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int wczytanie_deklaracji(void)
{
   int zmienna=0;
   do
   {
      puts("Prosze wybrac dla gracza 1. (1=X;2=O)\n");
      scanf(" %d", &zmienna);
      while (getchar()!= '\n');
   }while(!(zmienna == 1 || zmienna == 2));
   return zmienna;
}

int wczytaj_symbol_gracza(void)
{
   int wybor = wczytanie_deklaracji();
   switch(wybor)
   {
      case 1:
         wybor = WARTOSC_X;
         break;
      case 2:
         wybor = WARTOSC_O;
         break;
   }
   return wybor;
}


void ruch_gracz_2(int wybor_gracza2, int tablica[3][3])
{
   gracz2();
   ruch(wybor_gracza2, tablica);
   wypisz_tablice(tablica);
   if (sprawdz_wygrana(tablica) == 1)
   {
      wypisz_tablice(tablica);
      exit(0);
   }
}

void gracz2(void)
{
    puts("Kolej gracza 2\n");
}

int sprawdzam_poziom(int tryb, int tablica[3][3])
{
   int suma = 0;
   for(int a = 0; a < 3; a++)
   {
       suma = 0;
       for(int i = 0; i < 3; i++)
       {
          suma += tablica[a][i];
       }
       if (suma == tryb)
       {
          for(int j = 0; j < 3; j++)
          {
             if(tablica[a][j] == 0)
             {
                tablica[a][j] = 1;
            }
          }
       return 1;
       }
    }
    return 0;
}


int sprawdzam_pion(int tryb, int tablica[3][3])
{
   int suma = 0;
   for(int a = 0; a < 3; a++)
   {
      suma = 0;
      for(int i = 0; i < 3; i++)
      {
         suma += tablica[i][a];
      }
      if(suma == tryb)
      {
         for(int j = 0; j < 3; j++)
         {
            if(tablica[j][a] == 0)
            {
                tablica[j][a] = 1;
            }
         }
         return 1;
      }
   }
   return 0;
}

int sprawdzam_skosy(int tryb, int tablica[3][3])
{
   int suma = tablica[0][0]+tablica[1][1]+tablica[2][2];
   if(suma == tryb)
   {
      for(int c = 0; c < 3; c++)
      {
         if(tablica[c][c] == 0)
         {
            tablica[c][c] = 1;
         }
      }
      return 1;
   }

   suma = (tablica[0][2]+tablica[1][1]+tablica[2][0]);
   if(suma == tryb)
   {
      int e = 0;
      for (int d = 2; d > -1; d--)
      {
         if(tablica[e][d] == 0)
         {
            tablica[e][d] = 1;
         }
         e++;
      }
      return 1;
   }
   return 0;
}


int zagrozenie(int tryb, int tablica[3][3])
{
   return sprawdzam_pion(tryb,tablica) == 1 || sprawdzam_poziom(tryb,tablica) == 1 || sprawdzam_skosy(tryb,tablica) == 1;
}
