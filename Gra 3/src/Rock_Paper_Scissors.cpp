#include "../include/Rock_Paper_Scissors.h"

void Output::show_start() const {
    std::string name = "[ROCK PAPER SCISSORS GAME]";
    std::cout<< name << std::endl;
    pause(1);
    std::cout<< "\nRULES:\n";
    pause(1);
    std::cout<< "- Rock beats Scissors\n";
    pause(1);
    std::cout<< "- Paper beats Rock\n";
    pause(1);
    std::cout<< "- Scissors beat Paper\n\n\n";
    pause(5);
}

void Output::show_choices() const {
    std::cout << "       |CHOICES|" << std::endl;
    pause(1);
    std::cout << "\n1. ROCK, ";
    std::cout << "2. PAPER, ";
    std::cout << "3. SCISSORS" << std::endl;
    pause(1);
    std::cout << "\nOR" << std::endl;
    pause(1);
    std::cout << "4. Quit Game" << std::endl;
    pause(2);
}

void Output::show_chosen(int player_choice, int computer_choice) const {
    std::cout << "Your choice: ";
    if (player_choice == 1) {
        std::cout << "Rock";
    } else if(player_choice == 2) {
        std::cout << "Paper";
    } else if(player_choice == 3) {
        std::cout << "Scissors";
    }
    std::cout << std::endl;
    pause(1);
    std::cout << "Computer choice: ";
    if (computer_choice == 1) {
        std::cout << "Rock";
    } else if(computer_choice == 2) {
        std::cout << "Paper";
    } else if(computer_choice == 3) {
        std::cout << "Scissors";
    }
    std::cout << "\n" << std::endl;
    pause(1);
}

void Output::show_round_winner(std::string r_winner) const {
    std::cout << "Winner is: "
    << r_winner << std::endl;
}


void Output::show_score(std::size_t player_score, std::size_t computer_score) const {
    std::cout << "Score:\n" << std::endl;
    pause(1);
    std::cout << "Your score: "
    << player_score << std::endl;
    pause(1);
    std::cout << "Computer score: "
    << computer_score << std::endl;
}

void Output::show_final_score(std::size_t human_score, std::size_t computer_score) const {
    std::cout << "FINAL SCORE:\n" << std::endl;
    pause(2);
    std::cout << "You: " << human_score << std::endl;
    pause(2);
    std::cout << "Computer: " << computer_score << "\n" << std::endl;
    pause(2);
    if (human_score > computer_score) {
        std::cout << "You Won" << std::endl;
        pause(2);
        std::cout << "Congratulations\n" << std::endl;
        std::cout << "Thank You for playing." << std::endl;
        exit(0);
    } else if (human_score < computer_score) {
        std::cout << "Computer Won" << std::endl;
        pause(2);
        std::cout << "Try again\n" << std::endl;
        std::cout << "Thank You for playing." << std::endl;
        exit(0);
    } else if (human_score == computer_score) {
        std::cout << "DRAW" << std::endl;
        pause(2);
        std::cout << "Thank You for playing." << std::endl;
        exit(0);
    }
}






void Input::ask_round(int& round_count) {
    std::cout << "Number of rounds: ";
    std::cin >> round_count;
    if (round_count <= 0) {
        while (true) {
            std::cout << "Error: Incorrect number" << std::endl;
            std::cout << "Number of rounds: ";
            std::cin >> round_count;
            if (round_count > 0) {
                break;
            }
        }
    }
}





void pause(useconds_t time) {
    usleep(time * 1000000);
}


int random_number() {
    int number = rand() %3 + 1;
    return number;
}
