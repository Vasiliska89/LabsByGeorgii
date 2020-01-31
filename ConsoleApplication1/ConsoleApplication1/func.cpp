#define M 40
#define horse 500 
#define saber 100
#define rubie 50
#define necklace 10
#define wife 200
#include <iostream>
#include <string>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <locale.h>
#include "func.h"
void head() {
    cout << "------------------------------------------------------------------------------------------\n";
    cout << "|   Имя   | Живой |                        Имущество                         | Богатство |\n";
    cout << "|         |       |----------------------------------------------------------|           |\n";
    cout << "|         |       | Скакуны |  Сабли  | Рубины |  Ожерелья  |  Жены | Монеты |-----------|\n";
    cout << "------------------------------------------------------------------------------------------\n";
}
void write_rub(rubber r) {
    cout << "|";
    cout.width(9);
    cout << r.name;
    cout.width(1);
    cout << "|";
    cout.width(7);
    cout << r.alive;
    cout.width(1);
    cout << "|";
    cout.width(9);
    cout << r.horses;
    cout.width(1);
    cout << "|";
    cout.width(9);
    cout << r.sabers;
    cout.width(1);
    cout << "|";
    cout.width(8);
    cout << r.rubies;
    cout.width(1);
    cout << "|";
    cout.width(12);
    cout << r.necklaces;
    cout.width(1);
    cout << "|";
    cout.width(7);
    cout << r.wifes;
    cout.width(1);
    cout << "|";
    cout.width(8);
    cout << r.coins;
    cout.width(1);
    cout << "|";
    cout.width(11);
    cout << r.wealth;
    cout.width(1);
    cout << "|\n";
}
int set_wealth(rubber r) {
    return r.coins + r.horses * horse + r.sabers * saber + r.rubies * rubie + r.necklaces * necklace - r.wifes * wife;
}
int add(int a, int b) {
    return a + b;
}
rubber read(rubber rubbers[], string filename, rubber itogo) {
    srand(unsigned(std::time(0)));
    string name;
    int crew = 0;
    ifstream in(filename);
    if (in.is_open())
    {

        while (getline(in, name) && crew < M)
        {
            rubbers[crew].name = name;
            rubbers[crew].alive = rand() % 2;
            rubbers[crew].horses = rand() % 10;
            rubbers[crew].coins = rand() % 5000;
            rubbers[crew].necklaces = rand() % 10;
            rubbers[crew].rubies = rand() % 50;
            rubbers[crew].sabers = rand() % 5;
            rubbers[crew].wifes = rand() % 10;
            rubbers[crew].wealth = set_wealth(rubbers[crew]);
            if (rubbers[crew].alive) {
                itogo.alive++;
                itogo.horses += rubbers[crew].horses;
                itogo.coins += rubbers[crew].coins;
                itogo.necklaces += rubbers[crew].necklaces;
                itogo.rubies += rubbers[crew].rubies;
                itogo.sabers += rubbers[crew].sabers;
                itogo.wifes += rubbers[crew].wifes;
                itogo.wealth = set_wealth(itogo);
            }
            crew++;
        }
    }

    in.close();
    itogo.name = "Итого";
    return itogo;
}
void menu() {
    cout << "1 - Вся таблица" << "\n";
    cout << "2 - Вывод живых" << "\n";
    cout << "3 - Самый богатый" << "\n";
    cout << "4 - Убить" << "\n";
    cout << "5 - Новый член" << "\n";
    cout << "6 - Вывод по имени" << "\n";
    cout << "7 - Диаграмма" << "\n";
    cout << "0 - Выход" << "\n";
}
void write(rubber rubbers[], rubber itogo, int crew) {
    head();
    int i = 0;
    while (i < crew) {
        write_rub(rubbers[i]);
        i++;
    }
    write_rub(itogo);
}
void write_alive(rubber rubbers[], rubber itogo, int crew) {
    head();
    int i = 0;
    while (i < crew) {
        if (rubbers[i].alive) write_rub(rubbers[i]);
        i++;
    }
    write_rub(itogo);
}
void the_most_rich(rubber rubbers[], int crew) {
    int i = 0;
    int max = 0;
    for (i = 0; i < crew; i++) {
        if (rubbers[i].wealth > max) max = rubbers[i].wealth;
    }
    head();
    for (i = 0; i < crew; i++) {
        if (rubbers[i].wealth == max) write_rub(rubbers[i]);
    }
}
rubber kill(rubber rubbers[], rubber itogo) {
    cout << "Введите номер убитого:\n";
    int i;
    cin >> i;
    rubbers[i - 1].alive = 0;
    itogo.alive--;
    itogo.horses -= rubbers[i].horses;
    itogo.coins -= rubbers[i].coins;
    itogo.necklaces -= rubbers[i].necklaces;
    itogo.rubies -= rubbers[i].rubies;
    itogo.sabers -= rubbers[i].sabers;
    itogo.wifes -= rubbers[i].wifes;
    itogo.wealth = set_wealth(itogo);
    return itogo;
}
rubber freshman(rubber rubbers[], rubber itogo, int crew) {
    cout << "Введите имя:\n";
    cin >> rubbers[crew].name;
    cout << "Жив:\n";
    cin >> rubbers[crew].alive;
    cout << "Скакуны:\n";
    cin >> rubbers[crew].horses;
    cout << "Сабли:\n";
    cin >> rubbers[crew].sabers;
    cout << "Рубины:\n";
    cin >> rubbers[crew].rubies;
    cout << "Ожерелья:\n";
    cin >> rubbers[crew].necklaces;
    cout << "Жены:\n";
    cin >> rubbers[crew].wifes;
    cout << "Монеты:\n";
    cin >> rubbers[crew].coins;
    if (rubbers[crew].alive) {
        itogo.alive++;
        itogo.horses += rubbers[crew].horses;
        itogo.coins += rubbers[crew].coins;
        itogo.necklaces += rubbers[crew].necklaces;
        itogo.rubies += rubbers[crew].rubies;
        itogo.sabers += rubbers[crew].sabers;
        itogo.wifes += rubbers[crew].wifes;
        itogo.wealth = set_wealth(itogo);
    }
    return itogo;
}
void findname(rubber rubbers[], int crew) {
    _setmode(_fileno(stdout), _O_U16TEXT);
    cout << "Введите имя: ";
    string text;
    cin >> text;
    cout << text << "\n";
    head();
    for (int i = 0; i < crew; i++) {
        if (text == rubbers[i].name) write_rub(rubbers[i]);
    }
}