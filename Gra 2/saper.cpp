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

bool genruj_plansze ()
{
    for (int x = 0; x<10; x++)
    for (int y = 0; y<10; y++)
    {
        plansza[x][y].wartosc = 0;
        plansza[x][y].odkryte = false;
    }
    return true;
}

void pokaz_plansze()
{
    system ("cls"); //wyczysc ekran

    for (int i = 0; i<10; i++)
    {
        for (int j = 0; j<10; j++)
        {
            if (j==poz_x && i==poz_y) //aktualkna pozycja kursora
            {
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE  ), 0x02);
                cout << "#";
            }
            else
            {
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE  ), 0x07);
                if (plansza[j][i].odkryte==true) // pole odkryte
                {
                    if (plansza[j][i].wartosc==0)   //wartosc = 0
                        cout << " ";                //wyswietl spacje
                    else
                        cout << plansza[j][i].wartosc; //wyswietl wartosc 1-8

                }
                if (plansza[j][i].odkryte==false) //pole nie odkryte
                    cout << "#"; //wyswietl #
            }
        }
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
        cout << endl;
    }

    cout << "\npozycja kursora:\n";  //aktualkna pozycja kursora
    cout << "X: " << poz_x << endl;  //aktualkna pozycja kursora
    cout << "Y: " << poz_y << endl;  //aktualkna pozycja kursora
}
