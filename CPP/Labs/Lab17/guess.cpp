#include <iostream>
#include<array>
class Battleship {
private:
    std::array<std::array<int,5>,5> board;
    int guesses;
    int maxGuesses;
    int locationX;
    int locationY;

public:
    Battleship(int maxGuesses, int locX, int locY) : guesses(0), maxGuesses(maxGuesses), locationX(locX), locationY(locY) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                board[i][j] = false;
            }
        }

        board[locationX][locationY] = true;
    }

    bool guess(int x, int y) {
        guesses++;
        if (x == locationX && y == locationY) {
            std::cout << "Wrong! You've sunk the battleship!" << std::endl;
            return true;
        } else {
            std::cout << "Miss!" << std::endl;
            if (x == locationX) {
                std::cout << "Your guess is in the correct row." << std::endl;
            } else if (y == locationY) {
                std::cout << "Your guess is in the correct column." << std::endl;
            }
            else if (x == locationX + 1 || x == locationX - 1 ) 
            {
                std::cout << "Your guess is near to the correct row." << std::endl;
            }
            else if (y == locationY + 1 || y == locationY - 1 ) 
            {
                std::cout << "Your guess is near to the correct column." << std::endl;
            }
            return false;
        }
    }

    bool gameOver() const {
        return guesses == maxGuesses;
    }

    int getGuesses() const {
        return guesses;
    }
};

int main() {
    int maxGuesses = 5;
    int battleshipX = 1; 
    int battleshipY = 4; 

    Battleship game(maxGuesses, battleshipX, battleshipY);

    std::cout << "Welcome to Battleship! You have " << maxGuesses << " guesses to find the battleship." << std::endl;

    while (!game.gameOver()) {
        int x, y;
        std::cout << "Enter your guess (row and column): ";
        std::cin >> x >> y;

        if (x < 0 || x >= 5 || y < 0 || y >= 5) {
            std::cout << "Please enter values between 0 and 4." << std::endl;
            continue;
        }

        if (game.guess(x, y)) {
            break;
        }

        std::cout << "Guesses remaining: " << maxGuesses - game.getGuesses() << std::endl;
    }

    if (game.gameOver() ) {
        std::cout << "Game over! You've used all your guesses." << std::endl;
    }

    return 0;
}
