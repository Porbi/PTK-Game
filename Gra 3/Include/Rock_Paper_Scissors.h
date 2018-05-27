class Player {

public:
    Player() : _score(0), _choice(0) {}
    void add_choice(int choice) { _choice = choice; }
    void raise_score() { _score++; }
    const int& get_choice() const { return _choice; }
    const std::size_t& get_score() const { return _score; }
    ~Player() = default;

private:
    std::size_t _score;
    int _choice;
};

std::string choose_round_winner(Player& human, Player& computer);

class Output {

public:
    void show_start() const;
    void show_choices() const;
    void show_chosen(int player_choice, int computer_choice) const;
    void show_score(std::size_t player_score, std::size_t computer_score) const;
    void show_round_winner(std::string r_winner) const;
    void show_final_score(std::size_t human_score, std::size_t computer_score) const;
    ~Output() = default;
};

class Input {

public:
    void ask_choice(Player& player);
    void ask_round(int& round_count);
    ~Input() = default;
};







#endif //RPS_ROCK_PAPER_SCISSORS_H


