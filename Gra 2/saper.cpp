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

bool ustaw_mine (int poz_x, int poz_y)
{
    if (plansza[poz_x][poz_y].wartosc!=9)
    {
        plansza[poz_x][poz_y].wartosc = 9; //ustawiamy mine
        
        for (int k = -1; k<2; k++)
        for (int l = -1; l<2; l++)
        {
            if ((poz_x+l)<0 || (poz_y+k)<0 ) continue; //wyjdz bo krawedz
            if ((poz_x+l)>9 || (poz_y+k)>9 ) continue; //wyjdz bo krawedz
            
            if (plansza[poz_x+l][poz_y+k].wartosc==9) continue; //wyjdz bo mina
            plansza[poz_x+l][poz_y+k].wartosc += 1; //zwieksz o 1
        }
    }
    
    return true;
}

void odkryj_plansze(int x, int y)
{
    if (x<0 || x>9) return; // poza tablic¹ wyjœcie
    if (y<0 || y>9) return; // poza tablic¹ wyjœcie
    if (plansza[x][y].odkryte==true) return;  // ju¿ odkryte wyjœcie

    if(plansza[x][y].wartosc!=9 && plansza[x][y].odkryte==false)
        plansza[x][y].odkryte=true;   // odkryj!

    if (plansza[x][y].wartosc!=0) return; // wartoœæ > 0 wyjœcie

    //wywo³anie funkcji dla ka¿dego s¹siada
    odkryj_plansze(x-1,y-1);
    odkryj_plansze(x-1,y);
    odkryj_plansze(x-1,y+1);
    odkryj_plansze(x+1,y-1);
    odkryj_plansze(x+1,y);
    odkryj_plansze(x+1,y+1);
    odkryj_plansze(x,y-1);
    odkryj_plansze(x,y);
    odkryj_plansze(x,y+1);
}

