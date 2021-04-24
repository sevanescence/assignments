#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

struct employee
{
    int department;
    int employeeId;
    char employeeName[30];
};

int main(int argc, char *argv[])
{
    // ifstream inputBinary;    //Create a variable for our input file stream
    // char buffer[38];
    // int temp;

    // inputBinary.open("smallBinaryInput.dat");  //Open our smallBinaryInput file

    // if(!inputBinary)    //Check to see that you can open the file
    // {
    //     cout<<"Cannot open file"<<endl;
    //     return(0);
    // }
    
    ifstream file;
    file.open("smallBinaryInput.dat", ios::binary | ios::in);

    char buffer[38];
    file.readsome(buffer, 38);
    for (int i = 0; i < 38; i++) {
        cout << (int) buffer[i] << " ";
    } cout << endl;

    file.close();

    return 0;
}