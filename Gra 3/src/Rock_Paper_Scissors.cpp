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
