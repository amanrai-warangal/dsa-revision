#include"main.cpp"

int main() {
    TicTacToeGame game;
    game.initializeGame();
    string result = game.startGame();
    cout << "\nGame Over! Result: " << result << endl;
    return 0;
}