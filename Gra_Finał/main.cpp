#include "include/Rock_Paper_Scissors.h"
#include "src/funkcje_programu.c"



int main() {
    std::cout << "       |WELCOME|" << std::endl;
    pause(2);
    clear_screen();
    std::cout << "\n\n       |MENU|" << std::endl;
    pause(1);
    std::cout << "\n\n1. ROCK PAPER SCISSORS" << std::endl;
    pause(1);
    std::cout << "2. XOXOXO" << std::endl;
    pause(1);
    std::cout << "3. END" << std::endl;
    pause(1);
    std::cout << "\n\n\nCHOOSE: ";
    int main_choice = 0;
    std::cin >> main_choice;
    if (main_choice < 1 || main_choice > 3) {
        while (true) {
            std::cout << "Error: Incorrect number\n";
            std::cout << "CHOOSE: ";
            std::cin >> main_choice;
            if (main_choice > 1 && main_choice < 3) {
                break;
            }
        }
    }
    Player human;
    Player computer;
    Output output;
    Input input;
    int round_count = 0;
    switch (main_choice) {

        case 1 :
            output.show_start();
            input.ask_round(round_count);
            for (int round = 1; round <= round_count; round++) {
                clear_screen();
                if (round == round_count && round != 1) {
                    std::cout << "FINAL ROUND" << std::endl;
                    pause(2);
                    clear_screen();
                }
				
                std::cout << "        ROUND " << round << std::endl;
                std::cout << "-------------------------------------" << std::endl;
                output.show_choices();
                std::cout << "\n\n" << std::endl;
                input.ask_choice(human);
                if (human.get_choice() == 4) {
                    std::cout << "Thank You for playing." << std::endl;
                    exit(0);
                }
                computer.add_choice(random_number());
                output.show_chosen(human.get_choice(), computer.get_choice());
                output.show_round_winner(choose_round_winner(human, computer));
                std::cout << std::endl;
                output.show_score(human.get_score(), computer.get_score());
                pause(3);
                std::cout << "-------------------------------------" << std::endl;
                std::cout << "-------------------------------------" << std::endl;
                pause(2);
                clear_screen();
                pause(1);
                if (round < round_count) {
                    std::cout << "Get Ready" << std::endl;
                } else if (round == round_count) {
                    std::cout << "Calculating results..." << std::endl;
                }
                pause(2);
            }
            clear_screen();
            output.show_final_score(human.get_score(), computer.get_score());
            break;

        case 2 :

            time_t t;
            srand((unsigned) time(&t));
            puts("Witaj w grze w kolko i krzyzyk\nWybor miejsca na wstawienie znaku odbywa sie przez podanie 2 liczb.\n"
                         "Pierwsza liczba odpowiada wspolrzednej pionowej(kolumna)\n"
                         "Druga z nich odpowiada wspolrzednej poziomej(wiersz)");
            int tablica[3][3];
            czysc_tablice(tablica);
            switch (tryb_gry()) {
                case 1: {
                    wypisz_tablice(tablica);
                    int wybor_gracza1;
                    int wybor_gracza2;
                    switch (wczytaj_symbol_gracza()) {
                        case WARTOSC_X:
                            wybor_gracza1 = 1;
                            wybor_gracza2 = 2;
                            break;
                        case WARTOSC_O:
                            wybor_gracza1 = 2;
                            wybor_gracza2 = 1;
                            break;
                    }
                    for (int i = 0; i < 4; i++) {
                        ruch_gracz_1(wybor_gracza1, tablica);
                        ruch_gracz_2(wybor_gracza2, tablica);
                    }
                    ruch_gracz_1(wybor_gracza1, tablica);
                    puts("\n\nRemis\n\n");
                    return 0;
                }
                case 2:
                    switch (poziom_trudnosci()) {
                        case TRUDNOSC_SZYMPANS: {
                            puts("/n");
                            wypisz_tablice(tablica);
                            puts("Komputer - X, gracz - Y\n");
                            for (int i = 0; i < 4; i++) {
                                ruch_szympansa(tablica);
                                wypisz_tablice(tablica);
                                puts("\n");
                                if (sprawdz_wygrana(tablica) == 1) {
                                    wypisz_tablice(tablica);
                                    puts("\n");
                                    return 0;
                                }
                                ruch_gracz_1(2, tablica);
                            }
                            ruch_gracz_1(2, tablica);
                            puts("\n\nRemis\n\n");
                            return 0;
                        }
                    }
            }
        case 3 :
            std::cout << "See You Later" << std::endl;
            pause(1);
            exit(0);
    }
}
