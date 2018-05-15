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
