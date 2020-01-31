// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>
#include "func.h"


using namespace std;
int crew = M;
rubber rubbers[40];
rubber itogo;



int main()
{
    setlocale(0, "");
    //cout << "Hello World!\n";
    itogo = read(rubbers, "names.txt", itogo);
    menu();
    int i;
    cin >> i;
    while (i != 0) {
        switch (i) {
        case(1):
            write(rubbers, itogo, crew);
            break;
        case(2):
            write_alive(rubbers, itogo, crew);
            break;
        case(3):
            the_most_rich(rubbers, crew);
            break;
        case(4):
            itogo = kill(rubbers, itogo);
            break;
        case(5):
            itogo = freshman(rubbers, itogo, crew);
            crew++;
            break;
        case(6):
            findname(rubbers, crew);
            break;

        }
        menu();
        cin >> i;
    }
    /*for (int i = 0; i < 40; i++) {
        cout << rubbers[i].name << " | " << rubbers[i].alive << " | " << rubbers[i].horses <<"\n";
    }
    cout << add(4, 11);*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
