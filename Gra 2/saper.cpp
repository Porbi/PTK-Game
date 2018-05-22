#include <conio.h>
#include <windows.h>
#include <iostream>
#include <time.h>

#define strzalka_lewo 0x25
#define strzalka_prawo 0x27
#define strzalka_dol 0x28
#define strzalka_gora 0x26

#define enter 0x0D


using namespace std;

struct pole
{
    int wartosc;
    bool odkryte;                                       
};

pole plansza[10][10];

int poz_x = 0, poz_y = 0, o_poz_x = 1, o_poz_y = 1;
int koniec = 0;
