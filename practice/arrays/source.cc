#include <iostream>
#include <string>

void printIntArray(const int arraySize, int array[]);
void set(int index, int array[], int value);

int main(void) {
    constexpr int arraySize = 3;
    int array [arraySize]{ 1, 5, 2 };
    printIntArray(arraySize, array);
    
    set(0, array, 2);
    std::cout << "===" << std::endl;
    printIntArray(arraySize, array);

    return 0;
}

void printIntArray(const int arraySize, int array[]) {
    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << std::endl;
    }
}

void set(int index, int array[], int value) {
    array[index] = value;
}