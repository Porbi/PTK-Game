#ifndef CROSSCIRCLE_
#define CROSSCIRCLE_


int wczytanie_deklaracji(void);
int wczytaj_symbol_gracza(void);

void ruch_gracz_2(int wybor_gracza2, int tablica[3][3]);

void gracz2(void);

int sprawdzam_poziom(int tryb, int tablica[3][3]);
int sprawdzam_pion(int tryb, int tablica[3][3]);
int sprawdzam_skosy(int tryb, int tablica[3][3]);
int zagrozenie(int tryb, int tablica[3][3]);

int poziom_trudnosci(void);

void ruch_szympansa(int tablica[3][3]);
void ruch_komputera(int tablica[3][3]);
void ruch_pierwszy(int tablica [3][3]);
int ruch_drugi(int tablica [3][3]);
void ruch_trzeci(int scenariusz, int tablica [3][3]);
int strategiczny_ruch_komputera(int ktory, int scenariusz, int tablica[3][3]);
void ruch_gracz_1(int wybor_gracza1, int tablica[3][3]);



#endif // CROSSCIRCLE_
