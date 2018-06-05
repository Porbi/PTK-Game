
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
