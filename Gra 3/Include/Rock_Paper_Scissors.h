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



