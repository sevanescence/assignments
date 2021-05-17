#include <iostream>
#include <fstream>

using namespace std;

struct MagicCard {
    string cardName;
    string type;
    string subtype;
    int power;
    int toughness;
};

void LoadCards(MagicCard cards[], size_t size);
void DisplayCards(MagicCard cards[], size_t size);

int main() {
    size_t const SIZE = 3;
    MagicCard cards[SIZE];
    LoadCards(cards, SIZE);
    DisplayCards(cards, SIZE);
}

void LoadCards(MagicCard cards[], size_t size) {
    ifstream fin;
    fin.open("Cards.txt");
    for (int i = 0; i < size; i++) {
        getline(fin, cards[i].cardName);
        getline(fin, cards[i].type);
        getline(fin, cards[i].subtype);
        fin >> cards[i].power;
        fin >> cards[i].toughness;

        fin.ignore();
    }
    fin.close();
}

void DisplayCards(MagicCard cards[], size_t size) {
    system("clear");
    for (int i = 0; i < size; i++) {
        cout << "Name: " << cards[i].cardName << endl;
        cout << "Type: " << cards[i].type << endl;
        cout << "P/T: " << cards[i].power << "/" << cards[i].toughness << endl;
    }
}