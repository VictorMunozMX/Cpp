#include <iostream>

constexpr int WIDTH = 3;
constexpr int HEIGHT = 3;
using namespace std;

class TicTacToe {
private:

    char board[WIDTH][HEIGHT];
    char cSystem = ' ';
    char cPlayer = 'X';

public:
    TicTacToe() {
        // Constructor method
        // Parameters:
        // return value: 
        // 3 Marks
        // TODO: Initialize the board with empty spaces (e.g., ' ')
        // This method will fill the entire 3x3 board with the character ' '
        // 

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = cSystem;
            }
        }
    }

    void printBoard() {
        // Parameters:      none
        // return value:    none
        // 4 Marks
        // TODO: Implement the logic to print the board
        // Each element of the array is displayed on the screen as follows. 
        // a sample board is shown below:
        //  x0x
        //   x 
        //  0 0
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }

    bool setMark(int row, int col, char player) {
        // Parameters:      integer for row, integer for column and character for the player (x or o)
        // return value:    bool indicating whether the location is valid or not.
        // 3 marks
        // TODO: Place the player's mark on the board if the cell is empty
        // If the place on the board is empty, place the mark. If it is not, make no changes and return false.        
        if (board[row][col] == cSystem)
        {
            board[row][col] = player;
        }
        else
        {
            return false;
        }
    }
    char getMark(int row, int col) {
        // Parameters:      integer for row and column.
        // return value:    character at that location in the array.
        // 3 Marks
        // TODO: write a method that returns the character that is placed
        // at 'row' and 'column'. 
        return board[row][col];
    }

    bool checkWin() {
        // Parameters:      none
        // return value:    boolean indicating whether any player has won
        // 8 Marks
        // TODO: Implement the logic to check if a player has won by connecting 3 in a row
        // either vertically, horizontally or diagonally.

        // horizontally                            
        bool act = false;
        int x;
        for (int i = 0; i < 3; i++) {
            x = 1;
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == cSystem || board[i][j] != cPlayer)
                {
                    x = 0;
                }
            }
            if (x == 1) {
                act = true;
            }
        }

        // vertically
        for (int i = 0; i < 3; i++) {
            x = 1;
            for (int j = 0; j < 3; j++) {
                if (board[j][i] == cSystem || board[j][i] != cPlayer)
                {
                    x = 0;
                }
            }
            if (x == 1) {
                act = true;
            }
        }

        // diagonally    
        char cPlayer = 'X';
        if (board[0][0] == cPlayer && board[1][1] == cPlayer && board[2][2] == cPlayer) {
            act = true;
        }
        if (board[0][2] == cPlayer && board[1][1] == cPlayer && board[2][0] == cPlayer) {
            act = true;
        } 

        if (act)
        {
            return true;
        }

    }

    bool checkDraw() {
        // Parameters:      none
        // return value:    boolean indicating whether the game is over
        // 4 Marks
        // TODO: Implement the logic to check for a draw
        // if all the spaces have been taken on the board, the game
        // is a draw and return true.  If not, return false.
        bool drawing = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == cSystem)
                {
                    drawing = false;
                }
            }
        }
        return drawing;
    }
};

int main() {
    TicTacToe game;
    int row, col;
    char currentPlayer = 'X';

    // Game loop
    while (true) {
        game.printBoard();

        // Ask for player input
        std::cout << "Player " << currentPlayer << ", enter row and column to place your mark: ";
        std::cin >> row >> col;

        // Place mark and check for win/draw
        if (game.setMark(row, col, currentPlayer)) {
            //check to see if someone wins
            if (game.checkWin()) {
                game.printBoard();
                std::cout << "\n\nPlayer " << currentPlayer << " wins!" << std::endl;
                std::cout << "\nYou are an excellent player!" << std::endl;
                break;
            }
            //check to see if the game is a draw
            else if (game.checkDraw()) {
                std::cout << "The game is a draw!" << std::endl;
                break;
            }
            // change players from x to o or vice versa
            if (currentPlayer == 'X')
            {
                currentPlayer = 'O';
            }
            else
            {
                currentPlayer = 'X';
            }
        }
        else {
            std::cout << game.getMark(row, col) << " is already placed there. ";
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }
    return 0;
}