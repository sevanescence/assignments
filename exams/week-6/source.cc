#include <iostream>
#include <string.h>
#include <random>

using namespace std;

// Makoto Miyamoto
// COSC 1436
// Week 6 Exam

string * initZodiacs();
int scanIntPersistent();
int promptInt(string query);

int main(void) {
  cout << "========================================" << endl;
  cout << "      ANIMAL SIGN & LOTTEY NUMBERS      " << endl;
  cout << "========================================" << endl;

  string* zodiacs (initZodiacs());

  int year (promptInt("Enter your birth year (1900-2018): "));
  if (year < 1900 || year > 2018) {
    cout << "Enter another year between 1900 and 2018" << endl;
  } else {
    cout << endl << zodiacs[year % 12] << endl << endl;
  }

  srand(time(nullptr));
  cout << "Lottery numbers: ";
  for (int i = 0; i < 6; i++) {
    cout << rand() % 54 + 1 << " ";
  }
  cout << endl;

  cout << "========================================" << endl;
  cout << "       God I need a job so badly.       " << endl;
  cout << "========================================" << endl;
}

string * initZodiacs() {
  string* zodiacs = new string[12];
    zodiacs[0]  = "Monkey: Very funny and good problem solvers!";
    zodiacs[1]  = "Rooster: Talented and hard workers!";
    zodiacs[2]  = "Dog: Very loyal and can keep a secret!";
    zodiacs[3]  = "Pig: Good students, honest and brave!";
    zodiacs[4]  = "Rat: Very popular!";
    zodiacs[5]  = "Ox: Dependable and calm!";
    zodiacs[6]  = "Tiger: Brave and respected!";
    zodiacs[7]  = "Rabbit: Nice to be around!";
    zodiacs[8]  = "Dragon: Good health anmd lots of energy!";
    zodiacs[9]  = "Snake: Good luck with money!";
    zodiacs[10] = "Horse: Popular, cheerful, and quick to compliment others!";
    zodiacs[11] = "Ram: Good artists!";
  return zodiacs;
}

int scanIntPersistent() {
  int num;
  while (! (cin >> num)) {
    cout << "Please enter a number." << endl;
    cin.clear();
    cin.ignore(123, '\n');
    return scanIntPersistent();
  }
  return num;
}

int promptInt(string query) {
  cout << query;
  return scanIntPersistent();
}