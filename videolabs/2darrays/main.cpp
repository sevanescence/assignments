#include <iostream>
#include <cstdlib>

int main() {
    int const rows = 3;
    int const cols = 2;
    int array2D[rows][cols];

    std::srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array2D[i][j] = std::rand() % 100;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array2D[i][j] << ' ';
        } std::cout << std::endl;
    }
}