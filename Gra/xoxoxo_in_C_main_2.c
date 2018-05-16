#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funkcje_programu_2.h"

int main(void)
{
   time_t t;
   srand((unsigned) time(&t));
   puts("Witaj w grze w kolko i krzyzyk\nWybor miejsca na wstawienie znaku odbywa sie przez podanie 2 liczb.\n"
   "Pierwsza liczba odpowiada wspolrzednej pionowej(kolumna)\n"
   "Druga z nich odpowiada wspolrzednej poziomej(wiersz)");
   int tablica[3][3];
   czysc_tablice(tablica);

    switch (tryb_gry())
   {
      case 1:
      {
         wypisz_tablice(tablica);
         int wybor_gracza1;
         int wybor_gracza2;
         switch(wczytaj_symbol_gracza())
         {
            case WARTOSC_X:
               wybor_gracza1 = 1;
               wybor_gracza2 = 2;
               break;
            case WARTOSC_O:
               wybor_gracza1 = 2;
               wybor_gracza2 = 1;
               break;
         }
         for(int i = 0; i < 4; i++)
         {
              ruch_gracz_1(wybor_gracza1, tablica);
              ruch_gracz_2(wybor_gracza2, tablica);
         }
          ruch_gracz_1(wybor_gracza1, tablica);
          puts( "\n\nRemis\n\n");
          return 0;
      }
   }
}
