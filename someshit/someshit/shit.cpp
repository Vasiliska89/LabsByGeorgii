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

// ������� ����� � ��������� cp1251 (��� �� ANSI)
// �������� ��������, <windows.h> �� �����

int main()
{
    printf("This is russian [������] before cons1251()\n");
    cons1251();
    printf("This is russian [������] after cons1251()\n");


    char str[1000], buf[1000];

    printf("������ - ����� ����� �� \"������\"\n"); fflush(stdout);

    fgets(str, 1000, stdin);
    str[strlen(str) - 1] = 0;

    printf("�� �����: '%s'\n", str);
    if (strstr("������", str))
        printf("��, ����� �� '������'\n");
    else
        printf("������ ��� � ����� '������'\n");
    fflush(stdout);

    puts("���� ����� to exit...");  fflush(stdout);
    fgets(str, 1000, stdin);
}