#include <iostream>
#include <string>

void setup(std::string grid[3][3]);
void display(std::string grid[3][3]);
bool isMoveValid(std::string grid[3][3], int row, int col, bool player1);
bool checkWinner(std::string grid[3][3], bool player1);

int main() {

}

void setup(std::string grid[3][3]) {
    int counter = 1;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            grid[row][col] = counter;
            counter++;
        }
    }
}

void display(std::string grid[3][3]) {
    if (std::system("clear")) std::system("cls");

    for (int row = 0; row < 3; row++) {
        std::cout << " | ";
        for (int col = 0; col < 3; col++) {
            std::cout << grid[row][col] << " | ";
        }
        std::cout << std::endl;
    }
}

bool isMoveValid(std::string grid[3][3], int row, int col, bool player1) {

}

bool checkWinner(std::string grid[3][3], bool player1) {

}