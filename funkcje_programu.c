#include "funkcje_programu_2.h"
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
