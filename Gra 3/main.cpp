


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
