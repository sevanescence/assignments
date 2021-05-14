#include <iostream>
#include <string>

using namespace std;

// todo TicTacToeContext, TicTacToe::PlayerDefaults

void setup(string grid[3][3]);
void display(string grid[3][3]);
bool isMoveValid(string grid[3][3], int row, int col, bool player1);
bool checkWinner(string grid[3][3], bool player1);

int main() {
    string grid[3][3];
    bool player1 = true;
    bool winner = false;
    bool valid = false;
    int choice;

    setup(grid);

    while (! winner) {
        display(grid);

        cout << "Player " << (player1 ? "1" : "2") << " enter position: ";
        cin >> choice;

        switch (choice) {
            case 1:
                valid = isMoveValid(grid, 0, 0, player1);
                break;
            case 2:
                valid = isMoveValid(grid, 0, 1, player1);
                break;
            case 3:
                valid = isMoveValid(grid, 0, 2, player1);
                break;
            case 4:
                valid = isMoveValid(grid, 1, 0, player1);
                break;
            case 5:
                valid = isMoveValid(grid, 1, 1, player1);
                break;
            case 6:
                valid = isMoveValid(grid, 1, 2, player1);
                break;
            case 7:
                valid = isMoveValid(grid, 2, 0, player1);
                break;
            case 8:
                valid = isMoveValid(grid, 2, 1, player1);
                break;
            case 9:
                valid = isMoveValid(grid, 2, 2, player1);
                break;
            default:
                cout << "Error: Enter a number from 1-9!" << endl;
        }

        if (valid) {
            winner = checkWinner(grid, player1);
            if (winner) {
                string player = player1 ? "PLAYER 1" : "PLAYER 2";
                display(grid);
                cout << player << " wins!" << endl;
            } else {
                player1 = !player1;
            }
        } else {
            cout << "Enter a different position." << endl;
        }


    } // game loop
}

void setup(string grid[3][3]) {
    int counter = 1;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            grid[row][col] = to_string(counter);
            counter++;
        }
    }
}
void display(string grid[3][3]) { 
    system("clear");
    for (int row = 0; row < 3; row++) {
        cout << " | ";
        for (int col = 0; col < 3; col++) {
            cout << grid[row][col] << " | ";
        }
        cout << endl;
    }
}

bool isMoveValid(string grid[3][3], int row, int col, bool player1) {
    string token = player1 ? "X" : "O";
    bool valid = false;
    if (grid[row][col] != "X" || grid[row][col] != "O") {
        grid[row][col] = token;
        valid = true;
    }
    return valid;
}

bool evalDiagonals(string grid [3][3], string token) {
    for (int i = 0; i < 3; i++) {
        if (grid[i][i] != token)
            return false;
    }
    for (int i = 3; i > 0; i--) {
        if (grid[3 - i][i] != token)
            return false;
    }
    return true;
}

bool evalRowCols(string grid[3][3], string token) {
    int rowpvt = 0, colpvt = 0;
    int bitwise [3][3] =
    {
        { 1,  2,   4   },
        { 8,  16,  32  },
        { 64, 128, 256 }
    };

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row][col] == token) {
                rowpvt |= bitwise[row][col];
            }
        }
        if (rowpvt / bitwise[row][0] == 7) return true;
        rowpvt = 0;
    }
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[col][row] == token) {
                colpvt |= bitwise[col][row];
            }
        }
        if (colpvt / bitwise[0][row] == 73) return true;
        colpvt = 0;
    }
}

bool checkWinner(string grid[3][3], bool player1) {
    string token = player1 ? "X" : "O";
    bool winner = evalDiagonals(grid, token) || evalRowCols(grid, token);
    return winner;
}