#include <windows.h>                                        
#include <stdio.h> 
static int oldin = 0, oldout = 0;

static void exitfunc()
{
    SetConsoleCP(oldin);
    SetConsoleOutputCP(oldout);
}

void cons1251()
{
    if (oldin)
        return;

    atexit(exitfunc);

    oldin = GetConsoleCP();
    oldout = GetConsoleOutputCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

// русский текст в кодировке cp1251 (она же ANSI)
// обратите внимание, <windows.h> не нужен

int main()
{
    printf("This is russian [аЅв√д≈] before cons1251()\n");
    cons1251();
    printf("This is russian [аЅв√д≈] after cons1251()\n");


    char str[1000], buf[1000];

    printf("ѕривет - введи часть от \"привет\"\n"); fflush(stdout);

    fgets(str, 1000, stdin);
    str[strlen(str) - 1] = 0;

    printf("¬ы ввели: '%s'\n", str);
    if (strstr("привет", str))
        printf("да, часть от 'привет'\n");
    else
        printf("такого нет в слове 'привет'\n");
    fflush(stdout);

    puts("ждем ввода to exit...");  fflush(stdout);
    fgets(str, 1000, stdin);
}